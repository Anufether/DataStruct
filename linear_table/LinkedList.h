#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} LinkedList;

void init(LinkedList *list);
int insert(LinkedList *list, int position, int element);
int delete (LinkedList *list, int position);
int get(LinkedList *list, int position);
void print(LinkedList *list);

#endif
