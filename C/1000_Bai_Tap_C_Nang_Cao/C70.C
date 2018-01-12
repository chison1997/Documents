//Bài 70: Tính S(n) = 1 – 1/(1 + 2) + 1/(1 + 2 + 3)  + … + (-1)^n+1 * 1/(1 + 2 + 3+ … + n)
#include <stdio.h>
#include <math.h>
main()
{
        float S=0;
        unsigned int n,i,T=0;
        
        printf("n= ");scanf("%u",&n);
        
        
        for(i=1;i<=n;i++) 
                { 
                  T+=i;
                  S+=pow(-1,i+1)*1.0/T;
                }
                
                
        printf("S(%u)=%.3f \n", n, S);      
        
}
