#include <stdio.h>
#include <string.h>


void sortString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[1000];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if (strlen(str) == 0) {
        printf("Chuoi khong hop le\n");
        return 0;
    }
    sortString(str);
    printf("str = \"%s\"\n", str);
    return 0;
}
