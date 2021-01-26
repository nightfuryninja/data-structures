#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList *linked_list_init(void)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list != NULL)
    {
        list -> head = NULL;
        list -> tail = NULL;
        return list;
    }
    fprintf(stderr, "Failed to allocate memory for linked list.\n");
    return NULL;
}

Node *node_init(void)
{
    Node *node = malloc(sizeof(Node));
    if (node != NULL)
    {
        node -> next = NULL;
        node -> prev = NULL;
        node -> data = NULL;
        return node;
    }
    fprintf(stderr, "Failed to allocate memory for node.\n");
    return NULL;
}

void linked_list_prepend(LinkedList *list, void *data)
{
    Node *newNode;
    if(list == NULL)
    {
        fprintf(stderr, "Cannot append to null list.\n");
        return;
    }

    newNode = node_init();
    newNode -> next = list -> head;
    newNode -> data = data;

    if(list -> tail == NULL)
    {
        list -> tail = newNode;
    }
    else
    {
        list -> head -> prev = newNode;
    }
    
    list -> head = newNode;
}

void linked_list_append(LinkedList *list, void *data)
{
    Node *newNode;
    if(list == NULL)
    {
        fprintf(stderr, "Cannot append to null list.\n");
        return;
    }

    newNode = node_init();
    newNode -> data = data;
    newNode -> prev = list -> tail;
    
    if(list -> head == NULL)
    {
        list -> head = newNode;
    }
    else
    {
        list -> tail -> next = newNode;
    }

    list -> tail = newNode;
}

void linked_list_remove_head(LinkedList *list)
{
    Node *head;
    if(list == NULL)
    {
        fprintf(stderr, "Cannot remove head of null list.\n");
        return;
    }

    head = list -> head;
    list -> head = head -> next;

    if(list -> tail == head)
    {
        list -> tail = head -> next;
    }

    free(head);
}

void linked_list_remove_tail(LinkedList *list)
{
    Node *tail;
    if(list == NULL)
    {
        fprintf(stderr, "Cannot remove tail of null list.\n");
        return;
    }

    tail = list -> tail;
    if(tail == NULL)
    {
        fprintf(stderr, "Cannot remove tail of empty list.\n");
        return;
    }

    if(list -> head == tail)
    {
        list -> head = NULL;
    }
    else
    {
        list -> tail -> prev -> next = NULL;
    }
    
    list -> tail = tail -> prev;
    free(tail);
}

void linked_list_free(LinkedList *list)
{
    Node *node;
    if(list == NULL)
    {
        fprintf(stderr, "Cannot free null list.\n");
        return;
    }

    node = list -> head;
    while(node != NULL)
    {
        linked_list_remove_head(list);
        node = list -> head;
    }
    free(list);
}

void node_free(Node *node)
{
    if(node == NULL)
    {
        fprintf(stderr, "Cannot free null pointer.\n");
        return;
    }
    free(node);
}