//Bài 41: Tính S(n) = 1 / (1 + 1 / ( 1 + 1 / (…. 1 + 1 / (1 + 1))) có n dấu phân số
#include <stdio.h>
#include <math.h>

main()
{
        double S=1;
        unsigned int i,n;
        
        printf("n= ");scanf("%u",&n);
        
        for(i=1;i<=n;i++) S=1/(1+S);
        
        printf("S(%u)= %f \n",n,S);
        
}
