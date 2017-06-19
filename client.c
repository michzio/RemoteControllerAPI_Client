/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "client.h"
#include "../networking/common/network_types.h"

result_t start_client(client_t client, client_info_t *client_info) {

    return client(client_info);
}

result_t end_client(client_info_t *client_info) {

    sock_fd_t cs_fd = client_info_sock(client_info);

    if(close(cs_fd) < 0) {
        fprintf(stderr, "close: %s\n", strerror(errno));
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_CLOSE, strerror(errno));
        return FAILURE;
    }

    // publish connection end event
    client_info_connection_end_event(client_info);

    return SUCCESS;
}