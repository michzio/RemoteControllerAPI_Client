//
// Created by Michal Ziobro on 15/10/2016.
//

#include <stdio.h>
#include <unistd.h>
#include "test_transfer.h"
#include "../networking/connection.h"
#include "../client.h"
#include "../../networking/transfer/integer_transfer.h"
#include "../../unit_tests/test/assertion.h"

#define TEST_PORT "3333"

static void test_create_stream_conn(connection_handler_t test_service_handler) {

    if(create_stream_conn(SERVER_ADDRESS, TEST_PORT, test_service_handler) != SUCCESS) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return;
    }
}

static result_t uint8_transfer_handler(sock_fd_t sock_fd) {

    result_t res = 0;
    uint8_t sentUint8 = 20;
    uint8_t recvedUint8 = 0;

    res = send_uint8(sock_fd, sentUint8);
    assert_equal_int(res, SUCCESS, "Sent uint8 number to socket");

    res = recv_uint8(sock_fd, &recvedUint8);
    assert_equal_int(res, SUCCESS, "Received uint8 number from socket");

    assert_equal_int(sentUint8, recvedUint8, __func__);

    close(sock_fd);
}

static void test_uint8_transfer(void) {
    test_create_stream_conn(uint8_transfer_handler);
}

static void run_tests(void) {

    test_uint8_transfer();
    //test_uint16_transfer();
    //test_uint32_transfer();
    //test_uint64_transfer();
    //test_binary_transfer();
    //test_cstring_transfer();
}

test_client_transfer_t test_client_transfer = { .run_tests = run_tests };
