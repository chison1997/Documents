//Bài 45: Hãy tính tích các chữ số của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k,n;
        unsigned long Q=1;
        printf("n= ");scanf("%u",&n);
        
        k= floor(log10(n)) +1 ; //Số chữ số của n 
        
        for(int i=k-1;i>=0;i--) { Q*=n/((int) pow(10,i)); n=n% ((int) pow(10,i)); }                           
        printf("%ld \n",Q);
}
