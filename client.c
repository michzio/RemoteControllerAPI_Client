/*
 * Created by Michal Ziobro on 21/07/2016.
 */

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include "client.h"
#include "networking/conn_socket.h"

result_t start_client(void) {

    return SUCCESS;

}


int handle_communication(int cs_fd) {

    return echo(cs_fd);
}

int end_client(void) {

    return SUCCESS;
}

result_t echo(int cs_fd) {

    char sbuf[] = "Hello, world!";
    char rbuf[100];
    int n_sent; // number of bytes sent
    int n_recv; // number of bytes received

    if( (n_sent = send(cs_fd, sbuf, sizeof(sbuf), 0)) < 0) {
        perror("send");
        return FAILURE;
    }

    if( (n_recv = recv(cs_fd, rbuf, sizeof(rbuf) -1, 0)) < 0) {
        perror("recv");
        return FAILURE;
    }

    rbuf[n_recv] = '\0';

    printf("client: received '%s'\n", rbuf);

    return SUCCESS;
}