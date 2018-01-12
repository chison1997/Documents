#include<stdio.h>
typedef struct{
	int ngay,thang,nam;
}date;
typedef struct{
	float toan,ly,hoa;
}diemthi;
typedef struct{
	int sbd;
	char ten[128];
	char truong[200];
	date ngaysinh;
	diemthi diem;
}sinhvien;
void slist(sinhvien list[],int n);
void birthday(date* dob);
void newstudent(sinhvien list[],int n);
int main(){
	int n,i;
	sinhvien list[50];
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	slist(list, n);
	printf("\t DANH SACH SINH VIEN\n");
	printf("HO TEN\tNGAY SINH\tTRUONG\tSBD\tDIEM TB\n");
	for(i=0;i<n;i++){
		printf("%s\t",list[i].ten);
		printf("%0.2d/%0.2d/%0.4d\t",list[i].ngaysinh.ngay,list[i].ngaysinh.thang,list[i].ngaysinh.nam);
		printf("%d\t",list[i].sbd);
		printf("%s\t",list[i].truong);
		printf("%.2f\t",(list[i].diem.toan+list[i].diem.ly+list[i].diem.hoa)/3);
		printf("\n");
	}
return 0;
}
void slist(sinhvien list[],int n){
	int i;
	for(i=0;i<n;i++){
		newstudent(list,i);
	}
}
void birthday(date *dob){
	scanf("%d/%d/%d",&(dob->ngay),&(dob->thang),&(dob->nam));
}
void newstudent(sinhvien list[],int n){
	printf("Nhap sinh vien thu %d:\n",n+1);
	printf("Ho ten: \n");
	//fflush(stdin);
	//gets(list[n].ten);
	getchar();
	scanf("%[^\n]s",list[n].ten);
	printf("Ngay sinh: \n");
	birthday(&(list[n].ngaysinh));
	//scanf("%d/%d/%d",&list[n].ngaysinh.ngay,&list[n].ngaysinh.thang,&list[n].ngaysinh.nam);
	printf("Truong: \n");
	fflush(stdin);
	scanf("%[^\n]s",list[n].truong);
	printf("So bao danh: \n");
	scanf("%d",&list[n].sbd);
	printf("Diem toan: \n");
	scanf("%f",&list[n].diem.toan);
	printf("Diem ly: \n");
	scanf("%f",&list[n].diem.ly);
	printf("Diem hoa: \n");
	scanf("%f",&list[n].diem.hoa);
	printf("\n");
}
