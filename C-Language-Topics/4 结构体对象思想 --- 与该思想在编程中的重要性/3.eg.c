/*===============================================================
 *   文件名称：di1.c
 *   创 建 者：ruby
 *   创建日期：2017年11月12日
 ================================================================*/

#include<stdio.h>

#define NUM 10
struct stu {
	char name[30];
	int    number;
	int    grade ;
};
/*结构体初始化*/
void student_init (struct stu student[],int len) 
{
	int i;
	for(i=0;i<len;i++)
	{
		sprintf(student[i].name,"name%d",i);
		student[i].number = i;
		student[i].grade = i * 10;
	}
}
/*找到成绩最好的学生，并返回该对象*/
struct stu*  find_best_grade(struct stu student[],int len)         //由于使用的是结构体数组，所有要传入数组长度
{
	int i;
	struct stu *PtrRet;
	int GradeMax = 0;
	for(i=0;i<len;i++)
	{
		if( student[i].grade > GradeMax  )
		{
			PtrRet =  &student[i];
			GradeMax =  student[i].grade;
		}			
	}
	return PtrRet ;
}
int main()
{
	struct stu  student[NUM ];
	struct stu *PtrStu;
	student_init(student,NUM) ;
	PtrStu =  find_best_grade(student,NUM);
	printf("name = %s,number = %d,grade = %d\n",(*PtrStu).name,(*PtrStu).number,(*PtrStu).grade);   //将成绩最好的学生信息打印出来
	return 0;
}
