
#include<stdio.h>

void  create_btree(int * b_tree, int *nodelist, int len)
{
    int i;
    int level;

    b_tree[1] = nodelist[1];

    for (i = 2; i <= len; i++)
    {
        level = 1;
        // 找到数据存放位置
        while (b_tree[level] != 0)
        {
            if (nodelist[i] < b_tree[level])
            {
                level = level * 2;
            }
            else
            {
                level = level * 2 + 1;
            }
        }
        b_tree[level] = nodelist[i];
    }

}


int main() 
{
    int i, index;
    int data;
    int b_tree[16];
    int nodelist[16];

    printf("please input the elements of binary tree, (Exit for 0) : \n");

    index = 1;
    scanf("%d", &data);

    while (data != 0)
    {
        nodelist[index] = data;
        index = index + 1;
        scanf("%d", &data);
    }

    for (i = 1; i < 16; i++)
    {
        b_tree[i] = 0;
    }

    create_btree(b_tree, nodelist, index);

    printf("the binary tree is : \n");

    for ( i = 1; i < 16; ++i)
    {
        printf("%2d :  [%d]\n", i, b_tree[i]);
    }
    
    
}