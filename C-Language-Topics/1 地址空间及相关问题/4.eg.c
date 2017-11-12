/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/

#include <stdio.h>

int * invalid_array(void)
{
	int array[10];
	int i;
	for(i=0;i<10;i++)
		array[i] = i;
	return array;   //返回该数组的首地址
}

int main()
{
	int *ptr =invalid_array();
	printf("array[0]=%d\n",*ptr);   
	printf("array[1]=%d\n",*(ptr+1));    //并不会的到实际效果，应为那片内存已经释放掉了
}

