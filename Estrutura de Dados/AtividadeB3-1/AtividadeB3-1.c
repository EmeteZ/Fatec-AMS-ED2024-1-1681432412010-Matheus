#include <stdio.h>


void insertion_sort(int arr[], int n) {
    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;

      
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}


void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int A[] = {10, 21, 5, 12, 6};
    int n = sizeof(A) / sizeof(A[0]);

    insertion_sort(A, n);
    print_array(A, n);

    return 0;
}
