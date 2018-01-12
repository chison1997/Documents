//Bài 28: Cho số nguyên dương n. Tính tổng các ước số nhỏ hơn chính nó
#include <stdio.h>

 main()
 {
       
        unsigned int i,n;
        unsigned long S=0;
        
        printf("n=");scanf("%d",&n);
        for(i=1;i<n;i++) if(n%i==0) S+=i;
        
        printf("%ld \n",S);
        
        
}

