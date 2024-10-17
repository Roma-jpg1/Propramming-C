#include<stdio.h>

int prost(int x){
    int c =0;
    for (int j =2; j<=(x/2+1);j++){
        if (x%j==0){
            c+=1;
        }
    }
    return c==0;
}

int main(){
int z =0;
int a [10] = {11,2,3,4,5,6,7,8,9,10};
int len = sizeof(a)/sizeof(a[0]);
int b [len];
int k=len-1;
for (int i =0; i<len; i++){
    b[i]=a[k];
    k-=1;}

for (int n =0; n < len; n++){
    if (prost(b[n])==1){
        z+=1;
    }
}
for (int v = 0; v < len; v++) {
    printf("%d ", b[v]); //обратный порядок
}
printf("\n");
for (int n =0; n < len; n++){
    if (prost(b[n])==1){
        b[n]=0;
        break;
    }
}

for (int n =len-1; n >= 0; n--){
    if (prost(b[n])==1){
        b[n]=0;
        break;
    }
}
printf("%d \n", z); //количество простых чисел в массиве
for (int v = 0; v < len; v++) {
    printf("%d ", b[v]); //удаление простых чисел





}

}