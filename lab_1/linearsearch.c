#include <stdio.h>

int main() {
    int arr[] = {5, 3, 7, 1, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int index = -1;  // To store the found index, -1 means not found

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i;
            break;  // Stop searching once found
        }
    }

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
