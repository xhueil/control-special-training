/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdio.h>

int find_a(char * str)
{
	int count = 0;//必须要初始化才行
		while(*str != '\0')
		{
			if(isalpha(*str))         //大条件，判断是否是字母
			{
				if(*str == 'a')
					count++;
				if(*str == 's')//遇到s提前退出循环        
					break; 
			}
			str++;
		}
	return count;
}
int main()
{
	char str[]={"456dfa241gafdasd13234fadfa"};
	printf("number of a =%d \n",find_a(str));
	return 0;
}
