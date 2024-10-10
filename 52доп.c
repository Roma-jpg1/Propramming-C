#include <stdio.h>
int x;
int p;
int bit(unsigned int a){
    unsigned int b =a;
    int count =0;
    b=b>>16;
    return b&0xff; 

    }
// 0xBBCA 1011101111001010
// &      0000000000001111
int main(){
    scanf("%x",&x);
    p=bit(x);
    printf("%x",p);
}

111

