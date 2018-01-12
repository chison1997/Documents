//Bài 37: Tính S(n) = CanBac N(N + CanBac N - 1(N – 1 + … + CanBac3(3 + CanBac2(2))) có n – 1 dấu căn

#include <stdio.h>
#include <math.h>

main()
{
        double S=0;
        unsigned int i,n;
        
        printf("n=");scanf("%u",&n);
        
        for(i=2;i<=n;i++) S=pow(i+S,1.0/i);
        
        printf("S(%u)= %f \n",n,S);
        
}
