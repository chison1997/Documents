//Bài 90: Viết chương trình tìm số nguyên dương m lớn nhất sao cho 1 + 2 + … + m < N
#include <stdio.h>

main()
{
  	unsigned int N,S=0,m;
	printf("N= "); scanf("%u",&N);
	for(m=1; S<N; m++) S+=m; 
	m-=2;
	printf("m= %u \n",m);
}
	
