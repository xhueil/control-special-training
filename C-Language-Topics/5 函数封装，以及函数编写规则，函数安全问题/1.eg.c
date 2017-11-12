/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdio.h>
#include <string.h>

#define CHEAK_BARRAY_OUT 1

int str_copy(char const *StrOrig , char *StrDest,int size)   
{
	int ret = 0;                               //返回以写入的字节数
	int len = strlen(StrOrig);        //注意不包含'\0'的那个字节

#if  CHEAK_BARRAY_OUT                      //边界检查
	if(len >  size - 1)	                      
		ret = size - 1;
	else
		ret = len;
#else
	ret = len;
#endif
	strncpy(StrDest,StrOrig,ret);    //对于这个函数还要进行错误检查的，这里暂时不进行
	return ret;
}

int main()
{
	int ret;
	char StrOrig[]={"hallo world"};
	char StrDest[5];          //注意只有5个字节
	ret = str_copy(StrOrig,StrDest,5) ;

	printf("ret = %d\n",ret);
	printf("orignal str =%s\n",StrOrig);
	printf("desterminal str =%s\n",StrDest);
}
