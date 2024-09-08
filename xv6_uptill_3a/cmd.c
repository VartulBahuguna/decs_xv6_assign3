#include "types.h"

#include "stat.h"

#include "user.h"

 

int main(int argc, char *argv[])

{

    if (argc < 2)

    {

        printf(1, "Usage: %s <program> [arguments...]\n", argv[0]);

        exit();

    }

    //  --------------------------- Write your code here ---------------------------


    int size = strlen(argv[1]) + 1;
    char command[size];
    strcpy(command,argv[1]);
    char* param[argc];
    for(int i = 0; i<argc-1; ++i){
        param[i] = argv[i+1];
    }
    param[argc-1] = 0;
    
    int pid = fork();
    if(pid == 0){
        exec(command, param);
    }else{
        wait();
    }
    // if(pid == 0){
    //     exec(argv[1], argv + 1);
    // }else{
    //     wait();
    // }

    exit();

}