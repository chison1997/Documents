//Bài 51: Tìm chữ số lớn nhất của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k,max=0;
        unsigned long n;
        printf("n= ");scanf("%ld",&n);
        
        k= floor(log10(n)) + 1 ; //Số chữ số của n 
        
        for(int i=k-1;i>=0;i--) {  max=(n/((int) pow(10,i)) >max ) ? n/((int) pow(10,i)) : max ; n=n% ((int) pow(10,i)); }                          
                                     // n/((int) pow(10,i)) là chữ số của n           

        printf("%u \n",max);
}
