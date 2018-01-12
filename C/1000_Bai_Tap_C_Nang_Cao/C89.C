//Bài 89: Viết chương trình tính tổng các giá trị lẻ nguyên dương nhỏ hơn N
#include <stdio.h>

main()
{
  	unsigned int N,S=0;
	printf("N= "); scanf("%u",&N);
	for(int i=1; i<N; i+=2) S+=i; 
	printf("S= %u \n",S);
}
	
