/*����Ĺ����ǣ�����Ĺ����ǣ�������a�е����ݰ������ţ�����ա�
�������룺0 1 2 3 4 5 6 7 8 9
�����9 8 7 6 5 4 3 2 1 0

*/
#include<stdio.h>
#define M 10
void main()
{  int a[M],m,n,temp;
   for(m=0;m<M;m++)  scanf("%d",a+m);
   m=0;
   n=M-1;
   while(m<n)
   {  temp=*(a+m);
      *(a+m)=*(a+n);
	  *(a+n)=temp;
	  m++;
	  n--;
   }
   for(m=0;m<M;m++)
	   printf("%3d",*(a+m));
}
