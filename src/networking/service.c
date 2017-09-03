//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/errno.h>
#include "networking/service.h"
#include "helpers/io_helper.h"
#include "networking/authentication.h"

#define MAX_BUF_SIZE 256

result_t rpc_service_handler(client_info_t *client_info, sock_fd_t sock_fd) {

    // authenticate client on the server
    if(authenticate_client_on_server(client_info, sock_fd) == FAILURE) {
        fprintf(stderr, "authenticate_client_on_server: failed!\n");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_AUTH, "authenticate_client_on_server: failed!");
        return FAILURE;
    }

    return event_service_handler(client_info, sock_fd);
}

result_t event_service_handler(client_info_t *client_info, sock_fd_t sock_fd) {

    char buf[MAX_BUF_SIZE];
    int n_recv; // number of bytes received

    while(1) {

        if ((n_recv = recv(sock_fd, buf, sizeof(buf) - 1, 0)) <= 0) {
            if(n_recv == 0) {
                printf("connection is closing...\n");
                return CLOSED;
            }
            perror("recv");
            // publish connection error event
            client_info_connection_error_event(client_info, CONN_ERROR_RECV, strerror(errno));
            return FAILURE;
        }
        buf[n_recv] = '\0';

        printf("client: received event '%s'\n", buf);

    }
}

result_t echo_service_handler(client_info_t *client_info, sock_fd_t sock_fd) {

    char buf[MAX_BUF_SIZE];
    int n_sent; // number of bytes sent
    int n_recv; // number of bytes received

    // authenticate client on the server
    if(authenticate_client_on_server(client_info, sock_fd) == FAILURE) {
        fprintf(stderr, "authenticate_client_on_server: failed!\n");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_AUTH, "authenticate_client_on_server: failed!");
        return FAILURE;
    }

    while(1) {

        // read input from console
        char *input = read_line();

        if(strlen(input) == 0) {
            fprintf(stderr, "empty input!\n");
            continue;
        }
        if(strcmp(input, "q") == 0) return CLOSED;

        printf("client: console input '%s'\n", input);

        if( (n_sent = send(sock_fd, input, strlen(input), 0)) < 0) {
            perror("send");
            // publish connection error event
            client_info_connection_error_event(client_info, CONN_ERROR_SEND, strerror(errno));
            return FAILURE;
        }

        free(input);

        if( (n_recv = recv(sock_fd, buf, sizeof(buf)-1, 0)) <= 0) {
            if(n_recv == 0) {
                printf("echo connection is closing...\n");
                return CLOSED;
            }
            perror("recv");
            // publish connection error event
            client_info_connection_error_event(client_info, CONN_ERROR_RECV, strerror(errno));
            return FAILURE;
        }
        buf[n_recv] = '\0';

        printf("client: received '%s'\n", buf);
    }
}