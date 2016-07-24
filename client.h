/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#ifndef REMOTECONTROLLERAPI_CLIENT_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_CLIENT_H

#include "helper.h"

#define PORT "2016" // the port remote controller client will be connecting to
#define ADDRESS "localhost"

int start_client(void);
result_t create_connection_socket(int *res_fd);
int handle_communication(int cs_fd);
int end_client(void);

#endif /* REMOTECONTROLLERAPI_CLIENT_CLIENT_H */
