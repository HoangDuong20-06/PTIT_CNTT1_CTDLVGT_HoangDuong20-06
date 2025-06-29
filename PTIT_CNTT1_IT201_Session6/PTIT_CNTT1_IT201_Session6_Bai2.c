#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;
    printf("Nhap so luong so Fibonacci can in: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le\n");
        return 1;
    }
    int fib[n];
    for (int i = 0; i < n; i++) {
        fib[i] = fibonacci(i);
    }
    printf("Cac so Fibonacci dau tien la: [");
    for (int i = n -1; i >= 0; i--) {
        printf("%d", fib[i]);
        if (i > 0) printf(", ");
    }
    printf("]\n");
    return 0;
}