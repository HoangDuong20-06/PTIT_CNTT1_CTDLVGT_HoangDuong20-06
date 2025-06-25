#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int found = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        if (arr[left] == arr[right]) {
            printf("Cap doi xung: (%d, %d)\n", arr[left], arr[right]);
            found = 1;
        }
        left++;
        right--;
    }
    if (!found) {
        printf("Khong co phan tu doi xung\n");
    }
    return 0;
}