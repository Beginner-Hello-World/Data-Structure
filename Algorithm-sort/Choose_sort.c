#include<stdio.h>

void choose_sort(int* arr, int len) {
    if (len < 2) return;
    for (int i = 0; i < len; ++i) {
        int min_index = i;
        int cho = arr[min_index];
        for (int j = i; j < len; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        arr[i] = arr[min_index];
        arr[min_index] = cho;
    }
}
