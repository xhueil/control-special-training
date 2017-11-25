# 第五节：标准建立工程的步骤

> 以51单片机建立工程为例

### 一、建立文件夹 
- 1.首先在需要建立工程的目录下，先创建一个文件夹来存放工程的内容，如建立一个 `Template` 文件夹。
  ![](http://upload-images.jianshu.io/upload_images/6757403-5a2cb8cb26dba215.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 2.进入文件夹中再建立索需要的文件夹，如下图：
  ![](http://upload-images.jianshu.io/upload_images/6757403-4191e94596e7dabf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

**文件结构：**

>  **./**  项目主目录  
>  ├── **Documents**  说明文档文件夹，包含声明，更新日志  
>  │  
>  ├── **Hardware**   外接设备驱动文件夹，各外设驱动打包在内各自独立文件夹中  
>  │  
>  ├── **Library**    库文件夹、包含自己实现与平台不管的代码，如算法代码、第三方C库  
>  │  
>  ├── **Listing**    编译链接生成文件夹  
>  │  
>  ├── **Output**     编译输出文件夹，HEX文件在此目录下  
>  │  
>  ├── **Project**    项目工程文件夹，存放工程的文件  
>  │  
>  └── **User**       存放主函数和单片机内设驱动打包在各自独立的文件夹中，如定时器、串口等单片机内部资源

### 二、建立工程
- 1.打开keil软件，新建工程
  ![](http://upload-images.jianshu.io/upload_images/6757403-e1ba22186b63aed5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 2.找到对应文件夹的 `Project` 目录下,文件命名以英文命名，多个单词以驼峰式或者下划线隔开命名
  ![](http://upload-images.jianshu.io/upload_images/6757403-026185879140427d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 3.选择对应单片机的信号
  ![](http://upload-images.jianshu.io/upload_images/6757403-fa965e82c5198285.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 4.创建完成后的目录
  ![](http://upload-images.jianshu.io/upload_images/6757403-7622dc59a518bbd7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 三、为工程添加文件
!> 在建立工程文件及文件夹的时候注意事项：
	- 1.全小写加下划线命名或驼峰式命名（每个单词第一个大写），**限均用一种风格**
	- 2.命名要求用英文命名
	- 3.规范威哥模块做一个子文件夹装着
	- 4.每个 **.c** 文件**对应**一个 **.h** 文件,命名与文件夹名字一样

- 1.在 `User` 目录下创建 `timer`文件夹、`uart`文件夹、 main.c 文件、config.h 文件 等等需要的，再在 `timer` 文件夹下创建timer.c 和 timer.h 文件,在 `uart` 文件夹下创建uart.c 和 uart.h 文件   
  ![](http://upload-images.jianshu.io/upload_images/6757403-bf090accc94b6b75.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 2.再在其他文件夹下添加文件夹及文件，如下：
  ![image.png](http://upload-images.jianshu.io/upload_images/6757403-ab64f8eeb1ea943a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![](http://upload-images.jianshu.io/upload_images/6757403-e635634aa1db070c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
> 在对应的文件夹下创建对应名字的 .c 和 .h 文件

- 3.回到工程中点击图上按钮进入此界面，这里更改项目显示目录结构
  ![image.png](http://upload-images.jianshu.io/upload_images/6757403-16823f0a5e74303d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
> 更改之后的结构
> ![image.png](http://upload-images.jianshu.io/upload_images/6757403-cd1edc5fc739085b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![](http://upload-images.jianshu.io/upload_images/6757403-2185664b210e9f83.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 4.再次进入添加每个目录下的文件
  ![](http://upload-images.jianshu.io/upload_images/6757403-4356e72056e7d748.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

> 一般添加.c文件，如果某个.h文件用得多也可以添加进来

>添加之后的目录：
>![](http://upload-images.jianshu.io/upload_images/6757403-41d7cfff43ee2a28.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 四、更改一些配置 
- 1.更改输出文件的目录
  ![](http://upload-images.jianshu.io/upload_images/6757403-c430cc41751bce4b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 2. 同理更改链接输出文件
    ![image.png](http://upload-images.jianshu.io/upload_images/6757403-a2c54347ff297e43.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

!>现在编译
![](http://upload-images.jianshu.io/upload_images/6757403-c32874710b72150d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
?> 编译报错，找不到对应的文件

- 3. 还需要添加头文件所在的目录**（很重要）**
    点击开魔术棒，进入
    ![](http://upload-images.jianshu.io/upload_images/6757403-0f4f475d6948cf44.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
> 添加所有含有头文件的目录
> ![image.png](http://upload-images.jianshu.io/upload_images/6757403-5d5f65f8a31de454.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
> 再次编译通过
> ![](http://upload-images.jianshu.io/upload_images/6757403-4ed5c51849c8d68c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 4. 注意勾选输出HEX文件选项。
    ![image.png](http://upload-images.jianshu.io/upload_images/6757403-c81c2ca9d848333c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

> 接下来就可以向每个文件中添加内容了。。。。。

