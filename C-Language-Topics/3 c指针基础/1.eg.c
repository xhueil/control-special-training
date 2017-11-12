/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/

#include <stdio.h>

int main()
{
	int a = 0x11223344;
	char *ptr = (char *)&a;

	printf("%0x \n",*ptr);
	printf("%0x \n",*(ptr+1));
	printf("%0x \n",*(ptr+2));
	printf("%0x \n",*(ptr+3)); //将整形变量按字节的方式进行访问

	printf("%p \n",&a);
	printf("%p \n",ptr+1);
	printf("%p \n",ptr+2);
	printf("%p \n",ptr+3);   //看下地址的关系

	printf("%d \n",sizeof(a)); //打印该类型的空间
}
