#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "common.h"

#define MAX_ID 10
int quantities[MAX_ID + 1] = {0}; // πίνακας που κρατάει την ποσότητα για κάθε προϊόν

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s PORT\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]); // μετατρέπει την είσοδο σε ακέραιο (πόρτα)
    int server_sock, client_sock;
    struct sockaddr_in server_addr;

    server_sock = socket(AF_INET, SOCK_STREAM, 0); // δημιουργεί TCP socket
    server_addr.sin_family = AF_INET;              // ipv4
    server_addr.sin_port = htons(port);            // ορίζει την πόρτα
    server_addr.sin_addr.s_addr = INADDR_ANY;      // δέχεται συνδέσεις από οποιαδήποτε IP

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)); // "δένει" το socket στην πόρτα
    listen(server_sock, 1); // ορίζει το socket να ακούει για συνδέσεις (μέγιστο 1 ταυτόχρονα)
    printf("Server listening on port %d...\n", port);

    while (1) {
        client_sock = accept(server_sock, NULL, NULL); // περιμένει και αποδέχεται σύνδεση από client
        Message msg;
        recv(client_sock, &msg, sizeof(msg), 0); // λαμβάνει δομή message από client

        if (msg.type == 'P') { // αν είναι παραγωγός
            quantities[msg.product_id] += msg.quantity; // προσθέτει προϊόντα στην αποθήκη
            printf("Producer produced %d of product %d\n", msg.quantity, msg.product_id);
        } else if (msg.type == 'C') { // αν είναι καταναλωτής
            if (quantities[msg.product_id] >= msg.quantity) {
                quantities[msg.product_id] -= msg.quantity; // αφαιρεί ποσότητα από την αποθήκη
                printf("Consumer consumed %d of product %d\n", msg.quantity, msg.product_id);
            } else {
                printf("Not enough quantity for product %d (requested: %d, available: %d)\n",
                       msg.product_id, msg.quantity, quantities[msg.product_id]);
            }
        }

        close(client_sock); // κλείνει σύνδεση με client
    }

    return 0;
}