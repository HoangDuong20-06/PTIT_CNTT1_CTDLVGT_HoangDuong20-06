#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};
typedef struct Student Student;

Student nhap() {
    Student x;
    printf("Nhap id: ");
    scanf("%d", &x.id);
    getchar();
    printf("Nhap ten: ");
    fgets(x.name, sizeof(x.name), stdin);
    x.name[strcspn(x.name, "\n")] = '\0';

    printf("Nhap tuoi: ");
    scanf("%d", &x.age);
    getchar();

    return x;
}
void inThongTin(Student x) {
    printf("{ id: %d, name: \"%s\", age: %d }\n", x.id, x.name, x.age);
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();
    Student list[n];
    printf("Nhap thong tin sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        list[i] = nhap();
    }

    int searchId;
    printf("\nNhap id can tim: ");
    scanf("%d", &searchId);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (list[i].id == searchId) {
            inThongTin(list[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sinh vien khong ton tai\n");
    }
    return 0;
}