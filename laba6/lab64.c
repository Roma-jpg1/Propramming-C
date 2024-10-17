#include <stdio.h>

int main (){
    int i;
    int j;
    int a [10] = {-1,2,3,-4,5,6,-7,8,9,10};
    int b [10] = {-23,57,35,34,-25,-74,34343,1,1,5};
    int len = sizeof(a)/sizeof(a[0])*2;
    int c [len];
    int k=0;
    int n=0;
    int max = -100000;
    int bz = 0;
    float sr =0;
    int sum =0;
    int ku =0;


for (i=0; i < len; i++){

    if (i%2==0){
        c[i]=a[k];
        k+=1;}
    else{
        c[i]=b[n];
        n+=1;}
    

}

for (int y=0; y < len/2; y++){
    if (max<a[y]){
        max = a[y]; //максимальное реальных
    }
    if (b[y]<0){
        bz+=1;} //количество мнимых меньше нуля
}
for (j=0; j < len; j++) {
    sum+=c[j];}
sr = sum/len; //среднее арифм всех чисел

for (int v = 0; v < len; v++) {
    printf("%d ", c[v]);
}
printf("\n");
printf("%d \n",max);
printf("%d \n",bz);
printf("%f \n",sr);

}