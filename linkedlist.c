#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
    struct node* last;
} node;

typedef struct list
{
    int size;
    node* last;
} list;

list*
create_list()
{
    list* new_list = (list*)malloc(sizeof(list));
    new_list->size = 0;
    new_list->last = NULL;

    return new_list;
}

void
push(list* l, int new_value)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = new_value;
    new_node->next = l->last;

    l->last = new_node;
    l->size++;
}

void
for_each(list* l, void(*f)(int))
{
    node* current = l->last;
    while (current != NULL)
    {
        (*f)(current->value);
        current = current->next;
    }
}

int
remove_at(list* l, int el) {
    if (el >= l->size || el < 0)
    {
        return 1;
    }

    if (el == l->size - 1)
    {
        node* removing = l->last;
        l->last = removing->next;
        free(removing);
    }

    else
    {
        node* prev = l->last;
        for (int i = 0; i < el - 1; i++) {
            prev = prev->next;
        }
        node* removing = prev->next;
        prev->next = removing->next;
        free(removing);
    }

    l->size--;
    return 0;
}

void
delete_list(list* l)
{
    node* current = l->last;
    while (current != NULL)
    {
        node* next = current->next;
        free(current);
        current = next;
        l->size--;
    }
    free(l);
}

void
print(int n)
{
    printf(" %d ", n);
}

int
main()
{
    list* l = create_list();

    push(l, 4);
    push(l, 3);
    push(l, 2);
    push(l, 1);

    printf("size: %d\n", l->size);

    printf("printing list: ");
    for_each(l, print);

    printf("\nremoving second and third: ");
    printf("%s, ", remove_at(l, 1) == 0 ? "OK" : "ERR");
    printf("%s\n", remove_at(l, 1) == 0 ? "OK" : "ERR");

    printf("attempting to remove third: ");
    printf("%s\n", remove_at(l, 2) == 0 ? "OK" : "ERR");

    printf("printing list: ");
    for_each(l, print);

    delete_list(l);
    printf("\n");
}
