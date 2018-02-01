#include <stdio.h>
#include <math.h>
#include "mod.h"

long long addmod(long long a, long long b, long long c)
{
    a %= c;
    b %= c;

    c = a - c + b;
    if (c >= 0)
        return c;
    return a + b;
}

long long multimod1(long long a, long long b, long long c)
{
    if (a == 0 || b == 0)
        return 0;

    long long a1 = a / 2;
    a1 = multimod1(a1, b, c);
    if (a % 2 == 0)
    {
        return addmod(a1, a1, c);
    }
    else{
        a1 = addmod(a1, a1, c);
        return addmod(a1, b, c);
    }
}

long long mulmod(long long a, long long b, long long c)
{
    if (a > b)
        return multimod1(b, a, c);
    return multimod1(a, b, c);
}


