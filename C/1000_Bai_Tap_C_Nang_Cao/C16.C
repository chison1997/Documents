//Bài 16: Tính S(n) = x + x^2/(1+2) + x^3/(1+2+3) + ... + x^n/(1+2+3+....+n)

#include <stdio.h>
#include <math.h>
 main()
 {
       
        int i,n;
        float x;
        unsigned int T=0;
        long double S=0;
        
        printf("x=");scanf("%f",&x);
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) { T+=i; S+=pow(x,i)/T; }
        
        printf("S(%d)=%.2f\n",n,(double) S);
        
}

