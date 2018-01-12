//Bài 40: Tính S(n) = CanBac2(x^n + CanBac2(x^n-1 + … + CanBac2(x^2 + CanBac2(x)))) có n dấu căn

#include <stdio.h>
#include <math.h>

main()
{
        double S=0,LT=1;
        unsigned int i,n;
        float x;
        printf("x= ");scanf("%f",&x);
        printf("n= ");scanf("%u",&n);
        
        for(i=1;i<=n;i++) { LT*=x; S=sqrt(LT+S);}
        
        printf("S(%u)= %f \n",n,S);
        
}
