/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include "client.h"
#include "networking/stream_client.h"
#include "networking/datagram_client.h"

result_t start_client(client_t client, client_info_t *client_info) {

    client(client_info);

    return SUCCESS;

}

result_t end_client(client_info_t *client_info) {

    sock_fd_t cs_fd = client_info_sock(client_info);

    if(close(cs_fd) < 0) {
        fprintf(stderr, "close: %s\n", strerror(errno));
        return FAILURE;
    }

    return SUCCESS;
}