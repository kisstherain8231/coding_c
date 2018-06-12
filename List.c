/**
*  单个的链表节点
*  c  practice
*
*/


#include<stdlib.h>
#include<stdio.h>

#define Max 10

struct List
{
    int Number;
    char Name[Max];
    struct List *Next;
};

typedef struct List Node;
typedef Node * Link;


int main () 
{
    Link New;
    int DataNum;
    char DataName[Max];
    int i;
    New = (Link) malloc(sizeof(Node));

    if (New == NULL)
    {
       printf("Memory allocate Failure!!\n");
    } else 
    {
        printf("Please input the DataNum : ");
        scanf("%d", &DataNum);

        printf("Please input the data name : ");
        scanf("%s", DataName);

        New->Number = DataNum;

        for (i = 0; i <= Max; i++)
        {
            New->Name[i] = DataName[i];
        }

        New->Next = NULL;

        printf("##input data##\n");
        printf("Data Number = %d\n", New->Number);
        printf("Data Name : %s\n", New->Name);
        free(New);
    }
}