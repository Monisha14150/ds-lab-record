
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Delete at Beginning
void delete_begin()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("Linked List is Empty!\n");
    }
    else
    {
        temp = head;
        head = head->next;

        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

// Delete at End
void delete_end()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("Linked List is Empty!\n");
    }
    else if(head->next == NULL)
    {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        printf("Deleted element: %d\n", temp->data);

        prev->next = NULL;
        free(temp);
    }
}

// Delete at Specific Position
void delete_position()
{
    struct node *temp, *prev;
    int pos, i;

    if(head == NULL)
    {
        printf("Linked List is Empty!\n");
        return;
    }

    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1)
    {
        delete_begin();
        return;
    }

    temp = head;

    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position!\n");
    }
    else
    {
        prev->next = temp->next;

        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

// Display
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("Linked List is Empty!\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at End (For creating the list)
void insert()
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
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Node inserted successfully.\n");
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- SINGLY LINKED LIST DELETION ---\n");
        printf("1. Insert\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Specific Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_begin();
                break;

            case 3:
                delete_end();
                break;

            case 4:
                delete_position();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
