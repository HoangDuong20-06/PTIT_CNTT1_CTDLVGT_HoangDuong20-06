#include <stdio.h>

int tinhTong(int first,int second) {
    if (first > second)
        return 0;
    return first + tinhTong(first+1,second);
}

int main() {
    int first,second;
    printf("Enter first number: ");
    scanf("%d",&first);
    printf("Enter second number: ");
    scanf("%d",&second);
    if (first <= 0 || second <= 0 || first > second) {
        printf("Khong hop le");
    }else {
        int sum = tinhTong(first,second);
        printf("Tong trong khoang %d den %d la : %d",first,second,sum);
    }
    return 0;
}