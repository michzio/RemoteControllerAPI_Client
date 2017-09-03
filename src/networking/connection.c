//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include "../../include/networking/connection.h"

static result_t create_conn(client_info_t *info, create_conn_sock_t create_conn_sock , connection_handler_t handle_connection) {

    int cs_fd; // connection socket file descriptor

    printf("Creating new connection...\n");

    if(create_conn_sock(client_info_conn_ip(info),
                        client_info_conn_port(info),
                        client_info_pasv_port(info),
                        &cs_fd) == FAILURE) {
        fprintf(stderr, "create_conn_sock: failed!\n");
        // publish connection error event
        client_info_connection_error_event(info, CONN_ERROR_CREATE_SOCK, "create_conn_sock: failed!");
        return FAILURE;
    }

    if(client_info_fill(info, cs_fd)) {
        fprintf(stderr, "client_info_fill: failed!\n");
        return FAILURE;
    }

    // publish connection start event
    client_info_connection_start_event(info);

    switch(handle_connection(info, cs_fd)) {
        case FAILURE:
            fprintf(stderr, "handle_connection: failed!\n");
            // publish connection error event
            client_info_connection_error_event(info, CONN_ERROR_HANDLER, "handle_connection: failed!");
            return FAILURE;
        case CLOSED:
            if(close(cs_fd) < 0) {
                fprintf(stderr, "close: %s\n", strerror(errno));
                // publish connection error event
                client_info_connection_error_event(info, CONN_ERROR_CLOSE, strerror(errno));
                return FAILURE;
            }
            // publish connection end event
            client_info_connection_end_event(info);
            return CLOSED;
        default:
            break;
    }
    return SUCCESS;
}

result_t create_stream_conn(client_info_t *client_info, connection_handler_t handle_connection)  {
    return create_conn(client_info, create_stream_conn_sock, handle_connection);
}

result_t create_datagram_conn(client_info_t *client_info, connection_handler_t handle_connection) {
    return create_conn(client_info, create_datagram_conn_sock, handle_connection);
}