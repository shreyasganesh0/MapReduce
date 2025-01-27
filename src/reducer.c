#include <stdio.h>
#include <strings.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "reducer.h"
#include "hashmap.c"

int main(int argc, char *argv[]){

    hash_map_t *topic_score_map = create_hashmap(INITIAL_CAPACITY);        
    bool flag = true;
    do{
        
        int8_t *score = malloc(sizeof(int8_t)); 
        reducer_t *reducer_inp = malloc(sizeof(reducer_t));
        static char *curr_userID; // doesnt change with each iteration
        if(reducer_inp == NULL){
            printf("Malloc error\n");
            return 0;
        }

        char buf[25];

        if (fgets(buf, sizeof(buf), stdin) != NULL){
            size_t buf_len = strlen(buf);
            if (buf_len > 0 && buf[buf_len - 1] == '\n'){
                buf[buf_len - 1] = '\0';
            }
            if(!strcmp(buf, "exit")){
                hashmap_iterate(topic_score_map, curr_userID);
                break;
            }

            if (sscanf(buf, "(%4[^,],%[^,],%[^)])", reducer_inp->userID, reducer_inp->topic, reducer_inp->score) == 0){
                printf("Input Invalid\n");
                continue;
            }
            *score = (int8_t)atoi(reducer_inp->score); 


            if (curr_userID == NULL){
                curr_userID = reducer_inp->userID;
            }

            if (strcmp(curr_userID, reducer_inp->userID)){

                hashmap_iterate(topic_score_map, curr_userID);
                strcpy(curr_userID, reducer_inp->userID);
            }
            hashmap_insert(topic_score_map, reducer_inp->topic, score);

        }
        else{
            if (feof(stdin)) {
                hashmap_iterate(topic_score_map, curr_userID);
            } else if (ferror(stdin)) {
                perror("Error reading input");
            } else {
                printf("Unknown error occurred.\n");
            }
            return 1;
        }
    } while(flag);
        return 0;
}
