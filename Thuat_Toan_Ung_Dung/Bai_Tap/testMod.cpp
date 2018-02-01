#include <stdio.h>
#include <limits.h>
#include "mod.h"

int main(int argc, char** argv)
{
    long long a, b, c;
    //printf("Sizeof long long: %d byte, long int: %d\n", sizeof(long long), sizeof(long int));
   // a = LLONG_MAX;
    //printf("a = %lld, b = %lld, c = %lld\n", a, b, c);
    scanf("%lld %lld %lld", &a, &b, &c);

    printf("a = %lld, b = %lld, c = %lld\n", a, b, c);
    printf("a*b mod c = %lld\n", mulmod(a, b, c));
    return 0;
}