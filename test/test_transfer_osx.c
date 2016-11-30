//
// Created by Michal Ziobro on 30.11.2016.
//

/**
 * This code is implemented only for Mac OS X.
 */
#ifdef __APPLE__

#include "test_transfer.h"
#include <memory.h>
#include <stdlib.h>
#include <CoreServices/CoreServices.h>
#include <CoreGraphics/CoreGraphics.h>
#include "../../common/bitwise.h"
#include "../../common/bitmaps.h"
#include "../../common/libraries/lz4/lz4.h"
#include "../../networking/transfer/binary_transfer.h"
#include "../../networking/transfer/integer_transfer.h"
#include "../../unit_tests/test/assertion.h"
#include "../../unit_tests/common/terminal.h"

/**
 * PNG transfer
 * test_png_transfer()
 */
static result_t png_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    unsigned char *pngData = 0;
    size_t pngDataLength = 0;
    size_t width = 0, height = 0;

    // get size of png image
    recv_uint32(sock_fd, &width);
    recv_uint32(sock_fd, &height);
    // get length of png data
    recv_uint32(sock_fd, &pngDataLength);

    // get png data
    pngData = (unsigned char *) malloc(sizeof(unsigned char)*pngDataLength);
    res = recv_binary(sock_fd, PACKET_LENGTH, pngData, pngDataLength);

    assert_equal_int(res, SUCCESS, "received PNG data from socket");
    printf(ANSI_COLOR_CYAN "png image size (%zu, %zu)\n" ANSI_COLOR_RESET, width, height);

    res = (result_t) fwrite_binaries("/Users/michzio/Desktop/test_client_screen_snapshot.png", pngData, pngDataLength);
    assert_equal_int(res, SUCCESS, "PNG data saved to file");

    free(pngData);

    return SUCCESS;
}

static void test_png_transfer(void) {
    test_create_stream_conn(png_transfer_handler);
}

/**
 * Display Stream PNG transfer
 * test_display_stream_png_transfer()
 */
static int count = 0;

static result_t display_stream_png_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    unsigned char *pngData = 0;
    size_t pngDataLength = 0;
    size_t width = 0, height = 0;

    // get size of png frame
    if(recv_uint32(sock_fd, &width) != SUCCESS) return FAILURE;
    if(recv_uint32(sock_fd, &height) != SUCCESS) return FAILURE;
    // get length of png data
    if(recv_uint32(sock_fd, &pngDataLength) != SUCCESS) return FAILURE;

    // get png data
    pngData = (unsigned char *) malloc(sizeof(unsigned char)*pngDataLength);
    res = recv_binary(sock_fd, PACKET_LENGTH, pngData, pngDataLength);
    assert_equal_int(res, SUCCESS, "received PNG data from socket");

    if(res != SUCCESS) return FAILURE;
    printf(ANSI_COLOR_CYAN "png frame size (%zu, %zu)\n" ANSI_COLOR_RESET, width, height);

    count++;
    char filePath[256];
    sprintf(filePath, "/Users/michzio/Desktop/display_stream/%d.png", count);
    res = (result_t) fwrite_binaries(filePath, pngData, pngDataLength);
    assert_equal_int(res, SUCCESS, "PNG data saved to file");

    printf("Frame counter: %d\n", count);
    free(pngData);

    return SUCCESS;
}

static result_t display_stream_png_transfer_handler_loop(sock_fd_t sock_fd) {

    while(1)
        if(display_stream_png_transfer_handler(sock_fd) != SUCCESS) return FAILURE;
}

static void test_display_stream_png_transfer(void) {
    count = 0;
    test_create_stream_conn(display_stream_png_transfer_handler_loop);
}

/**
 * Display Stream LZ4 transfer
 * test_display_stream_lz4_transfer()
 */
#define FRAME_BUFFER_SIZE WIDTH_5K_16_9*HEIGHT_5K_16_9*RGBA_COMPONENTS_PER_PIXEL
#define LZ4_BUFFER_SIZE LZ4_COMPRESSBOUND(FRAME_BUFFER_SIZE)
static unsigned char xorFrameBuffer[FRAME_BUFFER_SIZE];
static unsigned char frameBuffer[FRAME_BUFFER_SIZE] = { 0 };
static size_t frameBufferLength = 0;
static size_t frameWidth = 0, frameHeight = 0;
static unsigned char lz4Data[LZ4_BUFFER_SIZE];

static result_t display_stream_lz4_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    size_t lz4DataLength = 0;

    // get length of LZ4 compressed data
    if (recv_uint32(sock_fd, &lz4DataLength) != SUCCESS) return FAILURE;
    // get LZ4 compressed data
    res = recv_binary(sock_fd, PACKET_LENGTH, lz4Data, lz4DataLength);
    assert_equal_int(res, SUCCESS, "received LZ4 compressed data from socket");
    if (res != SUCCESS) return FAILURE;

    printf(ANSI_COLOR_CYAN "LZ4 data length: %zu\n" ANSI_COLOR_RESET, lz4DataLength);

    // decompress frame data with LZ4
    if(LZ4_decompress_safe(lz4Data, xorFrameBuffer, lz4DataLength, frameBufferLength) < 0) {
        fprintf(stderr, "%s: Error at decompression of LZ4 data.\n", __func__);
        return FAILURE;
    }

    bitwise_xor64_static(frameBuffer, xorFrameBuffer, frameBufferLength, frameBuffer);

    CGContextRef context = CGBitmapContextCreate(frameBuffer, frameWidth, frameHeight, 8,
                                                 COMPONENTS_PER_PIXEL * frameWidth, CGColorSpaceCreateDeviceRGB(), kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
    CGImageRef image = CGBitmapContextCreateImage(context);
    CFRelease(context);

    count++;
    printf("Frame counter: %d\n", count);
    //char filePath[256];
    //sprintf(filePath, "/Users/michzio/Desktop/display_stream/%d.bmp", count);

    return SUCCESS;
}

static result_t display_stream_lz4_transfer_handler_loop(sock_fd_t sock_fd) {

    if (recv_uint32(sock_fd, &frameWidth) != SUCCESS) return FAILURE;
    if (recv_uint32(sock_fd, &frameHeight) != SUCCESS) return FAILURE;
    printf(ANSI_COLOR_CYAN "frame size (%zu, %zu)\n" ANSI_COLOR_RESET, frameWidth, frameHeight);

    frameBufferLength = frameWidth*frameHeight*RGBA_COMPONENTS_PER_PIXEL;

    while(1)
        if(display_stream_lz4_transfer_handler(sock_fd) != SUCCESS) return FAILURE;
}

static void test_display_stream_lz4_transfer(void) {
    count = 0;
    test_create_stream_conn(display_stream_lz4_transfer_handler_loop);
}

/*
 * Display Stream updates LZ4 transfer
 * test_display_stream_updates_lz4_transfer()
 */
static unsigned char updateBuffer[FRAME_BUFFER_SIZE] = { 0 };
static size_t updateBufferLength = 0;

static result_t display_stream_updates_lz4_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    size_t offsetX = 0, offsetY = 0;
    size_t updateWidth = 0, updateHeight = 0;
    size_t lz4DataLength = 0;

    // recv update frame metadata
    if (recv_uint32(sock_fd, &offsetX) != SUCCESS) return FAILURE;
    if (recv_uint32(sock_fd, &offsetY) != SUCCESS) return FAILURE;
    if (recv_uint32(sock_fd, &updateWidth) != SUCCESS) return FAILURE;
    if (recv_uint32(sock_fd, &updateHeight) != SUCCESS) return FAILURE;

    // get length of LZ4 compressed data
    if (recv_uint32(sock_fd, &lz4DataLength) != SUCCESS) return FAILURE;
    // get LZ4 compressed data
    res = recv_binary(sock_fd, PACKET_LENGTH, lz4Data, lz4DataLength);
    assert_equal_int(res, SUCCESS, "received LZ4 compressed data from socket");
    if (res != SUCCESS) return FAILURE;

    printf(ANSI_COLOR_CYAN "LZ4 data length: %zu\n" ANSI_COLOR_RESET, lz4DataLength);

    // decompress update data with LZ4
    updateBufferLength = updateWidth*updateHeight*RGBA_COMPONENTS_PER_PIXEL;
    if(LZ4_decompress_safe(lz4Data, updateBuffer, lz4DataLength, updateBufferLength) < 0) {
        fprintf(stderr, "%s: Error at decompression of LZ4 data.\n", __func__);
        return FAILURE;
    }

    // update frame buffer with new data
    size_t updateOffset = offsetY*frameWidth*RGBA_COMPONENTS_PER_PIXEL + offsetX*RGBA_COMPONENTS_PER_PIXEL;
    memcpy(frameBuffer + updateOffset, updateBuffer, updateBufferLength);

    count++;
    printf("Frame counter: %d\n", count);

    return SUCCESS;
}

static result_t display_stream_updates_lz4_transfer_handler_loop(sock_fd_t sock_fd) {

    if (recv_uint32(sock_fd, &frameWidth) != SUCCESS) return FAILURE;
    if (recv_uint32(sock_fd, &frameHeight) != SUCCESS) return FAILURE;
    printf(ANSI_COLOR_CYAN "frame size (%zu, %zu)\n" ANSI_COLOR_RESET, frameWidth, frameHeight);

    frameBufferLength = frameWidth*frameHeight*RGBA_COMPONENTS_PER_PIXEL;

    while(1)
        if(display_stream_updates_lz4_transfer_handler(sock_fd) != SUCCESS) return FAILURE;
}

static void test_display_stream_updates_lz4_transfer(void) {
    count = 0;
    test_create_stream_conn(display_stream_updates_lz4_transfer_handler_loop);
}

#endif // __APPLE__