#include <helium/he.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./server/server.h"

void print_usage() {
    fprintf(stdout, "Usage: ./lagnos server|client <port number>\n");
}

int main(int argc, char *argv[]) {
    // check if correct number of arguments
    if (argc != 3) {
        fprintf(stdout, "invalid number of arguments\n");
        print_usage();
        return 1;
    }

    fprintf(stderr, "-- initialising libhelium\n");

    if (he_init() != HE_SUCCESS) {
        fprintf(stdout, "failed to initialize HE\n");
        return 1;
    }

    // setting allocators, can use jemalloc or tcmalloc
    he_set_allocators(malloc, calloc, realloc, free);

    // check if server or client
    if (strcmp(argv[1], "server") == 0) {
        server_init();
    } else if (strcmp(argv[1], "client") == 0) {
        return 1;
    } else {
        fprintf(stderr, "invalid argument: %s\n", argv[1]);
        print_usage();
        return 1;
    }

    return 0;
}