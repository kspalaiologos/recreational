#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int pub[99][99];

int main(void) {
    int i=0,j=0,c=0,mi=0;
    while((c=getchar()) != -1) {
        if(c==10) {j++;if(mi<i)mi=i;i=0;}
        else if(c==48||c==49) {
            pub[j][i]=c-48;
            i++;
        }
    }

    const int max_x = mi, max_y = j; int sum = 0;
    for(int x1 = 0; x1 < max_x-1; x1++)
        for(int y1 = 0; y1 < max_y-1; y1++)
            for(int x2 = x1 + 1; x2 < max_x; x2++)
                for(int y2 = y1 + 1; y2 < max_y; y2++){
                    for (i = x1; i <= x2; i++)
                        if (pub[y1][i] != 1)
                            goto next;
                    for (i = y1; i <= y2; i++)
                        if (pub[i][x1] != 1)
                            goto next;
                    for (i = x1; i <= x2; i++)
                        if (pub[y2][i] != 1)
                            goto next;
                    for (i = y1; i <= y2; i++)
                        if (pub[i][x2] != 1)
                            goto next;
                    sum++;
                    next:;
                }
    printf("%d",sum);
}
