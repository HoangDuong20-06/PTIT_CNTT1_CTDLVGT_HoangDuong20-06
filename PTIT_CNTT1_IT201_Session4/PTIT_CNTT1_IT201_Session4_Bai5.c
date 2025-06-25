#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        }else if (arr[mid] < x) {
            left = mid + 1;
        }else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n,x;
    int arr[100];
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    printf("Nhap phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang hien co: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);
    printf("Mang sau khi duoc sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &x);
    int find = binarySearch(arr, n, x);
    if (find != -1) {
        printf("Phan tu co trong mang");
    }else {
        printf("Khong co phan tu trong mang");
    }
    return 0;
}