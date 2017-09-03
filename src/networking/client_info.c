//
// Created by Michal Ziobro on 19/06/2017.
//

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "networking/client_info.h"
#include "helpers/address_helper.h"

struct client_info {

    char *pasv_port;            // port client sock binds
    char *pasv_ip;              // ip address of client host
    char *conn_port;            // port client is connecting to
    char *conn_ip;              // ip address client is connecting to
    sock_fd_t sockfd;           // client socket
    char *security_password;    // password required to authenticate client on the server
    char *client_identity;      // client identity to authenticate client on the server
    char *client_os;            // client operating system to authenticate client on the server

    // client events callbacks
    connection_start_callback_t connection_start_callback;
    connection_authenticated_callback_t connection_authenticated_callback;
    connection_end_callback_t connection_end_callback;
    connection_error_callback_t connection_error_callback;
    datagram_error_callback_t datagram_error_callback;

    // client events callbacks custom arguments
    void *connection_start_callback_arg;
    void *connection_authenticated_callback_arg;
    void *connection_end_callback_arg;
    void *connection_error_callback_arg;
    void *datagram_error_callback_arg;
};

// client_info_t operations
void client_info_init(client_info_t **info) {

    *info = malloc(sizeof(client_info_t));
    (*info)->pasv_port = NULL;
    (*info)->pasv_ip = NULL;
    (*info)->conn_port = NULL;
    (*info)->conn_ip = NULL;
    (*info)->sockfd = 0;
    (*info)->security_password = NULL;
    (*info)->client_identity = NULL;
    (*info)->client_os = NULL;

    (*info)->connection_start_callback = NULL;
    (*info)->connection_authenticated_callback = NULL;
    (*info)->connection_end_callback = NULL;
    (*info)->connection_error_callback = NULL;
    (*info)->datagram_error_callback = NULL;

    (*info)->connection_start_callback_arg = NULL;
    (*info)->connection_authenticated_callback_arg = NULL;
    (*info)->connection_end_callback_arg = NULL;
    (*info)->connection_error_callback_arg = NULL;
    (*info)->datagram_error_callback_arg = NULL;
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

void client_info_set_security_password(client_info_t *info, const char *password) {

    info->security_password = password;
}

void client_info_set_client_identity(client_info_t *info, const char *identity) {

    info->client_identity = identity;
}

void client_info_set_client_os(client_info_t *info, const char *os) {

    info->client_os = os;
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

const char *client_info_security_password(const client_info_t *info) {

    return info->security_password;
}

const char *client_info_client_identity(const client_info_t *info) {

    return info->client_identity;
}

const char *client_info_client_os(const client_info_t *info) {

    return info->client_os;
}

// set event handlers (callbacks)
void client_info_set_connection_start_callback(client_info_t *info, connection_start_callback_t callback) {
    info->connection_start_callback = callback;
}

void client_info_set_connection_authenticated_callback(client_info_t *info, connection_authenticated_callback_t callback) {
    info->connection_authenticated_callback = callback;
}

void client_info_set_connection_end_callback(client_info_t *info, connection_end_callback_t callback) {
    info->connection_end_callback = callback;
}

void client_info_set_connection_error_callback(client_info_t *info, connection_error_callback_t callback) {
    info->connection_error_callback = callback;
}

void client_info_set_datagram_error_callback(client_info_t *info, datagram_error_callback_t callback) {
    info->datagram_error_callback = callback;
}

// set callbacks custom arguments
void client_info_set_connection_start_callback_arg(client_info_t *info, void *callback_arg) {
    info->connection_start_callback_arg = callback_arg;
}

void client_info_set_connection_authenticated_callback_arg(client_info_t *info, void *callback_arg) {
    info->connection_authenticated_callback_arg = callback_arg;
}

void client_info_set_connection_end_callback_arg(client_info_t *info, void *callback_arg) {
    info->connection_end_callback_arg = callback_arg;
}

void client_info_set_connection_error_callback_arg(client_info_t *info, void *callback_arg) {
    info->connection_error_callback_arg = callback_arg;
}

void client_info_set_datagram_error_callback_arg(client_info_t *info, void *callback_arg) {
    info->datagram_error_callback_arg = callback_arg;
}

// get event handlers (callbacks)
connection_start_callback_t client_info_connection_start_callback(client_info_t *info) {
    return info->connection_start_callback;
}

connection_authenticated_callback_t client_info_connection_authenticated_callback(client_info_t *info) {
    return info->connection_authenticated_callback;
}

connection_end_callback_t client_info_connection_end_callback(client_info_t *info) {
    return info->connection_end_callback;
}

connection_error_callback_t client_info_connection_error_callback(client_info_t *info) {
    return info->connection_error_callback;
}

datagram_error_callback_t client_info_datagram_error_callback(client_info_t *info) {
    return info->datagram_error_callback;
}

// get callbacks custom arguments
void *client_info_connection_start_callback_arg(client_info_t *info) {
    return info->connection_start_callback_arg;
}

void *client_info_connection_authenticated_callback_arg(client_info_t *info) {
    return info->connection_authenticated_callback_arg;
}

void *client_info_connection_end_callback_arg(client_info_t *info) {
    return info->connection_end_callback_arg;
}

void *client_info_connection_error_callback_arg(client_info_t *info) {
    return info->connection_error_callback_arg;
}

void *client_info_datagram_error_callback_arg(client_info_t *info) {
    return info->datagram_error_callback_arg;
}

// helper methods that publish client events
void client_info_connection_start_event(client_info_t *info) {

    if(info->connection_start_callback != NULL)
        info->connection_start_callback(info->sockfd, info->connection_start_callback_arg);
}

void client_info_connection_authenticated_event(client_info_t *info) {

    if(info->connection_authenticated_callback != NULL)
        info->connection_authenticated_callback(info->sockfd, info->connection_authenticated_callback_arg);
}

void client_info_connection_end_event(client_info_t *info) {

    connection_end_callback_t callback = info->connection_end_callback;
    void *callback_arg = info->connection_end_callback_arg;
    sock_fd_t sock_fd = info->sockfd;

    client_info_free(info);

    if(callback != NULL)
        callback(sock_fd, callback_arg);
}

void client_info_connection_error_event(client_info_t *info, const int error_code, const char *error_msg) {

    if(info->connection_error_callback != NULL)
        info->connection_error_callback(info->sockfd, error_code, error_msg, info->connection_error_callback_arg);
}

void client_info_datagram_error_event(client_info_t *info, const int error_code, const char *error_msg) {

    if(info->datagram_error_callback != NULL)
        info->datagram_error_callback(info->sockfd, error_code, error_msg, info->datagram_error_callback_arg);
}

void client_info_free(client_info_t *info) {

    if(info->conn_port != NULL) free(info->conn_port);
    if(info->conn_ip != NULL) free(info->conn_ip);
    if(info->pasv_port != NULL) free(info->pasv_port);
    if(info->pasv_ip != NULL) free(info->pasv_ip);

    info->security_password = NULL;
    info->client_identity = NULL;
    info->client_os = NULL;

    // set callbacks to NULL
    info->connection_start_callback = NULL;
    info->connection_authenticated_callback = NULL;
    info->connection_end_callback = NULL;
    info->connection_error_callback = NULL;
    info->datagram_error_callback = NULL;

    // set callbacks arguments to NULL
    info->connection_start_callback_arg = NULL;
    info->connection_authenticated_callback_arg = NULL;
    info->connection_end_callback_arg = NULL;
    info->connection_error_callback_arg = NULL;
    info->datagram_error_callback_arg = NULL;

    free(info); info = NULL;
}
