//Bài 93: Viết chương trình kiểm tra 1 số có phải là số nguyên tố hay không
#include <stdio.h>

main()
{	
	unsigned int n,k=1;
	printf("n= ");scanf("%u",&n);
	if (n<=1) k=0;
	if (n>=4) for(int i=2;i<=floor(sqrt(n));i++) if (n%i==0) { k=0; break;}
	if (k==1) printf("%u la so nguyen to \n",n); 
          else printf("%u khong phai la so nguyen to \n",n);
}
	
