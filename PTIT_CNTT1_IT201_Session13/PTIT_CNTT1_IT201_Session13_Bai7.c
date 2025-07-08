#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
bool isValid(char expr[]) {
    char stack[100];
    int top = -1;
    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1 || !isMatching(stack[top], c)) {
                return false;
            }
            top--;
        }
    }
    return top == -1;
}

int main() {
    char expr[100];
    printf("Nhap bieu thuc: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;
    if (isValid(expr))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
