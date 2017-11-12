/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdio.h>

struct stu{
	int a;
	char b;
	int c;
};
int main()
{
	struct stu student;
	struct stu *ptr = NULL;

	student.a = 0x11223344;
	student.b = 0x11;
	student.c = 0x11223344;           

	printf("room of struct stu =%d \n",sizeof(struct stu));//打印该结构体暂多少个字节，会发现是12个，而不是9个（字节对其的问题）

	ptr = & student;                                                             
	printf("addr  ptr=%p \n",ptr);
	printf("addr  ptr+1=%p \n",ptr+1);                             //会发现两次地址差为12，指针一次偏移了12个字节

	return 0;
}
