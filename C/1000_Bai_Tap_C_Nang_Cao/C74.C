//Bài 74: Tính S(x, n) = 1 – x + x^3/3! – x^5/5! + … + (-1)^n+1 * x^2n+1/(2n + 1)!
#include <stdio.h>
#include <math.h>

unsigned long GT(unsigned int i)
{
   if (i<=1) return 1;
   else return GT(i-1)*i;
}

main()
{
        float S=1,LT,x;
        unsigned int n,i;
        
        printf("x= ");scanf("%f",&x);
        printf("n= ");scanf("%u",&n);
        
        LT=1.0/x;
        for(i=0;i<=n;i++) 
                { 
                  LT*=x*x;
                  S+=pow(-1,i+1)*LT/GT(2*i+1);
                  
                }
                
                
        printf("S(%.3f,%u)=%.3f \n", x, n, S);      
        
}
