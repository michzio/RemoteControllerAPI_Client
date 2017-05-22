//
// Created by Michal Ziobro on 25/07/2016.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_STREAM_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_STREAM_CLIENT_H

#include "../../networking/helpers/address_helper.h"
#include "generic_client.h"

result_t rpc_stream_client(client_info_t *info);
result_t event_stream_client(client_info_t *info);
result_t echo_stream_client(client_info_t *info); // only for testing

#endif //REMOTECONTROLLERAPI_CLIENT_STREAM_CLIENT_H
