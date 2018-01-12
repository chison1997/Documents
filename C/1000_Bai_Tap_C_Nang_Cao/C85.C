//Bài 85: Nhập vào tháng của 1 năm. Cho biết tháng thuộc quý mấy trong năm
#include <stdio.h>


main()
{
        int n;
        char* str;
        do {printf("n= ");scanf("%d",&n);} while (n<1 || n>12);
        switch(n/4)
        {
            case 0: str="Mot"; break;
            case 1: str="Hai"; break;
            case 2: str="Ba"; break;
            case 3: str="Bon"; break;
        }
          
        printf("Thang %d thuoc quy %s \n",n,str);
        
}

