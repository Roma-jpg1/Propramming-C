# include <stdio.h>
int main(){
int a=17,s,n,k;
for (n=a, s=0; n!=0;n=n/10){
	k=n%10;
	s=s*10+k;

}

printf("%d %d %d",a,k,s);
}
