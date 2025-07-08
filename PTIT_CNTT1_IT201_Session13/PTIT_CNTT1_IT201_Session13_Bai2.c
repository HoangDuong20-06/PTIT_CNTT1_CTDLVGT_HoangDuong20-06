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
void push(Stack *s, int value) {
    if (s->top < s->cap - 1) {
        s->top++;
        s->elements[s->top] = value;
    } else {
        printf("Stack is full!\n");
    }
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
    int value;
    printf("Nhap 5 phan tu:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(&s, value);
    }
    printStack(s);
    return 0;
}