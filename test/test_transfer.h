//
// Created by Michal Ziobro on 15/10/2016.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H
#define REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H

#include "../include/networking/connection.h"
#include "../include/client.h"
#include "../include/config.h"

typedef struct {
    void (*run_tests)(void);
} test_client_transfer_t;

extern test_client_transfer_t test_client_transfer;


static void test_create_stream_conn(connection_handler_t test_service_handler) {

    client_info_t *client_info;
    client_info_init(&client_info);
    client_info_set_conn_ip(client_info, TEST_SERVER_ADDRESS);
    client_info_set_conn_port(client_info, TEST_SERVER_PORT);

    if(create_stream_conn(client_info, test_service_handler) != SUCCESS) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return;
    }

    client_info_free(client_info);
}

#endif //REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H
