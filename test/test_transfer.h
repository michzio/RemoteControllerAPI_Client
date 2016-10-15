//
// Created by Michal Ziobro on 15/10/2016.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H
#define REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H

typedef struct {
    void (*run_tests)(void);
} test_client_transfer_t;

extern test_client_transfer_t test_client_transfer;

#endif //REMOTECONTROLLERAPI_CLIENT_TEST_TRANSFER_H
