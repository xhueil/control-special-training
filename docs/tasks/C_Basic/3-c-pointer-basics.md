# 第三节：C语言指针基础

**本节知识点**
 
- 指向一维数组的指针
- C语言变量的作用域，生存时间
- 数组作为参数的弱化问题

> 在计算机中所有的东西（变量，函数）均时通过地址去访问。与上一篇的地址空间相对应。

表面上的两种方式：

- 1变量 = 变量名 + 变量类型
- 2指针 = 指针名 + 指针类型

下面先对变量进行分析

- 变量类型决定了计算机的存储方式与访问方式。
	
		int a；     //a 是变量名  int是类型
	
- int 我们都知道占4个字节，它实际代表计算机按int方式分配空间（分配4字节的空间），按int方式访问（将这4个字节作为一个整体去访问）
- a:变量名、&a代表计算机分配空间的首地址，它实际是将计算机的一个int类型的空间与变量名绑定【&变量名=那片空间的地址】
- int a = 0x11223344;     见图1

![图1](http://upload-images.jianshu.io/upload_images/6757403-29efdd602e387ceb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 一、反映计算机的存储
eg1：
	
	#include <stdio.h>
	
	int main()
	{
		int a = 0x11223344;
		char *ptr = (char *)&a;
	
		printf("%d \n",*ptr);
		printf("%d \n",*(ptr+1));
		printf("%d \n",*(ptr+2));
		printf("%d \n",*(ptr+3)); //将整形变量按字节的方式进行访问
	
		printf("%p \n",&a);
		printf("%p \n",ptr+1);
		printf("%p \n",ptr+2);
		printf("%p \n",ptr+3);   //看下地址的关系
	
		printf("%d \n",sizeof(a)); //打印该类型的空间
	}



## 二、变量名与指针的关系

- 对于指针，明确操作的是地址和还是操作地址所指向的值
	- 操作地址时：明确该地址的类型，类型决定了移动的单位，然后进行移动
	- 操作地址所指向的值：就当成变量操作
- 两个术语与两个术语之间的关系
	- 指针的类型          -----      地址的类型    
	- 指针指向对象的类型  -----      地址上变量的类型
	- 指针的类型 + * = 指针指向对象的类型
	- 指针的类型  = 指针指向对象的类型 +&

如：  
	
	int a = 1;  int *ptr = &a;   
	ptr 是一个地址 地址的类型 int *
	*ptr 是一个地址的内容 内容的类型 int    //见图2

![图2](http://upload-images.jianshu.io/upload_images/6757403-65067613879d6daf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


eg2：

	#include <stdio.h>
	int GlobalInit = 10;  
	int GlobalNotInit;   
	
	int add(int a,int b)
	{
		int AutoAdd = 1;
		static AutoStatic = 1; //静态变量               
		printf("access GlobalInit = %d\n",GlobalInit);
		printf("access GlobalNotInit = %d\n",GlobalNotInit);  //在函数中访问全局变量
		printf("access *MllocPtr = %d\n",*MllocPtr);  	      //在函数中访问动态分配的变量
	
		//printf("access AutoMain = %d\n",AutoMain);          //测试能不能访问mian中的自动变量
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
		free(ptr);
		return 0;
	}


## 三、一维数组与指针的关系

如：
	int a[10];                //计算机开辟了10个int型的地址空间，a就是地址空间的首地址
	printf("%d \n",sizeof(a));//结果为 40 = 10 * 4
	int (*PtrAll)[] =  a;     //PtrAll是一个地址，该地址指向整个数组空间
	PtrAll++;         //该地址移动 40 个字节（也就是整个数组的空间 -- int *[]）
	
	int *PtrElem = &a[0];     //PtrElem是一个地址，该地址指向数组首元素的空间
	printf("%d \n",sizeof(a));//结果为 4
	PtrElem ++;    //该地址移动4个字节    （也就是移动数组中一个元素的空间 -- int）   //见图三
	
几个等价表达式：

		a[1] ==== *(PtrElem +1);
		(*PtrAll)[1]  ===== a[1];       //这个应该能理解

![图3](http://upload-images.jianshu.io/upload_images/6757403-df8c4c35f44eec3a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

eg3：

	#include <stdio.h>
	  
	int main()
	{
		int a[10]={1,2,3,4,5,6,7,8,9,10};  
		int *PtrElem = &a[0]; //初始化指向数组元素的指针
		int (*PtrAll)[] = a;       //初始化指向数组的指针  
		
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

> 一维数组作为函数参数，它会被弱化为普通指针

	#include <stdio.h>
	
	void Array_parm(int a[])
	{
		int i;
		for(i=0;i<10;i++)
			printf("%d \n",a[i]);
		printf("%d \n",sizeof(a));  //会发现结果是4，而不是40，这就是体现被弱化的地方，所有一般还要传递参数 数组长度；
	}
	int main()
	{
		int a[10]={1,2,3,4,5,6,7,8,9,10};  
		Array_parm(a)；
		return 0;
	}


## 四、二维数组与指针的关系

!> 分析方法类似，自己扩展
