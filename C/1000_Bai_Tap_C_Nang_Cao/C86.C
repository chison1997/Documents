//Bài 86: Tính S(n) = 1^3 + 2^3 + … + N^3
#include <stdio.h>


main()
{
        int n;
        float S=0;
        do {printf("n= ");scanf("%d",&n);} while (n<1);
        
        for(int i=1;i<=n;i++) S+=i*i*i;
          
        printf("S(%d)=%.0f \n",n,S);
}

