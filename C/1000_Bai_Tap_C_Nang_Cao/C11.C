//Bài 11: Tính S(n) = 1 + 1.2 + 1.2.3 + ... + 1.2.3....N

#include <stdio.h>

main()
{
        int i,N;
        unsigned long Q=1,S=0;
        
        printf("N=");scanf("%d",&N);
        
        for(i=1;i<=N;i++)
                {       
                        Q*=i;
                        S+=Q;
                }
        
        printf("S(%d)=%d\n",N,S);
        
}
