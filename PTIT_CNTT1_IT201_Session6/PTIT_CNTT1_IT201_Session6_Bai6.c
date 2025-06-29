#include <stdio.h>

int demCachLeo(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return demCachLeo(n - 1) + demCachLeo(n - 2);
}
int main() {
    int n;
    printf("Nhap so bac cau thang: ");
    scanf("%d", &n);
    int cach = demCachLeo(n);
    printf("So cach leo len %d bac la: %d\n", n, cach);
    return 0;
}