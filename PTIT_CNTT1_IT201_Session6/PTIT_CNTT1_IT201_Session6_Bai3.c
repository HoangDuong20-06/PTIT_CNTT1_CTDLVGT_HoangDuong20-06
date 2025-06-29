#include <stdio.h>

int main() {\
    int n;
    int sum = 0;
    printf("Nhap mot so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Khong duoc nhap so am");
        return 0;
    }
    while (n>0) {
       int digit = n % 10;
        sum += digit;
        n = n / 10;
    }
    printf("Tong cac chu so la : %d " , sum);
    return 0;
}