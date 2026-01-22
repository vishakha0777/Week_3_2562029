#include <stdio.h>
#include <stdlib.h>

//Node structure 
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

//Creating the list
void create() {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to add another node? (1/0): ");
        scanf("%d", &choice);
    }
}

//Insert the node at beginning 
void insertBegin() {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node inserted at beginning.\n");
}

//Display list
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Delete the node at end 
void deleteEnd() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

//Main function 
int main() {
    int choice;

    do {
        printf("\n---- MENU ----\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Display List\n");
        printf("4. Delete at End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            printf("\nBefore Insertion:\n");
            display();
            insertBegin();
            printf("\nAfter Insertion:\n");
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}