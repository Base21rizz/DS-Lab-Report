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
    int choice = 1;

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
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to continue? If not, press 0 else 1: ");
        scanf("%d", &choice);
    }

    printf("Do you want to delete from the beginning? Press 1 for yes, 0 for no: ");
    int x;
    scanf("%d", &x);
    if (x == 1)
    {
        if (head == 0)
        {
            printf("List is already empty.\n");
        }
        else
        {
            temp = head;
            head = head->next;
            if (head != 0)
                head->prev = 0;
            free(temp);
            printf("Node deleted from the beginning.\n");
        }
    }

    printf("\nLinked List: ");
    temp = head;
    while (temp != 0)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
