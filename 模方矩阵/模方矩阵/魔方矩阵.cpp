#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#define Default_Size 3

typedef struct arr
{
	int* data;
	int  i;  //��
	int  j;   //��
}arr, * arrP;

void ArrInital(arrP p, int sz)
{
	int t = 0, u = 0;
	int sz2 = sz * sz;
	int defaultsize = Default_Size * Default_Size;
	int max_size = sz2 > defaultsize ? sz2 : defaultsize;
	p->data = (int *)malloc(max_size * sizeof(int));
	assert(p->data != NULL);
	p->i = p->j = 0;
	for (t = p->i; t < sz2; t += sz)
	{
		for (u = 0; u < sz; ++u)
		{
			p->data[t + u] = 0;
		}
	}
}

void MagicCube(arrP p, int sz)
{
	int i = 0, j = 0, k = 0;
	j = sz / 2;
	int _data = 1;
	int sz2 = sz * sz;
	while (_data <= sz2)
	{
		if (p->data[i + j] != 0 && (i + j + 1) == sz)
		{
			k = (k + 1 + sz) % sz;
			i = k * sz;
		}

		if (p->data[i + j] != 0)
		{
			k = (k + 2 + sz) % sz;
			i = k * sz;
			j = (j - 1 + sz) % sz;
		}

		p->data[i+j] = _data;

		k = (k - 1 + sz) % sz;
		i = k * sz;
		j = (j + 1) % sz;

		++_data;
	}
}

void ArrPrint(arrP p, int sz)
{
	int t = 0, u = 0;
	int sz2 = sz * sz;
	for (t = 0; t < sz2; t += sz)
	{
		for (u = 0; u < sz; ++u)
		{
			printf("%4d ", p->data[t + u]);
		}
		printf("\n\n");
	}
}


void CheckArrPrint(arrP p, int sz)
{
	int t = 0, u = 0;
	int sz2 = sz * sz;
	int sum = 0;
	int flag = 1;
	for (t = 0; t < sz2; t += sz)  //��֤ÿһ�еĽ��
	{
		sum = 0;

		printf("��%d��:", t / sz);

		for (u = 0; u < sz; ++u)
		{
			if (u != sz - 1)
			{
				sum += p->data[t + u];
				printf("%d+", p->data[t + u]);
			}
			
			if (u == sz-1)
			{
				sum += p->data[t + u];
				printf("%d", p->data[t + u]);
				printf("= %d\n", sum);
			}
		}
		printf("\n");
	}

	for (t = 0; t < sz; ++t)  //��֤ÿһ�еĽ��
	{
		sum = 0;

		printf("��%d��:", t);

		for (u = 0; u < sz2; u+= sz)
		{
			if (u != sz - 1)
			{
				sum += p->data[t + u];
				printf("%d+", p->data[t + u]);
			}

			if (u >= sz*(sz-1))
			{
				printf("%d", p->data[t + u]);
				printf("= %d\n", sum);
			}
		}
		printf("\n");
	}

	printf("��֤���Խ���:");
	sum = 0;
	for (t = 0, u = 0; t < sz2&& u < sz; t += sz, ++u)  //��֤���Խ���
	{
		if (u != sz - 1)
		{
			sum += p->data[t + u];
			printf("%d+", p->data[t + u]);
		}

		if (u == sz - 1)
		{
			sum += p->data[t + u];
			printf("%d", p->data[t + u]);
			printf("= %d\n", sum);
		}
	}
	printf("\n");

	printf("��֤���Խ���:");
	sum = 0;
	for (t = 0, u = sz - 1; t < sz2 && u < sz; t += sz, --u)  //��֤���Խ���
	{
		if (u != 0)
		{
			sum += p->data[t + u];
			printf("%d+", p->data[t + u]);
		}

		if (u == 0)
		{
			sum += p->data[t + u];
			printf("%d", p->data[t + u]);
			printf("= %d\n", sum);
		}
	}
	printf("\n");


	
}

void menu()
{
	printf("************************************************\n");
	printf("***        0.�˳�     **************************\n");
	printf("***  1.���û������������Ӧ��ħ������***********\n");
	printf("***  2.��ӡ��õ��û������������Ӧ��ħ������***\n");
	printf("***  3.��֤��õ��û���Ҫ��ħ�������Ƿ���ȷ*****\n");
	printf("************************************************\n");
	printf("�������û���Ҫ��������������Ӧ������:>");
}

int main()
{
	int n = 0;
	arr a;
	int select = 0;
	
	do{
		menu();
		(void)scanf("%d", &select);
		switch (select)
		{
		case 0:
			break;
		case 1:
			printf("������һ������:>");
			(void)scanf("%d", &n);
			ArrInital(&a, n);
			MagicCube(&a, n);
			break;
		case 2:
			ArrPrint(&a, n);
			break;
		case 3:
			CheckArrPrint(&a, n);
			break;
		}
	} while (select != 0);
	return 0;
}