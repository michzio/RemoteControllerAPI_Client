//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include "conn_socket.h"
#include "../client.h"

static result_t bind_conn_sock(const sock_fd_t conn_sock_fd, const sock_type_t sock_type, const char *bind_port);

/**
 * Function creates new client socket connected
 * to server (ADDRESS, PORT). Socket can be
 * either TCP or UDP depending on sock_type.
 * If UDP socket is connected, there can be used
 * send(), recv(), read(), write() functions
 * for data transfer besides sendto(), recvfrom().
 */
static result_t create_connection_socket(const char*addr, const char *port, const char *bind_port, sock_type_t sock_type, sock_fd_t *conn_sock_fd) {

    int cs_fd; // connection socket file descriptor
    struct addrinfo addrinfo_hints, *addrinfo_res, *ai_ptr; // address info structures holding server address information
    int gai_res; // getaddrinfo() result value

    // populating address info hints for getaddrinfo()
    memset(&addrinfo_hints, 0, sizeof(addrinfo_hints));
    addrinfo_hints.ai_family = AF_UNSPEC;
    addrinfo_hints.ai_socktype = (int) sock_type;

    // getting result address info structure
    if( (gai_res = getaddrinfo(addr, port, &addrinfo_hints, &addrinfo_res)) != 0 ) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(gai_res));
        return FAILURE;
    }

    // loop through address info results and connect to the first we can
    for(ai_ptr = addrinfo_res; ai_ptr != NULL; ai_ptr = ai_ptr->ai_next) {

        // create new client connection socket
        if( (cs_fd = socket(ai_ptr->ai_family, ai_ptr->ai_socktype, ai_ptr->ai_protocol)) < 0 ) {
            fprintf(stderr, "client connection socket: %s\n", strerror(errno));
            continue;
        }

        // possible explicit bind() for UDP connection socket
        if( (sock_type == SOCK_DGRAM) && bind_conn_sock(cs_fd, sock_type, bind_port)) {
            close(cs_fd);
            fprintf(stderr, "bind_conn_sock: failed!\n");
            continue;
        }

        if( connect(cs_fd, ai_ptr->ai_addr, ai_ptr->ai_addrlen) < 0 ) {
            close(cs_fd);
            fprintf(stderr, "connect: %s\n", strerror(errno));
            continue;
        }

        break;
    }

    if(ai_ptr == NULL) {
        fprintf(stderr, "client connection socket: failed to be created or connected\n");
        return FAILURE;
    }

    freeaddrinfo(addrinfo_res);

    *conn_sock_fd = cs_fd; // return created connection socket file descriptor

    print_socket_address(cs_fd, PASSIVE_SOCKET);
    print_socket_address(cs_fd, CONNECTION_SOCKET);

    return SUCCESS;
}

result_t create_stream_conn_sock(const char*addr, const char *port, const char *bind_port, sock_fd_t *conn_sock_fd) {
    return create_connection_socket(addr, port, bind_port, SOCK_STREAM, conn_sock_fd);
}

result_t create_datagram_conn_sock(const char*addr, const char *port, const char *bind_port, sock_fd_t *conn_sock_fd) {
    return create_connection_socket(addr, port, bind_port, SOCK_DGRAM, conn_sock_fd);
}

static result_t bind_conn_sock(const sock_fd_t conn_sock_fd, const sock_type_t sock_type, const char *bind_port) {

    struct addrinfo addrinfo_hints, *addrinfo_res, *ai_ptr; // address info structures holding host address information
    int gai_res; // getaddrinfo() result value

    // populating address info hints for getaddrinfo()
    memset(&addrinfo_hints, 0, sizeof(addrinfo_hints));
    addrinfo_hints.ai_flags = AI_PASSIVE; // current host IP
    addrinfo_hints.ai_family = AF_UNSPEC; // AF_INET to force IPv4, AF_INET6 to force IPv6
    addrinfo_hints.ai_socktype = (int) sock_type;

    // getting result address info structure
    if( (gai_res = getaddrinfo(NULL, bind_port, &addrinfo_hints, &addrinfo_res)) != 0 ) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(gai_res));
        return FAILURE;
    }

    // loop through address info results and bind to the first we can
    for(ai_ptr = addrinfo_res; ai_ptr != NULL; ai_ptr = ai_ptr->ai_next) {

        // bind connection socket to (address, port) defined in address info structure
        if (bind(conn_sock_fd, ai_ptr->ai_addr, ai_ptr->ai_addrlen) < 0) {
            fprintf(stderr, "bind: %s\n", strerror(errno));
            continue;
        }
        break;
    }

    if(ai_ptr == NULL) {
        fprintf(stderr, "client connection socket: failed to be binded\n");
        return FAILURE;
    }

    freeaddrinfo(addrinfo_res);

    return SUCCESS;
}