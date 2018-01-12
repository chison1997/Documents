//Bài 25: Tính tổng tất cả các “ước số chẵn” của số nguyên dương n
#include <stdio.h>

 main()
 {
       
        unsigned int i,n;
        unsigned long S=0;
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) if((n%i==0)&&(i%2==0)) S+=i;
        
        printf("S=%ld \n",S);
        
        
}

