#include <stdio.h>

typedef struct {
    int *elements;
    int top;
    int cap;
} Stack;
void printStack(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%d\n", s.elements[i]);
    }
}
int main() {
    Stack s = { (int[]){10, 20, 30, 40, 50}, 4, 5 };
    printStack(s);
    return 0;
}