//Bài 5: Tính S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n + 1)
#include <stdio.h>
main()
{
        float S=0;
        int n;
        printf("n= ");scanf("%d",&n);
        for(int i=0;i<=n;i++) S+=1.0/(2*i+1);
        printf("S(%d)=%6.2f \n",n,S);
}
