#include <stdio.h>
int main()
{
	int i,j,k,u,o,p;
	for (i=1;i<=4;i++){
		for(j=1;j<=4-i;j++){
			printf(" ");
		}
		for(k=1;k<=(2*i-1);k++){
			printf("*");
		}
		printf("\n");
	}
	
	for (u=1;u<=3;u++){
		for(o=1;o<=u;o++){
			printf(" ");
		}
		for(p=1;p<=(7-2*u);p++){
			printf("*");
		}
		printf("\n");		
	} 
}       
