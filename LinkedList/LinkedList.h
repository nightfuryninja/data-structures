#ifndef LINKEDLISTH
#define LINKEDLISTH

typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    void *data;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
} LinkedList;

LinkedList *linked_list_init(void);
Node *node_init(void);
void linked_list_prepend(LinkedList *list, void *data);
void linked_list_append(LinkedList *list, void *data);
void linked_list_remove_head(LinkedList *list);
void linked_list_remove_tail(LinkedList *list);
void linked_list_free_list(LinkedList *list);
void linked_list_free_node(Node *node);

#endif