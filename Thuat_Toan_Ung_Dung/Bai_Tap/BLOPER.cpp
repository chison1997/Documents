#include <stdio.h>
#include <time.h>

int N, S, s;

int TRY(int k)
{
    //cong            
    if (s + (N*(N+1) - k*(k-1)) / 2 < S)
        return 0;
    s += k;

    if (k == N)
    {
        if (s == S)
            return 1;
    }
    else
    {
        if (TRY(k+1))
            return 1;
    }
    s -= k;

    //tru
    if (s - (N*(N+1) - k*(k-1)) / 2 > S)
       return 0;

    s -= k;

    if (k == N)
    {
        if (s == S)
            return 1;
    }
    else
    {
        if (TRY(k+1))
            return 1;
    }
    s += k;

    return 0;
}

int main()
{
   // time_t t = clock();
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &S);
        printf("%d\n", ( N*(N+1)/2 + S ) % 2 == 0 );
    }
  //  printf("Time: %.2fs\n", (float)(clock() - t)/CLOCKS_PER_SEC);
    
    return 0;
}