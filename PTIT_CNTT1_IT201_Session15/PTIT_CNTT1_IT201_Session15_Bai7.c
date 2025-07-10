#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
} Customer;
typedef struct {
    Customer *array;
    int front;
    int rear;
    int capacity;
    int nameSize;
} Queue;
Queue* createQueue(int maxSize, int nameSize) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->array = (Customer*)malloc(sizeof(Customer) * maxSize);
    q->capacity = maxSize;
    q->nameSize = nameSize;
    q->front = 0;
    q->rear = -1;
    for (int i = 0; i < maxSize; i++) {
        q->array[i].name = (char*)malloc(sizeof(char) * nameSize);
    }

    return q;
}
int isEmpty(Queue* q) {
    return q->rear < q->front;
}
int isFull(Queue* q) {
    return q->rear >= q->capacity - 1;
}
void enqueue(Queue* q, char* name) {
    if (isFull(q)) {
        printf("Hang doi day! Khong the them khach moi.\n");
        return;
    }
    q->rear++;
    strncpy(q->array[q->rear].name, name, q->nameSize - 1);
    q->array[q->rear].name[q->nameSize - 1] = '\0';
    printf("Da them khach '%s' vao hang doi.\n", name);
}
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong! Khong co khach de phuc vu.\n");
        return;
    }
    printf("Dang phuc vu khach: %s\n", q->array[q->front].name);
    q->front++;
}
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }
    printf("Danh sach khach dang cho:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("- %s\n", q->array[i].name);
    }
}
void freeQueue(Queue* q) {
    for (int i = 0; i < q->capacity; i++) {
        free(q->array[i].name);
    }
    free(q->array);
    free(q);
}
int main() {
    int maxQueue = 100;
    int maxNameLength = 31;
    Queue* q = createQueue(maxQueue, maxNameLength);
    int choice;
    char name[100];
    do {
        printf("\n===== MENU =====\n");
        printf("1. Them khach vao hang doi\n");
        printf("2. Phuc vu khach\n");
        printf("3. Hien thi danh sach dang cho\n");
        printf("4. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap ten khach: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                enqueue(q, name);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 4);
    freeQueue(q);
    return 0;
}