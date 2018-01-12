//Bài 44: Hãy tính tổng các chữ số của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int S=0,k,n;
        
        printf("n= ");scanf("%u",&n);
        
        k= floor(log10(n)) +1 ; //Số chữ số của n 
        
        for(int i=k-1;i>=0;i--) { S+=n/((int) pow(10,i)); n=n% ((int) pow(10,i)); }                           
        printf("%u \n",S);
}
