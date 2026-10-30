#ifndef COMMON_H
#define COMMON_H

typedef struct {
    char type; // 'P' = producer, 'C' = consumer
    int product_id;
    int quantity;
} Message;

#endif