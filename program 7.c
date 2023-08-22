#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int arr[MAX_SIZE];
    int size = 0;
    printf("Array Operations Menu:\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Display the array\n");
    printf("4. Exit\n");
    int choice;
    do {
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (size < MAX_SIZE) {
                    int position, element;
                    printf("Enter position to insert (0-%d): ", size);
                    scanf("%d", &position);

                    if (position < 0 || position > size) {
                        printf("Invalid position. Please enter a valid position.\n");
                    } else {
                        printf("Enter the element to insert: ");
                        scanf("%d", &element);{
                        for (int i = size; i > position; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[position] = element;
                        size++;
                        printf("Element inserted successfully.\n");
                    }}
                } else {
                    printf("Array is full. Cannot insert more elements.\n");
                }
                break;
            case 2:
                if (size > 0) {
                    int position;
                    printf("Enter position to delete (0-%d): ", size - 1);
                    scanf("%d", &position);
                    if (position < 0 || position >= size) {
                        printf("Invalid position. Please enter a valid position.\n");
                    } else {
                        for (int i = position; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Element deleted successfully.\n");
                    }
                } else {
                    printf("Array is empty. Cannot delete elements.\n");
                }
                break;
            case 3:
                if (size > 0) {
                    printf("Array elements: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("Array is empty.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);
    return 0;
}

