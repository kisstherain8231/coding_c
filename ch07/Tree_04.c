
/**
*   gcc -g -o Tree_04.exe   Tree_04.c
*
*/

#include<stdlib.h>
#include <stdio.h>

struct tree
{
    struct  tree * left;
    int data;
    struct tree * right;
};

typedef struct tree treenode;
typedef treenode  * b_tree;


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


b_tree create_btree(int * data, int len)
{
    b_tree root = NULL;

    int i;

    for (i = 0; i < len; i++)
    {
        root = insert_node(root, data[i]);
    }

    return root;
}


void preorder(b_tree point)
{
    if (point != NULL)
    {
        printf("%d  ", point->data);
        preorder(point->left);
        preorder(point->right);
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

    printf("\n the preorder traveral result is (");
    preorder(root);
    printf(")\n");
}

