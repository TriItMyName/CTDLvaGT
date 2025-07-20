#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
// Dinh nghia node
typedef struct node
{
    int data, height;
    struct node *left;
    struct node *right;
} Node;
typedef Node *Tree;
// khoi tao cay
void InitTree(Tree &t)
{
    t = NULL;
}
// Kiem tra cay rong
int isEmpty(Tree t)
{
    return t == NULL;
}
// tao node
Tree createNode(int x)
{
    Tree p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
// tao cay
Tree createTree(Tree &t, int a[], int begin, int end,int n)
{
    if (begin > end)
    {
        return NULL;
    }
    int mid = (begin + end) / 2;
    t = createNode(a[mid]);
    createTree(t->left, a, begin, mid - 1);
    createTree(t->right, a, mid + 1, end);
    return t;
}

int GetHeight(Tree p)
{
    if (p == NULL)
        return 0;
    return p->height;
}
int height(Tree node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}
bool IsBalanced(Tree t)
{
    if (t == NULL)
    {
        return true;
    }
    int left_height = height(t->left);
    int right_height = height(t->right);
    if (abs(left_height - right_height) <= 1 && IsBalanced(t->left) && IsBalanced(t->right))
    {
        return true;
    }
    return false;
}
// In cay
void Print(Tree t, int space)
{
    if (t == NULL)
        return;
    space += COUNT;

    Print(t->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", t->data);
    Print(t->left, space);
}
void PrintTree(Tree t)
{
    Print(t, 0);
}
int main()
{
    Tree t;
    InitTree(t);
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    createTree(t,a,n);
    PrintTree(t);
    if (IsBalanced(t))
    {
        printf("Cay can bang.");
    }
    else
        printf("Cay khong can bang.");
}