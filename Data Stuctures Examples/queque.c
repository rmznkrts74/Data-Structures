#include <stdio.h>
#define SIZE 5

int que[SIZE], front = -1, rear = -1; // front en öndeki eleman rear en arkadaki
void enQueue(int data)
{
    if (rear == SIZE)
    {
        printf("FULL");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear = rear + 1;
        que[rear] = data;
    }
}
void deQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Free");
        front = -1;
        rear = -1;
    }
    else
    {
        front = front + 1;
    }
}
void print()
{
    int i;
    for (i = front; i <= rear; i++)
    {
        printf("%d ", que[i]);
    }
}
int main()
{
    int choose;
    while (1 == 1)
    {
        printf("\n1-enQueue");
        printf("\n2-deQueue");
        printf("\nChoose: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &choose);
            enQueue(choose);
            print();
            break;
        case 2:
            deQueue();
            print();
            break;
        }
    }

    return 0;
}
