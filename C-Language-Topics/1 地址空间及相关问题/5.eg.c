/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/
#include <stdio.h> 
int GlobalNotInit;   

void uninit_var(void)
{
	int i;  //一般默认ij变量为循环变量
	int AutoVar ;
	static StaticVar;
	int array[10];
	printf("defualt value AutoVar = %d\n",AutoVar);
	printf("defualt value StaticVar = %d\n",StaticVar);
	for(i=0;i<10;i++)
		printf("defualt value array[%d] = %d\n",i,array[i]);    

}

int main()
{
	printf("defualt value GlobalNotInit = %d\n",GlobalNotInit);

	uninit_var();
	return 0;
}
