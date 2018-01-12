//Bài 71: Tính S(x, n) = -x + x^2/(1 + 2) – x^3/(1 + 2 + 3) + … + (-1)^n * x^n/(1 + 2 +… + n)
#include <stdio.h>
#include <math.h>
main()
{
        float S=0,LT=1,x;
        unsigned int n,i,T=0;
        
        printf("x= ");scanf("%f",&x);
        printf("n= ");scanf("%u",&n);
        
        
        for(i=1;i<=n;i++) 
                { 
                  T+=i; LT*=x;
                  S+=pow(-1,i)*LT/T;
                }
                
                
        printf("S(%.3f, %u)=%.3f \n", x, n, S);      
        
}
