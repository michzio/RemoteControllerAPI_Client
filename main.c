#define _REENTRANT
#include <pthread.h>

#include<stdio.h>
#include "client.h"
#include "test/test_client.h"

int main(int argc, char **argv) {

    printf("Remote Controller Client - mobile side, remotely controlling.\n");

    //test_client.run_tests();
    start_client();

    return SUCCESS;
}