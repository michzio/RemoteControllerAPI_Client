//
// Created by Michal Ziobro on 25/07/2016.
//

#include "../../networking/helpers/address_helper.h"

#ifndef REMOTECONTROLLERAPI_CLIENT_STREAM_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_STREAM_CLIENT_H

result_t rpc_stream_client(client_info_t *info);
result_t event_stream_client(client_info_t *info);
result_t echo_stream_client(client_info_t *info); // only for testing

#endif //REMOTECONTROLLERAPI_CLIENT_STREAM_CLIENT_H
