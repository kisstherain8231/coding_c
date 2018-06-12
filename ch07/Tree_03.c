#include<stdlib.h>
#include<stdio.h>

struct tree
{
    struct tree * left;
    int data;
    struct tree * right;
};

typedef struct tree treenode;
typedef treenode * b_tree;

b_tree  insert_node(b_tree root, int node)
{
    b_tree newnode;
    b_tree currentnode;
    b_tree parentnode;

    newnode = (b_tree)malloc(sizeof(treenode));

    newnode->data = node;
    newnode->right = NULL;
    newnode->left= NULL;

    if (root == NULL)
    {
        return newnode;
    }
    else
    {
        currentnode = root;

        while (currentnode != NULL)
        {
            parentnode = currentnode;

            if (currentnode->data > node)
            {
                currentnode = currentnode->left;
            } 
            else
            {
                currentnode = currentnode->right;
            }
        }

        if (parentnode->data > node)
        {
            parentnode->left = newnode;
        }
        else
        {
            parentnode->right = newnode;
        }

        return root;
    }
}


/** 建立二叉树 */

b_tree create_btree(int * data, int len)
{
    b_tree root = NULL;
    int i = 0;

    for (i = 0; i < len; i++)
    {
        root = insert_node(root, data[i]);
    }

    return root;
}


void print_bree(b_tree root)
{
    b_tree pointer;

    pointer = root->left;
    printf("Print  left_subtree node of root:\n");

    while (pointer != NULL)
    {
        printf("[%2d]\n", pointer->data);
        pointer = pointer->left;
    }

    pointer = root->right;
    printf("Print  right_subtree node of root:\n");

    while (pointer != NULL)
    {
        printf("[%2d]\n", pointer->data);
        pointer = pointer->right;
    }

}


int main ()
{
    b_tree root = NULL;
    int i, index;
    int value;
    int nodelist[20];

    printf("\n Please input the elements of binary tree(Exit for0):\n");

    index = 0;

    scanf("%d", &value);

    while (value != 0)
    {
        nodelist[index] = value;
        index = index + 1;
        scanf("%d", &value); 
    }
    /** */
    root = create_btree(nodelist, index);

    print_bree(root);
}





