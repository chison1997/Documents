//Bài 60: Hãy kiểm tra các chữ số của số nguyên dương n có tăng dần từ trái sang phải hay không
#include <stdio.h>
#include <math.h>

main()
{
        
        unsigned int k, KiemTra=1, SoTruoc=0,SoSau;
        unsigned long n,m;
        printf("n= ");scanf("%u",&n);
        m=n; //tạo bản sao của n vì n sẽ thay đổi 
        k= floor(log10(n)) +1 ; //Số chữ số của n 
        
        for(int i=k-1;i>=0;i--) { SoSau=n/((int) pow(10,i));
                                  if(SoSau<SoTruoc) { KiemTra=0; break;}
                                  
                                  SoTruoc=SoSau;
                                                                  
                                  n=n% ((int) pow(10,i));
                                }                           
        if(KiemTra) printf("%ld co cac chu so tang dan tu trai sang phai \n",m);
        else printf("%ld khong co cac chu so tang dan tu trai sang phai \n",m);
        
}
