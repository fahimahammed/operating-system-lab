#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>

using namespace std;

int main()
{

    int fd[2],n;
    char bf[100];
    // string bf;
    pid_t pid;
    pipe(fd);
    pid = fork();

    time_t giveMeTime = time(NULL);
    if(pid>0) // parent process
    {
        printf("Parent pid is %d\n",getpid());
        printf("This is parent process and asking to child for current time.\n");
        write(fd[1],"Current time?",13);
    }else{
        printf("child pid is %d\n",getpid());
        printf("Child process is showing the current time: \n");
        read(fd[0],bf,100);
        printf("%s",ctime(&giveMeTime));
    }
}