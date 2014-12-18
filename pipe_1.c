#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DELAY_TIME 1
#define MAX 256
int main()
{
	pid_t pid;
	int pipe_fd[2];
        char buf[MAX];
	const char data[]="Hello,world!";

	memset((void*)buf,0,sizeof(buf));
        if(pipe(pipe_fd)<0)/*创建管道*/
	{
		printf("Can't creat pipe!\n");
		exit(1);
	}
	if((pid=fork())==0)  /*创建一个子进程*/
	{
		/*子进程关闭写描述符，并通过使子进程暂停3s等待父进程已关闭相应的读描述符*/	
		close(pipe_fd[1]);
		sleep(DELAY_TIME*3);
		/*子进程读取管道内容*/
		if(read(pipe_fd[0],buf,MAX)>0)
		{
			printf("I am child progress.I have read this from the pipe: '%s'\n",buf);
		}
		close(pipe_fd[0]); /*关闭子进程读描述符*/
		exit(0);
	}
	else if(pid>0)
	{
		/*父进程关闭读描述符，并通过使父进程暂停1s等待子进程已关闭相应的写描述符*/
		close(pipe_fd[0]);
		sleep(DELAY_TIME);
		if(write(pipe_fd[1],data,strlen(data))!=-1)
		{
			printf("I am parent progress.I have wrote this to the pipe:'%s'\n",data);
		}
		close(pipe_fd[1]);  /*关闭父进程写描述符*/
		waitpid(pid,NULL,0);  /*收集子进程退出信息，等待子进程退出*/
		exit(0);
	}
}

