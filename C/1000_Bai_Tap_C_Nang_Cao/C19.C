//Bài 19: Tính S(n) = 1 + x + x^3/3! + x^5/5! + … + x^(2n+1)/(2n+1)!

#include <stdio.h>
#include <math.h>
 main()
 {
       
        int i,n;
        float x;
        unsigned long GT=1;
        long double S=1;
        
        printf("x=");scanf("%f",&x);
        printf("n=");scanf("%d",&n);
        
        for(i=0;i<=2*n;i++) { if(i) GT*=i; if(i%2) S+=pow(x,i)/GT; }
        
        printf("S(%d)=%.2f\n",n,(double) S);
        
}

