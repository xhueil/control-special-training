# 第一节：改为DS1302时钟芯片计时

  ![](http://images2017.cnblogs.com/blog/1083998/201710/1083998-20171022225837818-413268826.png)

![](http://images2017.cnblogs.com/blog/1083998/201710/1083998-20171022225814787-1131304821.png)

## 一、芯片介绍
!> DS1302是DALLAS(达拉斯)公司出的一款涓流充电时钟芯片，2001年DALLAS被MAXIM(美信)收购，因此我们看到的DS1302的数据手册既有DALLAS的标志，又有MAXIM的标志；

!> DS1302实时时钟芯片广泛应用于电话、传真、便携式仪器等产品领域，他的主要性能指标如下：

- 1、DS1302是一个实时时钟芯片，可以提供秒、分、小时、日期、月、年等信息，并且还有软年自动调整的能力，可以通过配置AM/PM来决定采用24小时格式还是12小时格式。
- 2、拥有31字节数据存储RAM。
- 3、串行I/O通信方式，相对并行来说比较节省IO口的使用。
- 4、DS1302的工作电压比较宽，大概是2.0V~5.5V都可以正常工作。采用双电源供电，当主电源比备用电源高0.2V时，由主电源供电，否则采用备用电源，一般是一个纽扣电池。
- 5、DS1302这种时钟芯片功耗一般都很低，它在工作电压2.0V的时候，工作电流小于300nA。
- 6、DS1302共有8个引脚，有两种封装形式，一种是DIP-8封装，芯片宽度(不含引脚)是300mil，一种是SOP-8封装，有两种宽度，一种是150mil，一种是208mil。

## 二、引脚定义

![](http://images2017.cnblogs.com/blog/1083998/201710/1083998-20171022230131459-1977458588.png)

## 三、外围电路

![](http://images2017.cnblogs.com/blog/1083998/201710/1083998-20171022230929412-1683524905.png)

一般与单片机IO口相连时要加上拉电阻，提高 IO 口的驱动能力，这样信号比较稳定，计时也比较准确。

## 四、分析时序图

![](http://images2017.cnblogs.com/blog/1083998/201710/1083998-20171022231321943-459608670.png)

- 这是单字节写入的时序图，可见，先拉高使能端，进行使能选择，然后在时钟上升沿写入一个字节。
- DS1302在进行读写操作时最少读写两个字节，第一个是控制字节，就是一个命令，说明是读还是写操作，第二个时需要读写的数据。
- 对于单字节写，只有在SCLK为低电平时才能将 CE 置高电平，所以刚开始将SCLK 置低，CE置高，然后把需要写入的字节送入 IO口，然后跳变SCLK，在SCLK下降沿时，写入数据

![](http://images2017.cnblogs.com/blog/1083998/201710/1083998-20171022231814756-1549643395.png)



## 五、驱动程序

> 有了 上面的分析，我们就可以学着编写驱动程序了，可以把驱动程序分为几个模块来写，由底层慢慢往上累加，比如，我们先编写单个字节的读写操作，在编写整个数据的读写.c文件如下

```C

#include "DS1302.h"

//*******************
void ds1302_writebyte(uchar byte){
    uint i;
    uint t = 0x01;
    for(i=0;i<8;i++){
        SCIO = byte & t;        
        t<<=1;
        DOWN();       //下降沿完成一个位的操作
    }
    SCIO = 1;//确保释放io引脚
}
//********************
void ds1302_writedata(uchar addr,uchar data_){
    
    CE = 0;        nop();    
    SCLK = 0;    nop();    
    CE = 1;        nop();    //使能片选信号
    ds1302_writebyte((addr<<1)|0x80);    //方便后面写入
    ds1302_writebyte(data_);
    CE = 0;        nop();//传送数据结束

}
//*************************
uchar ds1302_readbyte(){
    uint i;
    uchar data_ = 0;
    uint t = 0x01;     
    for(i=0;i<7;i++){     //c51好像不支持直接在for循环里面直接定义变量

        if(SCIO){

            data_ = data_ | t;    //低位在前，逐位读取,刚开始不对，估计是这个的问题
        }                
        t<<=1;
        DOWN();
    }
     return data_;
}


//************************
uchar ds1302_readdata(uchar addr){

    uchar data_ = 0;

    CE = 0;     nop();
    SCLK = 0;  nop();
    CE = 1;      nop();
    ds1302_writebyte((addr<<1)|0x81);
    data_ = ds1302_readbyte();
    CE = 0;       nop();
    SCLK = 1;  nop();
    SCIO = 0;  nop();
    SCIO = 1;  nop();

    return data_;
}

//*********************
void init_ds1302(){

     uchar i;
     CE = 0;   //初始化引脚
     SCLK = 0; 
     i  = ds1302_readdata(0x00);  //读取秒寄存器,秒在最低位
     if((i & 0x80 != 0)){

         ds1302_writedata(7,0x00); //撤销写保护，允许写入数据
        for(i = 0;i<7;i++){

            ds1302_writedata(i,init_time[i]);
        }
     }    
}

//**************
void ds1302_readtime(){       //读取时间
      uint i;
      for(i = 0;i<7;i++){

             init_time[i] = ds1302_readdata(i);
      }
}
```

> 头文件如下：

```C
#ifndef DS1302_H__
#define DS1302_H__

#include "reg52.h"
#include "intrins.h"


#define uint unsigned int
#define uchar unsigned char
#define nop() _nop_()

#define UP() {SCLK = 0;nop();SCLK = 1;nop();} //上升沿  ,使用宏定义函数时最后一定家分号
#define DOWN() {SCLK = 1;nop();SCLK = 0;nop();} //下降沿

 //这个模块内没有集成上拉电阻，使用时最好接上2
sbit CE = P2^5;//RET,使能输入引脚，当读写时，置高位
sbit SCIO = P2^6;//IO     ，双向通信引脚，读写数据都是通过这个完成
sbit SCLK = P2^7;//SCLK，时钟信号


//为什么有时候好好的，也会出错显示少了分号呢？还气人啊！！！！

void ds1302_writebyte(uchar byte);//写一个字节; 
void ds1302_writedata(uchar addr,uchar data_);//给某地址写数据,data是c51内部的关键字，表示将变量定义在数据存储区，故此处用data_;
uchar ds1302_readbyte();//读一个字节
uchar ds1302_readdata(uchar addr);//读取某寄存器数据     ;
void init_ds1302();
void ds1302_readtime();


extern uchar init_time[];

#endif
```

## 六、实现功能

?> 功能实现就简单了，就是加上主函数嘛，然后加上我们可以亲眼看见并感知的模块，比如用数码管显示时间：

```c
#include "DS1302.h"

#define DIG P0
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;



uchar init_time[] = {0x50,0x15,0x14,0x22,0x10,0x06,0x17};//初始化的时间    //秒 分 时 日 月 周 年 
uchar code DIG_CODE[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //数码管数字表
uint disp[8]={0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f};//把要显示的数字传给他    
uchar Num=0;
uint count_flag = 0;     //中断溢出次数

void time0_init();//定时器0初始化
void display();//数码管显示时间

void main(void){
    
     init_ds1302();     //初始化时写入起始时间
     time0_init();

     while(1){
            display();
     }
}

//***************
void display(){
            
     ds1302_readtime();    //读取时间
    disp[7] = DIG_CODE[init_time[0]&0x0f];
    disp[6] = DIG_CODE[init_time[0]>>4];
    disp[5] = 0X40;        //显示一个横线
    disp[4] = DIG_CODE[init_time[1]&0x0f];
    disp[3] = DIG_CODE[init_time[1]>>4];
    disp[2] = 0X40;
    disp[1] = DIG_CODE[init_time[2]&0x0f];
    disp[0] = DIG_CODE[init_time[2]>>4];
}
//******************
void time0_init(){

    TMOD=0X02;//选择为定时器模式，工作方式2，8位自动重装模式，仅用TRX打开启动。
    TH0=0X9C;    //给定时器赋初值，定时100us，0x9c就是156，就是还需计数100次产生溢出，就是0.1ms
    TL0=0X9C;    
    ET0=1;//打开定时器0中断允许
    EA=1;//打开总中断
    TR0=1;//打开定时器
}

void DigDisplay() interrupt 1    //中断入口函数，扫描以实现动态显示
{
//定时器在工作方式二会自动重装初，所以不用在赋值。
//    TH0=0X9c;//给定时器赋初值，定时0.1ms
//    TL0=0X00;

    count_flag++;    
    if(count_flag==1)
    {
        count_flag = 0;
        DIG=0; 
        switch(Num)     //位选，选择点亮的数码管，
        {
            case(7):
                LSA=0;LSB=0;LSC=0; break;
            case(6):
                LSA=1;LSB=0;LSC=0; break;
            case(5):
                LSA=0;LSB=1;LSC=0; break;
            case(4):
                LSA=1;LSB=1;LSC=0; break;
            case(3):
                LSA=0;LSB=0;LSC=1; break;
            case(2):
                LSA=1;LSB=0;LSC=1; break;
            case(1):
                LSA=0;LSB=1;LSC=1; break;
            case(0):
                LSA=1;LSB=1;LSC=1; break;    
        }

        DIG=disp[Num]; //段选，选择显示的数字。
        Num++;
        if(Num>7)
            Num=0;
    }    
}
```

!> 总结一下：

- 这个芯片基本上不是很难，但是想要用的灵活，用的上手，还是得多练的，最好是先把上面的驱动程序对着时序图自己分析一遍，然后自己亲手编写一下。
- 还有就是看数据手册，一个芯片所能用到的数据，在数据手册上基本都能查到。资料谁都能查到，就看怎么用了。