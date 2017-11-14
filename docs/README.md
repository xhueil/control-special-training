# 创新实验室控制方向专题培训

> 完成培训计划，提升你的能力

?> 各部分培训计划请查看左侧侧边栏对应分类，每一期的培训限在一周之内完成

!>【注】此培训专题是针对于基础比较好，对C语言、软件、控制基础比较好的，每个组最好一个人。

培训专题的设置有一定难度，不是让每个零基础的人都来参与，那这样也没有体现专题培训的意义。

但培训难度也不是随便设置的，能力比较强的每周布置的任务都能完成

培训任务具有「引导性」，通过 **步骤、知识点、参考链接**，和 **明确的项目目的**，逐步引导学习和入门

在培训之前，请先读完本培训专题的整体描述，再开始按步骤进行操作

## 培训计划

### 1.11周-第一期：C语言基础+51单片机

	时间：11周周五晚6：00
	地点：8教（具体待定）

- C语言基础
  - 1.地址空间及相关问题
  - 2.C基本语句以及运算符
  - 3.C指针基础
  - 4.结构体对象思想与该思想在编程中的重要性
  - 5.函数封装，以及函数编写规则，函数安全问题
- 51单片机
  - 1.中断概念
  - 2.外部中断
  - 3.定时器中断
  - 4.多功能电子时钟
    - 4.1定时器+中断实现计时
    - 4.2数码管显示
- 原理图及PCB
  - 1.讲解原理图
  - 2.绘制电子时钟PCB板

### 2.12周-第二期：硬件PCB设计+扩展项目功能

	时间：待定
	地点：8教（具体待定）


- 扩展电子时钟功能模块
  - 1.改用时钟芯片（DS1302或DS12C887）
  - 2.改用LCD1602或LCD12864显示
  - 3.添加传感器（温度：DS18B20，温湿度：DHT11）
- PCB及其相关
  - 1.AD绘制封装
  - 2.AD改画电子时钟板子

### 3.13周-第三期：自行开始STM32的学习

- STM32
  - 1.了解学习STM32
  - 2.构建一个代码模板
- 参考资料

### 4.14周-第四期：STM32基础+C语言高级

	时间：待定
	地点：8教（具体待定）

- STM32单片机基础
  - 1.使用STM32实现流水灯
  - 2.外部中断+中断向量表

- C语言高级
  - 1.数据结构
  - 2.关键字、常用函数
  - 3.各种指针

- 绘制STM32最小系统
  - 1.讲解原理图
  - 2.绘制电子时钟PCB板

### 5.15周之后-第五期：STM32综合项目

	时间：待定
	地点：8教（具体待定）

- 拟定项目
  - 1.平衡小车 or 电子秤 or PCB自动腐蚀系统
  - 2.若有其他项目到时再确定

?> 培训专题主要提高**C语言编程能力、编程规范、单片机快速入门、程序调试方法**

<br/>
问概念解释可以上 [知乎](https://www.zhihu.com)，教程操作类推荐使用 [百度](https://www.baidu.com)，技术细节问题应找 **[谷歌](https://www.google.com)**
<br/>
禁止使用国内其他搜索引擎

!> 对于需要使用的软件工具[GitHub for Windows](https://desktop.github.com/)、[VC++ 6.0](http://www.microsoft.com/en-us/download/details.aspx?id=9183)、[Keil C51和MDK](https://www.keil.com/download/product/)，软件安装包在群文件也有。


## 培训说明

- 这次培训只针对于16级的实验室成员
- 本控制方向专题培训主要由三个人负责：
  - 王成：主要负责C语言
  - 陈木林：主要负责单片机
  - 李成龙：主要负责硬件（原理图&&PCB）
  - 其中会有一些变动，代码调试和维护三人共同进行
- 每组最好一人，还有要参加的找李成龙登记
- 说明来培训的目的，然后根据你们的需求可进行变动
- 所有的代码均需要使用 **[GitHub](https://github.com)** 上传
- Git 提交信息规范：[GUIDELINE commit](https://neko-dev.github.io/GUIDELINE/#/contribution/commit) - （源自 [Angular](https://github.com/angular/angular.js/blob/master/CONTRIBUTING.md#-git-commit-guidelines)）
- 培训器件应进行完成和学习情况的总结，写一篇文档附带一起传到Github上
- 每个人将自己的Github一起汇报到李成龙处
- 善用搜索引擎

?> 学习过程中**重视文档**，几乎所有知识点都有**官方文档**
<br/>
遇到问题应该优先自己解决，而不是去搜教程

## Github使用

github非常重要的一个工具，这次的专题培训，代码全部在github上管理，培训计划也在github上

对于 GitHub，需要掌握 

- 版本控制概念
- git 基本使用（add, check, commit, push）
- GitHub 用户注册、仓库建立、本地关联、上传代码

参考链接：

1. [廖雪峰 Git 教程](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)
2. [图解 GitHub 和 SourceTree 入门教程](http://blog.csdn.net/collonn/article/details/39259227)
3. [GitHub Desktop 使用方法](http://blog.csdn.net/harryptter/article/details/51363473)
4. [Tower](https://www.git-tower.com/windows/)

## 关于学习优先级

结论：先用限制一定范围内的**广度优先**， 再用限制最大深度的深度优先

即了解一个新概念时，优先了解个大概，再逐层深入掌握

相关讨论：[大家学习新东西的时候一般是广度优先还是深度优先](https://www.v2ex.com/t/393618)


## 关于提问方式

核心思想是

1. 能百度到的就不要再打扰别人

   大部分问题，简单搜索下就有固定答案；需要向人提问的，应该是依赖某些经验、或有讨论价值的问题

2. 让你的提问有价值

   描述具体问题现象并在解决后分享解决办法；让你的提问对后来遇到相同问题的人有帮助

   让这个提问不仅仅是解决**「我的问题」**，重点是转为留下了一种解决**「这个问题」**的方法

参考链接：

- [提问的正确姿势](https://blog.zthxxx.me/posts/Posture-for-Ask-Questions/)
- [让你的提问变得更有意义，做一个受欢迎的提问者](https://www.v2ex.com/t/399324)
- [碰到技术问题时，如何寻求帮助](http://zhangwenli.com/blog/2016/02/19/ask-for-technical-help/)


## License

[![license-badge]][license-link]

<!-- Link -->
[license-badge]:    https://img.shields.io/badge/License-CC%20BY--NC--ND%203.0-blue.svg
[license-link]:     https://creativecommons.org/licenses/by-nc-nd/3.0/cn/

> 本项目的网页设计引用了[WNCG](https://github.com/wncg/recruit-assessment)的项目，在此表示感谢！