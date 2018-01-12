//Bài 24: Liệt kê tất cả các “ước số lẻ” của số nguyên dương n
#include <stdio.h>

 main()
 {
       
        unsigned int i,n;
       
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) if((n%i==0)&&(i%2)) printf("%d \n",i);       
        
        
}

