#ifndef MAPPER_H
#define MAPPER_H

typedef struct {
    char userID[5];
    char action;
    char topic[16];
} mapper_t;

int mapper();

#endif
