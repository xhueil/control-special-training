# 第一节：地址空间及相关问题

**本节知识点**

- C语言的地址空间
- C语言变量的作用域，生存时间
- 函数传参（传值，传址)
- 函数内分配的变量，在离开后释放的问题
- 变量的初始化问题

## 一、C语言的地址空间问题、变量存放的区域

![图1](http://upload-images.jianshu.io/upload_images/6757403-7171f0a9251008e1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

eg1：

```c
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
```

## 二、C语言变量的作用域、生命周期

![图2](http://upload-images.jianshu.io/upload_images/6757403-e71ed3ba34f4ba14.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


eg2：

```c
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
    
    // printf("access *MllocPtr = %d\n",*MllocPtr);       //在函数中访问动态分配的变量
    // printf("access AutoMain = %d\n",AutoMain);         //测试能不能访问mian中的自动变量
    
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
```


**得出结论：在变量存放在不同的地址空间，就绝对了生存时间，已经作用范围。特别是函数的堆栈。**

!> 留出一个问题：static AutoStatic = 1; //静态变量 存放在地址空间的哪个区域中。

## 三、函数传参（传值，传址）
eg3：

```c
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
```

## 四、函数内分配的变量，在离开后释放的问题
eg4：

```c
#include <stdio.h>

int * invalid_array(void)
{
    int array[10];
    int i;
    for(i=0;i<10;i++)
        array[i] = i;
    return array;   //返回该数组的首地址
}

int main()
{
    int *ptr =invalid_array();
    printf("array[0]=%d\n",*ptr);   
    printf("array[1]=%d\n",*(ptr+1));    //并不会的到实际效果，应为那片内存已经释放掉了
}
```


## 五、变量的初始化问题，数组可能产生的覆盖问题，在函数中数组使用的一般方法

?> 对于未初始化的全局变量直接会初始化为0，未静态变量（static）同样会被初始化为0

?> 自动分配（auto)的变量如果未初始化就是一个随机值。

eg5：

```c
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
```
