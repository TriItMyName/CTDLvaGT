#include <stdio.h>
#include <math.h>
#include <conio.h>
#define count 10
typedef int Data;
typedef struct Node
{
    int data;
    int height;
    struct Node *left, *right;
} Node;

typedef struct Node *Tree;

void Init(Tree &t)
{
    t = NULL;
}

bool IsEmpty(Tree t)
{
    return t == NULL;
}

Tree CreateTree(Data x)
{
    Tree p = new Node;
    p->data = x;
    p->left = p->right = NULL;
    p->height = 1;
    return p;
}

void Write(Tree t, int s)
{
    if (t == NULL)
        return;
    s += count;
    Write(t->right, s);
    printf("\n");
    for (int i = count; i < s; i++)
        printf(" ");
    printf("%d(%d)\n", t->data, t->height);
    Write(t->left, s);
}

void WriteTree(Tree t)
{
    Write(t, 0);
}

int Get(Tree root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int Balance(Tree root)
{
    if (root == NULL)
        return 0;
    return Get(root->left) - Get(root->right);
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

Tree RotateLeft(Tree &t)
{
    printf("Xoay trai: \n");
    printf("Truoc khi xoay : \n");
    WriteTree(t);

    Node *p = t->right;
    t->right = p->left;
    p->left = t;

    t->height = 1 + Max(Get(t->left), Get(t->right));
    p->height = 1 + Max(Get(p->left), Get(p->right));
    printf("Sau khi xoay Trai: \n");
    WriteTree(p);
    return p;
}

Tree RotateRigth(Tree &t)
{
    printf("Xoay phai: \n");
    printf("Truoc khi xoay : \n");
    WriteTree(t);

    Node *p = t->left;
    t->left = p->right;
    p->right = t;

    t->height = 1 + Max(Get(t->left), Get(t->right));
    p->height = 1 + Max(Get(p->left), Get(p->right));
    printf("Sau khi xoay Phai: \n");
    WriteTree(p);
    return p;
}

Tree Insert(Tree &t, int x)
{
    if (IsEmpty(t))
        return CreateTree(x);
    if (t->data == x)
        return t;
    if (t->data > x)
        t->left=Insert(t->left, x);
    else
        t->right=Insert(t->right, x);

    t->height = 1 + Max(Get(t->left), Get(t->right));
    int bf = Balance(t);

    if (bf > 1 && x < t->left->data)
        t = RotateRigth(t);
    if (bf > 1 && x > t->right->data)
        t = RotateLeft(t);
    if (bf > 1 && x > t->left->data)
    {
        t->left = RotateLeft(t->left);
        t = RotateLeft(t);
    }
    if (bf > 1 && x < t->right->data)
    {
        t->left = RotateRigth(t->right);
        t = RotateRigth(t);
    }
    return t;
}

Tree Remove(Tree &t, int x)
{

    if (t == NULL)
        return t;
    if (x < t->data)
        t->left = Remove(t->left, x);
    if (x > t->data)
        t->right = Remove(t->right, x);
    else
    {
        if (t->left == NULL || t->right == NULL)
        {
            Tree temp = t->left ? t->left : t->right;
            if (temp == NULL)
            {
                temp = t;
                t = NULL;
            }
            else
            {
                *t = *temp;
            }
            delete temp;
        }
        else
        {
            Tree temp = t->right;
            while (temp->left != NULL)
                temp = temp->left;
            t->data = temp->data;
            t->right = Remove(t->right, temp->data);
        }
    }
    if (t == NULL)
        return t;
    t->height = 1 + Max(Get(t->left), Get(t->right));
    int bf = Balance(t);
    if (bf > 1 && Balance(t->left) >= 0)
        return RotateRigth(t);
    if (bf < -1 && Balance(t->right) <= 0)
        return RotateLeft(t);
    if (bf > 1 && Balance(t->left) < 0)
    {
        t->left = RotateLeft(t->left);
        return RotateRigth(t);
    }
    if (bf > 1 && Balance(t->right) > 0)
    {
        t->left = RotateRigth(t->right);
        return RotateLeft(t);
    }
    return t;
}

void CreateMang(Tree &t, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        t=Insert(t, a[i]);
        printf("Nhap phim bat ki: \n");
        printf("**********************");
        printf("\n");
        getch();
        WriteTree(t);
    }
}

int main()
{
    Tree t;
    Init(t);
    int a[]={2,10,20,11,24,21,14,5,3,34,6};
    int n= sizeof(a)/sizeof(int);
    CreateMang(t,a,n);
    printf("Cay ban dau: \n");
    WriteTree(t);

    int value;
    printf("Nhap so can xoa: ");
    scanf("%d",&value);
    printf("\n");
    t=Remove(t,value);
    printf("\nCay da xoa %d: \n",value);
    WriteTree(t);
    return 0;
}
