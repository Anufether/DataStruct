#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -1

int fibonacci(int k, int n)
{
    if (k < 1)
        exit(OVERFLOW);

    int *p = (int *)malloc((k + 1) * sizeof(int));
    int x;

    if (p == NULL)
    {
        return OVERFLOW;
    }

    int i, j;

    // 初始化p数组，将前k个元素都设置为0
    for (i = 0; i < k; i++)
    {
        p[i] = 0;
    }
    p[k] = 1; // 设置第k个元素为1

    for (i = k + 1; i < n + 1; i++)
    {
        x = p[0];
        for (j = 0; j < k; j++)
            p[j] = p[j + 1];
        p[k] = 2 * p[k - 1] - x;
    }

    int result = p[k];

    // 释放分配的内存块
    free(p);

    return result;
}

int main()
{
    int k, n;

    printf("请输入k和n的值：");
    scanf("%d %d", &k, &n);

    int result = fibonacci(k, n);

    if (result == OVERFLOW)
        printf("内存分配失败\n");
    else
        printf("第 %d 个斐波那契数列中的第 %d 项是：%d\n", n, k, result);

    return 0;
}
