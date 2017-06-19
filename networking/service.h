//
// Created by Michal Ziobro on 25/07/2016.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_SERVICE_H
#define REMOTECONTROLLERAPI_CLIENT_SERVICE_H

#include "conn_socket.h"
#include "../../common/types.h"
#include "client_info.h"

result_t rpc_service_handler(client_info_t *client_info, sock_fd_t sock_fd);
result_t event_service_handler(client_info_t *client_info, sock_fd_t sock_fd);
result_t echo_service_handler(client_info_t *client_info, sock_fd_t sock_fd); // only for testing

#endif //REMOTECONTROLLERAPI_CLIENT_SERVICE_H
