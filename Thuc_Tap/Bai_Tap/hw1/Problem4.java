package Samsung.java.hw1;

import java.util.Scanner;

public class Problem4 {

	
	static double X[] = new double[2];
	static int num = 0;
	
	public static double f(double x)
	{
		return Math.sin(2 * x) + x * x;
	}
	
	public static double daoHam(double x)
	{
		return 2 * ( Math.cos(2 * x) + x);
	}
	
	public static void solve(double a, double b)
	{
		boolean f = f(a)*f(b) > 0, df = daoHam(a)*daoHam(b) >= 0; 
		
		if (!df && f)
		{
			solve(a, (a+b)/2);
			solve((a+b)/2, b);
		}
		else if (!f)
		{
			do
			{
				double f1 = f(a), f2 = f((a+b)/2);
				if(f1 * f2 <= 0)
				{
					b = (a+b) / 2;
				}
				else
				{
					a = (a+b) / 2;
				}
			}
			while(b - a > 1E-12);
			
			X[num] = (a + b)/2;
			num++;
		}
		
		
	}

	
	public final static void clearConsole()
	{
	    try
	    {
	        final String os = System.getProperty("os.name");

	        if (os.contains("Windows"))
	        {
	            Runtime.getRuntime().exec("cls");
	        }
	        else
	        {
	            Runtime.getRuntime().exec("clear");
	        }
	    }
	    catch (final Exception e)
	    {
	        //  Handle any exceptions.
	    }
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		
		double x;
		char c;
		for(;;)
		{
			System.out.println("\nFuncion: f(x) = sin(2x) + x^2");
			System.out.println("1. Calculate f(x) at x");
			System.out.println("2. Calculate f'(x) at x");
			System.out.println("3. Solve equation f(x) = 0 at [a, b]");
			System.out.println("Press another key to quit");
			c = input.next(".").charAt(0);
			switch(c)
			{
			case '1':
				System.out.print("x = ");
				x = input.nextDouble();
				System.out.println("f(" + x + ") = " + f(x));
				//c = input.next(".").charAt(0);
				//clearScreen();
				break;
			
			case '2':
				System.out.print("x = ");
				x = input.nextDouble();
				System.out.println("f'(" + x + ") = " + daoHam(x));
				//c = input.next(".").charAt(0);
			
				clearConsole();
				break;
				
			case '3':
				double a, b;
				do
				{
					System.out.print("a = ");
					a = input.nextDouble();
					System.out.print("b = ");
					b = input.nextDouble();
				}while (a >= b);
				
				
				solve(a, b);
				
				if (num == 0)
				{
					System.out.printf("Phuong trinh vo nghiem tren [%f, %f]\n", a, b);
					
				}
				else if(num == 2)
				{
					System.out.printf("Phuong trinh co 2 nghiem tren [%f, %f]: %f, %f\n", a, b, X[0], X[1]);
				}
				else
				{
					System.out.printf("Phuong trinh co nghiem duy nhat tren [%f, %f]: %f\n", a, b, X[0]);
				}
				
				break;
			default:
				System.exit(0);
				
			}
			
		}
	}
}
