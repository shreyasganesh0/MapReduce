#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    char *mapper_path = "./bin/mapper";
    char *reducer_path = "./bin/reducer";

    int filedes[2];
    int pipe_err = pipe(filedes);
    if (pipe_err == -1) {
        int errsv = errno;
        printf("Pipe error: %d\n", errsv);
        return 1;
    }


    pid_t pid_map  = fork();

    if (pid_map < 0) {

        printf("Failed forking mapper\n");

    } else if (pid_map == 0) {

        close(filedes[0]); // close read end of the pipe
        if (dup2(filedes[1], 1) == -1) { // make stdout the writeend of the pipe

            printf("dup failed \n");
            return -1;

        }

        execv(mapper_path, NULL); 

    } 

    pid_t pid_red = fork();

    if (pid_red < 0) {

        printf("Failed forking mapper\n");

    } else if (pid_red == 0) { 

        close(filedes[1]); // close write end of the pipe
        if (dup2(filedes[0], 0) == -1) { //make stdin the read end of the pipe

            printf("dup failed \n");
            return -1;

        }

        execv(reducer_path, NULL); 

    } 
    close(filedes[0]);
    close(filedes[1]);
    wait(NULL);//wait on one child to terminate
    wait(NULL);//wait on the other child to terminate
}
        
