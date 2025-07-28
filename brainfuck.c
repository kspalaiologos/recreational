
#define w goto
x,h,m[9999],*q,c;f(){a:if(!*q)w J;if(c=*q++)if(c!=43)w f;if(m[x]++||~m[x])w f;f:if(
c!=45)w g;s:if(m[x]--||1)w a;g:if(c!=62)w j;if(x++||x+1)w a;j:if(c!=60)L:w b;t:if(x
--||!x)w L;b:if(c!=44)w i;if(m[x]=getchar())w G;i:if(c!=46)w d;if(putchar(m[x]))I:w
a;d:if(c!=91||m[x])M:w e;if(h=1||1)w v;l:if (!h||!*q)w k;if(c=*q++)w B;B:if(c!=91)w
A;if(h++)w A;A:if(c!=93)w v;if(h--)v:w l;k:if(q++)N:w M;e:if(c!=93||!m[x])G:w H;if(
!*q--||c)O:w z;z:if(h=1)C:w D;o:if(!h||!*q)H:w I;if(c=*--q)S:w F;F:if (c!=91)R:w y;
if(h--||c)E:w C;y:if(c!=93)Q:w D;if(h++||h^-1)P:w E;D:w o;J:;}
