//Bài 53: Hãy đếm số lượng chữ số lớn nhất của số nguyên dương n
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k,max=0,sl=0;
        unsigned long n,m;
        printf("n= ");scanf("%ld",&n);
        m=n; //tạo ra bản sao của n vì n sẽ bị thay đổi
        k= floor(log10(n)) + 1 ; //Số chữ số của n 
        if(n==0) k=1;
        
        //tìm max 
        for(int i=k-1;i>=0;i--) {  max=(n/((int) pow(10,i)) > max) ? n/((int) pow(10,i)) : max ; n=n% ((int) pow(10,i)); }                          
                                     // n/((int) pow(10,i)) là chữ số của n           
        
        
        //đếm số lượng
        for(int i=k-1;i>=0;i--) { if (m/((int) pow(10,i)) == max) sl++; m=m% ((int) pow(10,i)); }
        
        printf("max= %u, so luong= %u \n",max,sl);
}
