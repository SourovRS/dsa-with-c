#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(8);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(12);
    struct node *p3 = createNode(10);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      8
    //     / \
    //    2   12
    //   / \
    //  10   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);
    return 0;
}