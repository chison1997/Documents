#include <stdio.h>
#include <math.h>

main()
{
    float vectorA[3], vectorB[3], vectorC[3];

    printf("Nhap vector A: \n");
    for(int i = 0; i < 3; i ++)
    {
         printf("Nhap chieu thu %d: ", i + 1); scanf("%f", &vectorA[i]);
    }

    int N;
    float T[30];
    for(int i = 0; i < N; i++)
    {
        printf("Nhap so thu %d: ", i + 1); scanf("%f", &T[i]);
    }


    printf("Nhap vector B: \n");
    for(int i = 0; i < 3; i ++)
    {
         printf("Nhap chieu thu %d: ", i + 1); scanf("%f", &vectorA[i]);
    }

    printf("Vector tong: ");
    for(int i = 0; i < 3; i ++)
    {
        vectorC[i] = vectorA[i] + vectorB[i];
        printf("%.2f, ", vectorC[i]);
    }


    printf("Mang T: \n");
    for(int i = 0; i < N; i++)
    {
        printf("%5.2f", T[i]);
        if (i % 6 == 5)
            printf("\n");
    }


}