#include <stdio.h>
int main()
{
	int number,guessnumber,j;//
	while(scanf("%d %d",&number,&guessnumber)!=EOF)
	{
		j=(guessnumber-number)/10;  //����û����⸺�����Ծ� 
		printf("%d\n",j);
	}
	
}
