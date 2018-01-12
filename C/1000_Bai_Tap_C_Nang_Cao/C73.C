//Bài 73: Tính S(x, n) = -1 + x^2/2! – x^4/4! + … + (-1)^n+1 * x^2n/(2n)!
#include <stdio.h>
#include <math.h>

unsigned long GT(unsigned int i)
{
   if (i<=1) return 1;
   else return GT(i-1)*i;
}

main()
{
        float S=-1,LT=1,x;
        unsigned int n,i;
        
        printf("x= ");scanf("%f",&x);
        printf("n= ");scanf("%u",&n);
        
        
        for(i=1;i<=n;i++) 
                { 
                  LT*=x*x;
                  S+=pow(-1,i+1)*LT/GT(2*i);
                  
                }
                
                
        printf("S(%.3f, %u)=%.3f \n", x, n, S);      
        
}
