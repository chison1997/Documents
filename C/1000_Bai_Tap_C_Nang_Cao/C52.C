//Bài 52: Tìm chữ số nhỏ nhất của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k,min;
        unsigned long n;
        printf("n= ");scanf("%ld",&n);
        
        k= floor(log10(n)) + 1 ; //Số chữ số của n 
        min=n/((int) pow(10,k-1));
        for(int i=k-1;i>=0;i--) {  min=(n/((int) pow(10,i)) <min ) ? n/((int) pow(10,i)) : min ; n=n% ((int) pow(10,i)); }                          
                                     // n/((int) pow(10,i)) là chữ số của n           

        printf("%u \n",min);
}
