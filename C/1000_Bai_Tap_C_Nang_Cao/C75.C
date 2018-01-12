//Bài 75: Kiểm tra số nguyên 4 byte có dạng 2^k hay không
#include <stdio.h>
#include <math.h>


main()
{
        unsigned long n;
        
        printf("n= ");scanf("%lu",&n);
        
        if (n==0) printf("Khong ton tai k nguyen \n");
        else if (pow(2,floor(log10(n)/log10(2)))==n) printf("k= %.0f \n", log10(n)/log10(2));
        else printf("Khong ton tai k nguyen \n");
        
           
        
}
