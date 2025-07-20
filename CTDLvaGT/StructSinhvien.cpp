    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // Định nghĩa cấu trúc SinhVien
    typedef struct SinhVien {
        char maSV[11];
        char hoTen[41];
        float diemTrungBinh;
        struct SinhVien* next;
    } SinhVien;

    // Hàm tạo một nút SinhVien mới
    SinhVien* taoSinhVien(char maSV[], char hoTen[], float diemTrungBinh) {
        SinhVien* sv = (SinhVien*)malloc(sizeof(SinhVien));
        strcpy(sv->maSV, maSV);
        strcpy(sv->hoTen, hoTen);
        sv->diemTrungBinh = diemTrungBinh;
        sv->next = NULL;
        return sv;
    }

    // Hàm thêm một sinh viên vào đầu danh sách
    SinhVien* themSinhVienDau(SinhVien* head, SinhVien* sv) {
        sv->next = head;
        return sv;
    }

    // Hàm nhập danh sách sinh viên từ bàn phím
    SinhVien* nhapDanhSachSinhVien() {
        SinhVien* head = NULL;
        int n;
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            char maSV[11];
            char hoTen[41];
            float diemTrungBinh;

        
            scanf("%s", maSV);
            
            scanf(" %[^\n]s", hoTen);
            
            scanf("%f", &diemTrungBinh);

            SinhVien* sv = taoSinhVien(maSV, hoTen, diemTrungBinh);
            head = themSinhVienDau(head, sv);
        }

        return head;
    }

    // Hàm xuất thông tin sinh viên
    void xuatSinhVien(SinhVien* sv) {
    
        printf("%s - %s  - %.2f\n",sv->maSV,sv->hoTen,sv->diemTrungBinh);
    }

    // Hàm xuất danh sách sinh viên
    void xuatDanhSachSinhVien(SinhVien* head) {
        SinhVien* current = head;
        while (current != NULL) {
            xuatSinhVien(current);
            current = current->next;
        }
    }

// Hàm xuất thông tin các sinh viên có điểm trung bình > 5
void xuatSinhVienDTBLonHon5(SinhVien* head) {
    SinhVien* current = head;
    while (current != NULL) {
        if (current->diemTrungBinh > 5) {
            xuatSinhVien(current);
        }
        current = current->next;
    }
}

// Hàm tìm sinh viên theo mã SV
SinhVien* timSinhVien(SinhVien* head, char maSV[]) {
    SinhVien* current = head;
    while (current != NULL) {
        if (strcmp(current->maSV, maSV) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Hàm thêm một sinh viên vào sau một sinh viên đã cho
void themSinhVienSau(SinhVien* sv, SinhVien* svMoi) {
    svMoi->next = sv->next;
    sv->next = svMoi;
}

// Hàm sắp xếp danh sách sinh viên tăng dần theo điểm trung bình
SinhVien* sapXepDanhSach(SinhVien* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    SinhVien* prev = NULL;
    SinhVien* current = head;
    SinhVien* next = NULL;

    // Sử dụng thuật toán sắp xếp chèn (insertion sort)
    while (current != NULL) {
        next = current->next;

        if (prev!= NULL && current->diemTrungBinh < prev->diemTrungBinh) {
            prev->next = next;
            current->next = head;
            head = current;
            current = prev;
        } else {
            SinhVien* temp = head;
            while (temp->next != NULL && temp->next->diemTrungBinh <= current->diemTrungBinh) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        prev = current;
        current = next;
    }

    return head;
}

// Hàm xóa sinh viên đầu danh sách
SinhVien* xoaSinhVienDau(SinhVien* head) {
    if (head == NULL) {
        return NULL;
    }

    SinhVien* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Hàm xóa sinh viên cuối danh sách
SinhVien* xoaSinhVienCuoi(SinhVien* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    SinhVien* prev = NULL;
    SinhVien* current = head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
    return head;
}

// Hàm xóa toàn bộ danh sách sinh viên
void xoaDanhSachSinhVien(SinhVien* head) {
    SinhVien* current = head;
    while (current != NULL) {
        SinhVien* temp = current;
        current = current->next;
        free(temp);
    }
}

// Hàm xóa sinh viên theo mã SV
SinhVien* xoaSinhVien(SinhVien* head, char maSV[]) {
    if (head == NULL) {
        return NULL;
    }

    if (strcmp(head->maSV, maSV) == 0) {
        SinhVien* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    SinhVien* prev = NULL;
    SinhVien* current = head;
    while (current != NULL) {
        if (strcmp(current->maSV, maSV) == 0) {
            prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    return head;
}

// Hàm main
int main() {
    SinhVien* danhSachSinhVien = NULL;
    danhSachSinhVien = nhapDanhSachSinhVien();
    xuatDanhSachSinhVien(danhSachSinhVien);
    xuatSinhVienDTBLonHon5(danhSachSinhVien);
    char maSV[11];
    printf("Nhap ma SV: ");
    scanf("%s", maSV);
    SinhVien* sv = timSinhVien(danhSachSinhVien, maSV);
    if (sv != NULL) {
        printf("Thong tin sinh vien:\n");
        xuatSinhVien(sv);
    } else {
        printf("Khong tim thay sinh vien co ma SV %s\n", maSV);
    }
    danhSachSinhVien = sapXepDanhSach(danhSachSinhVien);
    printf("Da sap xep danh sach sinh vien theo diem trung binh.\n");
    
    printf("Nhap ma SV cua sinh vien can them: ");
    scanf("%s", maSV);
    if (sv != NULL) {
        char maSVMoi[11];
        char hoTenMoi[41];
        float diemTrungBinhMoi;

        printf("Nhap ma SV moi: ");
        scanf("%s", maSVMoi);
        printf("Nhap ho ten moi: ");
        scanf(" %[^\n]s", hoTenMoi);
        printf("Nhap diem trung binh moi: ");
        scanf("%f", &diemTrungBinhMoi);

        SinhVien* svMoi = taoSinhVien(maSVMoi, hoTenMoi, diemTrungBinhMoi);
        themSinhVienSau(sv, svMoi);
        printf("Da them sinh vien moi sau sinh vien co ma SV %s.\n", maSV);
    } else {
        printf("Khong tim thay sinh vien co ma SV %s\n", maSV);
    }
    danhSachSinhVien = xoaSinhVienDau(danhSachSinhVien);
    printf("Da xoa sinh vien dau danh sach.\n");
    danhSachSinhVien = xoaSinhVienCuoi(danhSachSinhVien);
    printf("Da xoa sinh vien cuoi danh sach.\n");
    xoaDanhSachSinhVien(danhSachSinhVien);
    danhSachSinhVien = NULL;
    printf("Da xoa toan bo danh sach sinh vien.\n");
    
    printf("Nhap ma SV cua sinh vien can xoa: ");
    scanf("%s", maSV);
    danhSachSinhVien = xoaSinhVien(danhSachSinhVien, maSV);
    printf("Da xoa sinh vien co ma SV %s.\n", maSV);
}   