#include <stdio.h>

int g(){
    int c=getchar();if(c=='0'||c=='1')return c-'0';if(c<0)exit(0);return g();}

int main(void){
    int r;scanf("%d",&r);int tab[]={r&1,r&2,r&4,r&8,r&16,r&32,r&64,r&128};
    int a=g(),b=g(),c=g();for(;;){putchar('0'+!!tab[a*4+b*2+c]);a=b;b=c;c=g();}}
