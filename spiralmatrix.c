#include <stdio.h>

void spi(int n){
    int matrix[n][n];
    int l =0;
    int r =n-1;
    int t =0;
    int b =n-1;
    int k=0;
    while (l<=r && t<=b){
        for (int i=l; i<=r; i++){ //verx
            matrix[t][i]=k;
            k+=1;
        }
        t+=1;
        for (int i=t; i<=b; i++){ //prav
            matrix[i][r]=k;
            k+=1;
        }
        r-=1;
        if (t<=b){ //niz
        for (int i=r; i>=l; i--){
            matrix[b][i]=k;
            k+=1;
        }
        b-=1;
        }
        if (l<=r){ //lev
            for (int i=b; i>=t; i--){
            matrix[i][l]=k;
            k+=1;
        }
        l+=1;
    }
}
    for (int i=0; i<n;i++){
        for (int j=0; j<n;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
int n=0;
printf("razmer? \n");
scanf("%d", &n);
spi(n);

}