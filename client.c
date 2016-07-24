/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include "client.h"
#include "helper.h"

int start_client(void) {

    int cs_fd; // connection socket file descriptor

    printf("Starting new client...\n");

    if(create_connection_socket(&cs_fd) == FAILURE) {
        fprintf(stderr, "create_connection_socket: failed!\n");
        return FAILURE;
    }

    handle_communication(cs_fd);

    close(cs_fd);

    return SUCCESS;
}

result_t create_connection_socket(int *res_fd) {

    int cs_fd; // connection socket file descriptor
    struct addrinfo addrinfo_hints, *addrinfo_res, *ai_ptr; // address info structures holding server address information
    int gai_res; // getaddrinfo() result value

    // populating address info hints for getaddrinfo()
    memset(&addrinfo_hints, 0, sizeof(addrinfo_hints));
    addrinfo_hints.ai_family = AF_UNSPEC;
    addrinfo_hints.ai_socktype = SOCK_STREAM;

    // getting result address info structure
    if( (gai_res = getaddrinfo(ADDRESS, PORT, &addrinfo_hints, &addrinfo_res)) != 0 ) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(gai_res));
        return FAILURE;
    }

    // loop through address info results and connect to the first we can


    return SUCCESS;
}
int handle_communication(int cs_fd) {

    return SUCCESS;
}

int end_client(void) {

    return SUCCESS;
}