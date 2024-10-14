#include <stdio.h>
int main(){
int k, s, n;
int a=1239422;
	for (n=a, s=0; n!=0; n=n/10){
		k =n%10;
		if (k>s){
			s=k;
printf("%d",s);
}

}

printf("%d %d %d",k,s,n);

}
