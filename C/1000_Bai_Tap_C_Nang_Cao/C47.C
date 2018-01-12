//Bài 47: Hãy tính tổng các chữ số chẵn của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int S=0,k;
        unsigned long n;
        printf("n= ");scanf("%ld",&n);
        
        k= floor(log10(n)) +1 ; //Số chữ số của n 
        
        for(int i=k-1;i>=0;i--)
                 { if( (n/((int) pow(10,i)))%2==0) /*chữ số chẵn*/  S+=n/((int) pow(10,i)); 
                   n=n%((int) pow(10,i));
                 }                           
        printf("%u \n",S);                      
}
