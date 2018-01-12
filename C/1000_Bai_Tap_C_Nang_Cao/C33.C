//Bài 33: Tính S(n) = CanBac2(2+CanBac2(2+….+CanBac2(2 + CanBac2(2)))) có n dấu căn
#include <stdio.h>
#include <math.h>

 main()
 {
       
        unsigned int i,n;
        double S=0;
        printf("n=");scanf("%u",&n);
        
        for(i=1;i<=n;i++) S=sqrt(2+S);
        
        printf("S(%u)=%f \n",n,S);
}

