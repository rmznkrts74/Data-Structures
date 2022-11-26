#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node* top = NULL;

void push(int veri)
{
    struct node *adding = (struct node *)malloc(sizeof(struct node));
    adding->data = veri;
    adding->next = NULL;
    if (top != NULL)
    {
        adding->next = top;
    }
    top = adding;
}

void pop()
{
    if (top->data == NULL)
    {
        printf("free");
    }
    else
    {
        struct node *temp;
        temp = top;
        top = top->next;
        free(temp);
    }
}
int peek()
{
    return top->data;
}
void print()
{
    struct node *q;
    q = top;
    printf("\n");
    while (q != NULL)
    {
        printf(" %d =>", q->data);
        q = q->next;
    }
    printf("NULL ");
}
int main()
{
    int choose;
    while (1 == 1)
    {
        printf("\n1-Push");
        printf("\n2-Pop");
        printf("\n3-Peek");
        printf("\nChoose: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &choose);
            push(choose);
            print();
            break;
        case 2:
            pop();
            print();
            break;
        case 3:
            printf("\n Top is => %d", peek());
            break;
        }
    }
    return 0;
}