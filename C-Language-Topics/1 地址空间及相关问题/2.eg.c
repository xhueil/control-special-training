/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdlib.h>
#include <stdio.h>
int GlobalInit = 10;  
int GlobalNotInit;   

int add(int a,int b)
{
	int AutoAdd = 1;
	static AutoStatic = 1; //静态变量               
	printf("access GlobalInit = %d\n",GlobalInit);
	printf("access GlobalNotInit = %d\n",GlobalNotInit);  //在函数中访问全局变量
//	printf("access *MllocPtr = %d\n",*MllocPtr);  	      //在函数中访问动态分配的变量

//  printf("access AutoMain = %d\n",AutoMain);          //测试能不能访问mian中的自动变量
	return (a + b);

}

int main()
{
	int AutoMain = 0;
	int *MllocPtr;
	int a=1,b=1;

	MllocPtr = malloc(sizeof(int)); 
	*MllocPtr = 1;
	printf("%d\n",add(a,b));

	//printf("access AutoStatic = %d\n",AutoStatic);     //测试能不能访问add中的静态变量
	free(MllocPtr);
	return 0;
}
