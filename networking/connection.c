//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include <unistd.h>
#include "connection.h"

static result_t create_conn(const char*addr, const char *port, create_conn_sock_t create_conn_sock , connection_handler_t handle_connection) {

    int cs_fd; // connection socket file descriptor

    printf("Creating new stream connection...\n");

    if(create_conn_sock(addr, port, &cs_fd) == FAILURE) {
        fprintf(stderr, "create_conn_sock: failed!\n");
        return FAILURE;
    }

    if(handle_connection(cs_fd) == FAILURE) {
        fprintf(stderr, "handle_connection: failed!\n");
        return FAILURE;
    }

    close(cs_fd);

    return SUCCESS;
}

result_t create_stream_conn(const char*addr, const char *port, connection_handler_t handle_connection)  {
    return create_conn(addr, port, create_stream_conn_sock, handle_connection);
}


result_t create_datagram_conn(const char*addr, const char *port, connection_handler_t handle_connection) {
    return create_conn(addr, port, create_datagram_conn_sock, handle_connection);
}