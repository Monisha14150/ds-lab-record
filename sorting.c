#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at End
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

// Sorting in Ascending Order
void sort()
{
    struct node *temp, *last;
    int swap;

    if(head == NULL)
    {
        printf("Linked List is Empty!\n");
        return;
    }

    for(last = NULL; last != head; last = temp)
    {
        for(temp = head; temp->next != last; temp = temp->next)
        {
            if(temp->data > temp->next->data)
            {
                swap = temp->data;
                temp->data = temp->next->data;
                temp->next->data = swap;
            }
        }
    }

    printf("Linked List sorted successfully.\n");
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

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- LINKED LIST SORTING ---\n");
        printf("1. Insert\n");
        printf("2. Sort\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                sort();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
