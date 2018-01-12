//Bài 96: Viết chương trình nhập giá trị x, sau đó tính giá trị của hàm số
//f(x) = 2x^2 + 5x + 9 khi x >= 5, f(x) = -2x^2 + 4x – 9 khi x < 5
#include <stdio.h>

main()
{	
	float x,f;
	printf("x=");scanf("%f",&x);
	
	if (x>=5) f=2*x*x+5*x+9; 
          else f=-2*x*x+4*x-9;
	
	printf("f(%.2f)=%.2f \n",x,f);
}
	
