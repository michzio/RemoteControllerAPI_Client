//
// Created by Michal Ziobro on 25/07/2016.
//

#include "../common/address_helper.h"

#ifndef REMOTECONTROLLERAPI_CLIENT_STREAM_H
#define REMOTECONTROLLERAPI_CLIENT_STREAM_H

result_t rpc_stream(void);
result_t event_stream(void);
result_t echo_stream(void); // only for testing

#endif //REMOTECONTROLLERAPI_CLIENT_STREAM_H
