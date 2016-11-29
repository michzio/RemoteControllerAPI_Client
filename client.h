/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#ifndef REMOTECONTROLLERAPI_CLIENT_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_CLIENT_H

#include "../networking/helpers/address_helper.h"

#define PASV_PORT "5555" // the port remote controller client will be bound to if there is explicit binding

#define RPC_PORT "2016" // the port remote controller client will be connecting to for remote procedure calls
#define EVENT_PORT "2017" // the port remote controller client will be connecting to for event handling
#define ECHO_PORT " 3333" // the port remote controller client will be connecting to for echo handling
#define SERVER_ADDRESS "192.168.8.101"

result_t start_client(void);
int end_client(void);

#endif /* REMOTECONTROLLERAPI_CLIENT_CLIENT_H */
