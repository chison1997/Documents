//Bài 43: Hãy đếm số lượng chữ số của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k,n;
        
        printf("n= ");scanf("%u",&n);
        
        k= floor(log10(n)) +1 ;
                                                
        printf("%u \n",k);
}
