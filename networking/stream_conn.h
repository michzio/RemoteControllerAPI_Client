//
// Created by Michal Ziobro on 25/07/2016.
//

#include "../../networking/helpers/address_helper.h"

#ifndef REMOTECONTROLLERAPI_CLIENT_STREAM_CONN_H
#define REMOTECONTROLLERAPI_CLIENT_STREAM_CONN_H

result_t rpc_stream_conn(void);
result_t event_stream_conn(void);
result_t echo_stream_conn(void); // only for testing

#endif //REMOTECONTROLLERAPI_CLIENT_STREAM_CONN_H
