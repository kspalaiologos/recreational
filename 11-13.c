#include <stdio.h>         /* ~~~~ ~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~~-~-~ ~~~~ */
#include <stdlib.h>        /*  SINGLE PAGE COMPRESSOR AND DECOMPRESSOR. MADE FOR THE ESOLANGS CODE GUESSING EVENT  --  0cad412cafd2fc03d47c72673061a2c3b873d81d  */
#include <string.h>        /*  Contains a suffix array implementation written by Yuta Mori in 2010. Default block size is 65K. Works great on low-entropy data.  */
typedef void*V;typedef int I;typedef unsigned U;typedef unsigned char Q;typedef unsigned long long R;Q tb[256];Q*iq,*oq;I ip,op,im;U lo,hi,c;unsigned short t0[256],t1[256][256],t2[2][256][17];I c1,c2,r;I bs=1<<16;
#define H(a)(cs==sizeof(I)?((I*)T)[a]:((Q*)T)[a])
#define DQ(a)unsigned short B0_##a(unsigned short p){return p-(p>>a);}
#define DR(a)unsigned short B1_##a(unsigned short p){return p+((p^65535)>>a);}
void gc(V T,I*C,I n,I k,I cs){I i;for(i=0;i<k;++i)C[i]=0;for(i=0;i<n;++i)++C[H(i)];}DQ(2);DQ(4);DQ(6);DR(2);DR(4);DR(6);
void gb(I*C,I*B,I k,I e){I i,s=0;if(e)for(i=0;i<k;++i)s+=C[i],B[i]=s;else for(i=0;i<k;++i)s+=C[i],B[i]=s-C[i];}void ls1(V T,I*SA,I*C,I*B,I n,I k,I cs){I*b,i,j,c0,c1;if(C==B)gc(T,C,n,k,cs);gb(C,B,k,0);j=n-1;b=SA+B[
c1=H(j)];--j;*b++=(H(j)<c1)?~j:j;for(i=0;i<n;++i){if(0<(j=SA[i])){if((c0=H(j))!=c1)B[c1]=b-SA,b=SA+B[c1=c0];--j;*b++=(H(j)<c1)?~j:j;SA[i]=0;}else if(j<0)SA[i]=~j;}if(C==B)gc(T,C,n,k,cs);gb(C,B,k,1);for(i=n-1,b=SA+
B[c1=0];0<=i;--i){if(0<(j=SA[i])){if((c0=H(j))!=c1)B[c1]=b-SA,b=SA+B[c1=c0];--j;*--b=(H(j)>c1)?~(j+1):j;SA[i]=0;}}}I lp1(V T,I*SA,I n,I m,I cs){I i,j,p,q,pl,ql,nm,c0,c1,diff;for(i=0;(p=SA[i])<0;++i)SA[i]=~p;if(i<m
){for(j=i,++i;;++i){if((p=SA[i])<0){SA[j++]=~p;SA[i]=0;if(j==m)break;}}}i=n-1;j=n-1;c0=H(n-1);do c1=c0;while(0<=--i&&(c0=H(i))>=c1);while(0<=i){do c1=c0;while(0<=--i&&(c0=H(i))<=c1);if(0<=i){SA[m+((i+1)>>1)]=j-i;j
=i+1;do c1=c0;while(0<=--i&&(c0=H(i))>=c1);}}for(i=0,nm=0,q=n,ql=0;i<m;++i){p=SA[i],pl=SA[m+(p>>1)],diff=1;if(pl==ql&&(q+pl)<n){for(j=0;j<pl&&H(p+j)==H(q+j);++j);if(j==pl)diff=0;}if(diff)++nm,q=p,ql=pl;SA[m+(p>>1)
]=nm;}return nm;}void ls2(V T,I*SA,I*C,I*B,I*D,I n,I k,I cs){I*b,i,j,t,d,c0,c1;gb(C,B,k,0);j=n-1;b=SA+B[c1=H(j)];--j;t=(H(j)<c1);j+=n;*b++=t&1?~j:j;for(i=0,d=0;i<n;++i){if(0<(j=SA[i])){if(n<=j)d+=1,j-=n;if((c0=H(j
))!=c1)B[c1]=b-SA,b=SA+B[c1=c0];--j;t=c0;t=(t<<1)|(H(j)<c1);if(D[t]!=d)j+=n,D[t]=d;*b++=(t&1)?~j:j;SA[i]=0;}else if(j<0)SA[i]=~j;}for(i=n-1;0<=i;--i){if(0<SA[i]){if(SA[i]<n){SA[i]+=n;for(j=i-1;SA[j]<n;--j);SA[j]-=
n;i=j;}}}gb(C,B,k,1);for(i=n-1,d+=1,b=SA+B[c1=0];0<=i;--i){if(0<(j=SA[i])){if(n<=j)d+=1,j-=n;if((c0=H(j))!=c1)B[c1]=b-SA,b=SA+B[c1=c0];--j;t=c0;t=(t<<1)|(H(j)>c1);if(D[t]!=d)j+=n,D[t]=d;*--b=(t&1)?~(j+1):j;SA[i]=0
;}}}I lp2(I*SA,I n,I m){I i,j,d,nm;for(i=0,nm=0;(j=SA[i])<0;++i){j=~j;if(n<=j)nm++;SA[i]=j;}if(i<m){for(d=i,++i;;++i){if((j=SA[i])<0){j=~j;if(n<=j)nm++;SA[d++]=j;SA[i]=0;if(d==m)break;}}}if(nm<m){for(i=m-1,d=nm+1;
0<=i;--i){if(n<=(j=SA[i]))j-=n,--d;SA[m+(j>>1)]=d;}}else{for(i=0;i<m;++i)if(n<=(j=SA[i]))j-=n,SA[i]=j;}return nm;}void isa(V T,I*SA,I*C,I*B,I n,I k,I cs){I*b,i,j,c0,c1;if(C==B)gc(T,C,n,k,cs);gb(C,B,k,0);j=n-1;b=SA
+B[c1=H(j)];*b++=(0<j&&H(j-1)<c1)?~j:j;for(i=0;i<n;++i){j=SA[i],SA[i]=~j;if(0<j){--j;if((c0=H(j))!=c1)B[c1]=b-SA,b=SA+B[c1=c0];*b++=(0<j&&H(j-1)<c1)?~j:j;}}if(C==B)gc(T,C,n,k,cs);gb(C,B,k,1);for(i=n-1,b=SA+B[c1=0]
;0<=i;--i){if(0<(j=SA[i])){--j;if((c0=H(j))!=c1)B[c1]=b-SA,b=SA+B[c1=c0];*--b=(!j||H(j-1)>c1)?~j:j;}else{SA[i]=~j;}}}I cb(V T,I*SA,I*C,I*B,I n,I k,I cs){I*b,i,j,pi=-1,c0,c1;if(C==B)gc(T,C,n,k,cs);gb(C,B,k,0);j=n-1
;b=SA+B[c1=H(j)];*b++=((0<j)&&(H(j-1)<c1))?~j:j;for(i=0;i<n;++i){if(0<(j=SA[i])){--j;SA[i]=~(I)(c0=H(j));if(c0!=c1){B[c1]=b-SA;b=SA+B[c1=c0];}*b++=(0<j&&H(j-1)<c1)?~j:j;}else if(j)SA[i]=~j;}if(C==B)gc(T,C,n,k,cs);
gb(C,B,k,1);for(i=n-1,b=SA+B[c1=0];0<=i;--i){if(0<(j=SA[i])){--j;SA[i]=(c0=H(j));if(c0!=c1){B[c1]=b-SA;b=SA+B[c1=c0];}*--b=(0<j&&H(j-1)>c1)?~(I)H(j-1):j;}else if(j)SA[i]=~j;else pi=i;}return pi;}I sm(V T,I*SA,I fs
,I n,I k,I cs,I isbwt){I*C,*B,*D,*RA,*b,i,j,m,p,q,t,nm,pi=0,nf,c0,c1;U fl;if(k<=256){C=malloc(k*sizeof(I));if(k<=fs){B=SA+(n+fs-k);fl=1;}else{B=malloc(k*sizeof(I));fl=3;}}else if(k<=fs){C=SA+(n+fs-k);if(k<=(fs-k))
{B=C-k;fl=0;}else if(k<=1024){B=malloc(k*sizeof(I));fl=2;}else B=C,fl=8;}else{B=C=malloc(k*sizeof(I));fl=12;}if(n<=0x3fffffff&&2<=n/k){if(fl&1)fl|=(k*2<=fs-k)?32:16;else if(!fl&&k*2<=fs-k*2)fl|=32;}gc(T,C,n,k,cs);
gb(C,B,k,1);for(i=0;i<n;++i)SA[i]=0;b=&t;i=n-1;j=n;m=0;c0=H(n-1);do c1=c0;while(0<=--i&&(c0=H(i))>=c1);while(0<=i){do{c1=c0;}while(0<=--i&&(c0=H(i))<=c1);if(0<=i){*b=j;b=SA+--B[c1];j=i;++m;do c1=c0;while(0<=--i&&(
c0=H(i))>=c1);}}if(1<m){if(fl&48){if(fl&16){D=malloc(k*2*sizeof(I));}else{D=B-k*2;}++B[H(j+1)];for(i=0,j=0;i<k;++i){j+=C[i];if(B[i]!=j)SA[B[i]]+=n;D[i]=D[i+k]=0;}ls2(T,SA,C,B,D,n,k,cs);nm=lp2(SA,n,m);if(fl&16)free
(D);}else{ls1(T,SA,C,B,n,k,cs);nm=lp1(T,SA,n,m,cs);}}else if(m==1)*b=j+(nm=1);else nm=0;if(nm<m){if(fl&4)free(C);if(fl&2)free(B);nf=(n+fs)-m*2;if(!(fl&13))if(k+nm<=nf)nf-=k;else fl|=8;RA=SA+m+nf;for(i=m+(n >> 1)-1
,j=m-1;m<=i;--i)if(SA[i])RA[j--]=SA[i]-1;sm(RA,SA,nf,m,nm,sizeof(I),0);i=n-1;j=m-1;c0=H(n-1);do c1=c0;while(0<=--i&&(c0=H(i))>=c1);while(0<=i){do c1=c0;while(0<=--i&&((c0=H(i))<=c1));if(0<=i){RA[j--]=i+1;do c1=c0;
while(0<=--i&&(c0=H(i))>=c1);}}for(i=0;i<m;++i){SA[i]=RA[SA[i]];}if(fl&4)C=B=malloc(k*sizeof(I));if(fl&2)B=malloc(k*sizeof(I));}if(fl&8)gc(T,C,n,k,cs);if(1<m){gb(C,B,k,1);i=m-1,j=n,p=SA[m-1],c1=H(p);do{q=B[c0=c1];
while(q<j)SA[--j]=0;do{SA[--j]=p;if(--i<0)break;p=SA[i];}while((c1=H(p))==c0);}while(0<=i);while(0<j)SA[--j]=0;}if(!isbwt)isa(T,SA,C,B,n,k,cs);else pi=cb(T,SA,C,B,n,k,cs);if(fl&5)free(C);if(fl&2)free(B);return pi;
}I AE(Q*T,Q*U,I n){I i,pi,*A=malloc(sizeof(I)*n);if(n==1){U[0]=T[0];return n;}pi=sm(T,A,0,n,256,sizeof(Q),1);if(pi<0)return pi;U[0]=T[n-1];for(i=0;i<pi;++i){U[i+1]=(Q)A[i];}for(i+=1;i<n;++i){U[i]=(Q)A[i];}free(A);
return pi+1;}Q*AD(Q*T,I n,I pi){I C[256];I*LF=malloc(sizeof(I)*n),i,t;Q*U=malloc(n);for(i=0;i<256;++i)C[i]=0;for(i=0;i<n;++i)LF[i]=C[T[i]]++;for(i=0,t=0;i<256;++i){t+=C[i];C[i]=t-C[i];}for(i=n-1,t=0;0<=i;--i){t=LF
[t]+C[U[i]=T[t]];t+=t<pi;}free(LF);return U;}I mtf(Q*str,I c){Q*q,*p;I sh=0;p=(Q*)malloc(257);memcpy(p,str,256);q=memchr(p,c,256);sh=q-p;memcpy(str+1,p,sh);str[0]=c;free(p);return sh;}void dc(Q*p,I size,Q*sym){I i
,index,c;for(i=0;i<256;i++)tb[i]=i;for(i=0;i<size;i++){c=tb[p[i]];index=mtf(tb,c);sym[i]=c;}sym[size]=0;}void en(Q*sym,I size,Q*p){I i=0;Q c;for(i=0;i<256;i++)tb[i]=i;for(i=0;i<size;i++){c=sym[i];p[i]=mtf(tb,c);}}
Q*pp(Q*s,I l,I*pir){Q*buf=malloc(l),*U=malloc(l);I pi=AE(s,U,l);en(U,l,buf);free(U);*pir=pi;return buf;}Q*dp(Q*s,I l,I pir){Q*buf=malloc(l),*dec;dc(s,l,buf);dec=AD(buf,l,pir);free(buf);return dec;}void wo(Q c){oq[
op++]=c;}Q ri(){if(ip<im)return iq[ip++];else return -1;}void b0(U p){lo+=(((R)(hi-lo)*p)>>18)+1;while((lo^hi)<(1<<24)){wo(lo>>24);lo<<=8;hi=(hi<<8)+255;}}void b1(U p){hi=lo+(((R)(hi-lo)*p)>>18);while((lo^hi)<(1<<
24)){wo(lo>>24);lo<<=8;hi=(hi<<8)+255;}}void F(){for(I i=0;i<4;++i){wo(lo>>24);lo<<=8;}}void N(){for(I i=0;i<4;++i)c=(c<<8)+ri();}I db(U p){U mid=lo+((R)(hi-lo)*p>>18);I b=(c<=mid);if(b)hi=mid;else lo=mid+1;while(
(lo^hi)<(1<<24)){lo<<=8;hi=(hi<<8)+255;c=(c<<8)+ri();}return b;}void nw(){c1=c2=r=lo=c=0;hi=(U)-1;for(I i=0;i<256;i++)t0[i]=1<<15;for(I i=0;i<256;i++)for(I j=0;j<256;j++)t1[i][j]=1<<15;for(I i=0;i<2;++i)for(I j=0;
j<256;++j)for(I k=0;k<17;++k)t2[i][j][k]=(k<<12)-(k==16);}void ed(U n){for(I i=0;i<32;++i){if(n&(1<<31))b1(1<<17);else b0(1<<17);n+=n;}}U dd(){U n=0;for(I i=0;i<32;++i){n+=n+db(1<<17);}return n;}void ef(I c){if(c1
==c2)++r;else r=0;I f=(r>2),ctx=1;while(ctx<256){I p0=t0[ctx],p1=t1[c1][ctx],p2=t1[c2][ctx],p=((p0+p1)*7+p2+p2)>>4,j=p>>12,x1=t2[f][ctx][j],x2=t2[f][ctx][j+1],ssep=x1+(((x2-x1)*(p&4095))>>12),bit=c&128;c+=c;if(bit
){b1(ssep*3+p);t0[ctx]=B1_2(t0[ctx]);t1[c1][ctx]=B1_4(t1[c1][ctx]);t2[f][ctx][j]=B1_6(t2[f][ctx][j]);t2[f][ctx][j+1]=B1_6(t2[f][ctx][j+1]);ctx+=ctx+1;}else{b0(ssep*3+p);t0[ctx]=B0_2(t0[ctx]);t1[c1][ctx]=B0_4(t1[c1
][ctx]);t2[f][ctx][j]=B0_6(t2[f][ctx][j]);t2[f][ctx][j+1]=B0_6(t2[f][ctx][j+1]);ctx+=ctx;}}c2=c1;c1=ctx&255;}I df(){if(c1==c2)++r;else r=0;I f=(r>2),ctx=1;while(ctx<256){I p0=t0[ctx],p1=t1[c1][ctx],p2=t1[c2][ctx],
p=((p0+p1)*7+p2+p2)>>4,j=p>>12,x1=t2[f][ctx][j],x2=t2[f][ctx][j+1],ssep=x1+(((x2-x1)*(p&4095))>>12),bit=db(ssep*3+p);if(bit){t0[ctx]=B1_2(t0[ctx]);t1[c1][ctx]=B1_4(t1[c1][ctx]);t2[f][ctx][j]=B1_6(t2[f][ctx][j]);t2
[f][ctx][j+1]=B1_6(t2[f][ctx][j+1]);ctx+=ctx+1;}else{t0[ctx]=B0_2(t0[ctx]);t1[c1][ctx]=B0_4(t1[c1][ctx]);t2[f][ctx][j]=B0_6(t2[f][ctx][j]);t2[f][ctx][j+1]=B0_6(t2[f][ctx][j+1]);ctx+=ctx;}}c2=c1;return c1=ctx&255;}
I compress(Q*buf,size_t size,char**res,size_t*ds){if(!size)return 1;nw();oq=malloc(size*2);op=0;I bsz=bs>size?size:bs,ch=size/bsz,pir,re;ed(size);for(I i=0;i<ch;i++){Q*p=pp(buf+i*bsz,bsz,&pir);ed(bsz);ed(pir);for(
I j=0;j<bsz;j++)ef(p[j]);free(p);}if(ch*bsz!=size){re=size-ch*bsz;Q*p=pp(buf+(size-re),re,&pir);ed(re);ed(pir);for(I j=0;j<re;j++)ef(p[j]);free(p);}ed(0);F();*ds=op;*res=oq;return 0;}I decompress(Q*buf,size_t size
,char**res,size_t*ds){iq=buf;im=size;ip=0;nw();N();I bsz=0,n,ms=dd(),idx;Q*data=NULL;oq=malloc(ms+1);op=0;while((n=dd())>0){if(!bsz){data=malloc(bsz=n);}idx=dd();for(I i=0;i<n;i++)data[i]=df();Q*buf=dp(data,n,idx)
;for(I i=0;i<n;i++)oq[op++]=buf[i];free(buf);}if(data)free(data);*ds=ms;*res=oq;return 0;}I main(I argc,char*argv[]){if(argc<3){printf("Usage: %s [-c/-d] <input> <output>\n",argv[0]);return 1;}FILE*f=fopen(argv[2]
,"rb");if(!f){printf("Could not open %s\n",argv[1]);return 1;}fseek(f,0,SEEK_END);I size=ftell(f);fseek(f,0,SEEK_SET);Q*data=malloc(size);fread(data,1,size,f);fclose(f);size_t ds;Q*dest;if(argv[1][1]=='c')compress
(data,size,&dest,&ds);else decompress(data,size,&dest,&ds);free(data);f=fopen(argv[3],"wb");if(!f){printf("Could not open %s\n",argv[2]);return 1;}fwrite(dest,1,ds,f);fclose(f);free(dest);}
