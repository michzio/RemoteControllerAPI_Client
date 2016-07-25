/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#ifndef REMOTECONTROLLERAPI_CLIENT_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_CLIENT_H

#include "common/helper.h"

#define PORT "2016" // the port remote controller client will be connecting to
#define ADDRESS "192.168.8.106"

result_t start_client(void);
int handle_communication(int cs_fd);
int end_client(void);
result_t echo(int cs_fd);

#endif /* REMOTECONTROLLERAPI_CLIENT_CLIENT_H */
