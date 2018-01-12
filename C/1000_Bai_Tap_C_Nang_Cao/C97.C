//Bài 97: Viết chương trình nhập 3 cạnh của 1 tam giác, cho biết đó là tam giác gì

#include <stdio.h>

main()
{	
	float a,b,c;
	int can=0,vuong=0,deu=0;
	printf("a=");scanf("%f",&a);
	printf("b=");scanf("%f",&b);
	printf("c=");scanf("%f",&c);
	
	if (a+b<=c || b+c<=a || a+c<=b) printf("ko phai tam giac \n");
	else 
	   {
               if (a*a+b*b==c*c || c*c+b*b==a*a || a*a+c*c==b*b) vuong=1;
	       if (a==b || b==c || a==c) can=1;
	       if (a==b && b==c) deu=1; 
	       
		if (deu) printf("tam giac deu");
		else if (vuong && can) printf("tam giac vuong can \n");
		else if (vuong && !can) printf("tam giac vuong \n");
		else if (!vuong && can) printf("tam giac can \n");
		else printf("tam giac thuong \n");
           }
	
	
}
	
