package Samsung.java.hw1;

import java.util.Scanner;

public class Problem10 {
	public static void main(String argv[]) {
		
		Scanner input = new Scanner(System.in);
	
		System.out.print("Nhap so luong tau: ");
		int n = input.nextInt();
		
		int V[] = new int[n];
		float X[] = new float[n];
		float Y[] = new float[n];
		
		for(int i = 0; i < n; i++)
		{
			System.out.println("Tau thu " + (i + 1) + " :");
			System.out.print("Loai tau (tau ta: 1, tau dich: -1): "); V[i] = input.nextInt();
			System.out.print("Hoanh do: "); X[i] = input.nextFloat();
			System.out.print("Tung do: "); Y[i] = input.nextFloat();
			System.out.println();
		}
		
		boolean flag = false;
		int index = 0;
		
		for(int i = 0; i < n; i++)
		{
			if (V[i] == -1)
				if ((X[i] * X[i]) + (Y[i] * Y[i]) <= 150 * 150)
				{
					index = i;
					flag = true;
					break;
				}
		}
		
		if (flag == false)
		{
			System.out.println("Khong co tau dich nao trong tam ban");
		}
		else
		{
			System.out.println("Cac tau dich trong tam ban: ");
			for(int i = index; i < n; i++)
			{
				if (V[i] == -1)
					if ((X[i] * X[i]) + (Y[i] * Y[i]) <= 150 * 150)
					{
						System.out.println("( " + X[i] + "; " + Y[i] + " )");
					}
			}
		}
			
	}
	
}
