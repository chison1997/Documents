//Bài 68: Tính S(x, n) = -x^2 + x^4  + … + (-1)^n * x^2n
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
                  LT*=x*x;
                  S+=pow(-1,i)*LT;
                }
                
        printf("S(%.3f, %u)=%.3f \n", x, n, S);      
        
}
