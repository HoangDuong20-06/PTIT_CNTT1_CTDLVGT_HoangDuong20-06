#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cleanStr(char *src, char *dest) {
    int n = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (isalnum(src[i])) {
            dest[n++] = tolower(src[i]);
        }
    }
    dest[n] = '\0';
}
int doiXung(char *str, int left, int right) {
    if (left > right)
        return 1;
    if (str[left] != str[right])
        return 0;
    return doiXung(str, left + 1, right-1);
}
int main() {
    char input[100];
    char clean[100];
    printf("Nhao chuoi: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    cleanStr(input, clean);
    if (doiXung(clean, 0, strlen(clean) - 1)) {
        printf("La chuoi doi xung");
    }else {
        printf("Khong la chuoi doi xung");
    }
    return 0;
}