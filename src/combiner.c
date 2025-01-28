#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    char *mapper_path = "./bin/mapper";
    char *reducer_path = "./bin/reducer";

    int filedes[2];
    int pipe_err = pipe(filedes);
    if (pipe_err == -1){
        int errsv = errno;
        printf("Pipe error: %d\n", errsv);
        return 1;
    }


    pid_t pid_map = fork();

    switch(pid_map){
        case -1:
            { // fork failed
                int errsv = errno;
                printf("Fork failed: %d", errsv);
                return 1;
            }
        case 0:
            { // this is the child
                pid_t pid_red = fork();

                switch (pid_red){
                    case -1:
                    { // fork failed
                        int errsv = errno;
                        printf("Fork failed: %d", errsv);
                        return 1;
                    }
                    
                    case 0:
                    {
                        // create reducer path
                        close(filedes[1]);
                        int dup_err = dup2(filedes[0], 0);
                        if (dup_err == -1){
                            int errsv = errno;
                            printf("dup failed: %d\n", errsv);
                            return 1;
                        }
                        
                        int err = execv(reducer_path, argv);
                        if (err){
                            int errsv = errno;
                            printf("Exec failed Mapper Child.: %d", errsv);
                            return 1;
                        }
			break;
                    }
                    
                    default:
                    {
                         // mapper execution part
                        close(filedes[0]);
                        int dup_err = dup2(filedes[1], 1);
                        if (dup_err == -1){
                            int errsv = errno;
                            printf("dup failed: %d\n", errsv);
                            return 1;
                        }

                        int err = execv(mapper_path, argv);
                        if (err){
                            int errsv = errno;
                            printf("Exec failed Mapper Child.: %d", errsv);
                            return 1;
                        }
                    }
                }
		break;

            }
        default:
            {
                // main
                close(filedes[0]);
                close(filedes[1]);
                int *stat_loc;
                waitpid(pid_map, stat_loc, WUNTRACED);
                printf("Program exited\n");

            }
    }
    return 0;
}




