//Bài 14: Tính S(n) = x + x^3 + x^5 + ... + x^(2n + 1)

#include <stdio.h>
#include <math.h>
 main()
 {
 
        int i,n;
        float x;
        double S=0;
        
        
        printf("x=");scanf("%f",&x);
        printf("n=");scanf("%d",&n);
        
        for(i=0;i<=n;i++) S+=pow(x,2*i+1);
        
        printf("S(%d)=%.2f\n",n,S);
        
}

