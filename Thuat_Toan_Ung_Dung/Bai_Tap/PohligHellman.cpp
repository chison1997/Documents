//                                       _     _
// __   ___   _  ___  _ __   __ _    ___| |__ (_)  ___  ___  _ __
// \ \ / / | | |/ _ \| '_ \ / _` |  / __| '_ \| | / __|/ _ \| '_  \*
//  \ V /| |_| | (_) | | | | (_| | | (__| | | | | \__ \ (_) | | | |
//   \_/  \__,_|\___/|_| |_|\__, |  \___|_| |_|_| |___/\___/|_| |_|
//                          |___/

#include <stdio.h>
#include <stdlib.h>
#include "mod.h"

// long long* convert(int* e, int size)
// {
//     int len_e = size / sizeof(int);
//     long long* E = (long long*) malloc(size*8*sizeof(long long));
   
//     int index = 0;
//     for(int i = len_e - 1; i >= 0; i--)
//     {
//         int x = e[i];
//         for(int j = 0; j < sizeof(int)*8; j++)
//         {
//             E[index] = (x & (1 << j)) ? 1 : 0;
//             index++;
//         }
//     }
//     return E;
// }

long long encode(long long N, unsigned long long p, int* e, int size)
{

    int len_e = size / sizeof(int);
    long long C = 1LL;
    long long c = N % p;
    
    for(int i = len_e - 1; i >= 0; i--)
    {
        for(int j = 0; j < sizeof(int)*8; j++)
        {
            if (e[i] & (1 << j))
            {
                C = mulmod(C, c, p);   
            }

            c = mulmod(c, c, p);
        }
    }
    return C;
}

long long decode();


int main()
{
    int e[] = {2, 3};
    unsigned long long p = 18014398241046527;

    printf("%llu\n",encode(69, p, e, sizeof(e)));
	return 0;
}