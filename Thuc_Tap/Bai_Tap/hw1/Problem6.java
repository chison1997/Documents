package Samsung.java.hw1;

import java.util.Scanner;

public class Problem6 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		long F1 = 1, F2 = 1, F3 = 2;
		
		for(int i = 0; i < n; i++)
		{
			System.out.printf("%d\t", F1);
			F1 = F2;
			F2 = F3;
			F3 = F1 + F2;
		}

	}

}
