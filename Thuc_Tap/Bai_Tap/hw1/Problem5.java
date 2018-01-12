package Samsung.java.hw1;

import java.util.Scanner;

public class Problem5 {

	static long A[][] = new long [50][50];
	public static long C(int k, int n)
	{
		if (k == n || k == 0)
			return 1;
		if (A[k][n] == 0)
			A[k][n] = C(k-1, n-1) + C(k, n-1);
		
		return A[k][n];
		
	}
	
	public static void main(String[] args) {
	
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < (n-i); j++)
				if (j%2==0)
					System.out.print("    ");
				else
					System.out.print("  ");
			
			for(int j = 0; j <= i; j++)
				System.out.print(C(j,i)	+ "    ");
			
			System.out.println();
		}
	}

}
