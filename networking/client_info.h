//
// Created by Michal Ziobro on 19/06/2017.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_CLIENT_INFO_H
#define REMOTECONTROLLERAPI_CLIENT_CLIENT_INFO_H

#include "../../networking/common/network_types.h"
#include "../../common/types.h"

// client_info_t contains information about created client
struct client_info;
typedef struct client_info client_info_t;

// client events callbacks
typedef void (*connection_start_callback_t)(const sock_fd_t sock_fd, void *callback_arg);
typedef void (*connection_authenticated_callback_t)(const sock_fd_t sock_fd, void *callback_arg);
typedef void (*connection_end_callback_t)(const sock_fd_t sock_fd, void *callback_arg);
typedef void (*connection_error_callback_t)(const sock_fd_t sock_fd, const int error_code, const char *error_msg, void *callback_arg);
typedef void (*datagram_error_callback_t)(const sock_fd_t sock_fd, const int error_code, const char *error_msg, void *callback_arg);

// client_info_t operations
void client_info_init(client_info_t **info);

void client_info_set_pasv_port(client_info_t *info, const char *port);
void client_info_set_pasv_ip(client_info_t *info, const char *ip);
void client_info_set_conn_port(client_info_t *info, const char *port);
void client_info_set_conn_ip(client_info_t *info, const char *ip);
void client_info_set_sock(client_info_t *info, const sock_fd_t sockfd);
void client_info_set_security_password(client_info_t *info, const char *password);
void client_info_set_client_identity(client_info_t *info, const char *identity);
void client_info_set_client_os(client_info_t *info, const char *os);
result_t client_info_fill(client_info_t *info, const sock_fd_t sockfd);
result_t client_info_fill_pasv(client_info_t *info, const sock_fd_t sockfd);
result_t client_info_fill_conn(client_info_t *info, const sock_fd_t sockfd);

const char *client_info_pasv_port(const client_info_t *info);
const char *client_info_pasv_ip(const client_info_t *info);
const char *client_info_conn_port(const client_info_t *info);
const char *client_info_conn_ip(const client_info_t *info);
const sock_fd_t client_info_sock(const client_info_t *info);
const char *client_info_security_password(const client_info_t *info);
const char *client_info_client_identity(const client_info_t *info);
const char *client_info_client_os(const client_info_t *info);

// set event handlers (callbacks)
void client_info_set_connection_start_callback(client_info_t *info, connection_start_callback_t callback);
void client_info_set_connection_authenticated_callback(client_info_t *info, connection_authenticated_callback_t callback);
void client_info_set_connection_end_callback(client_info_t *info, connection_end_callback_t callback);
void client_info_set_connection_error_callback(client_info_t *info, connection_error_callback_t callback);
void client_info_set_datagram_error_callback(client_info_t *info, datagram_error_callback_t callback);

// set callbacks custom arguments
void client_info_set_connection_start_callback_arg(client_info_t *info, void *callback_arg);
void client_info_set_connection_authenticated_callback_arg(client_info_t *info, void *callback_arg);
void client_info_set_connection_end_callback_arg(client_info_t *info, void *callback_arg);
void client_info_set_connection_error_callback_arg(client_info_t *info, void *callback_arg);
void client_info_set_datagram_error_callback_arg(client_info_t *info, void *callback_arg);

// get event handlers (callbacks)
connection_start_callback_t client_info_connection_start_callback(client_info_t *info);
connection_authenticated_callback_t client_info_connection_authenticated_callback(client_info_t *info);
connection_end_callback_t client_info_connection_end_callback(client_info_t *info);
connection_error_callback_t client_info_connection_error_callback(client_info_t *info);
datagram_error_callback_t client_info_datagram_error_callback(client_info_t *info);

// get callbacks custom arguments
void *client_info_connection_start_callback_arg(client_info_t *info);
void *client_info_connection_authenticated_callback_arg(client_info_t *info);
void *client_info_connection_end_callback_arg(client_info_t *info);
void *client_info_connection_error_callback_arg(client_info_t *info);
void *client_info_datagram_error_callback_arg(client_info_t *info);

// helper methods that publish client events
void client_info_connection_start_event(client_info_t *info);
void client_info_connection_authenticated_event(client_info_t *info);
void client_info_connection_end_event(client_info_t *info);
void client_info_connection_error_event(client_info_t *info, const int error_code, const char *error_msg);
void client_info_datagram_error_event(client_info_t *info, const int error_code, const char *error_msg);

void client_info_free(client_info_t *info);

// CONNECTION ERROR CONSTANTS
#define CONN_ERROR_BASE 2000
#define CONN_ERROR_CREATE_SOCK (CONN_ERROR_BASE+1)
#define CONN_ERROR_HANDLER (CONN_ERROR_BASE+2)
#define CONN_ERROR_CLOSE (CONN_ERROR_BASE+3)
#define CONN_ERROR_RECV (CONN_ERROR_BASE+5)
#define CONN_ERROR_SEND (CONN_ERROR_BASE+6)
#define CONN_ERROR_AUTH (CONN_ERROR_BASE+7)

#endif //REMOTECONTROLLERAPI_CLIENT_CLIENT_INFO_H
