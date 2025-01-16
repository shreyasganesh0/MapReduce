#ifndef REDUCER_H
#define REDUCER_H

typedef struct {
    char userID[5];
    char topic[16];
    char score[5];
} reducer_t;

int reducer();

#endif
