#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define nt op[op[0]++]
#define ot *sp--
#define C;break;case
typedef struct c_{struct c_*Q,*W;int E,R;}Z;long ip,_A;_B[10000];
Z _R={.E=999};Z*Y,*S,*W=&_R;FILE*in;void G(Z*p){for(;p&&p!=&_R;p=
p->W){if(--p->E)break;G(p->Q);p->Q=Y;Y=p;}}char I(){int c;while((
c=fgetc(in))!=EOF&&(c<'0'||c>'9'));return c==EOF?-1:c&1;}_P(){int
t,s=_A,b,m=0;for(;;){if((b=I())==-1){if(!m)break;}else if(b){for(
t=0;I(); )++t;_B[_A++]=1;_B[_A++]=t;break;}else if(I()){t=_A;_A+=
2;_B[t]=2;_B[t+1]=_P();m=1;}else{_B[_A++]=2+1;}}return _A-s;}main
(int _,char*v[]){long i;char*k="CVDCJBADCDCCBADCECBBAAAC";for(_A=
0;_A<24;++_A)_B[_A]=k[_A]-'A';++_A;in=fopen(v[1],"rb");_B[24]=_P(
);char o[ftell(in)];int po=0;rewind(in);Z *t,*e;for(;;)switch(_B[
ip]){C 1:e=t=W;for(int i=0;i<_B[ip+1]&&e!=&_R;++i)e=e->Q;ip=e->R;
W=(++(e->W)->E,e->W);G(t);break;C 2:if(!(t=Y)){t=calloc(1,sizeof(
Z));}Y=t->Q;t->E=1;t->R=ip+2+_B[ip+1];t->W=t->R>_B[1]&&t->R!=_A?(
++W->E,W):&_R;t->Q=S;S=t;ip+=2;C 3:if(!S){long s=0L,ind=0,c;while
(!feof(in)){c=fgetc(in);if(c==EOF)break;s+=c; if(isdigit(c))if(o[
ind++]!=(c&1))exit(1);}if(s%2!=o[ind])exit(1);rewind(in);ip=0;fth
();exit(0);}Z*t=S;S=t->Q;t->Q=W;W=t;++ip;C 0:o[po++]=ip&1;ip=2;G(
W);W=&_R;break;}}op[60000]={32},L=1,t=64,w,STK[10000],*sp=STK,top
;char s[10000];void _W(x){nt=L;L=*op-1;nt=t;nt=x;fscanf(in,"%s",s
+t);t+=strlen(s+t)+1;}exec(x){switch(op[x++]){C 5:for(w=fscanf(in
,"%s",s)<1?exit(0),0:L;strcmp(s,&s[op[w+1]]);w=op[w]);w-1?exec(w+
2):(nt=2,nt=atoi(s))C 12:ip=op[op[1]--] C 2:op[++op[1]]=ip;ip=x C
15:top=sp[-top] C 1:nt=x C 7:op[top]=ot;top=ot C 0:*++sp=top;top=
op[ip++]C 8:top=ot-top C 6:top=op[top] C 10:top=ot/top C 3:_W(1);
nt=2 C 11:top=top<=0; C 4:*op-=2;nt=2; C 13:putchar(top);top=ot C
14:*++sp=top;top=getchar();C 9:top*=ot;}}fth(){_W(3);_W(4);_W(1);
w=*op;nt=5;nt=2;ip=*op;nt=w;nt=ip-1;for(w=6;w<16;)_W(1),nt=w++;op
[1]=*op;*op+=512;for(;;)exec(op[ip++]);}
