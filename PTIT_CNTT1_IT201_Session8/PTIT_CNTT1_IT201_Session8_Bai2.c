#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main() {
    int n;
    int search;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("Gia tri n khong hop le!\n");
        return 1;
    }
    int arr[n];
    printf("Nhap %d phan tu tang dan:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);
    int result = binarySearch(arr, 0, n - 1, search);
    if (result != -1)
        printf("Phan tu vi tri thu %d\n", result + 1);
    else
        printf("Khong ton tai phan tu\n");
    return 0;
}