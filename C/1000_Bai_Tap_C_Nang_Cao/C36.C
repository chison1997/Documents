//Bài 36: Tính S(n) = CanBac2(n! + CanBac2((n-1)! +CanBac2((n – 2)! + … + CanBac2(2!) + CanBac2(1!)))) có n dấu căn

#include <stdio.h>
#include <math.h>

main()
{
        double S=0;
        unsigned long GT=1;
        unsigned int i,n;
        
        printf("n=");scanf("%u",&n);
        
        for(i=1;i<=n;i++) { GT*=i; S=sqrt(GT+S);}
        
        printf("S(%u)= %.2f \n",n,S);
        
}
