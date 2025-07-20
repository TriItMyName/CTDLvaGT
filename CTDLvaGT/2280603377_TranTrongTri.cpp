#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct {
	char MSSV[10];
	char HoTen[30];
	float Diem;
} SV;
typedef struct tagNode{
	SV data;
	tagNode *next;
} Node;

//Nhap 1 sinh vien
SV Nhap1SV()
{
	SV sv;
	printf("Nhap thong tin sinh vien:\n");
	printf("Ma SV: "); 
	scanf("%s", sv.MSSV);
	printf("Ho ten: ");
	fflush(stdin);	gets(sv.HoTen);
	printf("DTB: "); scanf("%f",&sv.Diem);
	return sv;
}
//Xuat 1 sinh vien
void Xuat1SV(SV &x)
{
  printf("%s | %s | %.2f\n",x.MSSV, x.HoTen,x.Diem);
}
//khoi tao
void initializeList(Node* &phead){
	phead = NULL;
}
//kiem tra rong
int isEmpty(Node* phead)
{
	return phead==NULL;
}
//tao 1 node
Node* createNode(SV x){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
//Nhap dau
void InsrtFirst(Node *&pHead, Node *p)
{
	p->next=pHead;
	pHead = p;
}
//Xuat danh sach sinh vien
void showList(Node* phead){
	Node* p = phead;
	while(p!=NULL){
		Xuat1SV(p->data);
		p = p->next;
	}
}
//Nhap danh sach sinh vien
void input(Node* &phead) {
	int n;
	scanf("%d",&n);	
	for(int i=0;i<n;i++)
	{
		SV sv;
		Node *p;
		sv = Nhap1SV();
		p = createNode(sv);
		InsrtFirst(phead,p);
	}
}
//xuat diem tren 5
void DTB(Node* phead) {
    Node* p = phead;
    printf("Cac sinh vien co diem trung binh > 5:\n");
    while (p != NULL) {
        if (p->data.Diem>5) {
        	Xuat1SV(p->data);
        }
        p = p->next;
    }
}
//tim mssv
Node* Find(Node* &phead,char x[])
{
	Node* p =phead;
	while(p!=NULL)
	{
		if (strcmp((p->data).MSSV,x)==0)
			return p;
		p=p->next;
	}
}
//Tim sinh vien
void xuatTheoMa(Node* phead,char ma[]) {
	Node* i;
    for (i=phead; i != NULL; i = i->next) 
	{
    	if (strcmp((i->data).MSSV,ma)==0)
		{
		Xuat1SV(i->data);
    	return ;
		}
        
    }
	printf("Not Found");
}
//sap
void swapData(SV* a, SV* b) {
    SV temp = *a;
    *a = *b;
    *b = temp;
}
// theo diem
void sapXepTheoDiemTB(Node* phead) {
    for (Node* i =phead;i!= NULL; i = i->next) {
        for (Node* j=i->next; j!=NULL;j = j->next) {
            if (i->data.Diem < j->data.Diem) {
                swapData(&(i->data), &(j->data));
            }
        }
    }
}
//chen sau x
void Chen(Node* phead)
{
	SV y;
	char x[11];
	scanf("%s",x);
	Node* p=Find(phead,x);
	if(p==NULL)
	printf("khong co x");
	else{
		y=Nhap1SV();
		Node* q=createNode(y);
		q->next = p->next;
		p->next=q;
	}
}
//xoa dau
void DeleteFirst(Node* &phead)
{
	if(phead!=NULL)
	{
		Node* p=phead;
		phead =p->next;
		delete p;
	}
}
//xoa cuoi
void DeleteLast(Node* &phead)
{
	if(phead==NULL)
		{
			printf("danh sach rong");
		}
	else if(phead->next ==NULL)
		DeleteFirst(phead);
	else{
		Node* p=phead;
		while(p->next->next != NULL)
			p=p->next;
		Node* q=p->next;
		p->next=NULL;
		delete q;
	}
}
//xoa toan bo
void DeleteALL(Node* &phead)
{
	while(phead!=NULL)
		DeleteFirst(phead);
}
//xoa SV co ma X
void DeleteX(Node* &phead)
{
	
}
int main() {
	Node* phead;
	char ma[11];
	initializeList(phead);
	input(phead);
    showList(phead);
	DTB(phead);
	scanf("%s",&ma);
	xuatTheoMa(phead,ma);
	sapXepTheoDiemTB(phead);
	Chen(phead);
	DeleteFirst(phead);
	DeleteLast(phead);
	DeleteALL(phead);
	return 0;
}