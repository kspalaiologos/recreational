
        #define f(k)if(k==a)\
     do k+=*p;while(*p++==a*a+30)
   unsigned char*b,*m,*d,*p;k,c,y,x
  ,a=15,v,z=1<<31;g(){for(b=p;c=*p++
  ,k=c>>4,x=c&a,1;){f(k);d=mempcpy(d,
  p,k);if((               p+=k)>=b+v)
  break;y=*p               ++;y|=*p\
  ++<<8;f(x)
  ;for(m=d-y
  ,x+=4;x--;               *d++=*m++
  );}}q=420;               main(int
  o,char**a)                  {a++
  ;struct stat                  t
  ;fstat(k=open(*a++,0),&t);for(p=6+
   mmap(x=0,t.st_size,1,1,k,0);x<8;x
    ++)c|=*p++<<x*8;ftruncate(k=open
     (*a,578,q),c);for(p++  ,d=mmap(
        0,c,2,o=1,k,0        );o;v=
                              o&~-
                              z,d=
                   o&z?(p+=v,mempcpy(d,p-v,v
                   )):(g(),d))for(x=o=0;x<4;
                    x++)o|=         *p++<<x
                      *8;             }/
