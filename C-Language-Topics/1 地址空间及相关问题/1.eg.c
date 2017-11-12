/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdio.h>
#include <stdlib.h>

int GlobalInit = 10;  //以初始化的全局变量
int GlobalNotInit;    //未初始化的全局变量

int add(int a,int b)
{
	int AutoAdd = 1;
	printf("AutoAdd  = %p\n",&AutoAdd);
	return (a + b);

}

int main()
{
	int AutoMain = 0;
	int *MllocPtr;
	int a=1,b=1;

	MllocPtr = malloc(sizeof(int)); 

	printf("GlobalInit = %p\n",&GlobalInit);
	printf("GlobalNotInit = %p\n",&GlobalNotInit);
	printf("AutoMain = %p\n",&AutoMain);
	printf("MllocPtr = %p\n",MllocPtr);  //打印4种类型变量的地址，在对应到图上

	printf("%d\n",add(a,b));

	free(MllocPtr);
	return 0;
}
