//Bài 82: Viết chương trình tìm số lớn nhất trong 3 số thực a, b, c

#include <stdio.h>

main()
{
        float a, b, c, max;
        
        printf("a= "); scanf("%f",&a);
        printf("b= "); scanf("%f",&b);
        printf("c= "); scanf("%f",&c);
        
        max= a>b ? a : b;
        max= max>c ? max : c;
        
        printf("%.3f \n",c);
        
}
