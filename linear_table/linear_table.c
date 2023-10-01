#include <stdio.h>
#include <stdlib.h>

// 定义线性表结构
#define MAX_SIZE 100 // 定义线性表的最大容量

typedef struct
{
    int data[MAX_SIZE]; // 用数组存储数据
    int size;           // 当前线性表中元素的个数
} LinearList;

// 初始化线性表
void init(LinearList *list)
{
    list->size = 0;
}

// 在指定位置插入元素
int insert(LinearList *list, int position, int element)
{
    if (position < 0 || position > list->size || list->size >= MAX_SIZE)
    {
        return 0; // 插入位置无效或线性表已满，插入失败
    }

    // 将位置position之后的元素后移一位
    for (int i = list->size - 1; i >= position; i--)
    {
        list->data[i + 1] = list->data[i];
    }

    // 插入元素并更新线性表的大小
    list->data[position] = element;
    list->size++;

    return 1; // 插入成功
}

// 删除指定位置的元素
int delete(LinearList *list, int position)
{
    if (position < 0 || position >= list->size)
    {
        return 0; // 删除位置无效，删除失败
    }

    // 将位置position之后的元素前移一位
    for (int i = position; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    // 更新线性表的大小
    list->size--;

    return 1; // 删除成功
}

// 获取指定位置的元素
int get(LinearList *list, int position)
{
    if (position < 0 || position >= list->size)
    {
        // 返回一个特殊的值表示获取失败
        return -1;
    }
    return list->data[position];
}

// 打印线性表的元素
void print(LinearList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main()
{
    LinearList list;
    init(&list);

    // 插入元素
    insert(&list, 0, 1);
    insert(&list, 1, 2);
    insert(&list, 0, 0);

    // 打印线性表
    printf("线性表元素: ");
    print(&list);

    // 删除元素
    delete (&list, 1);

    // 打印线性表
    printf("删除后的线性表元素: ");
    print(&list);

    // 获取元素
    int element = get(&list, 1);
    if (element != -1)
    {
        printf("第二个元素是: %d\n", element);
    }
    else
    {
        printf("获取元素失败，位置无效。\n");
    }

    return 0;
}
