/*����Ĺ����ǣ����ַ���s���ҳ������ַ����ڵ�һ��λ���ϣ��������ַ�ǰԭ�ַ�����˳���ƶ�������ա�
�������룺boy&girl
�����ybo&girl
*/
#include<stdio.h>
#include<string.h>
int main()
{ char s[80],*t,max,*w;
  t=s;
  gets(t);
  max=*(t++);
  while(*t!='\0')
  { if(max<*t)
 	{ max=*t;w=t; }
    t++;
  }
  t=w;
  while(t>s)
  { *t=*(t-1); t--; }
    *t=max;
  puts(t);
}

