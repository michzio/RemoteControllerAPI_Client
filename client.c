/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include "client.h"
#include "networking/stream_conn.h"
#include "networking/datagram_conn.h"

result_t start_client(void) {

    echo_stream_conn();
    //echo_datagram_conn();

    return SUCCESS;

}

int end_client(void) {

    return SUCCESS;
}