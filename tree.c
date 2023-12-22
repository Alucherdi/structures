#include <stdio.h>
#include <stdlib.h>

#define LEFT   0
#define RIGHT  1

typedef struct node
{
    int value;
    struct node* right;
    struct node* left;
} node;

typedef struct tree
{
    node* head;
} tree;

tree*
create_tree()
{
    tree* new_tree = (tree*)malloc(sizeof(tree));
    new_tree->head = (node*)malloc(sizeof(node));
    new_tree->head->left = NULL;
    new_tree->head->right = NULL;

    return new_tree;
}

int
push_to(node* n, int value, int side)
{
    node* new_node = (node*)malloc(sizeof(node));

    new_node->value = value;
    new_node->left  = NULL;
    new_node->right = NULL;

    if (n == NULL)
    {
        n = (node*)malloc(sizeof(node));
        n->left = NULL;
        n->right = NULL;
    }

    switch(side)
    {
        case LEFT:
            n->left = new_node;
            break;
        case RIGHT:
            n->right = new_node;
            break;
        default:
            return 1;
            break;
    }

    return 0;
}

void
print_tree(node* n)
{

    if (n->left != NULL)
        print_tree(n->left);

    printf("%d\n", n->value);

    if (n-> right != NULL)
        print_tree(n->right);
}

void
delete_nodes(node* n)
{
    if (n->left != NULL)
        delete_nodes(n->left);

    if (n->right != NULL)
        delete_nodes(n->right);

    free(n);
}

void
delete_tree(tree* t)
{
    delete_nodes(t->head);
    free(t);
}

int
main()
{
    tree* t = create_tree();
    printf("tree created\n");
    
    printf("%d\n",   push_to(t->head, 1, LEFT));
    printf("%d\n",   push_to(t->head, 3, RIGHT));
    printf("%d\n",   push_to(t->head->left, 2, LEFT));
    printf("%d\n\n", push_to(t->head->left, 4, RIGHT));

    print_tree(t->head);

    delete_tree(t);
}
