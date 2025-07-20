#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
typedef NODE *Tree;
// Hàm khởi tạo cây rỗng
void KhoitaoTree(Tree &t)
{
    t = NULL;
}

// Hàm thêm một phần tử vào cây nhị phân
void ThemNodevaoTree(Tree &t, int a)
{
    if (t == NULL)
    {
        NODE *p = new NODE;
        p->data = a;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }
    else
    {
        if (t->data > a)
        {
            ThemNodevaoTree(t->left, a);
        }
        else if (t->data < a)
        {
            ThemNodevaoTree(t->right, a);
        }
    }
}

void TimNodeThe(Tree &X, Tree &Y)
{
    if (Y->left != NULL)
    {
        TimNodeThe(X, Y->left);
    }
    else
    {
        X->data = Y->data;
        X = Y;
        Y = Y->right;
    }
}

void XoaNode(Tree &t, int data)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        if (data < t->data)
        {
            XoaNode(t->left, data);
        }
        else if (data > t->data)
        {
            XoaNode(t->right, data);
        }
        else
        {
            Tree X = t;
            if (t->left == NULL)
            {
                t = t->right;
            }
            else if (t->right = NULL)
            {
                t = t->left;
            }
            else
            {
                Tree Y = t->right;
                TimNodeThe(X, Y);
            }

            delete X;
        }
    }
}

// Hàm duyệt cây theo thứ tự trước (preorder)
void DuyetTruoc(Tree t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        DuyetTruoc(t->left);
        DuyetTruoc(t->right);
    }
}

void Menu(Tree &t)
{
    while (true)
    {
        printf("\n\n\t\t================Menu================");
        printf("\n1.Nhap du lieu");
        printf("\n2.Xuat du lieu");
        printf("\n3.Xoa phan tu:");
        printf("\n\n\t\t====================================");
        int luachon;
        printf("\nNhap lua chon: ");
        scanf("%d", &luachon);
        if (luachon < 0 || luachon > 3)
        {
            printf("Lua chon khong hop le");
            system("pause");
        }
        else if (luachon==1)
        {
            int x;
            printf("\nNhap so nguyen x: ");
            scanf("%d",&x);
            ThemNodevaoTree(t,x);
        }
        else if(luachon==2)
        {
            printf("Duyet cay theo thu tu truoc (preorder): ");
            DuyetTruoc(t);
            printf("\n");
            system("pause");
        }
        else if (luachon==3)
        {
            int x;
            printf("\nNhap gia tri can xoa: ");
            scanf("%d",&x);
            XoaNode(t,x);
            system("pause");
        }
        else
        {
            break;
        }
        
    }
}
int main()
{
    Tree t;
    KhoitaoTree(t);
    Menu(t);
    system("pause");
}