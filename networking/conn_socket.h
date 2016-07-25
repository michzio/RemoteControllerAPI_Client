//
// Created by Michal Ziobro on 25/07/2016.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_CONN_SOCKET_H
#define REMOTECONTROLLERAPI_CLIENT_CONN_SOCKET_H

#include "../common/address_helper.h"

typedef int sock_type_t;
typedef int sock_fd_t;

result_t create_stream_conn_sock(const char*addr, const char *port, sock_fd_t *conn_sock_fd);
result_t create_datagram_conn_sock(const char*addr, const char *port, sock_fd_t *conn_sock_fd);

#endif //REMOTECONTROLLERAPI_CLIENT_CONN_SOCKET_H
