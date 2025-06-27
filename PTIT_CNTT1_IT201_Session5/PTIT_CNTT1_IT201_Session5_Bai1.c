#include <stdio.h>

void inSo(int n) {
    if (n == 0)
        return;
    inSo(n - 1);
    printf("%d ", n);
}
int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong duoc nhap so am\n");
    } else {
        printf("Cac so tu 1 den %d la:\n", n);
        inSo(n);
        printf("\n");
    }
    return 0;
}