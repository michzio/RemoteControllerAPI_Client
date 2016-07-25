//
// Created by Michal Ziobro on 25/07/2016.
//
#ifndef REMOTECONTROLLERAPI_CLIENT_CONNECTION_H
#define REMOTECONTROLLERAPI_CLIENT_CONNECTION_H

#include "../common/helper.h"
#include "conn_socket.h"

typedef result_t (*connection_handler_t)(sock_fd_t);

result_t create_stream_conn(connection_handler_t conn_handler);
result_t create_datagram_conn(connection_handler_t conn_handler);

#endif //REMOTECONTROLLERAPI_CLIENT_CONNECTION_H
