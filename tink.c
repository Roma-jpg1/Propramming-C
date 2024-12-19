#include <stdio.h>
int kprost(int n){
    int k=-1;
    if (n==1){
            k=0;
        }
    else{
    for (int i=1; i<n; i++){
        if (n%i==0){
            k+=1;
        }
    }
    }
    return (k);
}

int del(int n){
    int k=0;
    for (int i=1; i<(n+1); i++){
        if (n%i==0){
            k+=1;
        }
    }
    return (k);
}

//25 1 5 25
//64 1 2 4 8 16 32 64
int main(){
    int l;
    int r;
    int c=0;
    scanf("%d", &l);
    scanf("%d", &r);
    for (int i = l; i<(r+1); i++){
        if (kprost(i)>0){
            if (kprost(del(i))==0){
            printf("%d ", i);
            c+=1;}
        }

    }
    printf("ответ: %d", c);
}