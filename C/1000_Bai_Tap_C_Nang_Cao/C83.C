//Bài 83: Viết chương trình nhập 2 số thực, kiểm tra xem chúng có cùng dấu hay không
#include <stdio.h>

main()
{
        float a, b;
        
        printf("a= "); scanf("%f",&a);
        printf("b= "); scanf("%f",&b);
        
        if (a*b > 0) printf("cung dau \n");
        else printf("khac dau");
        
}
