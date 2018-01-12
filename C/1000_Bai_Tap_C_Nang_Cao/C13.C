//Bài 13: Tính S(n) = x^2 + x^4 + ... + x^2n

#include <stdio.h>

main()
{

        float x;
        int i,n;
        double S=0,Q=1;
        
        printf("x=");scanf("%f",&x);
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) { Q*=x*x;S+=Q;}
        
        printf("S(%d)=%.2f\n",n,S);
       
}
