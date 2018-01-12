//Bài 95: Viết chương trình nhập 3 số thực. Hãy thay tất cả các số âm bằng trị tuyệt đối của nó
#include <stdio.h>
#include <math.h>
main()
{	
	float a,b,c;
	printf("a=");scanf("%f",&a);
	printf("b=");scanf("%f",&b);	
	printf("c=");scanf("%f",&c);

	a=fabs(a); b=fabs(b); c=fabs(c);
	
	printf("a=%.2f, b=%.2f, c=%.2f \n",a,b,c);
}
	
