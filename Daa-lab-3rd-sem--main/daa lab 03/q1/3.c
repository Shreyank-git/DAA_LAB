#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax findMinMax(int arr[], int low, int high) {

    MinMax result, left, right;

    // Case 1: Only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];

        return result;
    }

    // Case 2: Two elements
    if (high == low + 1) {

        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        }
        else {
            result.min = arr[high];
            result.max = arr[low];
        }

        return result;
    }
    
    // Divide
    int mid = low + (high - low) / 2;

    // Conquer
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Combine - find minimum
    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    // Combine - find maximum
    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main() {

    int arr[] = {12, 5, 7, 19, 3, 25, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax result = findMinMax(arr, 0, n - 1);

    printf("Minimum = %d\n", result.min);
    printf("Maximum = %d\n", result.max);

    return 0;
}