//
// Created by Michal Ziobro on 13/10/2016.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_TEST_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_TEST_CLIENT_H

typedef struct {
    void (*run_tests)(void);
} test_client_t;

extern test_client_t test_client;

#endif //REMOTECONTROLLERAPI_CLIENT_TEST_CLIENT_H
