#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Sinhvien
{
    char mssv[11];
    char hoten[41];
    float dqt, dcc;
} Sinhvien;

typedef struct node
{
    Sinhvien sv;
    struct node *next;
} Node;

typedef struct Queue
{
    Node *head;
    Node *tail;
} Queue;

int init(Queue *q)
{
    q->head = q->tail = NULL;
}

int isEmpty(Queue q)
{
    return q.head == NULL;
}

void Push(Queue *q, Sinhvien sv)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Cap Phat Bo Nho Khong Thanh Cong.\n");
        exit(1);
    }
    newNode->sv = sv;
    newNode->next = NULL;
    if (isEmpty(*q))
    {
        q->head = q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}
Sinhvien Pop(Queue *q)
{
    if (!isEmpty(*q))
    {
        Node *p = q->head;
        Sinhvien sv = p->sv;
        q->head = p->next;
        free(p);
        if (q->head == NULL)
        {
            q->tail = NULL;
        }
        return sv;
    }
    printf("Queue rong.\n");
    exit(1);
}

Sinhvien NhapSV()
{
    Sinhvien sv;
    printf("Ma so: \n");
    scanf("%s", &sv.mssv);
    printf("Ho ten: \n");
    fflush(stdin);
    gets(sv.hoten);
    printf("Diem quan trinh: \n");
    scanf("%f", &sv.dqt);
    printf("Diem chuyen can: \n");
    scanf("%f", &sv.dcc);
    return sv;
}

void XuatSV(Sinhvien sv)
{
    printf("%s - %s - %.2f - %.2f", sv.mssv, sv.hoten, sv.dqt, sv.dcc);
}

int main()
{
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    Queue q;
    init(&q);

    // Nhập thông tin cho n sinh viên và đưa vào queue
    for (int i = 0; i < n; i++)
    {
        Sinhvien sv = NhapSV();
        Push(&q, sv);
    }

    // In danh sách sinh viên ra màn hình
    printf("Danh sach sinh vien:\n");
    while (!isEmpty(q))
    {
        Sinhvien sv = Pop(&q);
        XuatSV(sv);
    }

    return 0;
}
