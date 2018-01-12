//Bài 4: Tính S(n) = ½ + ¼ + ... + 1/2n
#include <stdio.h>
main()
{
        float S=0;
        int n;
        printf("n= ");scanf("%d",&n);
        for(int i=1;i<=n;i++) S+=1.0/(2*i);
        printf("S(%d)=%6.2f \n",n,S);
}
