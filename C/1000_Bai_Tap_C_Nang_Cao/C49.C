//Bài 49: Cho số nguyên dương n. Hãy tìm chữ số đầu tiên của n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k,c;
        unsigned long n;
        printf("n= ");scanf("%ld",&n);
        
        k= floor(log10(n)) + 1 ; //Số chữ số của n 
        
        c=n/((int) pow(10,k-1));                           
        printf("%u \n",c);                      
}
