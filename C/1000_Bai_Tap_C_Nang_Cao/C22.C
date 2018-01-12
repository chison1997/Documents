//Bài 22:Tính tích tất cả các “ước số” của số nguyên dương n
#include <stdio.h>

 main()
 {
       
        unsigned int i,n;
        double Q=1;
       
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) if(n%i==0) Q*=i;       
        printf("Q=%.2f \n",Q);
        
}

