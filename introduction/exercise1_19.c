#include <stdio.h>
#include <limits.h> // 包含 limits.h 头文件以获取 MAXINT 的值

// 阶乘函数，计算 i!
unsigned long long factorial(int i)
{
    if (i <= 1)
    {
        return 1;
    }
    return i * factorial(i - 1);
}

// 计算 i!*2^i 并将结果存入数组 a
void calculateFactorialPower(int n, unsigned long long a[], int arrsize)
{
    for (int i = 0; i < arrsize; i++)
    {
        a[i] = factorial(i) * (1ULL << i); // 使用左移运算符计算2的幂次方
        if (a[i] > ULLONG_MAX / factorial(i))
        {
            // 如果结果超过最大整数限制，则打印错误消息并退出
            printf("计算溢出，无法继续。\n");
            break;
        }
    }
}

int main()
{
    int arrsize = 10; // 数组大小
    unsigned long long a[arrsize];

    calculateFactorialPower(arrsize, a, arrsize);

    // 打印结果
    for (int i = 0; i < arrsize; i++)
    {
        printf("%d!*2^%d = %llu\n", i, i, a[i]);
    }

    return 0;
}
