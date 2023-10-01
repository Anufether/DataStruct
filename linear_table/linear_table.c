#include "LinearList.h"
#include <stdio.h>

void init(LinearList *list)
{
    list->size = 0;
}

int insert(LinearList *list, int position, int element)
{
    if (position < 0 || position > list->size || list->size >= MAX_SIZE)
    {
        return 0;
    }

    for (int i = list->size - 1; i >= position; i--)
    {
        list->data[i + 1] = list->data[i];
    }

    list->data[position] = element;
    list->size++;

    return 1;
}

int delete(LinearList *list, int position)
{
    if (position < 0 || position >= list->size)
    {
        return 0;
    }

    for (int i = position; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    list->size--;

    return 1;
}

int get(LinearList *list, int position)
{
    if (position < 0 || position >= list->size)
    {
        return -1;
    }
    return list->data[position];
}

void print(LinearList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}
