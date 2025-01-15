#include <stdio.h>
#include <strings.h>
#include <stdint.h>
#include <stdbool.h>

#include "main.h"

int main(int argc, char *argv[]){
    printf("Enter input");

    while(true){
        
        input_t mapper_inp; 

        char buf[25];

        if (fgets(buf, sizeof(buf), stdin) != NULL){
            size_t buf_len = strlen(buf);
            if (buf_len > 0 && buf[buf_len - 1] == '\n'){
                buf[buf_len - 1] = '\0';
            }

            sscanf(buf, "(%4s,%c,%15s)", mapper_inp.userID, &mapper_inp.action, mapper_inp.topic);

            char score[4];
            switch(mapper_inp.action){
                case 'D':
                    {
                        strcpy(score,"-10");
                        break;
                    }
                case 'L':
                    {
                        strcpy(score,"20");
                        break;
                    }
                case 'C':
                    {
                        strcpy(score,"30");
                        break;
                    }
                case 'S':
                    {
                        strcpy(score,"40");
                        break;
                    }
                case 'P':
                    {
                        strcpy(score,"50");
                        break;
                    }
                default:
                    {
                        printf("Invalid action\n");
                        continue;
                    }
            }
            printf("(%s,%s,%s)\n", mapper_inp.userID, mapper_inp.topic, score);
        }
        else{
            if (feof(stdin)) {
                printf("End of file reached.\n");
            } else if (ferror(stdin)) {
                perror("Error reading input");
            } else {
                printf("Unknown error occurred.\n");
            }
            break;
        }
    }
        return 0;
}






