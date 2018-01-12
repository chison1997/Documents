#include <stdio.h>
#include <math.h>


main()
{
        float a,x0,x1;
        do      
                { printf("a= ");scanf("%f",&a); }
        while (a<0);
        
        x1=(a+1)/2;
        
        do {x0=x1;  x1=(x0+a/x0)/2;}
        while (x0-x1>1E-5);
        
        printf("can bac 2 cua %6.2f la %6.5f",a,x1);
        
}

