#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>/*调用getch()函数*/
void main()
{
	char c;
	clock_t start,end;
	double var,total=0;
	int i,guess,j=0;
loop:	
	srand(time(NULL));/*使随机数产生的值每一次都不一样*/

	i=rand()%100;/*产生0到99的随机数*/
	printf("\n请输入您猜测的数字（0--99）:");
	scanf("%d",&guess);/*输入所猜的数字*/	
	start=clock();/*开始计时*/
	while(guess!=i)
	{
		if(guess>i)
		{
			printf("过大，请再输入:");
			scanf("%d",&guess);//
		}
		else
		{
			printf("过小，请再输入:");
			scanf("%d",&guess);
		}
	}
	end=clock();/*结束计时*/
	
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
  }
