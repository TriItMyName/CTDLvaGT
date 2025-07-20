#include<stdio.h>
void chuyen(int n,char a, char b){

    printf("\nChuyen thu %d tu %s sang  %s",n,a,b);
}

void ThapHN(int n, char a, char c,char b){
    if(n==1){
        chuyen(1,a,c);
    }
    else{
        ThapHN(n-1,a,c,b);
        ThapHN(1,a,b,c);
        ThapHN(n-1,b,a,c);
    }
}

int main(){
    int n;
    char a='A';
    char b='B';
    char c='C';
    scanf("%d",&n);
    ThapHN(n,a,b,c);
}