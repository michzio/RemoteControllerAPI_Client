//
// Created by Michal Ziobro on 22/05/2017.
//

#ifndef REMOTECONTROLLERAPI_CLIENT_GENERIC_CLIENT_H
#define REMOTECONTROLLERAPI_CLIENT_GENERIC_CLIENT_H

// client_info_t contains information about created client
struct client_info;
typedef struct client_info client_info_t;

// client_info_t operations
void client_info_init(client_info_t **info);

void client_info_set_pasv_port(client_info_t *info, const char *port);
void client_info_set_pasv_ip(client_info_t *info, const char *ip);
void client_info_set_conn_port(client_info_t *info, const char *port);
void client_info_set_conn_ip(client_info_t *info, const char *ip);
void client_info_set_sock(client_info_t *info, const sock_fd_t sockfd);
result_t client_info_fill(client_info_t *info, const sock_fd_t sockfd);
result_t client_info_fill_pasv(client_info_t *info, const sock_fd_t sockfd);
result_t client_info_fill_conn(client_info_t *info, const sock_fd_t sockfd);

const char *client_info_pasv_port(const client_info_t *info);
const char *client_info_pasv_ip(const client_info_t *info);
const char *client_info_conn_port(const client_info_t *info);
const char *client_info_conn_ip(const client_info_t *info);
const sock_fd_t client_info_sock(const client_info_t *info);

void client_info_free(client_info_t *info);

// client_t function implementing logic of specific client
typedef result_t (*client_t)(client_info_t *info);

#endif //REMOTECONTROLLERAPI_CLIENT_GENERIC_CLIENT_H
