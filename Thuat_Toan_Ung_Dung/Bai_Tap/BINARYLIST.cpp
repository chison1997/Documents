#include <stdio.h>

int* A;
int n;
int k;
int K = 0;
int I = 0;
int i;

void print()
{
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int TRY(int l)
{
   
        A[l] = 0;
        I++;
        if (I == i)
             goto l1;

        if (l == n - 1)
        {
            K++;
            if (K == k)
            {
                return 1;
            }
        }
        else
        {
            if (TRY(l+1) == 1) 
                return 1;
        }
    
l1:   A[l] = 1;
     
        I = 0;

        if (l == n - 1)
        {  
            K++;
            if (K == k)
            {
                return 1;
            }
        }
        else
        {
            if (TRY(l+1) == 1) 
                return 1;
        }

    return 0;
}

int main()
{
    scanf("%d %d %d", &n, &k, &i);

    if ((n < 32) && (k > (1<<n)))
    {
        printf("-1\n");
        return 0;
    }

    A = new int[n];
    if (TRY(0) == 0)
        printf("-1\n");
    else
        print();

    delete A;
    return 0;
}