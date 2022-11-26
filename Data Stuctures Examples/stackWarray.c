#include <stdio.h>
#define SIZE 5
int array[SIZE], top;

void push(int data)//Eleman ekleme
{
    if (top + 1 == SIZE)
    {
        printf("Stack is full");
    }
    else
    {
        top = top + 1;
        array[top] = data;
    }
}
void pop()//eleman cıkar
{
    if (top == -1)
    {
        printf("Free");
    }
    else
    {
        top = top - 1;
    }
}

int peek()//top ı gösterir
{
    return array[top];
}
void print()
{
    int i;
    for (i = 0; i < top + 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("==> TOP");
}

int main()
{
    int choose;
    top = -1;
    while (1==1)
    {
        printf("\n1-Push");
        printf("\n2-Pop");
        printf("\n3-Peek");
        printf("\nChoose");
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