/**
 * pthread_one.c
 */
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr; /* set of thread attributes */
    int  msg1;

    /* set the default attributes of the thread */
    pthread_attr_init(&attr);

    /* create the thread */
    msg1 = pthread_create(&tid, &attr, runner, argv[1]);
    if(msg1)
    {   // if error
        fprintf(stderr,"Error - the pthread_create() return code: %d \n", msg1);
        exit(EXIT_FAILURE);
    }    

    printf("pthread_create() for the thread returns: %d \n", msg1);

    /* wait for the thread to exit */
    pthread_join(tid,NULL);
    
    printf("sum = %d \n",sum);   // print out the sum result
}

/* The thread will execute in this function */
void *runner(void *param)
{
    int i, upper = atoi(param);
    sum = 0;
    for (i = 1; i <= upper; i++){
        sum += i;   // accumulate the result 1 + 2 + 3 + ... 
    }
    pthread_exit(0);
}