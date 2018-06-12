/**
*
*
*/


#include<stdlib.h>

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
    new = (Link)   malloc(sizeof(Node));

    if (new == NULL)
    {
       printf("Memory allocate Failure!!\n");
    } else 
    {
        printf("Please input the DataNum : ");
        scanf("%d", &DataNum);
        printf("Please input the data name : ");

        scanf("%s", DataNum);
        New->DataNum = DataNum;

        for (i = 0; i <= Max; i++)
        {
            New->Name[i] = DataName[i];
        }

        New->Next = NULL;

        printf("##input data##\n");
        printf("Data Number = %d\n", New->DataNum);
        printf("Data Name : %s", New->Name);
        free(New);
    }
}