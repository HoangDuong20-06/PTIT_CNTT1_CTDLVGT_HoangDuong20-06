#include <stdio.h>

typedef struct {
    int *elements;
    int top;
    int cap;
} Stack;
int pop(Stack *s) {
    if (s->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    return s->elements[s->top--];
}
int main() {
    Stack s;
    s.elements = NULL;
    s.top = -1;
    s.cap = 5;
    int value = pop(&s);
    if (value != -1) {
        printf("%d\n", value);
    }
    return 0;
}
