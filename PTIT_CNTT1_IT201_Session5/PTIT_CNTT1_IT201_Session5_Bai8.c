#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidNumber(char str[]) {
    int start = 0;
    if (str[0] == '-') start = 1;
    for (int i = start; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}
int stringToInt(char str[], int len) {
    if (len == 0) return 0;
    return stringToInt(str, len - 1) * 10 + (str[len - 1] - '0');
}
int main() {
    char input[100];
    printf("Nhap chuoi so: ");
    scanf("%s", input);
    if (!isValidNumber(input)) {
        printf("Input khong hop le\n");
        return 1;
    }
    int isNegative = 0;
    int start = 0;
    if (input[0] == '-') {
        isNegative = 1;
        start = 1;
    }
    while (input[start] == '0' && input[start + 1] != '\0') {
        start++;
    }
    int result = stringToInt(&input[start], strlen(&input[start]));
    if (isNegative) result = -result;
    printf("So nguyen: %d\n", result);
    return 0;
}