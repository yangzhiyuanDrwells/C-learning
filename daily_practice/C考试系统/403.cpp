#include<stdio.h>
#include<math.h>
int main()
{
	double x,y,z;
	scanf("%lf,%lf",&x,&y);
	z=(sqrt(x+y))/(sin(x)+cos(y));//�ᵼ���ڴ���� 
	printf("z=%.2lf",z);
	return 0;
}
