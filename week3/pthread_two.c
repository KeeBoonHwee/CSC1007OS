/**
 * pthread_one.c
 */
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int sum1,sum2; /* this data is shared by the thread(s) */
void *runner1(void *param); /* threads call this function */
void *runner2(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
    pthread_t tid1,tid2; /* the thread identifier */
    pthread_attr_t attr1,attr2; /* set of thread attributes */
    int  msg1,msg2;

    /* set the default attributes of the thread */
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);

    /* create the thread */
    msg1 = pthread_create(&tid1, &attr1, runner1, argv[1]);
    msg1 = pthread_create(&tid2, &attr2, runner2, argv[1]);

    if(msg1 || msg2)
    {   // if error
        fprintf(stderr,"Error - the pthread_create() return codes: %d %d\n", msg1, msg2);
        exit(EXIT_FAILURE);
    }    

    printf("pthread_create() for the thread returns: %d %d\n", msg1, msg2);

    /* wait for the thread to exit */
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    
    printf("sum1 = %d \n",sum1);   // print out the sum result
    printf("sum2 = %d \n",sum2);   // print out the sum result
}

/* The thread will execute in this function */
void *runner1(void *param)
{
    int i, upper = atoi(param);
    sum1 = 0;
    for (i = 1; i <= upper; i++){
        sum1 += i;   // accumulate the result 1 + 2 + 3 + ... 
    }
    pthread_exit(0);
}

void *runner2(void *param)
{
    int i, upper = atoi(param);
    sum2 = 0;
    for (i = 1; i <= upper; i++){
        sum2 += i*i;   // accumulate the result 1 + 2 + 3 + ... 
    }
    pthread_exit(0);
}

// gcc -o pthread_two pthread_two.c -lpthread
// ./pthread_two 5