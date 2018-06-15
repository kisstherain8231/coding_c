#include<stdli.h>
#include<stdio.h>

struct tree
{   
    struct tree * left;
    int data;
    struct tree * right;
};

typedef struct tree treenode;
typedef struct treenode  * b_tree;


/** 递归的建立二叉树 */
