//Bài 8: Tính S(n) = ½ + ¾ + 5/6 + ... + 2n + 1/ 2n + 2
#include <stdio.h>
main()
{
        float S=0;
        int n;
        printf("n= ");scanf("%d",&n);
        for(int i=0;i<=n;i++) S+=(2*i+1)*1.0/(2*i+2);
        printf("S(%d)=%6.2f \n",n,S);
}
