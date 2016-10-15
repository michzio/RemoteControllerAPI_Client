#define _REENTRANT
#include <pthread.h>

#include<stdio.h>
#include "client.h"
#include "test/test_client.h"
#include "test/test_transfer.h"

int main(int argc, char **argv) {

    printf("Remote Controller Client - mobile side, remotely controlling.\n");

    //test_client.run_tests();
    test_client_transfer.run_tests();
    //start_client();

    return SUCCESS;
}