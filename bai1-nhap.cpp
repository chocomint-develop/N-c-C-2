#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char mssv[20];
    char name[50];
    float diem;
} SV;

typedef struct  Node
{
    SV data;
    struct Node* next;
} Node; 


void input(SV* s) 
{
    printf("nhap mssv: ");
    fgets(s->mssv, sizeof(s->mssv), stdin);

    printf("nhap Ho va Ten: ");
    fgets(s->name, sizeof(s->name), stdin);

    printf("nhap diem trung binh: ");
    scanf("%f", &s->diem);
    //cứ scanf thì dùng getchar()
    getchar();
}

void insertTail (Node** head, SV new_sv) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = new_sv;
    newnode->next = NULL;
    if (*head == NULL) 
    {
        *head = newnode;
        return;
    }
    // tạo tạm (temp)
    Node* tam = *head;
    while (tam->next != NULL) {
        tam = tam->next;
    }
    tam->next = newnode;
}

//print danh sách sinh viên 
void printlist(Node* head) 
{
    Node* tam = head;
    while (tam != NULL)
    {
        printf("-%s | %s | %.2f Diem\n", tam->data.mssv, tam->data.name, tam->data.diem);
        tam = tam->next;
    }
}

int main ()
{
    Node* head = NULL;
    int n;

    printf("nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) 
    {
        SV s;
        printf("\nNhap sinh vien thu %d: ", i+1);
        input(&s);
        insertTail(&head, s);
    }
    printlist(head);
return 0;
}