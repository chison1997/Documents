//Bài 30: Cho số nguyên dương n. Kiểm tra xem n có phải là số hoàn thiện hay không
#include <stdio.h>

 main()
 {
       
        unsigned int i,n;
        unsigned long S=0;
        
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<n;i++) if(n%i==0) 
                                    { 
                                       S+=i;
                                       if (S>n) break;
                                    } 
        
        if (S==n) printf("Yes \n"); else printf("No \n");
        
        
}

