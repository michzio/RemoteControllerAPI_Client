/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#ifndef REMOTECONTROLLERAPI_CLIENT_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_CLIENT_H

#include "../../networking/include/helpers/address_helper.h"
#include "networking/generic_client.h"

result_t start_client(client_t client, client_info_t *client_info);
result_t end_client(client_info_t *client_info);

#endif /* REMOTECONTROLLERAPI_CLIENT_CLIENT_H */
