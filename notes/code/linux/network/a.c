#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define CRLF "\r\n"

int main() {
    // Set stdout to non-buffer mode
    setvbuf(stdout, NULL, _IONBF, 0);

    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[4096];
    char* get_request;
    memset(buffer, 0, sizeof(buffer));

    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        fputs("Failed to create a socket.", stderr);
        return EXIT_FAILURE;
    }

    const char* host = "www.bing.com";
    const char* path = "/";
    const int port = 80;

    struct hostent* server;
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Failed to get the host of %s\n", host);
        close(sock);
        return EXIT_FAILURE;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char*)&serv_addr.sin_addr.s_addr,
           (char*)server->h_addr_list[0],
           server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        fputs("Failed to create a connection.", stderr);
        close(sock);
        return EXIT_FAILURE;
    }

    get_request = malloc(strlen("GET ") + strlen(path) + strlen(" HTTP/1.1") +
                         strlen(CRLF "Host: ") + strlen(host) +
                         strlen(CRLF "Connection: close" CRLF CRLF) + 1);

    sprintf(get_request, "GET %s HTTP/1.1" CRLF "Host: %s" CRLF "Connection: close" CRLF CRLF, path, host);

    send(sock, get_request, strlen(get_request), 0);
    printf("HTTP GET request send: \n%s\n", get_request);

    int valread;
    while ((valread = read(sock, buffer, 4096)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, 4096);
    }

    free(get_request);
    close(sock);
    return EXIT_SUCCESS;
}