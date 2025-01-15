#ifndef MAIN_H
#define MAIN_H

typedef enum __attribute__((packed)) {
    D = -10,
    L = 20,
    C = 30,
    S = 40,
    P = 50,
} action_t;

typedef struct {
    char userID[5];
    char action;
    char topic[16];
} input_t;


#endif
