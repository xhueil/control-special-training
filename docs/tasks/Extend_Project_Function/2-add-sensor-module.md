# 第二节：添加传感器模块



## 一、温湿度传感器 ---- DTH11

> DHT11是一款有已校准数字信号输出的温湿度传感器。 精度湿度+-5%RH， 温度+-2℃，量程湿度20-90%RH， 温度0~50℃。

### 1.电路连接分析

**A.引脚图**

![](http://img.blog.csdn.net/20151223204131422)

**B.接线图**

![](http://img.blog.csdn.net/20151223204411734)



### 2.数据采集分析

**A.  数据总时序**

- 用户主机（MCU）发送一次开始信号后，DHT11 从低功耗模式转换到高速模式，待主机开始信号结束后，DHT11 发送响应信号，送出 40bit 的数据，幵触发一次信采集

![](http://img.blog.csdn.net/20151223220803723)

**B.主机发送起始信号**

- 单片机连接DHT11的DATA引脚的I/O口输出低电平，且低电平保持时间不能小于 18ms，然后等待 DHT11 作出应答信号。

![](http://img.blog.csdn.net/20151223221022332)

**C.检测从机应答信号**

- DHT11 的 DATA 引脚检测到外部信号有低电平时， 等待外部信号低电平结束， 延迟后 DHT11 的 DATA引脚处于输出状态，输出 80 微秒的低电平作为应答信号，紧接着输出 80 微秒的高电平通知外设准备接收数据。

![](http://img.blog.csdn.net/20151223221324552)

**D.接收数据**

a. 数据判定规则 

- 位数据“0”的格式为： 50 微秒的低电平和 26-28 微秒的高电平，位数据“1”的格式为： 50 微秒的低电平加 70微秒的高电平。
- 接收数据时可以先等待低电平过去，即等待数据线拉高，再延时60us，因为60us大于28us且小于70us，再检测此时数据线是否为高，如果为高，则数据判定为1，否则为0。

![](http://img.blog.csdn.net/20151223221942474)



b.数据格式

**一次传送 40 位数据，高位先出**8bit 



湿度整数数据 + 8bit 湿度小数数据+8bit 温度整数数据 + 8bit 温度小数数据+8bit 校验位。



c.数据校正

- 判断“8bit 湿度整数数据 + 8bit 湿度小数数据+8bit 温度整数数据 + 8bit 温度小数数据”的结果是否等于8bit 校验位。如果等于则数据接收正确，否则应该放弃这一次的数据，重新接收。



### 3.驱动程序

```c
include<reg51.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit Data=P3^6;   //定义数据线
uchar rec_dat[9];   //用于显示的接收数据数组

void DHT11_delay_us(uchar n)
{
    while(--n);
}

void DHT11_delay_ms(uint z)
{
   uint i,j;
   for(i=z;i>0;i--)
      for(j=110;j>0;j--);
}

void DHT11_start()
{
   Data=1;
   DHT11_delay_us(2);
   Data=0;
   DHT11_delay_ms(20);   //延时18ms以上
   Data=1;
   DHT11_delay_us(30);
}

uchar DHT11_rec_byte()      //接收一个字节
{
   uchar i,dat=0;
  for(i=0;i<8;i++)    //从高到低依次接收8位数据
   {          
      while(!Data);   ////等待50us低电平过去
      DHT11_delay_us(8);     //延时60us，如果还为高则数据为1，否则为0 
      dat<<=1;           //移位使正确接收8位数据，数据为0时直接移位
      if(Data==1)    //数据为1时，使dat加1来接收数据1
         dat+=1;
      while(Data);  //等待数据线拉低    
    }  
    return dat;
}

void DHT11_receive()      //接收40位的数据
{
    uchar R_H,R_L,T_H,T_L,RH,RL,TH,TL,revise; 
    DHT11_start();
    if(Data==0)
    {
        while(Data==0);   //等待拉高     
        DHT11_delay_us(40);  //拉高后延时80us
        R_H=DHT11_rec_byte();    //接收湿度高八位  
        R_L=DHT11_rec_byte();    //接收湿度低八位  
        T_H=DHT11_rec_byte();    //接收温度高八位  
        T_L=DHT11_rec_byte();    //接收温度低八位
        revise=DHT11_rec_byte(); //接收校正位

        DHT11_delay_us(25);    //结束

        if((R_H+R_L+T_H+T_L)==revise)      //校正
        {
            RH=R_H;
            RL=R_L;
            TH=T_H;
            TL=T_L;
        } 
        /*数据处理，方便显示*/
        rec_dat[0]='0'+(RH/10);
        rec_dat[1]='0'+(RH%10);
        rec_dat[2]='R';
        rec_dat[3]='H';
        rec_dat[4]=' ';
        rec_dat[5]=' ';
        rec_dat[6]='0'+(TH/10);
        rec_dat[7]='0'+(TH%10);
        rec_dat[8]='C';
    }
}

/*这里使用lcd1602来显示采集到的数据，lcd1602驱动程序在博主的51单片机系列博文中有详细讲解*/
void main()
{
   uchar i;   
   lcd_init();   //lcd1602初始化
   while(1)
   {   
       DHT11_delay_ms(1500);    //DHT11上电后要等待1S以越过不稳定状态在此期间不能发送任何指令
       DHT11_receive();
       lcd_write_command(0x80);   //从lcd1602第一行第一个位置开始显示
       for(i=0;i<9;i++)
       lcd_write_data(rec_dat[i]);   //显示数据                      
   }
}

```



## 二、光照传感器 ---- BH1750





## 三、PM2.5传感器 





## 四、烟雾传感器 







## 



## 

