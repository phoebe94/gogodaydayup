#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "conio.h"//调用getch()函数
void main()
{
	char c;
	clock_t start,end;
	double var,total=0;
	int i,guess,j=0;
loop:	
	srand(time(NULL));//使随机数产生的值每一次都不一样
	printf("======欢迎进入猜数字的游戏========\n");
	printf("\n-----------第%d局--------------\n",++j);
	if(j!=1)
		printf("\n--------平均成绩%6.3lf--------------\n",total/(j-1));
	i=rand()%100;//产生0到99的随机数
	printf("\n请输入您猜测的数字（0--99）:");
	scanf("%d",&guess);//输入所猜的数字	
	start=clock();//开始计时
	while(guess!=i)
	{
		if(guess>i)//如果输入的数字过大
		{
			printf("请输入一个小一些的数字:");
			scanf("%d",&guess);//
		}
		else//如果输入的数字过小
		{
			printf("请输入一个大一些的数字:");
			scanf("%d",&guess);
		}
	}
	end=clock();//结束计时
	printf("\n 您花费了 %6.3f 秒钟\n",var=(double)(end-start)/CLOCKS_PER_SEC);//精确到毫秒
	total+=var;
	printf("恭喜您！成功猜出数字%2d！\n\n",i);
	if(var<15)
		printf("\1\1 您水平一流，真聪明! \1\1\n\n");
	else if(var<25)
		printf("\1\1 您的水平一般，再快点就好了! \1\1\n\n");
	else
		printf("\1\1 您的水平偏低，加油! \1\1\n\n");//分等级评价
	printf("\n再来一局？\n\t=====Y=====for YES\n\t=====N=====for NO\n");
	for(;;)
	{
		c=getch();
		if(c=='n'||c=='N')
			break;
		if(c=='y'||c=='Y')
		{
			system("cls");
			goto loop;
		}
	}
	system("cls");
	printf("--------------综合评价---------------\n\n");
	printf("\n-----------您一共玩了%d局--------------\n",j);
	printf("\n--------平均成绩%6.3lf--------------\n\n",total/j);
	var=total/(j);
	if(var<15)
		printf("\1\1 您平均水平一流，真聪明! \1\1\n\n");
	else if(var<25)
		printf(" 您的平均水平一般，再快点就好了! \n\n");
	else
		printf(" 您的平均水平偏低，加油! \n\n");//分等级评价
	system("pause");
}
