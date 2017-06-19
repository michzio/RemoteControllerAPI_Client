#define _REENTRANT
#include <pthread.h>

#include<stdio.h>
#include <unistd.h>
#include "client.h"
#include "test/test_client.h"
#include "test/test_transfer.h"
#include "networking/stream_client.h"
#include "networking/datagram_client.h"
#include "config.h"

void on_connection_start(const sock_fd_t sock_fd, void *callback_arg) {

    printf("Client connection on socket: %d started.\n", sock_fd);
}

void on_connection_authenticated(const sock_fd_t sock_fd, void *callback_arg) {

    printf("Client connection on socket: %d authenticated.\n", sock_fd);
}

void on_connection_end(const sock_fd_t sock_fd, void *callback_arg) {

    printf("Client connection on socket: %d ended.\n", sock_fd);
}

void on_connection_error(const sock_fd_t sock_fd, const int error_code, const char *error_msg, void *callback_arg) {

    printf("Client connection on socket: %d failed with error: %d, %s.\n", sock_fd, error_code, error_msg);
}

int main(int argc, char **argv) {

    printf("Remote Controller Client - mobile side, remotely controlling.\n");

    //test_client.run_tests();
    //test_client_transfer.run_tests();

    client_info_t *client_info;
    client_info_init(&client_info);
    client_info_set_pasv_port(client_info, CLIENT_PORT);
    //client_info_set_pasv_ip();
    client_info_set_conn_port(client_info, SERVER_PORT);
    client_info_set_conn_ip(client_info, SERVER_ADDRESS);
    client_info_set_client_identity(client_info, "TO JA");
    client_info_set_security_password(client_info, "PaSSword12!");
    //client_info_set_sock();
    //client_info_pasv_port();
    //client_info_pasv_ip();
    //client_info_conn_port();
    //client_info_conn_ip();
    //client_info_sock();
    //client_info_fill();
    //client_info_fill_pasv();
    //client_info_fill_conn();
    client_info_set_connection_start_callback(client_info, on_connection_start);
    client_info_set_connection_authenticated_callback(client_info, on_connection_authenticated);
    client_info_set_connection_end_callback(client_info, on_connection_end);
    client_info_set_connection_error_callback(client_info, on_connection_error);

    start_client(echo_stream_client, client_info);
    //start_client(echo_datagram_client, client_info);

    //end_client(client_info);

    return SUCCESS;
}