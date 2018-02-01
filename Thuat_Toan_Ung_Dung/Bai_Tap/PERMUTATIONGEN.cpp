#include <stdio.h>
#define gc getchar


void scanint(int *x) {
  register int c = gc();
 
  int neg = 0;
  *x = 0;
  while ( (c < '0' || c > '9') && c != '-' ) {
    c = gc();
  }
  if ( c == '-' ) {
    neg = 1;
    c = gc();
  }
  while ( !(c < '0' || c > '9') ) {
    *x *= 10;
    *x += (c - '0');
    c = gc();
  }
  if ( neg )
    *x = -*x;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    for(int i = 0; i < n; i++)
        //scanf("%d", &A[i]);
        {scanint(A + i);
        printf("%d ", A[i]);
        }

//for(int k = 0; k < n ; k++)
  //      printf("%d ", A[k]);
    return 0;

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

    // for(int I = i + 1, J = n - 1; I < J; I++, J--)
    // {
    //     // int t = A[I];
    //     // A[I] = A[J];
    //     // A[J] = t;
    //     //XOR Swap
    //     register int t = A[I] ^ A[J];
    //     A[J] = A[J] ^ t;
    //     A[I] = t ^ A[J];
    // }

    for(int k = 0; k <= i ; k++)
        printf("%d ", A[k]);
    for(int k = n-1; k >  i; k--)
        printf("%d ", A[k]);
    
    delete A;
    return 0;
    
}