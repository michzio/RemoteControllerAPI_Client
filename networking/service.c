//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "service.h"
#include "../../networking/helpers/io_helper.h"

result_t rpc_service_handler(sock_fd_t sock_fd) {
    // TODO

    return 0;
}

result_t event_service_handler(sock_fd_t sock_fd) {

    // TODO

    return 0;
}

result_t echo_service_handler(sock_fd_t sock_fd) {

    char buf[256];
    int n_sent; // number of bytes sent
    int n_recv; // number of bytes received

    while(1) {

        // read input from console
        char *input = read_line();

        if(strlen(input) == 0) {
            fprintf(stderr, "empty input!\n");
            continue;
        }

        if(strcmp(input, "q") == 0) break;

        printf("client: console input '%s'\n", input);

        if( (n_sent = send(sock_fd, input, strlen(input), 0)) < 0) {
            perror("send");
            return FAILURE;
        }

        free(input);

        if( (n_recv = recv(sock_fd, buf, sizeof(buf)-1, 0)) < 0) {
            perror("recv");
            return FAILURE;
        }

        buf[n_recv] = '\0';

        printf("client: received '%s'\n", buf);
    }

    return SUCCESS;
}