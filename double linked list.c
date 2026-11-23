
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at Beginning
void insert_begin()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Node inserted at beginning.\n");
}

// Insert at End
void insert_end()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted at end.\n");
}

// Insert at Specific Position
void insert_position()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1)
    {
        insert_begin();
        return;
    }

    temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Node inserted successfully.\n");
}

// Delete at Beginning
void delete_begin()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

// Delete at End
void delete_end()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev == NULL)
        head = NULL;
    else
        temp->prev->next = NULL;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

// Delete at Specific Position
void delete_position()
{
    struct node *temp;
    int pos, i;

    if(head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    temp = head;

    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

// Display
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List: NULL <-> ");

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_position();
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                delete_position();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
