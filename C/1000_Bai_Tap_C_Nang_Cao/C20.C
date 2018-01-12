//Bài 20: Liệt kê tất cả các “ước số” của số nguyên dương n

#include <stdio.h>

 main()
 {
       
        int i,n;
       
        printf("n=");scanf("%d",&n);
        printf("Cac uoc so cua %d: ",n);
        
        for(i=1;i<=n;i++) if(n%i==0) printf("\n%d",i);       
        printf("\n");
        
}

