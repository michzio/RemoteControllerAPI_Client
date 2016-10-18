//
// Created by Michal Ziobro on 15/10/2016.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "test_transfer.h"
#include "../networking/connection.h"
#include "../client.h"
#include "../../networking/transfer/integer_transfer.h"
#include "../../networking/transfer/str_transfer.h"
#include "../../networking/transfer/binary_transfer.h"
#include "../../unit_tests/test/assertion.h"
#include "../../unit_tests/common/terminal.h"
#include "../../comparers/comparer.h"
#include "../../common/bitwise.h"
#include "../../common/libraries/lz4/lz4.h"

#define TEST_PORT "3333"

static void test_create_stream_conn(connection_handler_t test_service_handler) {

    if(create_stream_conn(SERVER_ADDRESS, TEST_PORT, test_service_handler) != SUCCESS) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return;
    }
}

static result_t uint8_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    uint8_t sentUint8 = 8;
    uint8_t recvedUint8 = 0;

    res = send_uint8(sock_fd, sentUint8);
    assert_equal_int(res, SUCCESS, "Sent uint8 number to socket");

    res = recv_uint8(sock_fd, &recvedUint8);
    assert_equal_int(res, SUCCESS, "Received uint8 number from socket");

    assert_equal_int(sentUint8, recvedUint8, __func__);

    return SUCCESS;
}

static void test_uint8_transfer(void) {
    test_create_stream_conn(uint8_transfer_handler);
}

static result_t uint16_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    uint16_t sentUint16 = 16;
    uint16_t recvedUint16 = 0;

    res = send_uint16(sock_fd, sentUint16);
    assert_equal_int(res, SUCCESS, "Sent uint16 number to socket");

    res = recv_uint16(sock_fd, &recvedUint16);
    assert_equal_int(res, SUCCESS, "Received uint16 number from socket");

    assert_equal_int(sentUint16, recvedUint16, __func__);

    return SUCCESS;
}

static void test_uint16_transfer(void) {
    test_create_stream_conn(uint16_transfer_handler);
}

static result_t uint32_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    uint32_t sentUint32 = 32;
    uint32_t recvedUint32 = 0;

    res = send_uint32(sock_fd, sentUint32);
    assert_equal_int(res, SUCCESS, "Sent uint32 number to socket");

    res = recv_uint32(sock_fd, &recvedUint32);
    assert_equal_int(res, SUCCESS, "Received uint32 number from socket");

    assert_equal_int(sentUint32, recvedUint32, __func__);

    return SUCCESS;
}

static void test_uint32_transfer(void) {
    test_create_stream_conn(uint32_transfer_handler);
}

static result_t uint64_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    uint64_t sentUint64 = 64;
    uint64_t recvedUint64 = 0;

    res = send_uint64(sock_fd, sentUint64);
    assert_equal_int(res, SUCCESS, "Sent uint64 number to socket");

    res = recv_uint64(sock_fd, &recvedUint64);
    assert_equal_int(res, SUCCESS, "Received uint64 number from socket");

    assert_equal_int(sentUint64, recvedUint64, __func__);

    return SUCCESS;
}

static void test_uint64_transfer(void) {
    test_create_stream_conn(uint64_transfer_handler);
}

static result_t int8_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    int8_t sentInt8 = -8;
    int8_t recvedInt8 = 0;

    res = send_int8(sock_fd, sentInt8);
    assert_equal_int(res, SUCCESS, "Sent int8 number to socket");

    res = recv_int8(sock_fd, &recvedInt8);
    assert_equal_int(res, SUCCESS, "Received int8 number from socket");

    assert_equal_int(sentInt8, recvedInt8, __func__);

    return SUCCESS;
}

static void test_int8_transfer(void) {
    test_create_stream_conn(int8_transfer_handler);
}

static result_t int16_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    int16_t sentInt16 = -16;
    int16_t recvedInt16 = 0;

    res = send_int16(sock_fd, sentInt16);
    assert_equal_int(res, SUCCESS, "Sent int16 number to socket");

    res = recv_int16(sock_fd, &recvedInt16);
    assert_equal_int(res, SUCCESS, "Received int16 number from socket");

    assert_equal_int(sentInt16, recvedInt16, __func__);

    return SUCCESS;
}

static void test_int16_transfer(void) {
    test_create_stream_conn(int16_transfer_handler);
}

static result_t int32_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    int32_t sentInt32 = -32;
    int32_t recvedInt32 = 0;

    res = send_int32(sock_fd, sentInt32);
    assert_equal_int(res, SUCCESS, "Sent int32 number to socket");

    res = recv_int32(sock_fd, &recvedInt32);
    assert_equal_int(res, SUCCESS, "Received int32 number from socket");

    assert_equal_int(sentInt32, recvedInt32, __func__);

    return SUCCESS;
}

static void test_int32_transfer(void) {
    test_create_stream_conn(int32_transfer_handler);
}

static result_t int64_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    int64_t sentInt64 = -64;
    int64_t recvedInt64 = 0;

    res = send_int64(sock_fd, sentInt64);
    assert_equal_int(res, SUCCESS, "Sent int64 number to socket");

    res = recv_int64(sock_fd, &recvedInt64);
    assert_equal_int(res, SUCCESS, "Received int64 number from socket");

    assert_equal_int(sentInt64, recvedInt64, __func__);

    return SUCCESS;
}

static void test_int64_transfer(void) {
    test_create_stream_conn(int64_transfer_handler);
}

#define BINARY_DATA_LENGTH 32

static result_t binary_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    unsigned char sentBinaryData[BINARY_DATA_LENGTH];
    unsigned char recvedBinaryData[BINARY_DATA_LENGTH];

    // fill binary data to be send
    for(int i=0; i<BINARY_DATA_LENGTH; i++) {
        sentBinaryData[i] = (uint8_t) i;
    }

    res = send_binary(sock_fd, 8, sentBinaryData, BINARY_DATA_LENGTH);
    assert_equal_int(res, SUCCESS, "Sent binary data to socket");

    res = recv_binary(sock_fd, 8, recvedBinaryData, BINARY_DATA_LENGTH);
    assert_equal_int(res, SUCCESS, "Received binary data from socket");

    assert_equal_array(sentBinaryData, recvedBinaryData, BINARY_DATA_LENGTH, binary_cmp_func, __func__);

    return SUCCESS;
}

static void test_binary_transfer(void) {
    test_create_stream_conn(binary_transfer_handler);
}

static result_t cstring_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    char *sentCString = "Testowy tekst!";
    char *recvedCString = 0;
    size_t recvedCStringLen = 0;

    res = send_cstr(sock_fd, sentCString, strlen(sentCString));
    assert_equal_int(res, SUCCESS, "Sent cstring to socket");

    res = recv_cstr(sock_fd, &recvedCString, &recvedCStringLen);
    assert_equal_int(res, SUCCESS, "Received cstring from socket");

    assert_equal_int(strlen(sentCString), recvedCStringLen, "Sent and Received cstring lengths are equal");
    assert_equal(sentCString, recvedCString, str_cmp_func, __func__);

    free(recvedCString);

    return SUCCESS;
}

static void test_cstring_transfer(void) {
    test_create_stream_conn(cstring_transfer_handler);
}

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

static unsigned char *xorData = 0;
static size_t xorDataLength = 0;

static result_t display_stream_lz4_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    unsigned char *lz4Data = 0;
    size_t lz4DataLength = 0;

    // get length of LZ4 compressed data
    if (recv_uint32(sock_fd, &lz4DataLength) != SUCCESS) return FAILURE;
    // get LZ4 compressed data
    lz4Data = (unsigned char *) malloc(sizeof(unsigned char) * lz4DataLength);
    res = recv_binary(sock_fd, PACKET_LENGTH, lz4Data, lz4DataLength);
    assert_equal_int(res, SUCCESS, "received LZ4 compressed data from socket");

    if (res != SUCCESS) return FAILURE;
    printf(ANSI_COLOR_CYAN "LZ4 data length: %zu\n" ANSI_COLOR_RESET, lz4DataLength);

    // decompress frame data with LZ4
    if(LZ4_decompress_safe(lz4Data, xorData, lz4DataLength, xorDataLength) < 0) {
        fprintf(stderr, "%s: Error at decompression of LZ4 data.\n", __func__);
        return FAILURE;
    }

    count++;
    //char filePath[256];
    //sprintf(filePath, "/Users/michzio/Desktop/display_stream/%d.bmp", count);

    printf("Frame counter: %d\n", count);
    free(lz4Data);

    return SUCCESS;
}

static result_t display_stream_lz4_transfer_handler_loop(sock_fd_t sock_fd) {

    size_t width = 0, height = 0;
    if (recv_uint32(sock_fd, &width) != SUCCESS) return FAILURE;
    if (recv_uint32(sock_fd, &height) != SUCCESS) return FAILURE;
    printf(ANSI_COLOR_CYAN "frame size (%zu, %zu)\n" ANSI_COLOR_RESET, width, height);

    // allocate required data structures
    xorDataLength = width*height*4;
    xorData = malloc(sizeof(unsigned char)*xorDataLength);

    while(1)
        if(display_stream_lz4_transfer_handler(sock_fd) != SUCCESS) return FAILURE;
}

static void test_display_stream_lz4_transfer(void) {
    count = 0;
    test_create_stream_conn(display_stream_lz4_transfer_handler_loop);
}

static void run_tests(void) {

    printf(ANSI_COLOR_BLUE "Integration Test - requires to run: 'server' program only with 'test_server_transfer.run_tests()' \n" ANSI_COLOR_RESET);
    /*test_uint8_transfer();
    test_uint16_transfer();
    test_uint32_transfer();
    test_uint64_transfer();
    test_int8_transfer();
    test_int16_transfer();
    test_int32_transfer();
    test_int64_transfer();
    test_binary_transfer();
    test_cstring_transfer();
    test_png_transfer(); */
    //test_display_stream_png_transfer();
    test_display_stream_lz4_transfer();
}

test_client_transfer_t test_client_transfer = { .run_tests = run_tests };
