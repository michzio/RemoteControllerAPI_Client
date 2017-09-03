//
// Created by Michal Ziobro on 26/07/2016.
//

#include <stdio.h>
#include "../../include/networking/datagram_client.h"
#include "../../include/networking/connection.h"
#include "../../include/client.h"
#include "../../include/networking/service.h"

result_t echo_datagram_client(client_info_t *info) {

    if(create_datagram_conn(info, echo_service_handler) == FAILURE) {
        fprintf(stderr, "create_datagram_conn: failed!\n");
        return FAILURE;
    }

    return SUCCESS;
}