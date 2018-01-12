//Bài 54: Hãy đếm số lượng chữ số nhỏ nhất của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k,min=9,sl=0;
        unsigned long n,m;
        printf("n= ");scanf("%ld",&n);
        m=n;
        k= floor(log10(n)) + 1 ; //Số chữ số của n 
        if(n==0) k=1;
        
        //tìm min 
        for(int i=k-1;i>=0;i--) {  min=(n/((int) pow(10,i)) < min) ? n/((int) pow(10,i)) : min ; n=n% ((int) pow(10,i)); }                          
                                     // n/((int) pow(10,i)) là chữ số của n           
        
        for(int i=k-1;i>=0;i--) { if (m/((int) pow(10,i)) == min) sl++; m=m% ((int) pow(10,i)); }
        
        printf("min= %u, so luong= %u \n",min,sl);
}
