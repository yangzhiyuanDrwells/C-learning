/*--------------------------------------------------

题目：用函数求一个N阶方阵右下三角元素的和（包括副
      对角线上的元素）。    

------------------------------------------------*/
#include <stdio.h>
#define N 3

int sum(int a[][N])
{
  /**********Program**********/
	 int b=0;
	 int i,j;
	for(i=0;i<N;i++){
	  for(j=2;j>=2-i;j--){
		  b+=a[i][j];
	  }
	}
	  return b; 

  /**********  End  **********/
}

main()
{
  int a[N][N],i,j;
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      scanf("%d",&a[i][j]);
    }
    
  }

  printf("sum=%5d\n",sum(a));
 
}
/*1 2 3
  12 6 8
  3 8 4  */
