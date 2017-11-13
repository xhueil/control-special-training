# 第五节：函数封装、编写规则以及安全问题

**本节知识点**

- 编写函数名以及参数的规则
- 在函数中使用数组（边界检查）
- 函数添加合适的打印信息与函数中的错误处理
- 函数的层次感（均重要）+单片机的中断函数

**编写函数最基本原则：**

1.函数名必须体现函数功能
2.函数参数要提示调用的时候如何传入值
3.返回值最好要进行说明（一定不能使用拼音）

## 一、函数中数组越界

?>在函数中使用数组时，越界情况，体现边界检查的重要性
<br>
该函数实现字符串拷贝功能

eg1：

```c
#include <stdio.h>
#include <string.h>

#define CHEAK_BARRAY_OUT 1

int str_copy(char const *StrOrig , char *StrDest,int size)   
{
    int ret = 0;                     //返回以写入的字节数
    int len = strlen(StrOrig);       //注意不包含'\0'的那个字节

#if  CHEAK_BARRAY_OUT                //边界检查
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
```

## 二、函数添加打印调试信息


> 函数添加合适的打印信息，用于跟踪程序执行的状态

1.添加执行时的状态信息，并用宏开关去控制，这样对代码的整体掌握度更好，调试以及后期维护更加方便。

如： 在编写一个刷卡模块时（就是进门时：刷卡按密码那个）我们就可以给它定义几个状态。

|  序号  | 描述                   | 状态                            |
| :--: | :------------------- | :---------------------------- |
|  1   | 获取到卡号                | get CardId                    |
|  2   | 获取到用户的卡号与密码          | get CardId + Password         |
|  3   | 获取到卡号后，未输入密码被再次刷卡    | new card is arrived           |
|  4   | 获取到卡号后输入密码时间超过最大输入时间 | get CardId + Password timeout |
|  5   | 空闲                   | waitting                      |



这样做的好处就是实时跟踪代码的执行情况，更容易发现代码中的问题。

![图1](http://upload-images.jianshu.io/upload_images/6757403-53bb487c0e282c6d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


2.在程序运行出错时，必须将出错的信息打印出来

- 运行出错：这种错误常常是严重错误，导致程序不能继续执行下去的那种。
- 如： 在程序初始化完成后，检查刷卡模块是否正常工作（初始化是否成功），如果没有工作，那这个程序就没有任何执行下去的意义了，将该错误信息打印出来，结束该程序,或者程序再尝试重新初始化。
- 添加错误检查的好处：十分明确的知道程序时执行到哪里出错了，后期维护很方便。
- 该程序确实不好举例：我就画一个流程图：见图1


## 三、函数的层次感

> 如果你函数设计得好，那么这种层次感是很好的,程序越大，它就越重要

函数的层次感解释：

    如一本书：
    章节体现本书的主体框架
    章节下的子目录进行知识点的讲解
    子目录下的子目录进行知识点的更细致讲解 （就这样一层一层的）

可以举个例子（就通过飞控程序）


## 四、中断服务函数
