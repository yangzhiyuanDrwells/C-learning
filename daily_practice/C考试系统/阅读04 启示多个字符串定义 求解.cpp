#include <stdio.h>
int main()
{
	char password[2][2];//��һ��[]�����ַ����������ڶ���[] ��ʾÿһ���ַ������ܳ����ĳ���
	gets(password[1]);
	printf("%s\n",password[1]);
	gets(password[2]);
	printf("%s\n",password[2]);
}
