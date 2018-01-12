//Bài 50: Hãy tìm số đảo ngược của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k;
        unsigned long n,m=0;
        printf("n= ");scanf("%ld",&n);
        
        k= floor(log10(n)) + 1 ; //Số chữ số của n 
        
        for(int i=k-1;i>=0;i--) {  m+=(n/((int) pow(10,i)))*pow(10,k-1-i); n=n% ((int) pow(10,i)); }                          
                                     // n/((int) pow(10,i)) là chữ số của n           

        printf("%ld \n",m);
}
