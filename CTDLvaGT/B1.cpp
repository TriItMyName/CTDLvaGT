#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Date;
    struct Node* next;
}Node;

void initializelist(Node* &phead)
{
    phead= NULL;
}

int IsEmpty(Node* phead)
{
    return phead ==NULL;
}

Node* createNode(int x)
{
    Node* p= new Node;
    p->Date= x;
    p->next= NULL;
    return p;
}

void inserLast(Node* &phead, int x)
{
    Node* newNode=createNode(x);
    if(IsEmpty(phead))
    {
        phead=newNode;
    }
    else
    {
        Node* current = phead;
        while( current->next != NULL)
        {
            current = current->next;
        }
        current->next=newNode;
    }
}

void input(Node* &phead)
{
    initializelist(phead);
    int x,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        initializelist(phead,x);
    }
}

void showList(Node* phead)
{
    Node* current = phead;
    while (current !=NULL)
    {
        printf("%d ", current->Date);
        current = current->next;
    }
}

int main()
{
    Node* phead = NULL;
    int x;
    phead = initializelist(phead);
    IsEmpty(phead);
    createNode(phead);
    inserLast(phead);
    input(phead);
    showList(phead);
}