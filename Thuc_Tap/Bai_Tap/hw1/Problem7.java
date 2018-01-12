package Samsung.java.hw1;

import java.util.Scanner;

public class Problem7 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n;
		System.out.print("So luong phan tu cua mang: "); n = input.nextInt();
		
		int A[] = new int[n];
		int temp;
		
		for(int i = 0; i < n; i++)
		{
			A[i] = input.nextInt();
		}
		
		
		for(int i = 0; i < n; i++)
			for(int j = n - 1 ; j > i; j--)
				if (A[j] > A[j-1])
				{
					temp = A[j];
					A[j] = A[j-1];
					A[j-1] = temp;
					
				}
		System.out.println("OK");
		System.out.print("Day sau khi sap xep: ");
		for(int i = 0; i < n; i++)
		{
			System.out.print(A[i] + " ");
		}
	}	
}
