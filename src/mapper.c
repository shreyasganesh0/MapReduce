#include <stdio.h>
#include <strings.h>
#include <stdint.h>
#include <stdbool.h>

#include "mapper.h"
int main(int argc, char *argv[]){
    
    while(true){
        
        mapper_t mapper_inp; 

        char buf[25];

        if (fgets(buf, sizeof(buf), stdin) != NULL){
            size_t buf_len = strlen(buf);
            if (buf_len > 0 && buf[buf_len - 1] == '\n'){
                buf[buf_len - 1] = '\0';
            }
            if (strlen(buf) > 4+1+15){
                printf("Input too strong\n");
                continue;
            }

            if(!strcmp(buf, "exit")){
                printf("exit\n");
                return 0;
            }
            if(sscanf(buf, "(%[^,],%[^,],%[^)])", mapper_inp.userID, &mapper_inp.action, mapper_inp.topic) == 0){
                printf("Unable to parse input\n");
                continue;
            }

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
                        printf("Invalid entry to action\n");
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
            return 1;
            break;
        }
    }
    return 0;
}
