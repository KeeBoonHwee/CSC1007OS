#include <sys/types.h> /* Important header file with some types */
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t justPid, myPid, myParentPid; /* pid_t is defined in types.h */
    int status;
    int test_value = 100;

    printf("Before Forking.\n");   

    /* Fork new process: */
    justPid = fork();       /* New process is created at this moment */

    printf("After Forking.\n");
    
    if ( justPid < 0 )      /* If return from fork() is negative – error */
    {                       /* Error occurred - no child process. */
        fprintf( stderr, "Fork failed." ); /* Error message to stderr */
        return 1;
    }

    if ( justPid == 0 )
    {                       /* Child process */
        myPid = getpid();   /* To get PID of this process */
        myParentPid = getppid(); /* To get the PID of parent process – PPID */
        printf( "[CHILD]: PID = %d, PPID = %d.\n", myPid, myParentPid );

        /* Rest of the code which runs as child process. */
        execlp("/bin/date","date",NULL); 
        return( 0 );
    }
    else
    {                       /* Parent process */
        myPid = getpid();	/* To get PID of this process */
        myParentPid = getppid();    /* To get the PID of parent process – PPID */
        /* Rest of the code which runs as parent process. */
        /* parent will wait for the child to complete */
        wait(&status); 
        printf( "[PARENT]: PID = %d, PPID = %d, Child's PID = %d.\n", myPid, myParentPid, justPid );
        return( 0 );
    }
}

