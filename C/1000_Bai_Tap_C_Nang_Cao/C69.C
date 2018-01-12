//Bài 69: Tính S(x, n) = x – x^3 + x^5 + … + (-1)^n * x^2n+1
#include <stdio.h>
#include <math.h>
main()
{
        float S=0,x,LT=1;
        unsigned int n,i;
        
        printf("x= ");scanf("%f",&x);
        printf("n= ");scanf("%u",&n);
        
        LT=1.0/x;
        for(i=1;i<=n;i++) 
                { 
                  LT*=x*x;
                  S+=pow(-1,i)*LT;
                }
                
        printf("S(%.3f, %u)=%.3f \n", x, n, S);      
        
}
