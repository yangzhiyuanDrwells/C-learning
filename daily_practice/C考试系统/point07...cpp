/*����Ĺ����ǣ�ͳ���Ӵ�sub��ĸ���г��ֵĴ���������ա�
�������룺abcabsdefabc
          abc
�����2
*/ 
#include <stdio.h>
int count(char *p,char *q);
int main()//DeV������main����Ҫ�з���ֵ int,visual C�� ����û�� 
{
	char s[80],sub[80];
	gets(s);
	gets(sub);
	printf("%d\n",count(s,sub));
}

int count(char *p,char *q)
{
	int m,n,k,num=0;
	for(m=0;p[m];m++)
	for(n=m,k=0;q[k]==p[n];k++,n++)
	
	if(q[k+1]=='\0')
	{
		num++;
		break;
	}
	return num;	
}
//�������û�к���ԭ���������﷨��������������,����ʵ�ʱ�����,ǿ�ҽ���ʹ�ú���ԭ��

/*1��void main�ķ���ֵΪ��ֵ����û�з���ֵ����int main�ķ���ֵΪ��������ֵ��

2��void main ������ int main���棬���� int main ������ void main���档

3���еı�����main����Ҫ�з���ֵ int �� �Ǿ�д��int main ��*/
