#include <stdio.h>

int findMin(int arr[],int n,int index,int currentMin){
    if (index == n)
        return currentMin;
    if (arr[index] < currentMin)
        currentMin = arr[index];
    return findMin(arr,n,index+1,currentMin);
}
int findMax(int arr[],int n,int index,int currentMax) {
    if (index == n)
        return currentMax;
    if (arr[index] > currentMax)
        currentMax = arr[index];
    return findMax(arr,n,index+1,currentMax);
}
int main() {
    int n;
    int arr[100];
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    printf("Nhap phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }
    int min = findMin(arr,n,0,arr[0]);
    int max = findMax(arr,n,0,arr[0]);
    printf("Gia tri nho nhat trong mang: %d\n",min);
    printf("Gia tri lon nhat trong mang: %d\n",max);
    return 0;
}