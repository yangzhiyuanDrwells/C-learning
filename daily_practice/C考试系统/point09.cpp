/*����Ĺ����ǣ��Ƚ������ַ����Ƿ���ȣ�������򷵻�1�����򷵻�0������ղ������򲹳�������
�������룺abcdef
          abcdef
����������ַ������
���룺abcdefefg
      abcdef
����������ַ��������
*/
#include<stdio.h>
#include<string.h>
int fun(char *s,char *t)
{ int m=0;
  while(*(s+m)==*(t+m)&& s[m]!='\0')
     m++;
  return(*(s+m)==*(t+m));
}
int main()
{
/******************************/
char a[10],b[10],*s,*t;
char j;
gets(a);
gets(b);
j=fun(a,b);
if(j==1) printf("�����ַ������");
else
printf("�����ַ��������");
/******************************/
}
