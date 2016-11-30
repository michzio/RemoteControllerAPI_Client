//
// Created by Michal Ziobro on 15/10/2016.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H
#define REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H

#include "../networking/connection.h"
#include "../client.h"

typedef struct {
    void (*run_tests)(void);
} test_client_transfer_t;

extern test_client_transfer_t test_client_transfer;

#define TEST_PORT "3333"

static void test_create_stream_conn(connection_handler_t test_service_handler) {

    if(create_stream_conn(SERVER_ADDRESS, TEST_PORT, test_service_handler) != SUCCESS) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return;
    }
}

#endif //REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H
