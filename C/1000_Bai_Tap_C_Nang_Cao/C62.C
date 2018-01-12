//Bài 62: Cho 2 số nguyên dương a và b. Hãy tìm ước chung lớn nhất của 2 số này.
#include <stdio.h>


main()
{
        
        unsigned long a,b;
        
        printf("a= ");scanf("%ld",&a); 
        printf("b= ");scanf("%ld",&b);
        
        while (a!=b)
        {
                if (a>b) a-=b;
                else b-=a;
        }
        
         printf("%ld \n",a);
}
