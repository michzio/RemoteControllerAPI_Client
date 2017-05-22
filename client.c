/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include "client.h"
#include "networking/stream_client.h"
#include "networking/datagram_client.h"

result_t start_client(client_t client, client_info_t *client_info) {

    client(client_info);

    return SUCCESS;

}

result_t end_client(client_info_t *client_info) {

    return SUCCESS;
}