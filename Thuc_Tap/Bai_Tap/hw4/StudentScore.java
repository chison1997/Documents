import java.util.Scanner;
import java.util.StringTokenizer;

public class StudentScore {
	private String hoTenDem;
	private String ten;
	private String MSSV;
	private float diemQuaTrinh;
	private float diemCuoiKy;
	
	public StudentScore()
	{
		Scanner input = new Scanner(System.in);
		System.out.print("Ho ten dem: "); hoTenDem = input.nextLine();
		System.out.print("Ten: "); ten = input.nextLine();
		System.out.print("MSSV: "); MSSV = input.nextLine();
		System.out.print("Diem qua trinh: "); diemQuaTrinh = input.nextFloat();
		System.out.print("Diem cuoi ky: "); diemCuoiKy = input.nextFloat();
		
	}
	
	public StudentScore(String hoTenDem, String ten, String MSSV, float diemQuaTrinh, float diemCuoiKy)
	{
		this.hoTenDem = hoTenDem;
		this.ten = ten;
		this.MSSV = MSSV;
		this.diemQuaTrinh = diemQuaTrinh;
		this.diemCuoiKy = diemCuoiKy;
	}
	
	public StudentScore(String line) {
		StringTokenizer s = new StringTokenizer(line, "|");
		
		String temp;
		s.nextToken();
		MSSV = s.nextToken();
		hoTenDem = s.nextToken();
		ten = s.nextToken();
	
		temp = s.nextToken();
		diemQuaTrinh = Float.parseFloat(temp);
		
		
		temp = s.nextToken();
		diemCuoiKy = Float.parseFloat(temp);
		
	}

	public String getHoTenDem() {
		return hoTenDem;
	}
	public void setHoTenDem(String hoTenDem) {
		this.hoTenDem = hoTenDem;
	}
	public String getTen() {
		return ten;
	}
	public void setTen(String ten) {
		this.ten = ten;
	}
	public String getMSSV() {
		return MSSV;
	}
	public void setMSSV(String mSSV) {
		MSSV = mSSV;
	}
	public float getDiemQuaTrinh() {
		return diemQuaTrinh;
	}
	public void setDiemQuaTrinh(float diemQuaTrinh) {
		this.diemQuaTrinh = diemQuaTrinh;
	}
	public float getDiemCuoiKy() {
		return diemCuoiKy;
	}
	public void setDiemCuoiKy(float diemCuoiKy) {
		this.diemCuoiKy = diemCuoiKy;
	}
	
	
	
	public char getMark(int heSo)
	{
		float diem = diemQuaTrinh * heSo / 100 + diemCuoiKy * (100 - heSo) / 100;
		if (diem >= 8.5)
			return 'A';
		else if (diem >= 7)
			return 'B';
		else if (diem >= 5.5)
			return 'C';
		else if (diem >= 4)
			return 'D';
		else
			return 'F';
	}

	public String getMarkLine(int heSo)
	{
		return "S|" + MSSV + "|" + hoTenDem+ "|" + ten + "| " + diemQuaTrinh + " | " + diemCuoiKy + " | " + getMark(heSo) + " |";
	}

	public String toString()
	{
		return  "MSSV: " + MSSV + ", Ho va ten: " + hoTenDem + " " + ten + ", Diem qua trinh: " + diemQuaTrinh + ", Diem qua trinh: " + diemCuoiKy;
	}
	

}
