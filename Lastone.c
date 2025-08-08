#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = 0;
void insert_First(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = 0;
    newnode->next = head;
    if (head != 0)
        head->prev = newnode;
    head = newnode;
}
void insert_End(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = 0;
    if (head == 0)
    {
        newnode->prev = 0;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != 0)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}
void insert_Position(int val, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    if (pos == 1)
    {
        newnode->prev = 0;
        newnode->next = head;
        if (head != 0)
            head->prev = newnode;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        int i;
        for (i = 1; i < pos - 1 && temp != 0; i++)
            temp = temp->next;
        if (temp != 0)
        {
            newnode->next = temp->next;
            newnode->prev = temp;
            if (temp->next != 0)
                temp->next->prev = newnode;
            temp->next = newnode;
        }
        else
        {
            printf("Invalid position\n");
            free(newnode);
        }
    }
}
void delete_First()
{
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        if (head != 0)
            head->prev = 0;
        free(temp);
        printf("Deleted from first\n");
    }
}
void delete_End()
{
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else if (head->next == 0)
    {
        free(head);
        head = 0;
        printf("Deleted last node\n");
    }
    else
    {
        struct node *temp = head;
        while (temp->next != 0)
            temp = temp->next;
        temp->prev->next = 0;
        free(temp);
        printf("Deleted from end\n");
    }
}
void delete_Position(int pos)
{
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        struct node *temp = head;
        head = head->next;
        if (head != 0)
            head->prev = 0;
        free(temp);
        printf("Deleted from position 1\n");
    }
    else
    {
        struct node *temp = head;
        int i;
        for (i = 1; i < pos && temp != 0; i++)
            temp = temp->next;
        if (temp == 0)
        {
            printf("Invalid position\n");
        }
        else
        {
            if (temp->prev != 0)
                temp->prev->next = temp->next;
            if (temp->next != 0)
                temp->next->prev = temp->prev;
            free(temp);
            printf("Deleted from position %d\n", pos);
        }
    }
}
void displayList()
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int s, val, pos;
    while (1)
    {
        printf("\n1.Insert First |2.Insert End |3.Insert Position |4.Delete First |5.Delete End |6.Delete Position |7.Display List\n");
        printf("Enter choice: ");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert_First(val);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insert_End(val);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_Position(val, pos);
            break;
        case 4:
            delete_First();
            break;
        case 5:
            delete_End();
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            delete_Position(pos);
            break;
        case 7:
            displayList();
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}