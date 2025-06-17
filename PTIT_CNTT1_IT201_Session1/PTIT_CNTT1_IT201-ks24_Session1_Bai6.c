#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 2, 4, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 2;
    int count = 0;
    // Độ phức tạp thời gian: O(n)
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    // Độ phức tạp không gian: O(1)
    printf("%d xuat hien %d lan trong mang.\n", x, count);
    return 0;
}