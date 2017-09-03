//
// Created by Michal Ziobro on 13/10/2016.
//

#include "test_client.h"
#include "../include/networking/stream_client.h"
#include "../include/networking/datagram_client.h"
#include "../include/client.h"
#include "../include/config.h"

static void test_stream_client(void) {

    client_info_t *client_info;
    client_info_init(&client_info);
    client_info_set_conn_ip(client_info, TEST_SERVER_ADDRESS);
    client_info_set_conn_port(client_info, TEST_SERVER_PORT);

    start_client(echo_stream_client, client_info);


}

static void test_datagram_client(void) {

    client_info_t *client_info;
    client_info_init(&client_info);
    client_info_set_conn_ip(client_info, TEST_SERVER_ADDRESS);
    client_info_set_conn_port(client_info, TEST_SERVER_PORT);

    start_client(echo_datagram_client, client_info);
}

static void run_tests(void) {

    // TCP client
    test_stream_client();
    // UDP client
    test_datagram_client();
}

test_client_t test_client = { .run_tests = run_tests };