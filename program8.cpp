#include <stdio.h>
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target was found
        }
    }
    return -1; // Return -1 if the target was not found
}
int main() {
    int arr[] = {10, 5, 8, 20, 15, 25, 12, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);
    int index = linearSearch(arr, size, target);
    if (index != -1) {
        printf("Number %d found at index %d.\n", target, index);
    } else {
        printf("Number %d not found in the array.\n", target);
    }
    return 0;
}
