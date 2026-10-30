#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include "common.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s PORT\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]); // μετατρέπει την είσοδο σε ακέραιο (πόρτα)
    int sock = socket(AF_INET, SOCK_STREAM, 0); // δημιουργεί TCP socket
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET; // ipv4
    server_addr.sin_port = htons(port); // ορίζει την πόρτα
    server_addr.sin_addr.s_addr = INADDR_ANY; // ο server είναι στην ίδια μηχανή (localhost)

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)); // συνδέεται στον server

    Message msg = { 'C', rand() % 11, (rand() % 5) + 1 }; // δημιουργεί τυχαίο αίτημα κατανάλωσης
    send(sock, &msg, sizeof(msg), 0); // στέλνει μήνυμα στον server
    printf("Consumer with pid %d requested %d of product %d\n",
           getpid(), msg.quantity, msg.product_id); // εκτύπωση για ενημέρωση

    close(sock); // κλείνει τη σύνδεση
    return 0;
}