#include <stdio.h>

// Cách 1: Dùng vòng lặp
// Độ phức tạp thời gian: O(n)
// Độ phức tạp không gian: O(1)
int loop(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

// Cách 2: Dùng công thức
// Độ phức tạp thời gian: O(1)
// Độ phức tạp không gian: O(1)
int recipe(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n phai lon hon 0!\n");
        return 1;
    }

    printf("Tong theo cach 1 (vong lap): %d\n", loop(n));
    printf("Tong theo cach 2 (cong thuc): %d\n", recipe(n));

    return 0;
}
