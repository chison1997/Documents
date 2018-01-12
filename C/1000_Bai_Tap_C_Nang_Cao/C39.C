//Bài 39: Tính S(n) = CanBac N + 1(N! + CanBacN((N – 1)! + … + CanBac3(2! + CanBac2(1!))) có n dấu căn

#include <stdio.h>
#include <math.h>

main()
{
        double S=0;
        unsigned int i,n;
        unsigned long GT=1;
        printf("n=");scanf("%u",&n);
        
        for(i=2;i<=n+1;i++) {S=pow(GT+S,1.0/i); GT*=i; }
        
        printf("S(%u)= %f \n",n,S);
        
}
