//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include <unistd.h>
#include "connection.h"
#include "conn_socket.h"

result_t create_stream_conn(connection_handler_t handle_connection)  {

    int cs_fd; // connection socket file descriptor

    printf("Creating new stream connection...\n");

    if(create_stream_conn_sock(&cs_fd) == FAILURE) {
        fprintf(stderr, "create_stream_conn_sock: failed!\n");
        return FAILURE;
    }

    if(handle_connection(cs_fd) == FAILURE) {
        fprintf(stderr, "handle_connection: failed!\n");
        return FAILURE;
    }

    close(cs_fd);

    return SUCCESS;
}


result_t create_datagram_conn(connection_handler_t handle_connection) {


}