#include <stdio.h>
#include <string.h> // 包含字符串操作函数的头文件

// 高等院校
struct University
{
    char projectName[100];
    char gender[20];
    char schoolName[100];
    float grade;
    int score;
};

int main()
{
    // 创建5个结构体数组
    struct University universities[5];

    // 循环给结构体字段赋值
    for (int i = 0; i < 5; i++)
    {
        sprintf(universities[i].projectName, "Project %d", i + 1);
        sprintf(universities[i].gender, "Gender %d", i + 1);
        sprintf(universities[i].schoolName, "School %d", i + 1);
        universities[i].grade = 90.5 + i;
        universities[i].score = 95 + i;
    }

    // 打印表头
    printf("项目名称\t性别\t校名\t成绩\t得分\n");

    // 循环打印结构体内容
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t%s\t%s\t%.2f\t%d\n", universities[i].projectName,
               universities[i].gender,
               universities[i].schoolName,
               universities[i].grade,
               universities[i].score);
    }

    return 0;
}
