#define _REENTRANT
#include <pthread.h>

#include<stdio.h>
#include "client.h"

int main(int argc, char **argv) {

    printf("Remote Controller Client - mobile side, remotely controlling.\n");

    if( start_client() == FAILURE ) {
        fprintf(stderr, "start_client: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}