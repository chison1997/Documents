//Bài 38: Tính S(n) = CanBac N + 1(N + CanBac N(N – 1 +…+CanBac3(2 + CanBac2(1)))) có n dấu căn

#include <stdio.h>
#include <math.h>

main()
{
        double S=0;
        unsigned int i,n;
        
        printf("n=");scanf("%u",&n);
        
        for(i=2;i<=n;i++) S=pow(i-1+S,1.0/i);
        
        printf("S(%u)= %f \n",n,S);
        
}
