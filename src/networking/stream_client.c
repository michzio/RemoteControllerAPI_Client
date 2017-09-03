//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include "../../include/networking/stream_client.h"
#include "../../include/networking/connection.h"
#include "../../include/client.h"
#include "../../include/networking/service.h"

result_t rpc_stream_client(client_info_t *info) {

    if(create_stream_conn(info, rpc_service_handler) == FAILURE) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}

result_t event_stream_client(client_info_t *info) {

    if(create_stream_conn(info, event_service_handler) == FAILURE) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}

result_t echo_stream_client(client_info_t *info) {

    if(create_stream_conn(info, echo_service_handler) == FAILURE) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}
