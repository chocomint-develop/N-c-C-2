#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *l;
    struct Node *r;
} Node;


Node* taonode(int data) 
{
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode ==  NULL)
    {
        printf("loi");
        exit(1);
    }

    newnode->data = data;
    newnode->l = newnode->r = NULL;
    return newnode;
}

Node* nhap(Node* root, int data) 
{
    if (root == NULL)
    {
        return taonode(data);
    }
    if(data < root->data)
    {
        root->l = nhap(root->l, data);
    }
    else 
    {
        root->r = nhap(root->r, data);
    }
    return root;
}

void LNR(Node* root){
    if (root != NULL)
    //hint: cứ N thì printf root->data theo thứ tự 
    //còn lại l và r thì ghi theo hàm
    {
        LNR(root->l);
        printf("%d ", root->data);
        LNR(root->r);
    }
}

void NLR (Node* root) {
    if (root != NULL) 
    {
        printf("%d ", root->data);
        NLR(root->l);
        NLR(root->r);
    }
}

void LRN (Node* root){
    if (root != NULL) 
    {
        LRN(root->l);
        LRN(root->r);
        printf("%d ", root->data);
    }
}

int main () {
    Node* root = NULL;
    int n, k;

    printf("nhap so nut muon them: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("nhap gia tri nut thu %d: ", i+1);
        scanf("%d", &k);
        root = nhap (root, k);
    }


    // N ở đâu duyệt ở đó ex: LRN. N ở sau thì duyệt sau, LNR, N ở giữa thì duyệt giữa 

    printf("\nCay sau khi duyet giua: \n");
    LNR(root);
    printf("\nCay sau khi duyet truoc: \n");
    NLR(root);
    printf("\nCay sau khi duyet sau: \n");
    LRN(root);

return 0;
}