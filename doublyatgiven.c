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
        printf("Do you want to continue?if not, press 0 else 1 \n");
        scanf("%d", &choice);
    }

    printf("Do you want to insert at any position?if not press 0 else 1 \n");
    int x;
    scanf("%d", &x);
    if (x == 1)
    {
        int pos, i = 1;
        printf("Enter the position you want to insert at: ");
        scanf("%d", &pos);
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data you want to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;

        if (pos == 1)
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else
        {
            temp = head;
            while (i < pos - 1 && temp != 0)
            {
                temp = temp->next;
                i++;
            }
            if (temp == 0)
            {
                printf("Invalid position\n");
            }
            else
            {
                newnode->next = temp->next;
                newnode->prev = temp;
                if (temp->next != 0)
                    temp->next->prev = newnode;
                temp->next = newnode;
            }
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
