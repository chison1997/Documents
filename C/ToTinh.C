#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <math.h>

main()
{       char s[20];
        int l,j;
        long int i;
        printf("s=");gets(s);
        l=strlen(s);
        
        for(i=0;i<pow(2,l);i++) 
         
                {
                        for(j=0;j<l;j++)if (isalpha(s[j])) if (((i/((long int) pow(2,l-j-1)))%2)==1) s[j]=toupper(s[j]);
                                                         else s[j]=tolower(s[j]);
                                         
										
                        
                          puts(s);
                 }
        
}
