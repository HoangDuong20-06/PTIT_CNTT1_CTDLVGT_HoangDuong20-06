#include <stdio.h>

void decToBinary(int n) {
    int binary[32], i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
}

int main() {
    int number;
    printf("Nhap so nguyen: ");
    scanf("%d", &number);
    printf("Dang nhi phan: ");
    decToBinary(number);
    return 0;
}
