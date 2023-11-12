#define J putchar
#define H O->a
#define G H->a
#define K O->b
typedef struct x{struct x*a,*b;int q;}Y;Y*O;z=1;A(q){O=calloc(6,4);O->q=q;}h(Y*O){Y*u;O=H&&H->q==2?z=K:H&&G&&G->q==1?z=H->b:H&&G&&G->a&&!G->a->q?u=A(3),(u->a=A(3))->a=G->b,(u->b=A(3))->a=H->b,u->a->b=u->b->b=K,z=u:(O->q==3?H=h(H),K=h(K):0,O);}r(x){Y*O;x=getchar()-73;x=x+33?A(x?x!=10:2):!getchar(K=r(H=r(O=A(3))))+O;}q(Y*O){O&&J(O->q["SKI "],O->q-3||J(41,q(K),q(H),J(40)));}main(){Y*O=r();for(;z;O=h(O))z=0;q(O);}
