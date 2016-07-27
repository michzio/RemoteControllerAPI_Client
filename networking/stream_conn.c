//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include "stream_conn.h"
#include "connection.h"
#include "../client.h"
#include "service.h"

result_t rpc_stream_conn(void) {

    if(create_stream_conn(SERVER_ADDRESS, RPC_PORT, rpc_service_handler) == FAILURE) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}

result_t event_stream_conn(void) {

    if(create_stream_conn(SERVER_ADDRESS, EVENT_PORT, event_service_handler) == FAILURE) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}

result_t echo_stream_conn(void) {

    if(create_stream_conn(SERVER_ADDRESS, ECHO_PORT, echo_service_handler) == FAILURE) {
        fprintf(stderr, "create_stream_conn: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}
