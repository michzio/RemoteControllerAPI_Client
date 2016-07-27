//
// Created by Michal Ziobro on 26/07/2016.
//

#include <stdio.h>
#include "datagram_conn.h"
#include "connection.h"
#include "../client.h"
#include "service.h"

result_t echo_datagram_conn(void) {

    if(create_datagram_conn(SERVER_ADDRESS, RPC_PORT, echo_service_handler) == FAILURE) {
        fprintf(stderr, "create_datagram_conn: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}