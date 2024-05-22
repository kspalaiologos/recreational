
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdint.h>

#define TRAV(x,y) for (I x=NP(y)->c;x;x=NP(x)->s)
#define Fi(n,a...) for(I i=0;i<n;i++){a;}
#define B break;
#define NP(x) (&np[x])

typedef int I; typedef void V; typedef unsigned short T;
typedef struct N1{I v,m,s,c,p;}N1;I r1,r2;N1*np;I npc;
void m(I n){if(NP(n)->m)return;NP(n)->m=1;TRAV(x,n)m(x);}
I tmk(uint32_t v){N1*O=0;Fi(npc,if(!np[i].m){O=&np[i];B})
  if(!O){np=realloc(np,sizeof(N1)*(npc<<=1));memset(&np[npc>>1],0,sizeof(N1)*(npc>>1));O=&np[npc>>1];}
  O->v=v;O->s=O->c=0;O->m=1;return O-np;}
I tsx(I O){I sum=0;TRAV(x,O)sum+=tsx(x);return NP(O)->v+sum;}
V tnx(I O){NP(O)->v=-NP(O)->v;TRAV(x,O)tnx(x);}I tcnt(I O){I c=0;TRAV(_,O)c++;return c;}
void tright(I O){I C=NP(O)->c;NP(O)->c=NP(C)->s;NP(NP(C)->s)->p=NP(O)->c;NP(C)->s=NP(NP(O)->c)->c;NP(NP(O)->c)->c=C;}
void tleft(I O){I C=NP(O)->c;NP(O)->c=NP(C)->c;NP(NP(C)->c)->p=NP(O)->c;NP(C)->c=NP(NP(O)->c)->s;NP(NP(O)->c)->s=C;}
I tcopy(I O){
  I w=tmk(NP(O)->v),C,q,s,c;TRAV(C,O){c=tcopy(C);NP(c)->p=w;NP(c)->s=NP(w)->c;NP(w)->c=c;}
  for(C=NP(w)->c,q=0;C;){s=NP(C)->s;NP(C)->s=q;q=C;C=s;}NP(w)->c=q;return w;}
V tdi(I O,I d){Fi(d,printf("  "))printf("%d\n",NP(O)->v);TRAV(C,O)tdi(C,d+1);}
N1*run(I R,char*pr,I pl) {
  I C=R,O;r1=tmk(0);r2=tmk(0);Fi(pl,switch(pr[i]){
    case'A':O=tmk(pr[++i]);NP(O)->p=C;NP(O)->s=NP(C)->c;NP(C)->c=O;B
    case'B':(O=NP(C)->c)&&(NP(C)->c=NP(O)->s,NP(NP(O)->s)->p=NP(C)->c);B
    case'C':O=NP(C)->c;Fi(NP(r1)->v,O=NP(C)->s);r2=O;B
    case'D':O=NP(C)->c;Fi(NP(r1)->v-1,O=NP(C)->s);NP(O)->s=r2;B
    case'E':NP(C)->v=tsx(C);B
    case'F':tnx(C);B
    case'G':NP(r1)->v=tcnt(C);B
    case'H':O=r1;r1=r2;r2=O;B
    case'I':tright(C);B
    case'J':tleft(C);B
    case'K':r1=tcopy(C);B
    case'L':r1=C;B
    case'M':C=NP(C)->p;B
    case'N':C=NP(C)->c;B
    case'O':C=NP(C)->s;B
    case'P':C=r1;B
    case'Q':if(!NP(C)->v)i-=NP(r1)->v;else i+=NP(r1)->v;B
    case'R':putchar(NP(C)->v);B
    case'S':NP(C)->v=getchar();B
    case'T':NP(C)->v=NP(r1)->v*NP(r2)->v;B
    case'U':tdi(C,0);B
    case'V':C=R;B
    case'W':if(!NP(C)->v)i+=NP(r1)->v;B}if(rand()%10==0){Fi(npc,np[i].m=0);m(r1);m(r2);m(R);m(C);})return NP(C);}
typedef struct N2{struct N2*p,*a,*b;T s;I v,o;}N2;N2 n2p[513];int n2i=0;
N2*mn2(N2*p,T s,I v,I o){N2*O=&n2p[n2i++];O->p=p;O->a=O->b=0;O->s=s;O->v=v;O->o=o;return O;}
N2*n2s(T s,N2**z){N2*l=mn2(*z,0xFFFF,0,(*z)->o-2),*r=mn2(*z,s,1,(*z)->o-1),*q=*z;(*z)->s=0xFFFE;(*z)->a=l;(*z)->b=r;*z=l;return q;}
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
  N2*R=mn2(NULL,0xFFFF,0,512),*z=R,*n;
  for (;;updn2(n,R)) {
    for(n=R;n->a||n->b;){RF n=(bits>>--bc)&1?n->b:n->a;}
    if(n->s==0xFFFF){
      RF c=(bits>>--bc)&1;if(c)B c=0;Fi(8,RF c|=((bits>>--bc)&1)<<i)pr[pl++]=c;n=n2s(c,&z);
    }else pr[pl++]=n->s;if(pl==pr_cap)pr=realloc(pr,pr_cap*=2);}
  np=malloc(sizeof(N1)*(npc=64));memset(np,0,sizeof(N1)*npc);run(tmk(0),pr,pl);fclose(in);free(pr);free(np);}
