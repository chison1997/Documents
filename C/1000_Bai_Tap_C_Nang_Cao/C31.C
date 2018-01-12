//Bài 31: Cho số nguyên dương n. Kiểm tra xem n có phải là số nguyên tố hay không
#include <stdio.h>
#include <math.h>

 main()
 {
       
        unsigned int i,n,k=1;
        
        printf("n=");scanf("%d",&n);
        
        if (n<=1) k=0;
        if (n>2)
                for(i=2;i<=sqrt(n);i++) if (n%i==0) 
                                           { k=0; break;}
        
        if (k==1) printf("Yes \n"); else printf("No \n");        
        
}

