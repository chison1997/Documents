import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class ScoreManagement {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String choice;
		for(;;)
		{
			System.out.println("Learning Management System");
			System.out.println("---------------------------------");
			System.out.println("1. Add a new score board");
			System.out.println("2. Add score");
			System.out.println("3. Remove score");
			System.out.println("4. Search score");
			System.out.println("5. Display score board and score report");
			System.out.print("Your choice (1-5, other to quit): "); 
			choice = input.nextLine();
			
			switch(choice.charAt(0))
			{
			case '1':
				ScoreBoard sb = new ScoreBoard();
				sb.update();
				sb.report();
				break;
			case '2':
				String maMonHoc, maHocKy;
				System.out.print("Ma Mon Hoc: "); maMonHoc = input.nextLine();
				System.out.print("Ma hoc ky: "); maHocKy = input.nextLine();
				try {
					sb = new ScoreBoard(Paths.get(maMonHoc + "_" + maHocKy + ".txt"));
					sb.addScore();
					sb.update();
					sb.report();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
	
				break;
			case '3':
				String mssv;
				System.out.print("Ma Mon Hoc: "); maMonHoc = input.nextLine();
				System.out.print("Ma hoc ky: "); maHocKy = input.nextLine();
				System.out.print("Ma sinh vien: "); mssv = input.nextLine();
				try {
					sb = new ScoreBoard(Paths.get(maMonHoc + "_" + maHocKy + ".txt"));
					sb.delete(mssv);
					sb.update();
					sb.report();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				break;
			case '4':
				System.out.print("Ma Mon Hoc: "); maMonHoc = input.nextLine();
				System.out.print("Ma hoc ky: "); maHocKy = input.nextLine();
				System.out.print("Ma sinh vien: "); mssv = input.nextLine();
				try {
					sb = new ScoreBoard(Paths.get(maMonHoc + "_" + maHocKy + ".txt"));
					StudentScore ss = sb.find(mssv);
					if(ss == null)
					{
						System.out.println("Khong tim thay");
					}
					else {
						System.out.println(ss.toString());
					}
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				break;
			case '5':
				System.out.print("Ma Mon Hoc: "); maMonHoc = input.nextLine();
				System.out.print("Ma hoc ky: "); maHocKy = input.nextLine();
				if (Files.notExists(Paths.get(maMonHoc + "_" + maHocKy + ".txt")))
				{
					System.out.println("Khong tim thay");
				}
				else
				{
					try {
						sb = new ScoreBoard(Paths.get(maMonHoc + "_" + maHocKy + ".txt"));
						System.out.println("Score board: ");
						sb.display();
						System.out.println();
						System.out.println("----------------------------");
						System.out.println("Report: ");
						sb.displayReport();
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				break;
			default:
				System.exit(0);
				
			}
			choice = input.nextLine();
		}
	}

}
