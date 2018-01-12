//Bài 23: Đếm số lượng “ước số” của số nguyên dương n
#include <stdio.h>

 main()
 {
       
        unsigned int i,n,SoLuong=0;
       
        printf("n=");scanf("%d",&n);
        
        for(i=1;i<=n;i++) if(n%i==0) SoLuong++;       
        printf("%d co %d uoc so \n",n,SoLuong);
        
}

