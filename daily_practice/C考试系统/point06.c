/*程序的功能是：给所有输入的数组中的每一个元素加2并输出，请填空。
例如输入：1 2 3 4 5 6 7 8 9 10
输出：3,4,5,6,7,8,9,10,11,12,
*/
#include<stdio.h>
void main()
{ int a[10],*p,i;
  p=a;
  for(i=0;i<10;i++)
	 scanf("%d",p++);
  for(p=a;p<a+10;p++)
  {
	  *p+=2;
	  printf("%d,",*p);
  }
}
