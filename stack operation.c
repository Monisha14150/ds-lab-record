#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

int main()
{
    int choice, item, i;

    while(1)
    {
        printf("\n***** MENU *****\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(top == SIZE - 1)
                {
                    printf("Stack Overflow\n");
                }
                else
                {
                    printf("Enter the element to push: ");
                    scanf("%d", &item);

                    top++;
                    stack[top] = item;

                    printf("Insertion successfully\n");
                }
                break;

            case 2:
                if(top == -1)
                {
                    printf("Stack Underflow\n");
                }
                else
                {
                    top--;
                    printf("Deletion is successfully\n");
                }
                break;

            case 3:
                if(top == -1)
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    for(i = top; i >= 0; i--)
                    {
                        printf("%d ", stack[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
