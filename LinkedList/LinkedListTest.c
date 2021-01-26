#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(LinkedList *list)
{
    Node *node;
    node = list -> head;
    while(node)
    {
        fprintf(stdout, "%s\n", ((char *)node -> data));
        node = node -> next;
    }
}

int main(int argc, char const *argv[])
{
    LinkedList *list = linked_list_init();
    linked_list_append(list, "test");
    linked_list_append(list, "test2");
    linked_list_append(list, "test3");
    linked_list_remove_tail(list);
    print_list(list);
    return 0;
}
