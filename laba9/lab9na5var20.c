#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
double **rmatr (int size){
    srand(time(NULL));
    double **matrix = (double**)malloc(size*sizeof(double*));
    for (int i=0; i<size;i++){
        matrix[i]=(double*)malloc(size*sizeof(double));
    }

    for (int i=0; i<size;i++){
        for (int j=0; j<size; j++){
            matrix[i][j]=(rand()%50);
        }
    }
    return matrix;
}

double *maxmatr(double **matr, int k){
    double *arr=NULL;
    arr=(double*)calloc(k, sizeof(double));
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            if (arr[i]<matr[i][j]){
                arr[i]=matr[i][j];}
                }
                }
    return arr;
}

double *vektr(double **mat, double *ar, int k){
    double *vek=NULL;
    vek=(double*)calloc(k, sizeof(double));
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            vek[i]+=mat[i][j]*ar[j];
        }
    }
    return vek;
}
double **perev(double **matr,int k){
    double **pmatrix = (double**)malloc(k*sizeof(double*));
    for (int i=0; i<k;i++){
        pmatrix[i]=(double*)malloc(k*sizeof(double));
    }
    for (int i =0; i<k; i++){
        for (int j =0; j<k; j++){
            pmatrix[i][j]=matr[k-1-i][k-1-j];
        }
    }
    return pmatrix;
}

void free2(double **Ma, int k){
    for(int i=0; i<k; i++){
        free(Ma[i]);
        Ma[i]=NULL;
    }
    free(Ma);
    Ma=NULL;
}

int main(){
int v;
int n;
int e;
printf("Размеры матрицы: ");
scanf("%d", &n);
if (n<1 || n>15) printf("неккоректные данные для ввода \n");
else{
    printf("ввести вручную матрицу: 1-вручную 2-рандом \n");
    scanf("%d", &e);
    switch(e){
        case 1:
        int o=1;
        double **A =(double**)malloc(n*sizeof(double*));
        for (int i=0; i<n; i++){
            A[i]=(double*)malloc(n*sizeof(double));
        }
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    scanf("%d", &v);
                    if (v>-10000 && v<1000000){
                        A[i][j]=v;
                    }
                    else{
                        o-=1;
                        
                    }
                }
            }
            if (o<1){
                printf("неккоректные данные \n");
                break;
            }
            double *B=maxmatr(A,n);
            double *C=vektr(A,B,n);
            double **pA=perev(A,n);
            int k=0;
            for (int i=0; i<n;i++){
                for (int j=0; j<n; j++){
                    printf("%lf ", A[i][j]);}
                printf("\n");}
            printf("\n");
            printf("\n");
            for (int i=0; i<n; i++){
                printf("%lf  ",B[i]);
            }
            printf("\n");
            printf("\n");
            for (int i=0; i<n; i++){
                printf("%lf  ",C[i]);
            }
            printf("\n");
            printf("\n");
            for (int i=0; i<n;i++){
                for (int j=0; j<n; j++){
                    if (A[i][j]==0){
                        k+=1;
                        }}}
            printf("\n");
            printf("\n");
            if (k>0){
                for (int i=0; i<n;i++){
                    for (int j=0; j<n; j++){
                        printf("%lf ", pA[i][j]);}
                    printf("\n");}
            }
            else{
                for (int i=0; i<n;i++){
                    for (int j=0; j<n; j++){
                        printf("%lf ", A[i][j]);}
                    printf("\n");}
            }
            //----------------------------------------очищение
            free(B);
            B=NULL;
            free(C);
            C=NULL;
            free2(A,n);
            free2(pA,n);
            break;
        
        
        case 2:
            A=rmatr(n);
            B=maxmatr(A,n);
            C=vektr(A,B,n);
            pA=perev(A,n);
            for (int i=0; i<n;i++){
                    for (int j=0; j<n; j++){
                        printf("%lf ", A[i][j]);}
                    printf("\n");}
            printf("\n");
            printf("\n");
            for (int i=0; i<n; i++){
                printf("%lf  ",B[i]);
            }
            printf("\n");
            printf("\n");
            for (int i=0; i<n; i++){
                printf("%lf  ",C[i]);
            }
            printf("\n");
            printf("\n");
            for (int i=0; i<n;i++){
                for (int j=0; j<n; j++){
                    if (A[i][j]==0){
                        k+=1;
                        }}}
            printf("\n");
            printf("\n");
            if (k>0){
                for (int i=0; i<n;i++){
                    for (int j=0; j<n; j++){
                        printf("%lf ", pA[i][j]);}
                    printf("\n");}
            }
            else{
                for (int i=0; i<n;i++){
                    for (int j=0; j<n; j++){
                        printf("%lf ", A[i][j]);}
                    printf("\n");}
            }
            free(B);
            B=NULL;
            free(C);
            C=NULL;
            free2(A,n);
            free2(pA,n);
            break;
        default:
            printf("неккоректный ввод \n");
    }
}
// double **A=rmatr(3);
// double *B=maxmatr(A,3);
// double *C=vektr(A,B,3);
// double **pA=perev(A,3);
// for (int i=0; i<3;i++){
//         for (int j=0; j<3; j++){
//             printf("%lf \n", A[i][j]);}
// }
// for (int i=0; i<3; i++){
//     printf("%lf  ",B[i]);
// }

// for (int i=0; i<3; i++){
//     printf("%lf  ",C[i]);
// }
// for (int i=0; i<3;i++){
//         for (int j=0; j<3; j++){
//             printf("%lf \n", pA[i][j]);}
// }
}