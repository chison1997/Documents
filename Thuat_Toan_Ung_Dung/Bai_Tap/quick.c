#include <stdio.h>
#include "quick.h"

#define gc getchar

void swap(int* a, int*b)
{
    register int t = *a ^ *b;
    *b = *b ^ t;
    *a = t ^ *b;
}

void swap(long long* a, long long* b)
{
    register long long t = *a ^ *b;
    *b = *b ^ t;
    *a = t ^ *b;
}

void swap(float* a, float* b)
{
    register float t = *a;
    *a = *b;
    *b = t;
}

void swap(double* a, double* b)
{
    register double t = *a;
    *a = *b;
    *b = t;
}

void scan(int* a)
{
    register int c = gc();
 
    int neg = 0;
    *a = 0;
    while ( (c < '0' || c > '9') && c != '-' ) {
        c = gc();
    }
    if ( c == '-' ) {
        neg = 1;
        c = gc();
    }
    while ( !(c < '0' || c > '9') ) {
        *a *= 10;
        *a += (c - '0');
        c = gc();
    }
    if ( neg )
    *a = -*a;
}


int scandigits(float *x, int div, int* neg) {
    register int c = gc();
    register float pow10 = 1;
    if ( x == NULL ) {
    return -1;
    }
    *x = 0;
    while ( (c < '0' || c > '9') && c != '-' ) {
    c = gc();
    }
    if ( c == '-' ) {
    *neg = 1;
    c = gc();
    }
    while ( !(c < '0' || c > '9') ) {
    *x *= 10;
    *x += (c - '0');
    pow10 *= 10;
    c = gc();
    }
    if ( *neg )
    *x = -*x;
    if ( div )
    *x /= pow10;
    return c;
}

void scan(float *x) {
  float left, right = 0;
  if ( x == NULL ) {
    return;
  }
  int neg = 0;
  int ret = scandigits(&left, 0, &neg);
  if ( ret == '.' )
    scandigits(&right, 1, &neg);
  *x = left + right;
}