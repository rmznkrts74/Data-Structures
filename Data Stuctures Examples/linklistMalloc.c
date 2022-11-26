#include <stdio.h>
#include <stdlib.h> //for malloc
// structure of node
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *firstnode = NULL;
    firstnode = (struct node *)malloc(sizeof(struct node));
    struct node *secondnode = (struct node *)malloc(sizeof(struct node));
    firstnode->data = 15;
    firstnode->next = secondnode;
    secondnode->data = 20;
    secondnode->next = NULL;
    printf("%d => %d", firstnode->data, secondnode->data);//değerleri yazdırır
    printf("\n");
    printf("%d => %d", firstnode->next, secondnode->next);//adresleri pointer içindeki adresleri yazdırır

    return 0;
}