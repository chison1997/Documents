//Bài 26: Tính tích tất cả các “ước số lẻ” của số nguyên dương n
#include <stdio.h>

 main()
 {
       
        unsigned int i,n;
        unsigned long S=0;
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) if((n%i==0)&&(i%2)) S+=i;
        
        printf("S=%ld \n",S);
        
        
}

