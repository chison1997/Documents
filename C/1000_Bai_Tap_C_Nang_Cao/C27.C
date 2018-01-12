//Bài 27: Đếm số lượng “ước số chẵn” của số nguyên dương n
#include <stdio.h>

 main()
 {
       
        unsigned int i,n,SoLuong=0;
        
        printf("n=");scanf("%d",&n);
        for(i=1;i<=n;i++) if((n%i==0)&&(i%2==0)) SoLuong++;
        
        printf("%u \n",SoLuong);
        
        
}

