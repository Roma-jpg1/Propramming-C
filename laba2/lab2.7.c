#include <stdio.h>

int main(){
int n =2, flag =0,a=7;
while(a%n!=0){
	n++;
	if (n==a){
		flag =1;
		break;
}

}

printf("%d %d %d", n,flag,a);

}
