#include <stdio.h>
int main(void)
{
	int	n,i,j;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)printf(" ");
		for(j=1;j<=2*i-1;j++)printf("*");
		putchar('\n');
	}
	for(i=1;i<=n-1;i++){
		for(j=1;j<=i;j++)printf(" ");
		for(j=1;j<=2*(n-i)-1;j++)
			printf("*");
			printf("\n");
	}
}
