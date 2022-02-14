#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main(){
    int i;
    char id[20];
    pid_t pid;
    char user_id = "user1";
    pid = fork();

    /*child process*/
    if(pid == 0){
        for(i = 0;i<10 ;i++){
            printf("child %d \n",i);
            while(1){
                scanf("%s",id);
                if(strcmp(id,user_id) == 0)
                    break;
            }
        }
        exit(0);
    }

    /*parent process*/
    else if(pid>0){
        for(i=0;i<10;i++){
            printf("parent %d\n",i);
            while(1){
                scanf("%s",id);
                if(strcmp(id,user_id) == 0)
                    break;
            }
        }
        exit(0);
    }
    else{
        fprintf(stderr,"cant't fork, errror %d\n",errno);
        exit(1);
    }
    return 0;
}
