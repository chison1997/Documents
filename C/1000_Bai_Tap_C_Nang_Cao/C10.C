//Bài 10: Tính T(x, n) = x^n
#include <stdio.h>
main()
{
        double T=1;
        int n;
        float x;
        printf("x= ");scanf("%f",&x);
        printf("n= ");scanf("%d",&n);
        for(int i=1;i<=n;i++) T*=x ;
        printf("T(%.2f,%d)=%.2lf \n",x,n,T);
}
