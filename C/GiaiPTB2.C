#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,c,delta;
	printf("a= ");scanf("%f",&a);
	printf("\nb= ");scanf("%f",&b);
	printf("\nc= ");scanf("%f",&c);
	
	if (a==0) if (b==0) if (c==0) printf("PT vo so nghiem");
			    else printf("PT vo nghiem");
	          else printf("PT co nghiem duy nhat: %6.2f", -c/b);
	else 
	        {
	             delta=b*b-4*a*c;
	             if (delta<0) printf("PT vo nghiem");
	             else if (delta==0) printf("PT co nghiem kep: x=%6.2f", -b/(2*a));
	             else printf("PT co 2 nghiem phan biet: x1=%6.2f; x2=%6.2f \n ", (-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a) );
	                     
	        }

return 0;
		  
}
