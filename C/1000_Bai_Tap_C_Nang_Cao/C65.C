//Bài 65. Giải phương trình bậc hai ax^2+bx+c=0
#include <stdio.h>
#include <math.h>

void GPTB1(float a,float b)
{
      if (a==0 && b==0) printf("PT vo so nghiem \n");
        else if (a==0 && b!=0) printf("PT vo nghiem \n");        
        else printf("PT co nghiem duy nhat x=%.3f \n",-b/a); 
        
}

main()
{
        float a,b,c;
        printf("a= ");scanf("%f",&a);
        printf("b= ");scanf("%f",&b);
        printf("c= ");scanf("%f",&c);
        
        if (a==0) GPTB1(b,c);
        else 
             {
                float delta=b*b-4*a*c;
                if (delta<0) printf("PT vo nghiem \n");
                else if (delta==0) printf("PT co nghiem duy nhat x=%.3f \n",-b/(2*a));
                else printf("PT co 2 nghiem phan biet: x1=%.3f; x2=%.3f \n",(-b+sqrt(delta))/(2*a) ,(-b-sqrt(delta))/(2*a) );
             } 
                   
}
