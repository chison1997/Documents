//Bài 6: Tính S(n) = 1/1x2 + 1/2x3 +...+ 1/(n x (n + 1))
#include <stdio.h>
main()
{
        float S=0;
        int n;
        printf("n= ");scanf("%d",&n);
        for(int i=1;i<=n;i++) S+=1.0/(i*(i+1));
        printf("S(%d)=%6.2f \n",n,S);
}
