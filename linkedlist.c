#include <stdio.h>
#include <stdlib.h>
// creating the nodes
typedef struct node
{
    int value;
    struct node *next;
    struct node *before;
} node;
// creating the list
typedef struct list
{
    int len;
    node *first;
    node *last;
} list;
// function append
void append(struct list *vect, int k)
{
    if (vect->len == 0)
    {
        vect->first = (struct node *)malloc(sizeof(struct node));
        vect->first->value = k;
        vect->last = vect->first;
        vect->len++;
        vect->last->next = NULL;
    }
    else
    {
        vect->last->next = (struct node *)malloc(sizeof(struct node));
        vect->last->next->before = vect->last;
        vect->last = vect->last->next;
        vect->last->value = k;
        vect->len++;
        vect->last->next = NULL;
    }
}
// function pop
void pop(struct list *vect)
{
    if (vect->len > 0)
    {
        if (vect->len == 1)
        {
            vect->first = NULL;
        }
        else
        {
            if (vect->len > 1)
            {
                vect->last = vect->last->before;
            }
            vect->last->next = NULL;
        }
        vect->len--;
    }
}
// function delete
void delete(list *vect, int k)
{
    struct node *n = vect->first;
    int l = vect->len;
    for (int i = 0; i < l; i++)
    {
        if (n->value == k)
        {
            if (n == vect->first)
            {    
                if (n == vect->last)
            {
                vect->last = NULL;
                vect->first = NULL;
                vect->len = 0;
                return;
            }
                vect->first = n->next;
                vect->first->before = NULL;
                vect->len--;
            }
            else {
            if (n == vect->last)
            {
                vect->last = vect->last->before;
                vect->last->next = NULL;
                vect->len--;
                return;
            }
            vect->len--;
            n->before->next = n->next;
            n->next->before = n->before;
        }}
        n = n->next;
    }
}
// function show to print the elements of the list
void show(struct list *vect)
{
    struct node *n = vect->first;
    while (n != NULL)
    {
        printf("%d ", n->value);
        n = n->next;
    }
}
