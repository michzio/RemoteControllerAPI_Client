/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include "client.h"
#include "networking/stream.h"

result_t start_client(void) {

    echo_stream();

    return SUCCESS;

}

int end_client(void) {

    return SUCCESS;
}