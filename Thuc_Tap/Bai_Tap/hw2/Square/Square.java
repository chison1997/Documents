package Samsung.java.hw2.Square;

public class Square {
	private float canh;
	
	public void setCanh(float canh)
	{
		this.canh = canh;
	}
	
	public void hienThiCanh() {
		System.out.println("Canh: " + canh);
	}
	
	public void hienThiChuVi() {
		System.out.println("Chu vi: " + canh * 4);
	}
	
	public void hienThiDienTich() {
		System.out.println("Dien tich: " + canh * canh);
	}
	
	public void hienThi() {
		this.hienThiCanh();
		this.hienThiChuVi();
		this.hienThiDienTich();
	}
}
