//Bài 48: Hãy tính tích các chữ số lẻ của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int Q=1,k;
        unsigned long n;
        printf("n= ");scanf("%ld",&n);
        
        k= floor(log10(n)) +1 ; //Số chữ số của n 
        
        for(int i=k-1;i>=0;i--)
                 { if( (n/((int) pow(10,i)))%2) /*chữ số lẻ*/  Q*=n/((int) pow(10,i)); 
                   n=n%((int) pow(10,i));
                 }                           
        printf("%u \n",Q);                      
}
