//Bài 59: Hãy kiểm tra số nguyên dương n có phải là số đối xứng hay không
#include <stdio.h>
#include <string.h>

main()
{
        
        unsigned int k, KiemTra=1;
        char n[15];
        printf("n= ");gets(n);
        
        k= strlen(n);        
        
        for(int i=0; i<=(k-1)/2; i++) if (n[i]!=n[k-1-i]) KiemTra=0;                     
                                     
        if (KiemTra==1) printf("%s doi xung \n",n); 
        else            printf("%s khong doi xung \n",n);
        
       
}
