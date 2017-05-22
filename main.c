#define _REENTRANT
#include <pthread.h>

#include<stdio.h>
#include "client.h"
#include "test/test_client.h"
#include "test/test_transfer.h"
#include "networking/stream_client.h"
#include "networking/datagram_client.h"

#define CLIENT_PORT "0" // the port remote controller client will be bound to if there is explicit binding (0 means any port)
#define SERVER_PORT "55551" // the port remote controller client will be connecting to server
#define SERVER_ADDRESS "192.168.8.101"

#define RPC_PORT "2016" // the port remote controller client will be connecting to for remote procedure calls
#define EVENT_PORT "2017" // the port remote controller client will be connecting to for event handling
#define ECHO_PORT " 3333" // the port remote controller client will be connecting to for echo handling

int main(int argc, char **argv) {

    printf("Remote Controller Client - mobile side, remotely controlling.\n");

    //test_client.run_tests();
    //test_client_transfer.run_tests();

    client_info_t *client_info;
    client_info_init(&client_info);
    client_info_set_pasv_port(client_info, CLIENT_PORT);
    //client_info_set_pasv_ip();
    //client_info_set_pasv_sock();
    client_info_set_conn_port(client_info, SERVER_PORT);
    client_info_set_conn_ip(client_info, SERVER_ADDRESS);
    //client_info_set_conn_sock();
    //client_info_pasv_port();
    //client_info_pasv_ip();
    //client_info_pasv_sock();
    //client_info_conn_port();
    //client_info_conn_ip();
    //client_info_conn_sock();
    //client_info_fill_pasv();
    //client_info_fill_conn();

    start_client(echo_stream_client, client_info);
    //start_client(echo_datagram_client, client_info);

    client_info_free(client_info);

    return SUCCESS;
}