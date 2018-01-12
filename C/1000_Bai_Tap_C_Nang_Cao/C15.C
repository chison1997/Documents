//Bài 15: Tính S(n) = 1 + 1/(1+2) + 1/(1+2+3) + ..... + 1/(1+2+3+ .... +N)

#include <stdio.h>

 main()
 {
 
        int i,n;
        unsigned int T=0;
        double S=0;
        
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) { T+=i; S+=1.0/T; }
        
        printf("S(%d)=%.2f\n",n,S);
        
}

