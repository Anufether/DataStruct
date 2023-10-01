#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void init(LinkedList *list)
{
    list->head = NULL;
    list->size = 0;
}

int insert(LinkedList *list, int position, int element)
{
    if (position < 0 || position > list->size)
    {
        return 0;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return 0; // Memory allocation failed
    }

    newNode->data = element;

    if (position == 0)
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    else
    {
        Node *current = list->head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list->size++;

    return 1;
}

int delete(LinkedList *list, int position)
{
    if (position < 0 || position >= list->size || list->head == NULL)
    {
        return 0;
    }

    Node *temp;
    if (position == 0)
    {
        temp = list->head;
        list->head = list->head->next;
    }
    else
    {
        Node *current = list->head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }

    free(temp);
    list->size--;

    return 1;
}

int get(LinkedList *list, int position)
{
    if (position < 0 || position >= list->size || list->head == NULL)
    {
        return -1;
    }

    Node *current = list->head;
    for (int i = 0; i < position; i++)
    {
        current = current->next;
    }

    return current->data;
}

void print(LinkedList *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
