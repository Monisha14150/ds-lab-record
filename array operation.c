#include <stdio.h>
int main()
{
    int a[100], n, i, pos, item, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\n1. Insertion");
    printf("\n2. Deletion");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter position: ");
            scanf("%d", &pos);

            printf("Enter element: ");
            scanf("%d", &item);

            for(i = n; i >= pos; i--)
            {
                a[i] = a[i - 1];
            }

            a[pos - 1] = item;
            n++;

            printf("Array after insertion: ");
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            for(i = pos - 1; i < n - 1; i++)
            {
                a[i] = a[i + 1];
            }

            n--;

            printf("Array after deletion: ");
            break;

        default:
            printf("Invalid choice");
            return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
