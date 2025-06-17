#include <stdio.h>
//Bai 1
int main() {
    int n = 10;
    // Độ phức tạp thời gian: O(n)
    for (int i = 0; i < n; i++) {
        printf("Hello\n");
    }
    return 0;
}
//Bai 2
void printDouble(int n){
    int i = 1;

    // Độ phức tạp thời gian: O(log n)
    while (i < n) {
        printf("%d\n", i);
        i *= 2;
    }
}
//Bai 3
int* mallocArray(int n) {
    // Độ phức tạp không gian: O(n)
    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    return arr;
}