#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    char* S = new char[n+1];
    S[n] = 0;
    fgets(S, n+1, stdin);
    int m = 1;
    for(int i = n-1; i >= 0; i--)
    {
        if (S[i] == '0')
        {
            S[i] = '1';
            m = 0;
            break;
        }

    }
    if (m == 1)
        printf("-1");
    else
        printf("%s", S);
    return 0;
}