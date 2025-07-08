#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - i - 1])
            return false;
    return true;
}
int main() {
    char input[100];
    printf("Nhap chuoi: ");
    gets(input);
    if (isPalindrome(input))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
