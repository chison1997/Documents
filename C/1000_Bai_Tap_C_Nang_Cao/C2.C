//Bài 2: Tính S(n) = 1^2 + 2^2 + ... + n^2

#include <stdio.h>
main()
{
        int S=0;
        int n;
        printf("n= "); scanf("%d",&n);
        for(int i=1;i<=n;i++) S+=i*i;
        printf("S(%d)=%d \n",n,S);
}
        
