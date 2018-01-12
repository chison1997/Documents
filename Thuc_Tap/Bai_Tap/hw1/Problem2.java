package Samsung.java.hw1;

import java.util.Scanner;

public class Problem2 {

	static final double deltax = 1E-6;
	
	public static double f(double x)
	{
		return Math.tan(2 * x) - x + 1; 
	}
	
	public static double daoHam(double x)
	{
		return (f(x + deltax) - f(x)) / deltax;
	}
	
	
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("x = ");
		double x = input.nextDouble();
		
		System.out.println("f(" + x + ") = " + f(x));
		System.out.println("f'(" + x + ") = " + daoHam(x));

	}

}
