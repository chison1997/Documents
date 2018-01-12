//Bài 29: Tìm ước số lẻ lớn nhất của số nguyên dương n. Ví dụ n = 100 ước lẻ lớn nhất là 25
#include <stdio.h>

 main()
 {
       
        unsigned int i,n,max=1;
        
        printf("n=");scanf("%d",&n);
        if (n%2) max=n;
        else  for(i=1;i<n;i++) if((n%i==0)&&(i%2)) max=i;
        
        printf("%u \n",max);
        
        
}

