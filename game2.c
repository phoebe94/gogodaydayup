#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "conio.h"//����getch()����
void main()
{
	char c;
	clock_t start,end;
	double var,total=0;
	int i,guess,j=0;
loop:	
	srand(time(NULL));//ʹ�����������ֵÿһ�ζ���һ��
	printf("======��ӭ��������ֵ���Ϸ========\n");
	printf("\n-----------��%d��--------------\n",++j);
	if(j!=1)
		printf("\n--------ƽ���ɼ�%6.3lf--------------\n",total/(j-1));
	i=rand()%100;//����0��99�������
	printf("\n���������²�����֣�0--99��:");
	scanf("%d",&guess);//�������µ�����	
	start=clock();//��ʼ��ʱ
	while(guess!=i)
	{
		if(guess>i)//�����������ֹ���
		{
			printf("������һ��СһЩ������:");
			scanf("%d",&guess);//
		}
		else//�����������ֹ�С
		{
			printf("������һ����һЩ������:");
			scanf("%d",&guess);
		}
	}
	end=clock();//������ʱ
	printf("\n �������� %6.3f ����\n",var=(double)(end-start)/CLOCKS_PER_SEC);//��ȷ������
	total+=var;
	printf("��ϲ�����ɹ��³�����%2d��\n\n",i);
	if(var<15)
		printf("\1\1 ��ˮƽһ���������! \1\1\n\n");
	else if(var<25)
		printf("\1\1 ����ˮƽһ�㣬�ٿ��ͺ���! \1\1\n\n");
	else
		printf("\1\1 ����ˮƽƫ�ͣ�����! \1\1\n\n");//�ֵȼ�����
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
	printf("--------------�ۺ�����---------------\n\n");
	printf("\n-----------��һ������%d��--------------\n",j);
	printf("\n--------ƽ���ɼ�%6.3lf--------------\n\n",total/j);
	var=total/(j);
	if(var<15)
		printf("\1\1 ��ƽ��ˮƽһ���������! \1\1\n\n");
	else if(var<25)
		printf(" ����ƽ��ˮƽһ�㣬�ٿ��ͺ���! \n\n");
	else
		printf(" ����ƽ��ˮƽƫ�ͣ�����! \n\n");//�ֵȼ�����
	system("pause");
}
