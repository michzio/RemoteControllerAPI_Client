//
// Created by Michal Ziobro on 22/05/2017.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_CONFIG_H
#define REMOTECONTROLLERAPI_CLIENT_CONFIG_H

#define CLIENT_PORT "0" // the port remote controller client will be bound to if there is explicit binding (0 means any port)
#define SERVER_PORT "52478" // the port remote controller client will be connecting to server
#define SERVER_ADDRESS "192.168.8.101"

#define TEST_SERVER_ADDRESS "0.0.0.0"
#define TEST_SERVER_PORT "62651"

#define RPC_PORT "2016" // the port remote controller client will be connecting to for remote procedure calls
#define EVENT_PORT "2017" // the port remote controller client will be connecting to for event handling
#define ECHO_PORT " 3333" // the port remote controller client will be connecting to for echo handling

#endif //REMOTECONTROLLERAPI_CLIENT_CONFIG_H
