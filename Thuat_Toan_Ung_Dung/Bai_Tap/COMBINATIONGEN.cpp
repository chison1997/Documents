#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int* A = new int[m];
    for(int i = 0; i < m; i++)
        scanf("%d", &A[m]);
    int c = 1;
    for(int i = m-1; i >= 0; i--)
    {
        if (A[i] < n)
        {
            A[i] ++;
            c = 0;
            break;
        }
        else{
            A[i] = 1;
        }
    }
    if (c == 1)
        printf("-1");
    else
        for(int i = 0; i < m; i++)
            printf("%d ", A[i]);
    return 0;
}