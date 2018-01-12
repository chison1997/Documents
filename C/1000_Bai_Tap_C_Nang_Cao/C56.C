//Bài 56: Hãy kiểm tra số nguyên dương n có toàn chữ số lẻ hay không
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k, KiemTra=1;
        unsigned long n,m;
        printf("n= ");scanf("%ld",&n);
        m=n; //tạo ra bản sao của n vì n sẽ bị thay đổi 
                
        k= floor(log10(n)) + 1 ; //Số chữ số của n 
        if(n==0) k=1;
        
        
        for(int i=k-1;i>=0;i--) { if( (n/((int) pow(10,i)))%2 == 0)     { KiemTra=0; break;}    // n/((int) pow(10,i)) là chữ số của n         
                                  
                                  n=n% ((int) pow(10,i)); 
                                  
                                }                         
                                     
        if (KiemTra==1) printf("%ld co toan chu so le \n",m); 
        else            printf("Khong phai tat ca chu so cua %ld deu la le \n",m);
        
       
}
