//Bài 9: Tính T(n) = 1 x 2 x 3...x n
#include <stdio.h>
main()
{
        long int T=1;
        int n;
        printf("n= ");scanf("%d",&n);
        for(int i=1;i<=n;i++) T*=i ;
        printf("T(%d)=%ld \n",n,T);
}
