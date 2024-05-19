
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdint.h>

#define TRAV(x,y) for (N1*x=y->c;x;x=x->s)
#define Fi(n,a...) for(I i=0;i<n;i++){a;}
#define B break;

typedef int I; typedef void V; typedef unsigned short T;
typedef struct N1{I v,m;struct N1*s,*c,*p;}N1;N1*r1,*r2,*np;I npc;
void m(N1*n){if(n->m)return;n->m=1;TRAV(x,n)m(x);}
N1*tmk(uint32_t v){N1*O=0;Fi(npc,if(!np[i].m){O=&np[i];B})
  if(!O){np=realloc(np,sizeof(N1)*(npc<<=1));memset(&np[npc>>1],0,sizeof(N1)*(npc>>1));O=&np[npc>>1];}
  O->v=v;O->s=O->c=0;O->m=1;return O;}
I tsx(N1*O){I sum=0;TRAV(x,O)sum+=tsx(x);return O->v+sum;}
V tnx(N1*O){O->v=-O->v;TRAV(x,O)tnx(x);}I tcnt(N1*O){I c=0;TRAV(_,O)c++;return c;}
void tright(N1*O){N1*C=O->c;O->c=C->s;C->s=O->c->c;O->c->c=C;}
void tleft(N1*O){N1*C=O->c;O->c=C->c;C->c=O->c->s;O->c->s=C;}
N1 * tcopy(N1*O){
  N1*w=tmk(O->v),*C,*q,*s,*c;TRAV(C,O){c=tcopy(C);c->p=w;c->s=w->c;w->c=c;}
  for(C=w->c,q=0;C;){s=C->s;C->s=q;q=C;C=s;}w->c=q;return w;}
V tdi(N1*O,I d){Fi(d,printf("  "))printf("%d\n",O->v);TRAV(C,O)tdi(C,d+1);}
N1*run(N1*R,char*pr,I pl) {
  N1*C=R,*O;r1=tmk(0);r2=tmk(0);Fi(pl,switch(pr[i]){
    case'A':O=tmk(pr[++i]);O->p=C;O->s=C->c;C->c=O;B
    case'B':(O=C->c)&&(C->c=O->s);B
    case'C':O=C->c;Fi(r1->v)O=O->s;r2=O;B
    case'D':O=C->c;Fi(r1->v-1)O=O->s;O->s=r2;B
    case'E':C->v=tsx(C);B
    case'F':tnx(C);B
    case'G':r1->v=tcnt(C);B
    case'H':O=r1;r1=r2;r2=O;B
    case'I':tright(C);B
    case'J':tleft(C);B
    case'K':r1=tcopy(C);B
    case'L':r1=C;B
    case'M':C=C->p;B
    case'N':C=C->c;B
    case'O':C=C->s;B
    case'P':C=r1;B
    case'Q':if(!C->v)i-=r1->v;else i+=r1->v;B
    case'R':putchar(C->v);B
    case'S':C->v=getchar();B
    case'T':C->v=r1->v*r2->v;B
    case'U':tdi(C,0);B
    case'V':C=R;B
    case'W':if(!C->v)i+=r1->v;B}if(rand()%10==0){Fi(npc,np[i].m=0);m(r1);m(r2);m(R);m(C);})return C;}
typedef struct N2{struct N2*p,*a,*b;T s;I v,o;}N2;N2 n2p[512];int n2i=0;
N2*mn2(N2*p,T s,I v,I o){N2*O=&n2p[n2i++];O->p=p;O->a=O->b=0;O->s=s;O->v=v;O->o=o;return O;}
N2*n2s(T s,N2**z,N2**ss){N2*l=mn2(*z,0xFFFF,0,(*z)->o-2),*r=mn2(*z,s,1,(*z)->o-1),*q=*z;(*z)->s=0xFFFE;(*z)->a=l;ss[s]=(*z)->b=r;*z=l;return q;}
N2*fr(N2*m,N2*R){N2*r=m,*t;if(R->v>r->v&&R->a&&R->b){
  t=fr(r,R->a);if(t)r=t;t=fr(r,R->b);if(t)r=t;}else if(R->v==r->v&&R->o>r->o)r=R;return r!=m?r:0;}
V swpn2(N2*n1,N2*n2){
  I t=n1->o;n1->o=n2->o;n2->o=t;if(n1->p->a==n1)n1->p->a=n2;else n1->p->b=n2;
  if(n2->p->a == n2)n2->p->a=n1;else n2->p->b=n1;N2*t2=n1->p;n1->p=n2->p;n2->p=t2;}
void updn2(N2*s,N2*R){for(N2*r;s->p;s->v++,s=s->p){r=fr(s,R);if(r&&s->p!=r)swpn2(s,r);}s->v++;}
int main(int argc,char*argv[]){
  #define RF if(!bc){bits=fgetc(in);bc=8;}
  srand(time(NULL));
  if (argc!=2){fprintf(stderr,"Usage: %s <file>\n",argv[0]);return 1;}
  FILE * in=fopen(argv[1],"rb");
  if (!in){perror("fopen");return 1;}
  I pr_cap=1024,pl=0;char * pr=malloc(pr_cap);I bits=0,bc=0,c;
  N2*R=mn2(NULL,0xFFFF,0,512),* z=R,* n,* ss[256];memset(ss,0,sizeof(ss));
  for (;;updn2(n,R)) {
    for(n=R;n->a||n->b;){RF n=(bits>>--bc)&1?n->b:n->a;}
    if(n->s==0xFFFF){
      RF c=(bits>>--bc)&1;if(c)B c=0;Fi(8,RF c|=((bits>>--bc)&1)<<i)pr[pl++]=c;n=n2s(c,&z,ss);
    }else pr[pl++]=n->s;if(pl==pr_cap)pr=realloc(pr,pr_cap*=2);}
  np=malloc(sizeof(N1)*(npc=64));memset(np,0,sizeof(N1)*npc);run(tmk(0),pr,pl);fclose(in);free(pr);free(np);}
