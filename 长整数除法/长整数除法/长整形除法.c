#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#define DataType short

//����ջ�ṹ���ñ������ͳ�����С�ȽϺ��̽���Ĵ�ӡ
typedef struct Stack
{
	short* st;
	int top;
}Stack;

void StackInital(Stack* Pst)
{
	Pst->top = 0;
	Pst->st  = NULL;
}

void StackPush(Stack* Pst, short x)
{
	short* s = (short*)realloc(Pst->st, sizeof(short)*(Pst->top+1));
	assert(s != NULL);
	Pst->st = s;
	Pst->st[Pst->top++] = x;
}

//�����������Խṹ��װ�����ͱ���������
typedef struct SListNode  
{
	DataType data;
	struct SListNode* next;
}SListNode;

typedef struct Div
{
	int digit;
	struct SListNode* P;
}Div;



void DivInital(Div* Pdiv)
{
	Pdiv->digit = 0;
	Pdiv->P = NULL;
}

void SListPush(Div* Pdiv, char* x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	if (!Pdiv->digit)
		s->next = NULL;
	s->data = *x - 48;

	if (Pdiv->P == NULL)
		Pdiv->P = s;
	else
	{
		s->next = Pdiv->P;
		Pdiv->P = s;
	}
	Pdiv->digit++;
}

void _PlusUnit(SListNode* p)
{
	if (p == NULL)
	{
		SListNode* s = (SListNode*)malloc(sizeof(SListNode));
		assert(s != NULL);
		s->next = NULL;
		p = s;
		s->data = 1;
	}
	if (p->data < 9)
		p->data++;
	else
	{
		if (p->next == NULL && p->data == 9)
		{
			SListNode* s = (SListNode*)malloc(sizeof(SListNode));
			assert(s != NULL);
			s->data = 0;
			s->next = NULL;
			p->next = s;
		}
		p->data = 0;
		_PlusUnit(p->next);
	}

}

void PlusUnit(Div* quitent, int x)
{
	if (x == 0) return;
	SListNode* p = NULL;
	if (quitent->P == NULL)
	{
		SListNode* s = (SListNode*)malloc(sizeof(SListNode));
		assert(s != NULL);
		s->next = NULL;
		quitent->P = s;
		s->data = 0;
	}
	while (x--)
	{
		p = quitent->P;
		if (p == NULL)
		{
			SListNode* s = (SListNode*)malloc(sizeof(SListNode));
			assert(s != NULL);
			s->next = NULL;
			p = s;
			s->data = 0;
		}
		_PlusUnit(p);
	}

}

bool same_digit_greater(SListNode* first, SListNode* last)
{
	int same_sz = 0;
	Stack st1;  //ջ1��¼������
	Stack st2;  //ջ2��¼����
	StackInital(&st1);
	StackInital(&st2);
	while (first != NULL && last != NULL)  //����¼�������ͳ���������ѹջ
	{
		StackPush(&st1, first->data);
		StackPush(&st2, last->data);
		first = first->next;
		last = last->next;
	}
	//�Ƚϱ������ͳ����Ĵ�С
	same_sz = st1.top - 1;
	if (st1.st[same_sz] > st2.st[same_sz]) return true;
	if (st1.st[same_sz] < st2.st[same_sz]) return false;
	while (same_sz-- >= 0)  //����¼�������ͳ����������ջ���Ƚϱ������ͳ�����С
	{
		if (st1.st[same_sz] == st2.st[same_sz])
			same_sz--;
		if (st1.st[same_sz] < st2.st[same_sz])
			return false;
		if (st1.st[same_sz] > st2.st[same_sz])
			return true;
	}
}

void _Divide(Div* Pdiv1, SListNode* div1, SListNode* div1_prve)  //����ĺ����㷨
{
	int flag = 1;
	SListNode* div1_temp = div1;
	SListNode* div1_prve_temp = div1;
	while (div1_prve_temp->next != NULL)
	{
		//ɾ�����λ��0
		if (div1_temp->next == NULL && div1_temp->data == 0)  
		{
			free(div1_prve_temp->next);
			div1_prve_temp->next = NULL;
			Pdiv1->digit--;
			return;
		}
		//��ǰλ�ȼ���һ�������ڱ����ߵ�λ�����ֵ�ǰ���½�1
		if (div1_prve_temp->next != NULL && div1_temp->next != NULL && div1_temp->data < 0) 
		{
			div1_temp->data += 10;
			div1_temp->next->data--;
		}
		//ָ�򱻳���λ��ǰ��ָ������ߣ�����һλ�����͵������λ��1
		if (flag)
		{
			div1_temp = div1_temp->next;
			flag--;
		}
		else
		{
			div1_temp = div1_temp->next;
			div1_prve_temp = div1_prve_temp->next;
		}
	}
}

void Divide(Div* Pdiv1, Div* Pdiv2, Div* quitent)
{
	SListNode* div1 = Pdiv1->P;
	SListNode* div2 = Pdiv2->P;
	SListNode* p1 = NULL;
	SListNode* p2 = NULL;
	while (Pdiv1->digit > Pdiv2->digit || (Pdiv1->digit == Pdiv2->digit && same_digit_greater(Pdiv1->P, Pdiv2->P) ))
	{
		p1 = div1;
		p2 = div2;
		while (p2 != NULL)
		{
			p1->data -= p2->data;
			_Divide(Pdiv1, p1, p1);
			p1 = p1->next;
			p2 = p2->next;
		}
		PlusUnit(quitent, 1);
	}
}

void printQuitent(SListNode* p)  //�ǵݹ鷽ʽ��ӡ�̽��
{
	SListNode* pt = p;
	Stack QuitentStack;
	StackInital(&QuitentStack);
	if (NULL == p)
		return;
	else
	{
		while (pt != NULL)  //����ջ
		{
			StackPush(&QuitentStack,  pt->data);
			pt = pt->next;
		}
		QuitentStack.top--;
		while (QuitentStack.top)  //�̳�ջ
		{
			printf("%d", QuitentStack.st[QuitentStack.top--]);
		}
		printf("%d\n", QuitentStack.st[QuitentStack.top]);
	}
	free(QuitentStack.st);
	QuitentStack.st = NULL;
}

void PrintRemainder(SListNode* p)  //��ӡ����
{
	SListNode* pt = p;
	Stack Div1RemainderStack;
	StackInital(&Div1RemainderStack);
	if (NULL == p)
		return;
	else
	{
		while (pt != NULL)  //������ջ
		{
			StackPush(&Div1RemainderStack, pt->data);
			pt = pt->next;
		}
		Div1RemainderStack.top--;
		while (Div1RemainderStack.top)  //������ջ
		{
			printf("%d", Div1RemainderStack.st[Div1RemainderStack.top--]);
		}
		printf("%d\n", Div1RemainderStack.st[Div1RemainderStack.top]);
	}
	free(Div1RemainderStack.st);
	Div1RemainderStack.st = NULL;
}


int main()
{
	Div div1;
	Div div2;
	Div quitent;
	DivInital(&div1);
	DivInital(&div2);
	DivInital(&quitent);
	char divident;
	char divisor;

	printf("�����뱻�������ַ�'e'��Ϊ������־\n");
	while (scanf("%c", &divident)&& divident != 'e')
	{
		SListPush(&div1, &divident);
	}
	(void)scanf("%c", &divident);  //ȡ��\n��Ӱ��
	printf("������������ַ�'e'��Ϊ������־\n");
	while (scanf("%c", &divisor) && divisor != 'e')
	{
		SListPush(&div2, &divisor);
	}
	Divide(&div1, &div2, &quitent);
	printf("���ǣ�");
	printQuitent(quitent.P);
	printf("�����ǣ�");
	PrintRemainder(div1.P);
	return 0;
}



//void _Divide(Div* Pdiv1, SListNode* div1, SListNode* div1_prve)  //����ĺ����㷨���ݹ飬���ǵ�Ч������ĳ�����ķǵݹ鷽ʽ��
//{
//	static flag = 1;
//	if (div1->next == NULL && div1->data == 0)
//	{
//		free(div1_prve->next);
//		div1_prve->next = NULL;
//		Pdiv1->digit--;
//	}
//	if (div1_prve->next != NULL && div1->next != NULL && div1->data < 0)
//	{
//		div1->data += 10;
//		div1->next->data--;
//		if (flag)
//			{
//				_Divide(Pdiv1, div1->next, div1_prve);
//				flag--;
//			}
//			
//		else
//			_Divide(Pdiv1, div1->next, div1_prve->next);
//	}
//}


//void printQuitent(SListNode* p)  //�ݹ��ӡ�̽�����ݹ飬���ǵ�Ч������ĳ�����ķǵݹ鷽ʽ��
//{
//	if (NULL == p)
//		return;
//	else
//	{
//		printQuitent(p->next);
//		printf("%d", p->data);
//	}
//}



