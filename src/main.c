#include <stdio.h>
#include <strings.h>
#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "mapper.h"
#include "reducer.h"

int main(int argc, char *argv[]){

    for (int i = 1; i < argc; i++){
        if (!strcmp(argv[i], "--mapper")){

            if(mapper()){
                printf("Mapper threw an error\n");
                return 1;
            }
        }
        else if (!strcmp(argv[i], "--reducer")){

            if(reducer()){
                printf("Reducer threw an error\n");
                return 1;
            }
        }
        else{
            printf("Invalid input args\n");
            return 1;
        }

    }
        printf("Program exiting");
        return 0;
}






