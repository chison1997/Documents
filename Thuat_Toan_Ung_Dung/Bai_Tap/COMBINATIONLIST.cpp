#include <stdio.h>

int n, m, k;
int* A;
void print()
{
    for(int i = 0; i < m; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    
    scanf("%d %d %d", &n, &m, &k);
    A = new int[m];

    for(int i = 0; i < m; i++)
        A[i] = i+1;


    int i = 0;
    for(int K = 2; K <= k; K++)
    {
        i = m-1;
        while( i >= 0)
        {
            if (A[i] <= n-m+i)
                break;
            i--;
        }
        if (i < 0)
            break;
        
        A[i]++;

        for(int j = i+1; j < m; j++)
            A[j] = A[i] + j - i;

    }


    if (i == 0)
        printf("-1");
    else
        print();

    delete A;
    return 0;
}