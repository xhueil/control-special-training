# 第一节：多功能电子时钟

## 一、硬件设计
硬件构成：

- 第一阶段：51单片机+数码管+按键+蜂鸣器
- 第二阶段：51单片机+LCD液晶屏+DS1302时钟芯片+温湿度模块+按键+蜂鸣器

## 二、实现功能

> 本设计基于STC89C52单片机

### 第一阶段
- 1.使用51单片机的定时器+中断实现，时、分、秒走时
- 2.使用数码管进行显示
- 3.使用按键对时间进行调整
- 4.使用蜂鸣器实现闹钟功能
- 5.可通过按键切换到秒表功能

### 第二阶段
- 1.使用DS1302时钟芯片获取时间
- 2.添加温湿度模块获取室内温湿度
- 3.使用LCD液晶屏显示时间等信息
- 4.具有整点报时、闹钟功能（闹钟滴滴响，响30秒），可以显示年、月、日、 时、分、秒、星期、温湿度。
- 5.可通过设置时间和闹钟。设置数据掉电保存功能，下次开机无需重新设置。

## 三、软件设计

