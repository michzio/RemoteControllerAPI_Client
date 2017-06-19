//
// Created by Michal Ziobro on 25/07/2016.
//
#ifndef REMOTECONTROLLERAPI_CLIENT_CONNECTION_H
#define REMOTECONTROLLERAPI_CLIENT_CONNECTION_H

#include "../../networking/helpers/address_helper.h"
#include "conn_socket.h"
#include "generic_client.h"

typedef result_t (*connection_handler_t)(client_info_t *, sock_fd_t);

result_t create_stream_conn(client_info_t *client_info, connection_handler_t conn_handler);
result_t create_datagram_conn(client_info_t *client_info, connection_handler_t conn_handler);

#endif //REMOTECONTROLLERAPI_CLIENT_CONNECTION_H
