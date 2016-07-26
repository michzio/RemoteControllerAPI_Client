/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#ifndef REMOTECONTROLLERAPI_CLIENT_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_CLIENT_H

#include "common/address_helper.h"

#define RPC_PORT "2016" // the port remote controller client will be connecting to for remote procedure calls
#define EVENT_PORT "2017" // the port remote controller client will be connecting to for event handling
#define SERVER_ADDRESS "192.168.8.106"

result_t start_client(void);
int end_client(void);

#endif /* REMOTECONTROLLERAPI_CLIENT_CLIENT_H */
