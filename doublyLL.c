#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
int main()
{
    struct node *head, *newnode, *temp;
    head = 0;
    int choice=1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Do you want to continue?if not, press 0 else 1 \n");
        scanf("%d", &choice);
    }
    printf("\nLinked List: ");
    temp = head;
    while (temp != 0)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return 0;
}