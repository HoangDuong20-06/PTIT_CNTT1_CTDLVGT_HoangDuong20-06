#include <stdio.h>

void thapHaNoi(int n, char A, char B, char C) {
    if (n <= 0) {
        printf("Input khong hop le\n");
        return;
    }
    if (n == 1) {
        printf("Dia 1 di chuyen tu %c sang %c\n", A, C);
        return;
    }
    thapHaNoi(n - 1, A, C, B);
    printf("Dia %d di chuyen tu %c sang %c\n", n, A, C);
    thapHaNoi(n - 1, B, A, C);
}
int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);
    thapHaNoi(n, 'A', 'B', 'C');
    return 0;
}