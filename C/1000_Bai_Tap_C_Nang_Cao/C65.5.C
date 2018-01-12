//Bài 65.5 Giải phương trình bậc ba ax^3+bx^2+cx+d=0 (a khác 0)
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

main()
{
        float a,b,c,d;
        double delta,k;
        long double x=0,x1=0,x2=0,x3=0;
        printf("a= ");scanf("%f",&a);
        printf("b= ");scanf("%f",&b);
        printf("c= ");scanf("%f",&c);
        printf("d= ");scanf("%f",&d);
        
        delta=b*b-3*a*c;
        
        if (delta==0) x=(-b+pow(b*b*b-27*a*a*d,1.0/3))/(3*a);
        else {
                k=(9*a*b*c-2*b*b*b-27*a*a*d)/(2*pow(fabs(delta),3.0/2));
                
                if(delta<0) x= sqrt(fabs(delta))*(pow(k+sqrt(k*k+1),1.0/3) + pow(k-sqrt(k*k+1),1.0/3) )/ (3*a) - b/(3*a) ;
                
                else if (fabs(k)>1) x=sqrt(delta)*fabs(k)*(pow(fabs(k)+sqrt(k*k-1),1.0/3) + pow(fabs(k)-sqrt(k*k-1),1.0/3) )/ (3*a*k) - b/(3*a);
                
                else if(fabs(k)<=1) { x1= (2*sqrt(delta)*cos(acos(k)/3)-b)/(3*a) ; 
                                      x2= (2*sqrt(delta)*cos(acos(k)/3 -2*PI/3)-b)/(3*a);
                                      x3= (2*sqrt(delta)*cos(acos(k)/3 + 2*PI/3)-b)/(3*a) ;
                                    }
              }
       printf("%Lf \n%Lf \n%Lf \n%Lf \n",x,x1,x2,x3);           
}

// https://vi.wikipedia.org/wiki/Ph%C6%B0%C6%A1ng_tr%C3%ACnh_b%E1%BA%ADc_ba
