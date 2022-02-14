#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *test(void *arg);

int main(){
    int main_counter = 1;
    
    pthread_t test_thread;
    
    pthread_create(&test_thread, NULL, test, (void*)main_counter);

    while(1)
    {
        printf("main: %d\n", main_counter);
        main_counter++;
        sleep(1);
    }
    
    return 0;
}



void *test(void *arg)
{
    int thread_counter = 1;
    while(1)
    {
        printf("thread: %d\n", thread_counter);
        thread_counter++;
        sleep(1);
    }
}
