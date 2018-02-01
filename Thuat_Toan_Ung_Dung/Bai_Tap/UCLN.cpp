// __     __                          ____ _     _   ____
// \ \   / /   _  ___  _ __   __ _   / ___| |__ (_) / ___|  ___  _ __
//  \ \ / / | | |/ _ \| '_ \ / _` | | |   | '_ \| | \___ \ / _ \| '_  \*
//   \ V /| |_| | (_) | | | | (_| | | |___| | | | |  ___) | (_) | | | |
//    \_/  \__,_|\___/|_| |_|\__, |  \____|_| |_|_| |____/ \___/|_| |_|
//                           |___/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    unsigned long long a, b;
    if (argc != 3)
    {
        scanf("%llu", &a);
        scanf("%llu", &b);
    }
    else{
        a = atoll(argv[1]);
        a = atoll(argv[2]);
    }

    while(a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    printf("%llu\n", a);

    return 0;
}