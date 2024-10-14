#include <stdio.h>

int main(){

int s,n, a = 7;
for (s=0,n=2; n<a; n++){
	if (a%n==0){
		s=1;
		break;
}

}
printf("%d",s);
}
