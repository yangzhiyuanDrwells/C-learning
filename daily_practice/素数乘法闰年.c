#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	
#if 0
//��ӡ100~200֮������� (һ)

	int count = 0;
	for (int i = 100; i < 200; i++)
	{
		int j;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%d   ", i);
			count++;
		}	
	}
	printf("\n Primenumber's number = %d\n\n", count);

#endif


#if 0
//��ӡ100~200֮������� (��)

	int count = 0;
	for (int i = 100; i < 200; i++)
	{
		int j;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d   ", i);
			count++;
		}
	}
	printf("\n Primenumber's number = %d\n\n", count);

#endif

#if 1
//��ӡ100~200֮������� (��)

;	int count = 0;
	for (int i = 101; i < 200; i+=2)
	{
		int j;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d   ", i);
			count++;
		}
	}
	printf("\n Primenumber's number = %d\n\n", count);

#endif

	



//1*1=1
//2*1=2  2*2=4
//3*1=3  3*2=6  3*3=9
// ...

#if 1
//����˷��ھ���
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", i, j, i * j);
		}
		printf("\n");
	}
	printf("\n\n");
#endif

#if 0
//�ж�1000��---2000��֮�������
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0)
		{
			if (year % 100 != 0)
			{
				printf("%d ", year);
			}
		}
		if (year % 400 == 0)
		{
			printf("%d ", year);
		}
	}

#endif

#if 1
	//�ж�1000��---2000��֮�������(Self)
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				printf("%d ", year);
	}
#endif
	system("pause");
	return 0;
}
