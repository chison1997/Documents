//Bài 17: Tính S(n) = x + x^2/2! + x^3/3! + ... + x^n/N!

#include <stdio.h>
#include <math.h>
 main()
 {
       
        int i,n;
        float x;
        unsigned long GT=1;
        long double S=0;
        
        printf("x=");scanf("%f",&x);
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) { GT*=i; S+=pow(x,i)/GT; }
        
        printf("S(%d)=%.2f\n",n,(double) S);
        
}

