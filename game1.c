#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>/*����getch()����*/
void main()
{
	char c;
	clock_t start,end;
	double var,total=0;
	int i,guess,j=0;
loop:	
	srand(time(NULL));/*ʹ�����������ֵÿһ�ζ���һ��*/

	i=rand()%100;/*����0��99�������*/
	printf("\n���������²�����֣�0--99��:");
	scanf("%d",&guess);/*�������µ�����*/	
	start=clock();/*��ʼ��ʱ*/
	while(guess!=i)
	{
		if(guess>i)
		{
			printf("������������:");
			scanf("%d",&guess);//
		}
		else
		{
			printf("��С����������:");
			scanf("%d",&guess);
		}
	}
	end=clock();/*������ʱ*/
	
	printf("\n����һ�֣�\n\t=====Y=====for YES\n\t=====N=====for NO\n");
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