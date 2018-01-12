//Bài 63: Cho 2 số nguyên dương a và b. Hãy tìm bội chung nhỏ nhất của 2 số này
#include <stdio.h>

int UCLN(int a, int b)
 {
        while (a!=b)
        {
                if (a>b) a-=b;
                else b-=a;
        }
        
        return a;
 }

main()
{
        
        unsigned long a,b;
        
        printf("a= ");scanf("%ld",&a); 
        printf("b= ");scanf("%ld",&b);
        
        printf("%ld \n",a*b/UCLN(a,b));
}
