/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdio.h>

void exchange_addr(int *a,int *b)   //函数栈+指针
{
	int store;
	store = *a;
	*a = *b;
	*b = store;

}
void exchange_value(int a,int b)
{
	int store;
	store = a;
	a = b;
	b = store;
}
int main()
{
	int a=1,b=3;
	exchange_addr(&a,&b);
	printf("a=%d  b=%d\n",a,b);   

	a=1;
	b=3;
	exchange_value(a,b);
	printf("a=%d  b=%d\n",a,b);
	return 0;
}
