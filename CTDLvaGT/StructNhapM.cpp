#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
void initializeList(Node *&phead)
{
    phead = NULL;
}
int isEmpty(Node *phead)
{
    return phead == NULL;
}
Node *createNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void showList(Node *phead)
{
    Node *current = phead;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void insertLast(Node *&phead, int x)
{
    Node *newNode = createNode(x);
    if (isEmpty(phead))
    {
        phead = newNode;
    }
    else
    {
        Node *current = phead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
void input(Node *&phead)
{
    initializeList(phead);
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertLast(phead, x);
    }
}
void insertAfter(Node *phead)
{
    int x, y;
    scanf("%d%d", &x, &y);
    Node *current = phead;
    while (current != NULL)
    {
        if (current->data == x)
        {
            Node *newNode = createNode(y);
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current = current->next;
    }
}

int countNode(Node *phead)
{
    int count = 0;
    Node *current = phead;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int getNodeValue(Node *phead, int k)
{
    int count = 0;
    Node *current = phead;
    while (current != NULL)
    {
        if (count == k)
        {
            return current->data;
        }
        count++;
        current = current->next;
    }
    return -1;
}

int findMax(Node *phead)
{
    if (phead == NULL)
    {
        printf("Ham rong\n");
        return -1;
    }
    int max = phead->data;
    Node *current = phead->next;
    while (current != NULL)
    {
        if (current->data > max)
        {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}
int findMin(Node *phead)
{
    if (phead == NULL)
    {
        printf("Ham rong\n");
        return -1;
    }
    int min = phead->data;
    Node *current = phead->next;
    while (current != NULL)
    {
        if (current->data < min)
        {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}
int Delete(Node *phead, int x)
{
    if (phead == NULL)
    {
        printf("Ham rong\n");
        return false;
    }
    if (phead->data == x)
    {
        Node *temp = phead;
        phead = phead->next;
        delete temp;
        printf("Da xoa pha tu co khoa x\n");
        return true;
    }
    Node *prev = phead;
    Node *current = phead;
    while (current != NULL)
    {
        if (current->data == x)
        {
            prev->next = current->next;
            delete current;
            printf("Da xoa pha tu co khoa x\n");
            return true;
        }
        prev = current;
        current = current->next;
    }
    printf("Khong tim thay phan tu co khoa x trong danh sach\n");
    return false;
}

void interchangeSort(Node *phead)
{
    if (phead == NULL)
    {
        printf("Danh sach rong\n");
        return;
    }
    Node *current = phead;
    while (current != NULL)
    {
        Node *min = current;
        Node *temp = current->next;
        while (temp != NULL)
        {
            if (temp->data < min->data)
            {
                min = temp;
            }
            temp = temp->next;
        }
        int tempData = current->data;
        current->data = min->data;
        min->data = tempData;
    }
    printf("Danh sach su khi sap xep tang dan: \n");
    showList(phead);
}
int main()
{
    Node *phead;
    input(phead);
    // printf("\nPhan tu trong mang:\n");
    // showList(phead);
    //  insertAfter(phead);
    //  printf("\nPhan tu trong mang sau thay doi:");
    //  showList(phead);
    //  int count = countNode(phead);
    //  printf("\nSo nut: %d\n", count);
    //  int k;
    //  scanf("%d", &k);
    //  int current = getNodeValue(phead, k);
    //  printf("Gia tri node thu k: %d\n", current);
    //  int MAX = findMax(phead);
    //  printf("MAX: %d\n", MAX);
    //  int MIN = findMin(phead);
    //  printf("MAX: %d\n", MIN);
    int x;
    printf("Nhap gia tri cua x: ");
    scanf("%d", &x);
    int deletex = Delete(phead, x);
    showList(phead);
    if (deletex == false)
    {
        printf("0");
    }
    else
    {
        printf("1");
    }
     interchangeSort(phead);
     Node *current = phead;
     while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
    }
     phead == NULL;
}