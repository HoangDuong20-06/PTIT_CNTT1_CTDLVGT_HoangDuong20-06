#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    int top;
    int cap;
} Stack;
Stack createStack(int capacity) {
    Stack s;
    s.elements = (int*)malloc(sizeof(int) * capacity);
    s.top = -1;
    s.cap = capacity;
    return s;
}
void printStack(Stack s) {
    printf("stack={\n  elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.elements[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\n  top: %d,\n  cap: %d\n}\n", s.top, s.cap);
}
int main() {
    Stack s = createStack(5);
    printStack(s);
    return 0;
}