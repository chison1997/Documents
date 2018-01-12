package Samsung.java.hw1;

import java.util.Scanner;

public class Problem3 {

	public static double tienDien(int soDien)
	{
		if (soDien <= 0)
			return 0;
		if (soDien <= 25)
			return soDien * 1000;
		if (soDien <= 75)
			return tienDien(25) + (soDien - 25) * 1250;
		if (soDien <= 150)
			return tienDien(75) + (soDien - 75) * 1800;
		
		return tienDien(150) + (soDien - 150) * 2500;
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Nhap so dien tieu thu: ");
		int soDien = input.nextInt();
		
		System.out.println("Tien dien phai tra: " + tienDien(soDien) + " VND");
		
	}

}
