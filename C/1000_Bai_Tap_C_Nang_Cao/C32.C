//Bài 32: Cho số nguyên dương n. Kiểm tra xem n có phải là số chính phương hay không
#include <stdio.h>
#include <math.h>

 main()
 {
       
        unsigned int n;
        
        printf("n=");scanf("%d",&n);
        
        if (sqrt(n)==floor(sqrt(n))) printf("Yes \n"); else printf("No \n");      
        
}

