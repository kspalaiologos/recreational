#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef int I;
typedef short T;
typedef long long L;
typedef unsigned long long U;
typedef void V;
typedef char C;
typedef unsigned int D;
typedef unsigned char B;
#define S static
#define SI static int
#define SV static void
#define SC static char
#define W while
#define R return
#define IF(c,b...) if(c){b;}
#define ELSE(b...) else{b;}
#define _(a...) {return({a;});}
#define Fi(n,a...) for(int i=0;i<n;i++){a;}
#define Fj(n,a...) for(int j=0;j<n;j++){a;}
#define Fx(n,a...) for(int x=0;x<n;x++){a;}
#define Fy(n,a...) for(int y=0;y<n;y++){a;}
#define F_(z,i,n,a...) for(int z=i;z<n;z++){a;}
#define F1(n,x,a...) for(i32 i=0;i<n;i+=x){a;}

typedef struct E{I t;union{struct{struct E*l,*r;}c;C*v;I r;struct{I f;struct E*a;}ap;};}E;
typedef struct{C*s;E*d;}O;E*me(I t)_(E*e=malloc(sizeof(E));e->t=t;e)
E*mc(E*l,E*r)_(E*e=me(0);e->c.l=l;e->c.r=r;e)E*mf(C*v)_(E*e=me(1);e->v=v;e)
E*mr(I r)_(E*e=me(2);e->r=r;e)E*ma(I f,E*a)_(E*e=me(3);e->ap.f=f;e->ap.a=a;e)
FILE*in;U l,h=0xffffffffffffffffLL,x;D cxt,_pr=0xFFFFFFFF;
I ct[512][2];V up(I y){IF(++ct[cxt][y]>0xFFFFFFF,ct[cxt][0]>>=1,ct[cxt][1]>>=1)
  cxt=(cxt<<1)|y;cxt&=0xff;_pr=(((U)(ct[cxt][1]+1)<<32)/(ct[cxt][0]+ct[cxt][1]+2));}
I rb(){U m=l+((h-l)>>32)*_pr;I y=x<=m;if(y)h=m;else l=m+1;up(y);
  W(((l^h)&0xff00000000000000LL)==0){l=l<<8;h=h<<8|0xff;I c=getc(in);if(c==EOF)c=0;x=x<<8|c;}R y;}
D eg(){D l2=0;W(rb())l2++;D v=0;W(l2--)v=(v<<1)|rb();R v;}
O**fs;D*fns,nfs;E*pe(){C t=rb()*2+rb();switch(t){case 0:R mc(pe(),pe());
  case 1:D len=eg();C*v=calloc(len+1,1);Fi(len,v[i]=rb()?49:48);R mf(v);
  case 2:R mr(eg());case 3:D x=eg();R ma(x, pe());}}
V pf(){fs=calloc(nfs=eg(),sizeof(O*));fns=calloc(nfs,sizeof(O));
  Fi(nfs,fs[i]=calloc(fns[i]=eg(),sizeof(O));
    Fj(fns[i],O*op=&fs[i][j];D len;op->s=calloc((len=eg())+1,1);
      Fx(len,op->s[x]=rb()?49:48)op->d=pe()))}
I pre(C*w, C*z){W(*w)IF(*w!=*z,R 0)ELSE(w++,z++)R 1;}C*eval(I f, C*in);
C*de(E*e,C*in){switch(e->t){case 2:R strdup(!e->r?in:e->r>=strlen(in)?"":in+e->r);
case 1:R strdup(e->v);case 0:C*l=de(e->c.r,in),*r=de(e->c.l,in),*o=malloc(strlen(l)+strlen(r)+1);
       strcpy(o,l);strcat(o,r);free(l);free(r);R o;
case 3:R eval(e->ap.f,de(e->ap.a,in));}}
C*eval(I f,C*in){O*ops=fs[f];re:Fj(strlen(in),Fi(fns[f],if(pre(ops[i].s,in+j)){
  C*o=de(ops[i].d,in+j+strlen(ops[i].s));C*ni=malloc(strlen(o)+strlen(in)-strlen(ops[i].s)+1+j);
  strncpy(ni,in,j);ni[j]=0;strcat(ni,o);strcat(ni,in+j+strlen(ops[i].s));free(in);free(o);in=ni;
  goto re;}))R in;}
I main(I ac, C*av[]){in=fopen(av[1],"rb");
    Fi(8,I c=getc(in);if(c==EOF)c=0;x=x<<8|c)pf();C*ni=malloc(strlen(av[2])+5);
    strcpy(ni,"000");strcat(ni,av[2]);C*r=eval(0,ni);printf("%s\n",r);}

