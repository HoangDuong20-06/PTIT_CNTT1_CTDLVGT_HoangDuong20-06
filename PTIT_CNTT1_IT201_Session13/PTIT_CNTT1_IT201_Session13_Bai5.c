#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    int top;
    int cap;
} Stack;
Stack createStack(int n) {
    Stack s;
    s.elements = (int*)malloc(sizeof(int) * n);
    s.top = -1;
    s.cap = n;
    return s;
}
void push(Stack *s, int val) {
    if (s->top < s->cap - 1)
        s->elements[++s->top] = val;
}
int pop(Stack *s) {
    if (s->top == -1)
        return -1;
    return s->elements[s->top--];
}
void reverseArray(int arr[], int n) {
    Stack s = createStack(n);
    for (int i = 0; i < n; i++)
        push(&s, arr[i]);
    for (int i = 0; i < n; i++)
        arr[i] = pop(&s);
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    return 0;
}