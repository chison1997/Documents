#include <stdio.h>
#include <stdarg.h>

int sum(int argc,...)
{
    va_list ap;
    va_start(ap, argc);
    int sum = 0;
    for(int i = 0; i < argc; i++)
    {
        sum += va_arg(ap, int);
    }
    return sum;
}

int main(int argc, char* argv[], char* envp)
{
    printf("%d\n", sum(3, 1, 2, 3));

    return 0;
}