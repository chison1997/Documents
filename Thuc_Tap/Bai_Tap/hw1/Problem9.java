package Samsung.java.hw1;

import java.util.Scanner;

public class Problem9 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n;
		System.out.print("So luong sinh vien: "); n = input.nextInt();
		String temp = input.nextLine();
		String A[] = new String[n];
		
		for(int i = 0; i < n; i++)
		{
			A[i] = new String();
			A[i] = input.nextLine();
		}
		
		String s = new String();
		System.out.print("Nhap ho ten sinh vien can tim: "); s = input.nextLine();
		
		boolean flag = false;
		
		for(int i = 0; i < n; i++)
		{
			if (s.equals(A[i]))
			{
				flag = true;
				break;
			}
		}
		
		if (flag == true)
			System.out.println("Sinh vien co nam trong danh sach");
		else
			System.out.println("Sinh vien khong nam trong danh sach");

	}

}
