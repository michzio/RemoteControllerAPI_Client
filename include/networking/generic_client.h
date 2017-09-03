//
// Created by Michal Ziobro on 22/05/2017.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_GENERIC_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_GENERIC_CLIENT_H

#include "types.h"
#include "client_info.h"

// client_t function implementing logic of specific client
typedef result_t (*client_t)(client_info_t *info);

#endif //REMOTECONTROLLERAPI_CLIENT_GENERIC_CLIENT_H
