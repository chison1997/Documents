//Bài 7: Tính S(n) = ½ + 2/3 + ¾ + .... + n / (n + 1)
#include <stdio.h>
main()
{
        float S=0;
        int n;
        printf("n= ");scanf("%d",&n);
        for(int i=1;i<=n;i++) S+=i*1.0/(i+1);
        printf("S(%d)=%6.2f \n",n,S);
}
