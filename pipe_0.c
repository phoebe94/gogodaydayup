#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
int pipe_fd[2];
int count=0;

if(pipe(pipe_fd)<0)/*创建管道*/
{
printf("Can't creat pipe");
exit(1);
}

while(1)/*查看管道容量*/
{
write(pipe_fd[1]," ",sizeof(char));
printf("count=%d\n",++count);
}
return 0;
}
