#include <stdio.h>
#include <ctype.h>//���� isdigit  isalpha��lower��upper�� 
int main()
{
	char a[100];
	gets(a);
	for(int i=0;a[i]!='\0';i++)
	{
		if(isdigit(a[i])) printf("%c",a[i]);            //�ж��ǲ������� 
		if(isalpha(a[i]))	//�ж��ǲ�����ĸ 
		{
			if(islower(a[i]))printf("%c",toupper(a[i]));//islower�ж��ǲ���Сд��ĸ��toupper��Сд��ĸ��Ϊ��д��ĸ 
			if(isupper(a[i]))printf("%c",tolower(a[i]));//isupper�ж��ǲ��Ǵ�д��ĸ��tolower��д��ĸ��ΪСд��ĸ
		}
	}		
}
