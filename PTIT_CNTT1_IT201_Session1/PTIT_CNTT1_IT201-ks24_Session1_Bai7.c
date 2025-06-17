#include <stdio.h>

int main() {
    int a[] = {1, 3, 5, 7, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int found = 0;
    // Cách 1
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    if (found)
        printf("Mang co phan tu trung lap (Cach 1).\n");
    else
        printf("Mang khong co phan tu trung lap (Cach 1).\n");
    // Độ phức tạp thời gian: O(n^2)
    // Độ phức tạp không gian: O(1)
    // Cách 2
    found = 0;
    int freq[1001] = {0};
    for (int i = 0; i < n; i++) {
        if (freq[a[i]] == 1) {
            found = 1;
            break;
        }
        freq[a[i]] = 1;
    }
    if (found)
        printf("Mang co phan tu trung lap (Cach 2).\n");
    else
        printf("Mang khong co phan tu trung lap (Cach 2).\n");
    return 0;
}
// Độ phức tạp thời gian: O(n)
// Độ phức tạp không gian: O(1)