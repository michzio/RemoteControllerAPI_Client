//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include <unistd.h>
#include "connection.h"
#include "generic_client.h"

static result_t create_conn(client_info_t *info, create_conn_sock_t create_conn_sock , connection_handler_t handle_connection) {

    int cs_fd; // connection socket file descriptor

    printf("Creating new connection...\n");

    if(create_conn_sock(client_info_conn_ip(info),
                        client_info_conn_port(info),
                        &cs_fd) == FAILURE) {
        fprintf(stderr, "create_conn_sock: failed!\n");
        return FAILURE;
    }

    if(client_info_fill(info, cs_fd)) {
        fprintf(stderr, "client_info_fill: failed!\n");
        return FAILURE;
    }

    if(handle_connection(cs_fd) == FAILURE) {
        fprintf(stderr, "handle_connection: failed!\n");
        return FAILURE;
    }

    close(cs_fd);

    return SUCCESS;
}

result_t create_stream_conn(client_info_t *client_info, connection_handler_t handle_connection)  {
    return create_conn(client_info, create_stream_conn_sock, handle_connection);
}


result_t create_datagram_conn(client_info_t *client_info, connection_handler_t handle_connection) {
    return create_conn(client_info, create_datagram_conn_sock, handle_connection);
}