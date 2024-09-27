/*######################################
# University of Information Technology
31
# IT007 Operating System 
#
# <Your name>, <your Student ID>
# File: test_fork_wait.c 
######################################*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
        printf("Child process, pid=%d\n",pid);
    else
    {
        wait(NULL);
        printf("Parent Proces, pid=%d\n",pid);
    }

    exit(0);
}