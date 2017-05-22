//
// Created by Michal Ziobro on 22/05/2017.
//

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "generic_client.h"
#include "../../networking/helpers/address_helper.h"

struct client_info {
    char *pasv_port;
    char *pasv_ip;
    char *conn_port;
    char *conn_ip;
    sock_fd_t sockfd;
};

// client_info_t operations
void client_info_init(client_info_t **info) {

    *info = malloc(sizeof(client_info_t));
    (*info)->pasv_port = NULL;
    (*info)->pasv_ip = NULL;
    (*info)->conn_port = NULL;
    (*info)->conn_ip = NULL;
    (*info)->sockfd = 0;

}

void client_info_set_pasv_port(client_info_t *info, const char *port) {

    if(info->pasv_port == NULL) {
        info->pasv_port = malloc(sizeof(port));
    } else {
        info->pasv_port = realloc(info->pasv_port, sizeof(port));
    }
    strcpy(info->pasv_port, port);
}

void client_info_set_pasv_ip(client_info_t *info, const char *ip) {

    if(info->pasv_ip == NULL) {
        info->pasv_ip = malloc(sizeof(ip));
    } else {
        info->pasv_ip = realloc(info->pasv_ip, sizeof(ip));
    }
    strcpy(info->pasv_ip, ip);
}

void client_info_set_conn_port(client_info_t *info, const char *port) {

    if(info->conn_port == NULL) {
        info->conn_port = malloc(sizeof(port));
    } else {
        info->conn_port = realloc(info->conn_port, sizeof(port));
    }
    strcpy(info->conn_port, port);
}

void client_info_set_conn_ip(client_info_t *info, const char *ip) {

    if(info->conn_ip == NULL) {
        info->conn_ip = malloc(sizeof(ip));
    } else {
        info->conn_ip = realloc(info->conn_ip, sizeof(ip));
    }
    strcpy(info->conn_ip, ip);
}

void client_info_set_sock(client_info_t *info, const sock_fd_t sockfd) {

    info->sockfd = sockfd;
}

result_t client_info_fill(client_info_t *info, const sock_fd_t sockfd) {

    result_t result = SUCCESS;

    if(client_info_fill_pasv(info, sockfd) == FAILURE) {
        fprintf(stderr, "client_info_fill_pasv: failed!\n");
        result = FAILURE;
    }
    if(client_info_fill_conn(info, sockfd) == FAILURE) {
        fprintf(stderr, "client_info_fill_conn: failed!\n");
        result = FAILURE;
    }

    return result;
}

result_t client_info_fill_pasv(client_info_t *info, const sock_fd_t sockfd) {

    info->sockfd = sockfd;

    char *ip_address;
    int port_number;

    if(get_current_address_and_port(sockfd, &ip_address, &port_number) == FAILURE) {
        fprintf(stderr, "get_current_address_and_port: failed!\n");
        return FAILURE;
    }

    // converting integer port number into string equivalent
    size_t port_len = (size_t) ((ceil(log10(port_number))+1)*sizeof(char));
    char *port = malloc(port_len);
    snprintf(port, port_len, "%d", port_number);

    if(info->pasv_ip) free(info->pasv_ip);
    info->pasv_ip = ip_address;
    if(info->pasv_port) free(info->pasv_port);
    info->pasv_port = port;

    return SUCCESS;
}

result_t client_info_fill_conn(client_info_t *info, const sock_fd_t sockfd) {

    info->sockfd = sockfd;

    char *ip_address;
    int port_number;

    if(get_peer_address_and_port(sockfd, &ip_address, &port_number) == FAILURE) {
        fprintf(stderr, "get_peer_address_and_port: failed!\n");
        return FAILURE;
    }

    // converting integer port number into string equivalent
    size_t port_len = (size_t) ((ceil(log10(port_number))+1)*sizeof(char));
    char *port = malloc(port_len);
    snprintf(port, port_len, "%d", port_number);

    if(info->conn_ip) free(info->conn_ip);
    info->conn_ip = ip_address;
    if(info->conn_port) free(info->conn_port);
    info->conn_port = port;

    return SUCCESS;
}

const char *client_info_pasv_port(const client_info_t *info) {

    return info->pasv_port;
}

const char *client_info_pasv_ip(const client_info_t *info) {

    return info->pasv_ip;
}

const char *client_info_conn_port(const client_info_t *info) {

    return  info->conn_port;
}

const char *client_info_conn_ip(const client_info_t *info) {

    return  info->conn_ip;
}

const sock_fd_t client_info_sock(const client_info_t *info) {

    return info->sockfd;
}

void client_info_free(client_info_t *info) {

    if(info->conn_port) free(info->conn_port);
    if(info->conn_ip) free(info->conn_ip);
    if(info->pasv_port) free(info->pasv_port);
    if(info->pasv_ip) free(info->pasv_ip);
    free(info); info = NULL;
}
