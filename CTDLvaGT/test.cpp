#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
struct Node {
    int info;
    struct Node* left;
    struct Node* right;
};

// Hàm khởi tạo cây rỗng
struct Node* createEmptyTree() {
    return NULL;
}

// Hàm tạo một Node mới
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm thêm một phần tử vào cây nhị phân
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->info) {
        root->left = insert(root->left, value);
    } else if (value > root->info) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Hàm duyệt cây theo thứ tự trước (preorder)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Hàm duyệt cây theo thứ tự giữa (inorder)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->info);
        inorderTraversal(root->right);
    }
}

// Hàm duyệt cây theo thứ tự sau (postorder)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->info);
    }
}

// Hàm đếm số Node trên cây
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Hàm đếm số Node có giá trị lớn hơn x trên cây
int countNodesGreaterThanX(struct Node* root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (root->info > x) {
        return 1 + countNodesGreaterThanX(root->left, x) + countNodesGreaterThanX(root->right, x);
    } else {
        return countNodesGreaterThanX(root->right, x);
    }
}

// Hàm đếm số Node lá
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Hàm đếm số Node lá có giá trị nhỏ hơn y trên cây
int countLeafNodesLessThanY(struct Node* root, int y) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL && root->info < y) {
        return 1;
    }
    return countLeafNodesLessThanY(root->left, y) + countLeafNodesLessThanY(root->right, y);
}

// Hàm tìm giá trị nhỏ nhất trên cây
struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL) {
        return root;
    }
    return findMin(root->left);
}

// Hàm tìm một Node có giá trị x trên cây
struct Node* search(struct Node* root, int x) {
    if (root == NULL || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}

int main() {
    struct Node* root = createEmptyTree();
    int arr[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Tạo cây từ mảng số nguyên
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    
    printf("Duyệt cây theo thứ tự trước (preorder): ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Duyệt cây theo thứ tự giữa (inorder): ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Duyệt cây theo thứ tự sau (postorder): ");
    postorderTraversal(root);
    printf("\n");
    
    printf("Số node trên cây: %d\n", countNodes(root));
    
    int x = 4;
    printf("Số node có giá trị lớn hơn %d trên cây: %d\n", x, countNodesGreaterThanX(root, x));
    
    printf("Số node lá trên cây: %d\n", countLeafNodes(root));
    
    int y = 5;
    printf("Số node lá có giá trị nhỏ hơn %d trên cây: %d\n", y, countLeafNodesLessThanY(root, y));
    
    struct Node* minNode = findMin(root);
    if (minNode != NULL) {
        printf("Giá trị nhỏ nhất trên cây: %d\n", minNode->info);
    } else {
        printf("Cây rỗng\n");
    }
    
    int valueToSearch = 6;
    struct Node* searchResult = search(root, valueToSearch);
    if (searchResult != NULL) {
        printf("Tìm thấy giá trị %d trên cây\n", valueToSearch);
    } else {
        printf("Không tìm thấy giá trị %d trên cây\n", valueToSearch);
    }
    
    return 0;
}
