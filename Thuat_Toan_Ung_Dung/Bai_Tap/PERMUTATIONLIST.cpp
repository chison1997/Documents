#include <stdio.h>


int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int *A = new int[n];
    for(int i = 0; i < n; i++)
        A[i] = i + 1;

    for(int K = 2; K <= k; K++)
    {
        int i;   
        for(i = n-2; i >= 0; i--)
            if (A[i] < A[i+1])
                break;
        if (i == -1)
        {
            printf("-1\n");
            delete A;
            return 0;
        }
        int j;
        for(j = n-1; j >= i; j--)
            if (A[j] > A[i])
            {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
    }

    return 0;
}