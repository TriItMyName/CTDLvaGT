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

// Hàm tìm Node có giá trị nhỏ nhất trong cây
Tree findMin(Tree t)
{
    if (t == NULL)
    {
        return NULL;
    }
    while (t->left != NULL)
    {
        t = t->left;
    }
    return t;
}
// Hàm timd node thế
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
// Hàm xóa Node có giá trị x khỏi cây BST
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

// Hàm in danh sách giảm dần
void Danhsachgiam(Tree t)
{
    if (t != NULL)
    {
        Danhsachgiam(t->right);
        printf("%d ", t->data);
        Danhsachgiam(t->left);
    }
}

// Hàm tìm cha của Node chứa giá trị x
Tree TimchaNode(Tree t, int x)
{
    if (t == NULL || t->data == x)
    {
        return NULL;
    }
    if ((t->left != NULL && t->left->data == x) || (t->right != NULL && t->right->data == x))
    {
        return t;
    }
    if (x < t->data)
    {
        return TimchaNode(t->left, x);
    }
    else
    {
        return TimchaNode(t->right, x);
    }
}

// Hàm đếm số nút lá và nút giữa
void Demsolavagiua(Tree t, int *la, int *giua)
{
    if (t == NULL)
    {
        return;
    }
    if (t->left == NULL && t->right == NULL)
    {
        (*la)++;
    }
    else
    {
        (*giua)++;
    }
    Demsolavagiua(t->left, la, giua);
    Demsolavagiua(t->right, la, giua);
}

// Hàm tính chiều cao của cây
int Tinhchieucao(Tree t)
{
    if (t == NULL)
    {
        return 0;
    }
    int leftHeight = Tinhchieucao(t->left);
    int rightHeight = Tinhchieucao(t->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Hàm tính tổng các giá trị trên cây
int Tong(Tree t)
{
    if (t == NULL)
    {
        return 0;
    }
    return t->data + Tong(t->left) + Tong(t->right);
}

// Hàm kiểm tra xem cây có phải là cây nhị phân đúng không
int KTtree(Tree t, int min, int max)
{
    if (t == NULL)
    {
        return 1;
    }
    if (t->data < min || t->data > max)
    {
        return 0;
    }
    return KTtree(t->left, min, t->data - 1) && KTtree(t->right, t->data + 1, max);
}

int isBST(Tree t)
{
    return KTtree(t, INT_MIN, INT_MAX);
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

    /*int f;
    printf("Nhap gai tri can xoa: ");
    scanf("%d", &f);
    XoaNode(t, f);

    printf("Duyet cay theo thu tu truoc (preorder): ");
    DuyetTruoc(t);
    printf("\n");

    printf("Duyet cay theo thu tu giua (inorder): ");
    DuyetGiua(t);
    printf("\n");

    printf("Duyet cay theo thu tu sau (postorder): ");
    DuyetSau(t);
    printf("\n");

    printf("Danh sach giam dan: ");
    Danhsachgiam(t);
    printf("\n");

    int x;
    printf("Nhap gia tri x đa tim cha: ");
    scanf("%d", &x);
    Tree parent = TimchaNode(t, x);
    if (parent != NULL)
    {
        printf("Nut cha cua %d la %d\n", x, parent->data);
    }
    else
    {
        printf("Khong tim thay nut cha cua %d\n", x);
    }

    int la = 0, giua = 0;
    Demsolavagiua(t, &la, &giua);
    printf("So nut la: %d\n", la);
    printf("So nut giua: %d\n", giua);

    printf("Chieu cao cua cay: %d\n", Tinhchieucao(t));

    printf("Tong cac gia tri tren cay: %d\n", Tong(t));

    if (isBST(t))
    {
        printf("Cay la cay nhi phan dung.\n");
    }
    else
    {
        printf("Cay la cay nhi phan sai.\n");
    }*/
    if (IsBalanced(t))
    {
        printf("Cay can bang.");
    }
    else
        printf("Cay khong can bang.");
    return 0;
}
