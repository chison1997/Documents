import java.util.Scanner;

public class Subject {
	private String maMonHoc;
	private String tenMonHoc;
	private int heSoQuaTrinh;
	private int heSoCuoiKy;
	
	
	public Subject(String maMonHoc, String tenMonHoc, int heSoQuaTrinh)
	{
		this.maMonHoc = maMonHoc;
		this.tenMonHoc = tenMonHoc;
		this.heSoQuaTrinh = heSoQuaTrinh;
		this.heSoCuoiKy = 100 - heSoQuaTrinh;
	}

	public Subject() {
		Scanner input = new Scanner(System.in);
		System.out.print("Ma mon hoc: "); this.maMonHoc = input.nextLine();
		System.out.print("Ten mon hoc: "); this.tenMonHoc = input.nextLine();
		System.out.print("He so qua trinh: "); this.heSoQuaTrinh = input.nextInt();
		this.heSoCuoiKy = 100 - this.heSoQuaTrinh;
	}

	public String getMaMonHoc() {
		return maMonHoc;
	}

	public void setMaMonHoc(String maMonHoc) {
		this.maMonHoc = maMonHoc;
	}

	public String getTenMonHoc() {
		return tenMonHoc;
	}

	public void setTenMonHoc(String tenMonHoc) {
		this.tenMonHoc = tenMonHoc;
	}

	public int getHeSoQuaTrinh() {
		return heSoQuaTrinh;
	}

	public void setHeSoQuaTrinh(int heSoQuaTrinh) {
		this.heSoQuaTrinh = heSoQuaTrinh;
	}

	public int getHeSoCuoiKy() {
		return heSoCuoiKy;
	}

	public void setHeSoCuoiKy(int heSoCuoiKy) {
		this.heSoCuoiKy = heSoCuoiKy;
	}
	
	
	
}
