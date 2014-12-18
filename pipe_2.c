#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main()
{
 int i,r,p1,p2,fd[2];
 char buf[50],s[50];
 pipe(fd);
 
 if(fd<0)/*创建管道*/
	{
		printf("Can't creat pipe!\n");
		exit(1);
	}

while((p1=fork())==-1);//创建子进程1，锁定写端，往管道里写入内容
 if(p1==0)
 {
  lockf(fd[1],1,0);
  sprintf(buf,"I am process1,Hello world!\n");
  printf("child processP1!\n");
  write(fd[1],buf,50);
  sleep(3);
  lockf(fd[1],0,0);
  exit(0);
 }
 else
 {
  while((p2=fork())==-1);//创建子进程2,锁定写端，往管道内写入内容，解锁
  if(p2==0)
  {
   lockf(fd[1],1,0);
   sprintf(buf,"I am process2,Hello world!\n");
   printf("child processP2!\n");
   write(fd[1],buf,50);
   sleep(3);
   lockf(fd[1],0,0);
   exit(0);
  }

  wait(0);//父进程等待子进程调用结束
  if(r=read(fd[0],s,50)==-1)
  {
   printf("Can't read pipe\n");
  }
  else
  {
   printf("%s\n",s);
  }
  wait(0);//父进程等待子进程调用结束
  if(r=read(fd[0],s,50)==-1)
  {
   printf("Can't read pipe\n");
  }
  else
  {
   printf("%s\n",s);
  }
  exit(0);
 }
}
