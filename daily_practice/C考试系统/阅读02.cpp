#include <stdio.h>
int k=1;
main()
{
	int i=4;
	void fun(int m);
	fun(i);
	printf("%d %d\n",i,k);
}
void fun(int m)
{
	m+=k;
	printf("%d\n",m);//
	k+=m;
	printf("%d\n",k);//
	{
		char k='B';
		printf("%d\n",k);// ˫б�ߺ��涼��Ϊ���Ķ����򷽱����ע�� 
		printf("%d\n",k-'A');
	}
	printf("%d,%d",m,k);
}
