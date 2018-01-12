//Bài 42: Cho n là số nguyên dương. Hãy tìm giá trị nguyên dương k lớn nhất sao cho S(k)  <= n. Trong đó chuỗi k được định nghĩa như sau: S(k) = 1 + 2 + 3 + … + k
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k,n;
        
        printf("n= ");scanf("%u",&n);
        
        k=floor((sqrt(1+8*n)-1)/2);   //S(k)=k*(k+1)/2 
                                      //GBPT: S(k)<=n, k max => GPT k^2+k-2n=0   
                                                
        printf("k=%u \n",k);
}
