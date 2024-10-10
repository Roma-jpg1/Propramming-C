#include <stdio.h>

int poisk(unsigned int a){
	unsigned int b =~a;
	int count =0;
	while ((b&1)==0){
		b = b>>1;
		count++;}
	return count;
}

int main(){
unsigned int x;
int p;
scanf("%u", &x);
p = poisk(x);
printf("%d \n",p);


}
