#include <stdio.h>
int main()
{
	float a,b,c=0;
	float i;
	scanf("%f",&i);
	for(int j;j<i+1;j++)
	{
		a=1.0/(4*j-3);
		b=1.0/(4*j-1);
		c+=4*(a-b);
	}
	printf("%.5f",c);		
}
/*
����nֵ�����������и�����﹫ʽ���㲢���Բ���ʣ�
*/
