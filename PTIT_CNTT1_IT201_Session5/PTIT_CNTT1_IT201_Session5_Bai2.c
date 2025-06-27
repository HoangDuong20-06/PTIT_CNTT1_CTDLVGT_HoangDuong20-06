#include <stdio.h>

int tinhTong(int n) {
    if (n == 0)
        return 0;
    return n + tinhTong(n-1);
}

int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong nhap so am\n");
    } else {
        int sum = tinhTong(n);
        printf("Tong cac so tu 1 den %d la: %d", n,sum);
    }
    return 0;
}