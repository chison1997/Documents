//Bài 18: Tính S(n) = 1 + x^2/2! + x^4/4! + ... + x^2n/(2n)!

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
        
        for(i=0;i<=2*n;i++) { if(i) GT*=i; if(i%2==0) S+=pow(x,i)/GT; }
        
        printf("S(%d)=%.2f\n",n,(double) S);
        
}

