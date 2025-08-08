#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node *start = 0;

void insert_at_start(int val) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = val;
    node->next = start;
    start = node;
}

void insert_at_end(int val) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = val;
    node->next = 0;
    if (start == 0) {
        start = node;
        return;
    }
    struct Node *ptr = start;
    while (ptr->next != 0) {
        ptr = ptr->next;
    }
    ptr->next = node;
}

void insert_at_position(int val, int pos) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = val;
    if (pos == 1) {
        node->next = start;
        start = node;
        return;
    }
    struct Node *ptr = start;
    for (int i = 1; i < pos - 1 && ptr != 0; i++) {
        ptr = ptr->next;
    }
    if (ptr == 0) {
        printf("Position out of range\n");
        free(node);
    } else {
        node->next = ptr->next;
        ptr->next = node;
    }
}

void delete_from_start() {
    if (start == 0) {
        printf("Nothing to delete\n");
        return;
    }
    struct Node *temp = start;
    start = start->next;
    free(temp);
    printf("Deleted from beginning\n");
}

void delete_from_end() {
    if (start == 0) {
        printf("List is empty\n");
        return;
    }
    if (start->next == 0) {
        free(start);
        start = 0;
        printf("Deleted last node\n");
        return;
    }
    struct Node *prev = 0, *ptr = start;
    while (ptr->next != 0) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = 0;
    free(ptr);
    printf("Deleted from end\n");
}

void delete_from_position(int pos) {
    if (start == 0) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        struct Node *temp = start;
        start = start->next;
        free(temp);
        printf("Deleted from position 1\n");
        return;
    }
    struct Node *prev = 0, *ptr = start;
    for (int i = 1; i < pos && ptr != 0; i++) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == 0) {
        printf("Position not valid\n");
    } else {
        prev->next = ptr->next;
        free(ptr);
        printf("Deleted from position %d\n", pos);
    }
}

void show_list() {
    if (start == 0) {
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = start;
    printf("List: ");
    while (ptr != 0) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\nOptions:\n");
        printf("1.Insert Start  2.Insert End  3.Insert Position  4.Delete Start  5.Delete End  6.Delete Position  7.Show List\n");
        printf("Select: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            insert_at_start(val);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &val);
            insert_at_end(val);
        } else if (choice == 3) {
            printf("Value & Position: ");
            scanf("%d%d", &val, &pos);
            insert_at_position(val, pos);
        } else if (choice == 4) {
            delete_from_start();
        } else if (choice == 5) {
            delete_from_end();
        } else if (choice == 6) {
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_from_position(pos);
        } else if (choice == 7) {
            show_list();
        } else {
            printf("Invalid option\n");
        }
    }
    return 0;
}
