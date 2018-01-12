//Bài 3: Tính S(n) = 1 + ½ + 1/3 + ... + 1/n
#include <stdio.h>
main()
{
        float S=0;
        int n;
        printf("n= ");scanf("%d",&n);
        for(int i=1;i<=n;i++) S+=1.0/i;
        printf("S(%d)=%6.2f",n,S);
}


