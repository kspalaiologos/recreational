
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define P(a,b) {u32 x=a;x^=x>>17;x*=0xed5ad4bbU;x^=x>>11;x*=0xac4c1b51U;x^=x>>15;x*=0x31848babU;x^=x>>14;b=x;}

typedef uint32_t u32;

u32*mem,s;uint16_t t[16640],ai;void gw(u32 a){if(__builtin_expect(a>=s,0)){u32 i=s;s=a+1;mem=realloc(mem,s*sizeof(u32));while(i<s)
{P(i,mem[i]);i++;}}}u32 mg(u32 a){gw(a);return mem[a];}void ms(u32 a,u32 v){gw(a);mem[a]=v;}int sse(int p,int c,int b){int g=(b
<<16)+(b<<6)-b-b;t[ai]+=(g-t[ai])>>6;t[ai+1]+=(g-t[ai+1])>>6;int w=p&127;ai=(p>>2)+(c<<6)+c;return(t[ai]*(128-w)+t[ai+1]*w)>>15;
}u32 pc(u32 x){x-=(x>>1)&0x55555555;x=(x&0x33333333)+((x>>2)&0x33333333);x=(x+(x>>4))&0x0f0f0f0f;return(x*0x01010101)>>24;}
int main(int argc,char*argv[]) {for(int i=0;i<256;i++)for(int j=0;j<65;j++)t[i*65+j]=i==0?j<<10:t[j];FILE*in=fopen(argv
[1],"rb");u32 idx=0;while(!feof(in)){uint8_t instr=fgetc(in);ms(idx,mg(idx)^instr);idx++;if((instr&15)==15){u32 value=0;
for(int i=0;i<4;i++)value=(value<<8)|fgetc(in);ms(idx,mg(idx)^value);idx++;}}fclose(in);for(u32 i=1;i<idx;i++)ms(idx,mg
(idx)^sse(mg(i-1)&255,mg(i)&255,pc(mg(i))&1));u32 a=0x66,b=0xF0,c=0x0F,ip=0;for(;;){switch(mg(ip++)){
case 0x0F:a=mg(ip++);break;                           case 0x1F:b=mg(ip++);break;
case 0x2F:c=mg(ip++);break;                           case 0x3F:ip=mg(ip++);break;
case 0x4F:if(a<=b)ip=mg(ip++);break;                  case 0x5F:if(b>=c)ip=mg(ip++);break;
case 0x6F:a=sse(b&0xFF,c&0xFF,pc(mg(ip++))&1);break;  case 0x00:ms(ip++,a);break;
case 0x10:ms(ip++,b);break;                           case 0x20:ms(ip++,c);break;
case 0x30:ms(a,b);break;                              case 0x40:ms(a,c);break;
case 0x50:ms(a,mg(a));break;                          case 0x60:b=a;break;
case 0x70:c=a;break;                                  case 0x80:a=b;break;
case 0x90:a=c;break;                                  case 0xA0:ip=a;break;
case 0xB0:a=b+c;break;                                case 0xC0:a=b-c;break;
case 0xD0:putchar(a);break;                           case 0xE0:a=getchar();break;
case 0xF0:return 0;                                   default:P(a,a);P(b,b);P(c,c);}}}
