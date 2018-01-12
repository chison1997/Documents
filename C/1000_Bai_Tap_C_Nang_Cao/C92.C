//Bài 92: Tìm ước số chung lớn nhất của 2 số nguyên dương
#include <stdio.h>

unsigned int UCLN(unsigned int m,unsigned int n)
{ 
	while (m!=n) 
	 if (m<n) n-=m; else m-=n;
	return m;
}

main()
{	
	unsigned int m,n;
	printf("m= ");scanf("%u",&m);
	printf("n= ");scanf("%u",&n);
	
	printf("UCLN(%u,%u)=%u \n",m,n,UCLN(m,n));
}
	
