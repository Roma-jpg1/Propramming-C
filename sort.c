#include<stdio.h>
void Insertsort(int n, int a[], int *Cf, int *Mf) {
    for (int i = 1; i < n; i++) {
        int t = a[i];
        (*Mf)++;
        int j = i - 1;

        while (j >= 0) {
            (*Cf)++;  
            if (t < a[j]) {
                a[j + 1] = a[j];  
                (*Mf)++;
                j = j - 1;
            } else {
                break;
            }
        }

        a[j + 1] = t;  
        (*Mf)++;
    }
} //проверка


//проверка3

//check4

int main(){
    int a[]={4,2};
    Insertsort(2,a,NULL,NULL);
    print("hello git/n");
}