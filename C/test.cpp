char* reverseParentheses(char s[]) {
    char outPut[56];
    int index=0,i=0;
    
    for(i=0;i<s.size();i++)
    {
        printf("%c",s[i]);
             if(s[i]==')') 
             {
                 int j=i,k=i;
                 while(s[j]!='(') j--;
                 s[i]='0'; s[j]='0';
                 printf("%c",s[i]);
                 while (k!=j) 
                {
                    j++;k--;
                     int temp= s[k];
                     s[k]=s[j];
                     s[j]=temp;
                 }
                 printf("%s",s);
             }
    }
    printf("%s",s);
    
    for(int i=0;i<s.size();i++ )
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) 
        {
            outPut[index]=s[i];
            index++;
        }
    return outPut;
}

main()
{
	printf("%s",reverseParentheses("a(bc)"));
	
}
