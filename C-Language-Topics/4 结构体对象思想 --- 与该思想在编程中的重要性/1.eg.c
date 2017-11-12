/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdio.h>

struct stu{
	int a;
	int b;
	int c;
};
int main()
{
	struct stu student;
	struct stu *ptr = NULL;

	student.a = 1;
	student.b = 2;
	student.c = 3;              //自动变量在使用前一定要初始化

	ptr = & student;
	printf("a=%d,b=%d,c=%d\n",student.a,student.b,student.c);
	printf("a=%d,b=%d,c=%d\n",ptr->a,ptr->b,ptr->c);             //两次打印的结构肯定是一样的

	return 0;
}
