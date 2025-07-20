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

// Hàm duyệt cây theo thứ tự giữa (inorder)
void DuyetGiua(Tree t)
{
    if (t != NULL)
    {
        DuyetGiua(t->left);
        printf("%d ", t->data);
        DuyetGiua(t->right);
    }
}

// Hàm duyệt cây theo thứ tự sau (postorder)
void DuyetSau(Tree t)
{
    if (t != NULL)
    {
        DuyetSau(t->left);
        DuyetSau(t->right);
        printf("%d ", t->data);
    }
}

// Hàm đếm số Node trên cây
int DemsoNode(Tree t)
{
    if (t == NULL)
    {
        return 0;
    }
    return 1 + DemsoNode(t->left) + DemsoNode(t->right);
}

// Hàm đếm số Node có giá trị lớn hơn x trên cây
int NodegiatriMax(Tree t, int x)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->data > x)
    {
        return 1 + NodegiatriMax(t->left, x) + NodegiatriMax(t->right, x);
    }
    else
    {
        return NodegiatriMax(t->right, x);
    }
}

// Hàm đếm số Node lá
int DemsoLa(Tree t)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->left == NULL && t->right == NULL)
    {
        return 1;
    }
    return DemsoLa(t->left) + DemsoLa(t->right);
}

// Hàm đếm số Node lá có giá trị nhỏ hơn y trên cây
int DemsolacoGiatrinhohonY(Tree t, int y)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->left == NULL && t->right == NULL && t->data < y)
    {
        return 1;
    }
    return DemsolacoGiatrinhohonY(t->left, y) + DemsolacoGiatrinhohonY(t->right, y);
}

// Hàm tìm giá trị nhỏ nhất trên cây
struct node *timMin(Tree t)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->left == NULL)
    {
        return t;
    }
    return timMin(t->left);
}

// Hàm tìm một Node có giá trị x trên cây
struct node *Timnode(Tree t, int x)
{
    if (t == NULL || t->data == x)
    {
        return t;
    }
    if (x < t->data)
    {
        return Timnode(t->left, x);
    }
    else
    {
        return Timnode(t->right, x);
    }
}

int main()
{
    Tree t;
    KhoitaoTree(t);
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        ThemNodevaoTree(t, a[i]);
    }

    printf("Duyet cay theo thu tu truoc (preorder): ");
    DuyetTruoc(t);
    printf("\n");

    printf("Duyet cay theo thu tu giua (inorder): ");
    DuyetGiua(t);
    printf("\n");

    printf("Duyet cay theo thu tu sau (postorder): ");
    DuyetSau(t);
    printf("\n");

    printf("Sa node tren cay: %d\n", DemsoNode(t));

    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Sa node co gia tri lon hon %d tren cay: %d\n", x, NodegiatriMax(t, x));

    printf("Sa node la tren cay: %d\n", DemsoLa(t));

    int y;
    printf("Nhap y: ");
    scanf("%d", &y);
    printf("So node la co gia tri nho hon %d tren cay: %d\n", y, DemsolacoGiatrinhohonY(t, y));

    Tree min = timMin(t);
    if (min != NULL)
    {
        printf("Gia tri nho nhat tren cay: %d\n", min->data);
    }
    else
    {
        printf("Cay rong\n");
    }

    int c;
    printf("Nhap gia tri can tim trong cay: ");
    scanf("%d", &c);
    
    Tree tim = Timnode(t, c);
    if (tim != NULL)
    {
        printf("Tim thay gia tri %d tren cay\n", c);
    }
    else
    {
        printf("Khong tim thay gia tri %d tren cay\n", c);
    }

    return 0;
}
