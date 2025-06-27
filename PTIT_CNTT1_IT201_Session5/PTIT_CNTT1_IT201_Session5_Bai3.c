#include <stdio.h>

int tinhGiaiThua(int n) {
    if (n == 0)
        return 1;
    return n * tinhGiaiThua(n - 1);
}
int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong nhap so am\n");
    } else {
        int giaiThua = tinhGiaiThua(n);
        printf("Giai cac so tu 1 den %d la: %d\n", n, giaiThua);
    }
    return 0;
}