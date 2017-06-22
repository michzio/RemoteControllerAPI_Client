//
// Created by Michal Ziobro on 19/06/2017.
//

#include <sys/socket.h>
#include <sys/errno.h>
#include <string.h>
#include "authentication.h"

#define MAX_BUF_SIZE 256

result_t authenticate_client_on_server(const client_info_t *client_info, const sock_fd_t sock_fd) {

    char buf[MAX_BUF_SIZE];
    int n_recv; // number of bytes receivedś
    int n_sent; // number of bytes sent

    printf("Client authentication on the server ...\n");

    if( (n_recv = recv(sock_fd, buf, sizeof(buf)-1, 0)) < 0) {
        perror("recv");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_RECV, strerror(errno));
        return FAILURE;
    }
    buf[n_recv] = '\0';

    printf("%s\n", buf);

    if(strcmp(buf, "AUTHENTICATE") != 0) {
        fprintf(stderr, "Authentication protocol error!\n");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_AUTH, "Authentication protocol error!");
        return FAILURE;
    }

    // create client authentication response
    // OS <client_os> ID <client_identity> PASS <security_password>
    const char *client_os = client_info_client_os(client_info);
    if( client_os != NULL ) {
        strcpy(buf, "OS ");
        strcat(buf, client_os);
    } else {
        fprintf(stderr, "Client OS not specified. Could not proceed authentication.");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_AUTH, "Client OS not specified. Could not proceed authentication.");
        return FAILURE;
    }

    const char *client_identity = client_info_client_identity(client_info);
    if( client_identity != NULL ) {
        strcat(buf, " ID ");
        strcat(buf, client_identity);
    } else {
        fprintf(stderr, "Client identity not specified. Could not proceed authentication.\n");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_AUTH, "Client identity not specified. Could not proceed authentication.");
        return FAILURE;
    }

    const char *security_password =  client_info_security_password(client_info);
    if( security_password != NULL ) {
        strcat(buf, " PASS ");
        strcat(buf, security_password);
    }

    if( (n_sent = send(sock_fd, buf, strlen(buf), 0)) < 0) {
        perror("send");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_SEND, strerror(errno));
        return FAILURE;
    }

    // get authentication confirmation from server
    if( (n_recv = recv(sock_fd, buf, sizeof(buf)-1, 0)) < 0) {
        perror("recv");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_RECV, strerror(errno));
        return FAILURE;
    }
    buf[n_recv] = '\0';

    if(strcmp(buf, "AUTHENTICATION SUCCESS") == 0) {
        printf("Client authenticated successfully on the server.\n");
        // publish client authenticated event
        client_info_connection_authenticated_event(client_info);
        return SUCCESS;
    } else if(strcmp(buf, "AUTHENTICATION FAILED") == 0) {
        fprintf(stderr, "Client authentication failed!");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_AUTH, "Client authentication failed!");
        return FAILURE;
    } else {
        fprintf(stderr, "Authentication protocol error!\n");
        // publish connection error event
        client_info_connection_error_event(client_info, CONN_ERROR_AUTH, "Authentication protocol error!");
        return FAILURE;
    }
}