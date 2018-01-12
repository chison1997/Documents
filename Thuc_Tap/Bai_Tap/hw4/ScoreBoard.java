import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class ScoreBoard {
	Subject monHoc;
	ArrayList<StudentScore> sinhVien;
	String maHocKy;
	int soLuongSV;
	
	
	public ScoreBoard(Path path) throws IOException
	{
		if (Files.notExists(path))
		{
			Files.createFile(path);
		}
		else
		{
			BufferedReader buf = Files.newBufferedReader(path);
			String line = buf.readLine();
			StringTokenizer s = new StringTokenizer(line, "|");

			monHoc = new Subject(null, null, 0);
			
			
			s.nextToken();
			monHoc.setMaMonHoc(s.nextToken()); 
		
			line = buf.readLine();
			s = new StringTokenizer(line, "|");
			s.nextToken();
			monHoc.setTenMonHoc(s.nextToken()); 
			
	
			line = buf.readLine();
			s = new StringTokenizer(line, "|");
			s.nextToken();
			monHoc.setHeSoQuaTrinh(Integer.parseInt(s.nextToken()));
			
			monHoc.setHeSoCuoiKy(Integer.parseInt(s.nextToken())); 
			
			line = buf.readLine();
			s = new StringTokenizer(line, "|");
			s.nextToken();
			maHocKy = s.nextToken(); 
			
			line = buf.readLine();
			s = new StringTokenizer(line, "|");
			s.nextToken();
			soLuongSV = Integer.parseInt(s.nextToken());
			
			sinhVien = new ArrayList<StudentScore>(soLuongSV);

			
			while ((line = buf.readLine()) != null)
			{
				if (line.charAt(0) != 'S')
				{
					System.out.println("Break");
					break;
				}
				
				StudentScore SV = new StudentScore(line);
				sinhVien.add(SV);
			}
		}	
	}
	
	public ScoreBoard()
	{
		System.out.println("Score Board");
		Scanner input = new Scanner(System.in);
		monHoc = new Subject();
		System.out.print("Ma hoc ky: "); this.maHocKy = input.nextLine();
		System.out.print("So Luong SV: "); this.soLuongSV = input.nextInt();
		sinhVien = new ArrayList<StudentScore>();
		System.out.println("Nhap thong tin cac SV: ");
		for(int i = 1; i <= soLuongSV; i++)
		{
			System.out.println("Sinh vien thu " + i + ": ");
			StudentScore ss = new StudentScore();
			sinhVien.add(ss);
		}
		
		try {
			if (Files.notExists(Paths.get(monHoc.getMaMonHoc() + "_" + maHocKy + ".txt")))
				Files.createFile(Paths.get(monHoc.getMaMonHoc() + "_" + maHocKy + ".txt"));
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public Subject getMonHoc() {
		return monHoc;
	}

	public void setMonHoc(Subject monHoc) {
		this.monHoc = monHoc;
	}

	public String getMaHocKy() {
		return maHocKy;
	}

	public void setMaHocKy(String maHocKy) {
		this.maHocKy = maHocKy;
	}

	public int getSoLuongSV() {
		return soLuongSV;
	}

	public void setSoLuongSV(int soLuongSV) {
		this.soLuongSV = soLuongSV;
	}

	
public ArrayList<StudentScore> getSinhVien() {
		return sinhVien;
	}


	public StudentScore find(String mssv)
	{
		for(StudentScore ss: sinhVien)
		{
			if (ss.getMSSV().equals(mssv))
			{
				return ss;
			}
		}
		return null;
	}
	public void addScore()
	{
		StudentScore sv = new StudentScore();
		sinhVien.add(sv);
		soLuongSV ++;
	}
	public void editScore(String MSSV)
	{
		boolean flag = false;
		Scanner input = new Scanner(System.in);
		String choose;
		for(StudentScore sv: sinhVien)
		{
			if (MSSV.equals(sv.getMSSV()))
			{
				flag = true;
				System.out.println(sv.toString());
				System.out.print("Ban muon sua diem khong? (Y/N): ");
				choose = input.nextLine();
				
				if (choose.charAt(0) == 'Y')
				{
					System.out.print("Ban muon sua diem qua trinh hay cuoi ky? (Q/C)");
					choose = input.nextLine();
					if (choose.charAt(0) == 'Q')
					{
						System.out.print("Sua diem qua trinh thanh: "); 
						sv.setDiemQuaTrinh(input.nextFloat());
						System.out.println("Da sua diem qua trinh");
					}
					else if (choose.charAt(0) == 'C')
					{
						System.out.print("Sua diem cuoi ky thanh: "); 
						sv.setDiemCuoiKy(input.nextFloat());
						System.out.println("Da sua diem cuoi ky");
					}
				}
				
			}
		}
		
		if (flag == false)
		{
			System.out.print("Khong tim thay, ban co muon them sinh vien vao bang diem khong? (Y/N): ");
			choose = input.nextLine();
			
			if (choose.charAt(0) == 'Y')
			{
				addScore();
			}
		}
	}
	

	public boolean delete(String MSSV)
	{
		for(StudentScore sv: sinhVien)
		{
			if (MSSV.equals(sv.getMSSV()))
			{
				sinhVien.remove(sv);
				soLuongSV--;
				return true;
			}
		}
		return false;
	}
	
	public void display()
	{
		for(StudentScore ss: sinhVien)
		{
			System.out.printf("%s  %s %-10s %.1f  %.1f  %c\n", ss.getMSSV(), ss.getHoTenDem(), ss.getTen(), ss.getDiemQuaTrinh(), ss.getDiemCuoiKy(), ss.getMark(monHoc.getHeSoQuaTrinh()));
		}
	}
	
	
	public void displayReport()
	{
		float highestMark = 0, lowestMark = 10, average = 0;
		int count[] = new int[6];
		float mark;
		StudentScore highestMarkStudent = null, lowestMarkStudent = null;
		
		for(StudentScore sv: sinhVien)
		{
			mark = (sv.getDiemQuaTrinh() * monHoc.getHeSoQuaTrinh() + sv.getDiemCuoiKy() * monHoc.getHeSoCuoiKy()) / 100;
			average += mark;
			if (mark >= highestMark)
			{
				highestMark = mark;
				highestMarkStudent = sv;
			}
			if (mark <= lowestMark)
			{
				lowestMark = mark;
				lowestMarkStudent = sv;
			}
			
			count[sv.getMark(monHoc.getHeSoQuaTrinh()) - 'A'] ++;
		}
		
		average /= sinhVien.size();
		System.out.println("The student with the highes mark is: " + highestMarkStudent.getHoTenDem() + " " + highestMarkStudent.getTen());
		System.out.println("The student with the lowest mark is: " + lowestMarkStudent.getHoTenDem() + "  " + lowestMarkStudent.getTen());
		System.out.println("The average mark is: " + average);
		System.out.println("A histogram of the subject " + monHoc.getMaMonHoc() + " is: ");
		
		for(char c = 'A'; c <= 'F'; c++)
		{
			System.out.print(c + ": ");
			for(int i = 0; i < count[c - 'A']; i++)
				System.out.print("*");
			System.out.println();
		}
	}
	
	public void update()
	{
		String path = (monHoc.getMaMonHoc() + "_" + maHocKy + ".txt");
		
		try {
			FileWriter wr = new FileWriter(path);
			
			wr.write("SubjectID|" + monHoc.getMaMonHoc() + "\n");
			wr.write("Subject|" + monHoc.getTenMonHoc() + "\n");
			wr.write("F|" + monHoc.getHeSoQuaTrinh() + "|" + monHoc.getHeSoCuoiKy() + "\n");
			wr.write("Semester|" + monHoc.getTenMonHoc() + "\n");
			wr.write("StudentCount|" + soLuongSV + "\n");
			
			for(StudentScore sv : sinhVien)
			{
				wr.write(sv.getMarkLine(monHoc.getHeSoQuaTrinh()) + "\n");
			}
			
			wr.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void report()
	{
		String path = monHoc.getMaMonHoc() + "_" + maHocKy + "_rp.txt";
		
		if (Files.notExists(Paths.get(path)))
		{
			try {
				Files.createFile(Paths.get(path));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		try {
			
			
			float highestMark = 0, lowestMark = 10, average = 0;
			int count[] = new int[6];
			float mark;
			StudentScore highestMarkStudent = null, lowestMarkStudent = null;
			for(StudentScore sv: sinhVien)
			{
				mark = (sv.getDiemQuaTrinh() * monHoc.getHeSoQuaTrinh() + sv.getDiemCuoiKy() * monHoc.getHeSoCuoiKy()) / 100;
				average += mark;
				if (mark >= highestMark)
				{
					highestMark = mark;
					highestMarkStudent = sv;
				}
				if (mark <= lowestMark)
				{
					lowestMark = mark;
					lowestMarkStudent = sv;
				}
				
				count[sv.getMark(monHoc.getHeSoQuaTrinh()) - 'A'] ++;
			}
				
			average /= soLuongSV;
			
			FileWriter wr = new FileWriter(path);
			wr.write("The student with the highes mark is: " + highestMarkStudent.getHoTenDem() + " " + highestMarkStudent.getTen()  + "\n");
			wr.write("The student with the lowest mark is: " + lowestMarkStudent.getHoTenDem() + " " + lowestMarkStudent.getTen() + "\n");
			wr.write("The average mark is: " + average + "\n\n");
			wr.write("A histogram of the subject " + monHoc.getMaMonHoc() + " is: \n");
			
			for(char c = 'A'; c <= 'F'; c++)
			{
				wr.write(c + ": ");
				for(int i = 0; i < count[c - 'A']; i++)
					wr.write("*");
				wr.write("\n");
			}
			
			wr.close();
		} catch (IOException e) {
			e.printStackTrace();
		}	
	}
	
}
