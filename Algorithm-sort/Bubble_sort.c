include<stdio.h>
//bubble sort
void bubble_sort(int* arr, int len) {
    if (len < 2) return;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tem = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tem;
            }
        }

    }
}
