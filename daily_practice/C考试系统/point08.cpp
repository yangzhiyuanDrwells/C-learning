/*����Ĺ����ǣ�ɾ���ַ���s�е����пհ׷�������tab�����س�����������ա�
�������룺abcde abcd efg
�����abcdeabcdefg
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
delspace(char *t)
{ int m,n;
  char c[80];
  for(m=0,n=0;__(1)__;m++)
	if(!isspace(__(2)__))    /*C�����ṩ�Ŀ⺯���������ж��ַ��Ƿ�Ϊ�հ׷�*/
	{ c[n]=t[m]; n++; }
	c[n]='\0';
	strcpy(t,c);
}
void main()
{ char s[80];
  gets(s);
  delspace(s);
  puts(s);
}

