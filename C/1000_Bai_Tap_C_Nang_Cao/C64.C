//Bài 64. Giải phương trình bậc nhất
#include <stdio.h>
#include <math.h>

main()
{
        float a,b;
        printf("a= ");scanf("%f",&a);
        printf("b= ");scanf("%f",&b);
        
        if (a==0 && b==0) printf("PT vo so nghiem \n");
        else if (a==0 && b!=0) printf("PT vo nghiem \n");        
        else printf("PT co nghiem duy nhat x=%.3f \n",-b/a); 
}
