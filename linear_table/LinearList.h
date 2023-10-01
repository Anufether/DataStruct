#ifndef LINEARLIST_H
#define LINEARLIST_H

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int size;
} LinearList;

void init(LinearList *list);
int insert(LinearList *list, int position, int element);
int delete(LinearList *list, int position);
int get(LinearList *list, int position);
void print(LinearList *list);

#endif
