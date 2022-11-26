#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *q = NULL;
void addend(int data2)
{
    struct node *add = (struct node *)malloc(sizeof(struct node));
    add->data = data2;
    add->next = NULL;
    if (start == NULL)
    {
        start = add;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = add; 
    }
}
void addBegin(int first)
{
    struct node *addfirst = (struct node *)malloc(sizeof(struct node));
    addfirst->data = first;
    addfirst->next = start;
    start = addfirst;
}
void print()
{
    q = start;
    while (q->next != NULL)
    {
        printf("%d =>", q->data);
        q = q->next;
    }
    printf("%d", q->data);
}
/*for add last of linked list*/
int main()
{
    int choose, counter = 0;
    while (choose != -1)
    {
        printf("\nEnter a int...: ");
        scanf("%d", &choose);
        addend(choose);
        print();
        counter += 1;
    }
    printf("\nLength of linked list: %d", counter - 1);
    return 0;
}

// for add begin of linked list
/*int main()
{
    int choose2, last, begin;
    while (1)
    {
        printf("\n1-Add End of list: ");
        printf("\n2-Add Begin of list: ");
        printf("\n Do you wanna add element begin or end of linked list\n");
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
            printf("\n Please enter the num which you want for end: ");
            scanf("%d", &last);
            addend(last);
            print();
            break;
        case 2:
            printf("\n Please enter the num which you want for begin: ");
            scanf("%d", &begin);
            addBegin(begin);
            print();
            break;
        }
    return 0;
}
    }*/