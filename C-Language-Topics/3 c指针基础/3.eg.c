/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdio.h>

int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};  
	int *PtrElem = &a[0]; //初始化指向数组元素的指针
	int (*PtrAll)[10] = a;       //初始化指向数组的指针  

	/**针对数组指针操作*/
	printf("addr a= %p \n",a);
	printf("%d \n",sizeof(a));
	printf("addr PtrAll= %p \n",PtrAll);
	printf("addr PtrAll+1= %p \n",PtrAll+1);         //地址偏移了40个字节

	/**针对指向数组元素的指针*/
	printf("addr a[0]= %p \n",&a[0]);
	printf("addr PtrElem= %p \n",PtrElem);
	printf("addr PtrElem+1= %p \n",PtrElem+1);    //地址偏移了4个字节
}
