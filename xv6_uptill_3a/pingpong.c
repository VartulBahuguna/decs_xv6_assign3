#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define BUFSIZE 512

void ping_pong(int fd) 
{
   // ------------------------- Write your code here -------------------------
    char ch[1];
    // read(fd, ch, sizeof(ch));
    char word[100];
    int i = 0;
    int cnt = 0;
    while(read(fd, ch, sizeof(ch)) > 0){
        if((ch[0] >= 'a' && ch[0] <='z') || (ch[0] >= 'A' && ch[0] <='Z') || (ch[0] >= '0' && ch[0] <='9')){
            word[i++] = ch[0];
        }else{
            word[i++] = '\0';
            if(strcmp(word, "ping") == 0){
                cnt++;
                printf(1, "%s\n", "pong");
            }
            i=0;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf(1, "Usage: %s <input_file>\n", argv[0]);
        exit();
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf(1, "Error opening file %s\n", argv[1]);
        exit();
    }

    ping_pong(fd);
    close(fd);

    exit();

    // int fd = open(argv[1], O_RDONLY);
    // char ch[1];
    
    // char word[100];
    // int i = 0;
    // int cnt = 0;
    // while(read(fd, ch, sizeof(ch)) > 0){
    //     if((ch[0] >= 'a' && ch[0] <='z') || (ch[0] >= 'A' && ch[0] <='Z') || (ch[0] >= '0' && ch[0] <='9')){
    //         word[i++] = ch[0];
    //     }else{
    //         word[i++] = '\0';
    //         if(strcmp(word, "ping") == 0){
    //             cnt++;
    //             printf(1, "%s\n", "pong");
    //         }
    //         i=0;
    //     }
    // }

    // close(fd);
    // exit();
}

