//Bài 12: Tính S(n) = x + x^2 + x^3 + ... + x^n

#include <stdio.h>

main()
{
        int i,n;
        float x;
        double Q=1,S=0;
        
        printf("n=");scanf("%d",&n);
        printf("x=");scanf("%f",&x);
        
        for(i=1;i<=n;i++)
                {       
                        Q*=x;
                        S+=Q;
                }
        
        printf("S(%d)=%.2f\n",n,S);
        
}
