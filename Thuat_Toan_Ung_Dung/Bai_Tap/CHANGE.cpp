#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    N = 1000 - N;
    int M[] = {500, 100, 50, 10, 5, 1};
    int count = 0;
    for(int i = 0; N > 0 && i < sizeof(M)/sizeof(int); i++)
    {
        count += N / M[i];
        N = N % M[i];
    }
    printf("%d", count);
    return 0;
}