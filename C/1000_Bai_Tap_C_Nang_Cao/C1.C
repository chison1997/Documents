//Bài 1: Tính S(n) = 1 + 2 + 3 + ... + n
#include <stdio.h>

main()
{
        long int S=0;
        int i,n;
        printf("n= "); scanf("%d",&n);
        for(i=1; i<=n; i++) S+=i;
        
        printf("S(%d)=%d",n,S);
       
}
