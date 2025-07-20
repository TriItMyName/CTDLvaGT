#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char maSV[11];
    char tenSV[41];
    float diemTrungBinh;
} SinhVien;

typedef struct Node
{
    SinhVien data;
    struct Node *next;
} Node;
//Hàm nhập 1 danh sách
SinhVien nhapSinhVien()
{
    SinhVien sv;
    printf("Nhap ma sinh vien: ");
    scanf("%s", sv.maSV);
    printf("Nhap ten sinh vien: "); fflush(stdin); gets(sv.tenSV);
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv.diemTrungBinh);
    return sv;
}
//Hàm xuất 1 danh sách
void xuatSinhVien(SinhVien sv)
{
    printf("%s - %s - %.2f\n", sv.maSV, sv.tenSV, sv.diemTrungBinh);
}

void KhoitaoNode(Node *&phead)
{
    phead = NULL;
}
int isEmpty(Node *phead)
{
    return phead == NULL;
}

Node *taoNode(SinhVien sv)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node *&phead, Node *p)
{
    p->next = phead;
    phead = p;
}

void NhapDanhsachSinhVien(Node *phead)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        SinhVien x;
        Node *p;
        x = nhapSinhVien();
        p = taoNode(x);
        insertFirst(phead, p);
    }
}

void XuatDanhsachSinhVien(Node *phead)
{
    Node *p = phead;
    while (p != NULL)
    {
        xuatSinhVien(p->data);
        p = p->next;
    }
}
void xuatSinhVienCoDiemTren5(Node *phead)
{
    Node *p = phead;
    printf("Cac sinh vien co diem trung binh > 5:\n");
    while (p != NULL)
    {
        if (p->data.diemTrungBinh > 5)
        {
            xuatSinhVien(p->data);
        }
        p = p->next;
    }
}

Node *timSinhVienTheoMa(Node *phead, char maSV[])
{
    Node *temp = phead;
    while (temp != NULL)
    {
        if (strcmp(temp->data.maSV, maSV) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void swapData(SinhVien *a, SinhVien *b)
{
    SinhVien temp = *a;
    *a = *b;
    *b = temp;
}

void sapXepDanhSachTheoDiemTrungBinh(Node *phead)
{
    for (Node *i = phead; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->data.diemTrungBinh < j->data.diemTrungBinh)
            {
                swapData(&(i->data), &(j->data));
            }
        }
    }
}

void themSinhVienSau(Node *phead)
{
    SinhVien y;
    char x[11];
    scanf("%s", x);
    Node *p = timSinhVienTheoMa(phead, x);
    if (p == NULL)
        printf("khong co x");
    else
    {
        y = nhapSinhVien();
        Node *q = taoNode(y);
        q->next = p->next;
        p->next = q;
    }
}

void xoaSinhVienDau(Node *&phead)
{
    if (phead != NULL)
    {
        Node *p = phead;
        phead = p->next;
        delete p;
    }
}

void xoaSinhVienCuoi(Node *&phead)
{
    if (phead == NULL)
    {
        return;
    }
    else if ((phead)->next == NULL)
    {
        free(phead);
        phead = NULL;
    }
    else
    {
        Node *temp = phead;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void xoaToanBoDanhSach(Node *phead)
{
    Node *current = phead;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    phead = NULL;
}

void xoaSinhVienTheoMa(Node *phead, char maSV[])
{
    if (phead == NULL)
    {
        return;
    }
    Node *temp = phead;
    if (strcmp(temp->data.maSV, maSV) == 0)
    {
        phead = temp->next;
        free(temp);
        return;
    }
    Node *prev = NULL;
    while (temp != NULL && strcmp(temp->data.maSV, maSV) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main()
{
    Node *phead;
    KhoitaoNode(phead);
    NhapDanhsachSinhVien(phead);
    XuatDanhsachSinhVien(phead);
    xuatSinhVienCoDiemTren5(phead);
    char maSV[11];
    printf("Nhap ma sinh vien can tim: ");
    scanf("%s", maSV);
    Node *svTimThay = timSinhVienTheoMa(phead, maSV);
    if (svTimThay != NULL)
    {
        xuatSinhVien(svTimThay->data);
    }
    else
    {
        printf("Khong tim thay sinh vien co ma %s\n", maSV);
    }
    sapXepDanhSachTheoDiemTrungBinh(phead);
    XuatDanhsachSinhVien(phead);
    themSinhVienSau(phead);
    XuatDanhsachSinhVien(phead);
    xoaSinhVienDau(phead);
    xoaSinhVienCuoi(phead);
    xoaToanBoDanhSach(phead);
    char ma[11];
    printf("Nhap ma sinh vien can tim: ");
    scanf("%s", ma);
    xoaSinhVienTheoMa(phead, ma);
}