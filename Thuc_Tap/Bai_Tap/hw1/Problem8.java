package Samsung.java.hw1;

import java.util.Scanner;

public class Problem8 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String s = input.nextLine();
		boolean flag = false;
		int countWord = 0;
		int count[] = new int[26];
		for(int i = 0; i <s.length(); i++)
		{
			if (Character.isLetter(s.charAt(i)) == true)
			{
				if(flag == false)
				{
					countWord ++;
					flag = true;
				}
				
				count[Character.toLowerCase(s.charAt(i)) - 'a'] ++;
	
			}
			else if (Character.isLetter(s.charAt(i)) == false)
			{
				flag = false;
			}
		}
		
		if (countWord == 0)
		{
			System.out.println("Khong co tu nao trong xau");
		}
		else
		{
			System.out.printf("Co %d tu trong xau\n", countWord);
			
			for(int i = 0; i < 26; i++)
			{
				if (count[i] != 0)
					System.out.printf("%c: %d\n", 'A' + i, count[i]);
			}
		}

	}



}


