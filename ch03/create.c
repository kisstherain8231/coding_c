/*
* 创建链表
*/

#include<stdlib.h>
#include<stdio.h>

#define Max  10

struct List
{
    int Number;
    char Name[Max];
    struct  List * Next;
};

typedef struct List Node;
typedef Node * Link;


void Free_List(Link Head) 
{
    Link Pointer;

    while (Head != NULL)
    {
        Pointer = Head;
        Head = Head->Next;
        free(Pointer);
    }

}
/**
* 打印list 
*/
void Print_List(Link Head) 
{
    Link Pointer;
    Pointer  = Head;

    while (Pointer != NULL) 
    {
        printf("##Input Data ##\n");
        printf("Data Number : %d\n", Pointer->Number);
        printf("Data Name : %s\n", Pointer->Name);
        Pointer = Pointer->Next;
    }
}

/**
*  建立链表
*/
Link Create_List(Link Head)
{
    int DataNum;
    char DataName[Max];
    Link New;
    Link Pointer;
    int i;

    Head = (Link)malloc(sizeof(Node));

    if ( Head == NULL)
    {
        printf("Memory allocate failer \n");
    }
    else
    {
        DataNum = 1;
        printf("Please input the data name \n");
        scanf("%s", DataName);
        Head->Number = DataNum;

        for (i = 0; i <= Max; ++i)
        {
            Head->Name[i] = DataName[i];
        }

        Pointer = Head;

        while (1)
        {
            DataNum++;
            New = (Link) malloc(sizeof(Node));
            printf("Please input the data name : \n");
            scanf("%s", DataName);

            if (DataName[0] == '0')
            {
                break;
            }

            New->Number = DataNum;
            for (i = 0; i <= Max; ++i)
            {
                New->Name[i] = DataName[i];
            }

            New->Next = NULL;
            Pointer->Next = New;
            Pointer = New;
        }
    }


    return Head;
}


/**
* 主函数
*/
int main ()
{
    Link Head;
    Head = Create_List(Head);

    if (Head != NULL)
    {
        Print_List(Head);
        Free_List(Head);
    }
}



