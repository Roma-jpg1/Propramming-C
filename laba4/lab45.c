#include <stdio.h>
int main(){
	int height;
	int cha = 0;
	int cnk =0;
	int k;
	scanf("%d",&height);
	for (int i =0;i<height;i++){
	if (height/2+1>i){
		for (int j=0; i>j;j++){
			printf(" ");}
			for (int cnt =0; height-i*2>cnt;cnt++){
				printf("1");}
		printf("\n");

	}

	else{
		for (k =1;k<(height - 2*cha)/2;k++){
			printf(" ");}
		for (int h =0; h<3+2*cha;h++){
			printf("1");}
		printf("\n");
		cha++;
		}
}
}
