#include <stdio.h>
#include "LinearList.h"

int main()
{
    LinearList list;
    init(&list);

    insert(&list, 0, 1);
    insert(&list, 1, 2);
    insert(&list, 2, 3);
    insert(&list, 3, 4);
    insert(&list, 4, 5);

    printf("线性表元素: ");
    print(&list);

    delete(&list, 1);

    printf("删除后的线性表元素: ");
    print(&list);

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
