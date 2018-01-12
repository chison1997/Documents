//Bài 87: Tìm số nguyên dương n nhỏ nhất sao cho 1 + 2 + … + n > 10000
#include <stdio.h>


main()
{
        int n=0,S=0;
        
        while(S<=10000) 
                {
                   n++;
                   S+=n;
                }
        S-=n; n--;  
        printf("n=%d, S=%d \n",n,S);
}

