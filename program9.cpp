#include <stdio.h>
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Return the index where the target was found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if the target was not found
}
int main() {
    int arr[] = {3, 6, 8, 12, 15, 20, 25, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);
    int index = binarySearch(arr, size, target);
    if (index != -1) {
        printf("Number %d found at index %d.\n", target, index);
    } else {
        printf("Number %d not found in the array.\n", target);
    }
    return 0;
}
