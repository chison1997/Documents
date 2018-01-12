package Samsung.java.hw1;

import java.util.Scanner;



public class Problem1 {

	public static double g(double x, double y)
	{
		return Math.cos(2 * x) + y * y - y + 1;
	}
	
	public static double f(double x)
	{
		return (Math.log(x * x + 1) + Math.sqrt(x * x * x * x + 1)) / (x * x - x + 1);
	}
	
	public static void main(String argv[])
	{
		Scanner input = new Scanner(System.in);
		System.out.print("Enter x: ");
		double x = input.nextDouble();
		
		System.out.print("Enter y: ");
		double y = input.nextDouble();
		
		
		System.out.println("f(" + x + ") = " + Problem1.f(x));
		
		System.out.println("g(" + x + ", " + y + ") = " + Problem1.g(x, y));
		
	}
}
