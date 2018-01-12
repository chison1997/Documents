//Bài 72: Tính S(x, n) = - x + x^2/2! – x^3/3! + … + (-1)^n * x^n/n!
#include <stdio.h>
#include <math.h>
main()
{
        float S=0,LT=1,x;
        unsigned int n,i;
        unsigned long GT=1;
        
        printf("x= ");scanf("%f",&x);
        printf("n= ");scanf("%u",&n);
        
        
        for(i=1;i<=n;i++) 
                { 
                  GT*=i; LT*=x;
                  S+=pow(-1,i)*LT/GT;
                }
                
                
        printf("S(%.3f, %u)=%.3f \n", x, n, S);      
        
}
