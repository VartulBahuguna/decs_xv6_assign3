#include "types.h"
#include "user.h"

int main(){
    int pid = fork();
    if(pid == 0){
        while(1){
            char buff[1000];
            
            write(1, ">>> ", 4);
            int r = read(0, buff, sizeof(buff));
            
            write(1, buff, sizeof(buff));
            if(r == 0) break;
        }
    }else{
        wait();
    }
    
    exit();
}