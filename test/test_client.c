//
// Created by Michal Ziobro on 13/10/2016.
//

#include "test_client.h"
#include "../networking/stream_conn.h"
#include "../networking/datagram_conn.h"

static void test_stream_client(void) {
    echo_stream_conn();
}

static void test_datagram_client(void) {
    echo_datagram_conn();
}

static void run_tests(void) {

    // TCP client
    // test_stream_client();
    // UDP client
    test_datagram_client();
}

test_client_t test_client = { .run_tests = run_tests };