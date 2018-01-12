//Bài 67: Tính S(x, n) = x – x^2 + x^3 + … + (-1)^n+1 * x^n
#include <stdio.h>
#include <math.h>
main()
{
        float S=0,x,LT=1;
        unsigned int n,i;
        
        printf("x= ");scanf("%f",&x);
        printf("n= ");scanf("%u",&n);
        
        for(i=1;i<=n;i++) 
                { 
                  LT*=x;
                  S+=pow(-1,i+1)*LT;
                }
                
        printf("S(%.3f, %u)=%.3f \n", x, n, S);      
        
}
