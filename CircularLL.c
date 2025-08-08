#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head, *newnode, *temp;
    head = 0;
    int choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue? If not, press 0 else 1: ");
        scanf("%d", &choice);
    }
    if (temp != 0)
        temp->next = head;
    printf("\nCircular Linked List: ");
    temp = head;
    if (head != 0)
    {
        do
        {
            printf("%d->", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("(head)\n");
    return 0;
}
