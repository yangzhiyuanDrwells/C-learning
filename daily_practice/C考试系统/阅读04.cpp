#include <stdio.h>
#include <string.h> 
int main()
{
	char s[3][20]={"BASIC","JAVA","C++"}; //��������Ӻ췢��[20]��ʾÿһ���ַ������ܳ����ĳ��ȣ������������ַ������ȣ� 
	int i,k=0;
	for(i=1;i<3;i++)
	if(strcmp(s[k],s[i])<0)
	k=i;
	puts(s[k]);
}
