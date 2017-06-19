//
// Created by Michal Ziobro on 19/06/2017.
//

#include "generic_client.h"

#ifndef REMOTECONTROLLERAPI_CLIENT_AUTHENTICATION_H
#define REMOTECONTROLLERAPI_CLIENT_AUTHENTICATION_H

result_t authenticate_client_on_server(const client_info_t *client_info, const sock_fd_t sock_fd);

#endif //REMOTECONTROLLERAPI_CLIENT_AUTHENTICATION_H
