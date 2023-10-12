#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

//Dat ten cho ma mau
#define WHITE 7
#define RED 12
#define GREEN 10
#define YELLOW 14

//Ham to mau
void textColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

//Ham an nut ESC thoat chuong trinh
void thoatChuongTrinh(){
	textColor(GREEN);
	printf("Nhan ESC de quay lai !");
	
	int chon;
	do {
		chon = getch(); //Bat 1 ki tu, tu ban phim
	} while(chon!=27);
}	

//Them dau phay thu 1
void motDauPhay(char s[], int chieuDai) {
	for(int i=chieuDai-1; i>=chieuDai-6; i--)  {
		s[i+1] = s[i];
	}
	s[chieuDai-6] = ',';
	s[chieuDai+1] = '\0';
	
}

//Them dau phay thu 2
void haiDauPhay(char s[], int chieuDai) {
	for(int i=chieuDai; i>=chieuDai-9; i--)  {
		s[i+1] = s[i];
	}
	s[chieuDai-9] = ',';
	s[chieuDai+2] = '\0';
}

//Them dau phay thu 3
void baDauPhay(char s[], int chieuDai) {
	
	for(int i=chieuDai+1; i>=chieuDai-12; i--)  {
		s[i+1] = s[i];
	}
	
	s[chieuDai-12] = ',';
	s[chieuDai+3] ='\0';
}

//Them dau phay
void themDauPhay(double so, char s[]) {

	sprintf(s,"%.02f", so); //Chuyen double thanh string
	
	int chieuDai ;                     
	chieuDai = strlen(s); 
	
	//Bat dieu kien de them dau phay
	if(chieuDai <=6) {
		
	}else if(chieuDai >=7 && chieuDai <= 9) {
		motDauPhay(s,chieuDai);
	} else if (chieuDai <=12) {
		motDauPhay(s, chieuDai);
		haiDauPhay(s, chieuDai);
	} else {
		motDauPhay(s, chieuDai);
		haiDauPhay(s, chieuDai);
		baDauPhay(s, chieuDai);
	}

}

//Kiem tra so nguyen to
void soNguyenTo(int x) {
	int dem=0;
	if(x <= 1 ) { // 1 khong phai so nguyen to
		printf("%d khong phai la so nguyen to\n", x);
	} else  {
		//Co 1 so chia het trong khoang 2->x , thi so do khong phai so nguyen to
		for(int i=2; i<x; i++) {
			if(x%i==0) {
				dem++;
				break;
			}
		}
		
		if(dem==0 || x==2) { //Neu khong co nao, hoac x=2 thi so do la so nguyen to
			printf("%d la so nguyen to\n",x);
		} else {
			printf("%d khong phai la so nguyen to\n", x);
		}
	}
}

//Kiem tra so chinh phuong
void soChinhPhuong(int x) {
	int soChinhPhuong=0; //check
	
	for(int i=0; i<=(x/2+1); i++) {
		if(i*i == x) { //binh phuong cua 1 so = x
			soChinhPhuong = 1; //check out
			break;
		}
	}
	
	if(soChinhPhuong) {
		printf("%d la so chinh phuong", x);
	} else {
		printf("%d khong phai la so chinh phuong", x);
	}
}



void bai1() {
	char kiTu;
	int kiemTraKiTu;
	float x;
	
	
	system("cls");
	textColor(WHITE);
	printf("Bai 1: Kiem tra so nguyen\n\n");
	
	do {
		printf("Nhap so x: ");
		kiemTraKiTu = scanf("%f%c", &x, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n'); //Kiem tra co ki tu, thi nhap lai
	
	printf("\n");
	textColor(YELLOW);
	
	if(x==(int)x) { //Kiem tra so nguyen
		printf("%0.f la so nguyen\n", x);
		soNguyenTo((int)x); //Goi ham check so nguyen to
		soChinhPhuong((int)x); //Goi ham check so chinh phuong
	} else {
		printf("%.2f khong phai la so nguyen\n",x);
		printf("%.2f khong phai la so nguyen to\n",x);
		printf("%.2f khong phai la so chinh phuong\n",x);
	}
	
	printf("\n\n");
	thoatChuongTrinh();
}

//Tim uoc chung lon nhat
int uocChungLonNhat(int a, int b) {
	int temp, UCLN;
	
	if(a>b) { //Mac dinh a<b, neu a>b, thi doi lai
		temp = a;
		a = b;
		b = temp;
	}
	
	
	for(int i=a; i>=1; i--) { //Duyet bat tu so a, so be hon, giam dan (a<b)
		if(a%i==0 && b%i==0) { //Neu co 1 so chia het cho ca a va b, thi do la UCLN
			UCLN = i;
			break;
		}
	}
	
	return UCLN; //tra ve UCLN
}

//Tim boi chung nho nhat
int boiChungNhoNhat(int a, int b, int UCLN) {
	return (a*b)/UCLN; //tich cua 2 so chia cho UCLN = BCNN
}

void bai2() {
	system("cls");
	textColor(RED);
	printf("Bai 2: Tim uoc chung va boi chung nho nhat\n\n");
	textColor(WHITE);
	
	int a,b, temp, kiemTraKiTu, UCLN=1, BCNN=1;
	char kiTu;
	
	//Nhap so a
	do {
		printf("Nhap so a: ");
		kiemTraKiTu = scanf("%d%c", &a, &kiTu);
		fflush(stdin); //Xoa bo dem
	} while(kiemTraKiTu !=2 || kiTu !='\n' || a<=0);
	
	//Nhap so a	
	do {
		printf("Nhap so b: ");
		kiemTraKiTu = scanf("%d%c", &b, &kiTu);
		fflush(stdin);
	} while(kiemTraKiTu !=2 || kiTu !='\n' || a<=0);
	
	
	UCLN = uocChungLonNhat(a,b); //Goi ham tim UCLN
	
	BCNN = boiChungNhoNhat(a,b,UCLN); //Goi ham tim BCNN
	
	//In ket qua
	printf("\nHai so %d va %d\n\n", a, b);
	
	printf("Uoc chung lon nhat la: %d\n", UCLN);
	printf("Boi chung nho nhat la: %d\n\n", BCNN);
	
	thoatChuongTrinh();
}

//Khai bao gia tri mac dinh
const float tienBaGioDau = 150000;
const float tienGioThuTu = 105000;

void bai3() {
	system("cls");
	textColor(RED);
	printf("Bai 3: Tinh tien cho quan Karaoke\n\n");
	textColor(YELLOW);
	
	float gioBatDau, gioKetThuc, kiemTraKiTu;
	float tongGio = 0, tongTien=0, baGioDau = 3;
	char kiTu;
	
	printf("Quan hoat dong trong khoang tu 12h -> 23h\n\n");
	
	textColor(WHITE);
	
	do {
		//Nhap gio bat dau
		do {
			printf("Nhap gio bat dau: ");
			kiemTraKiTu = scanf("%f%c", &gioBatDau, &kiTu);
			fflush(stdin);
		} while(kiemTraKiTu !=2 || kiTu !='\n' || gioBatDau > 22 || gioBatDau < 12);
		
		//Nhap gio ket thuc 
		do {
			printf("Nhap gio ket thuc: ");
			kiemTraKiTu = scanf("%f%c", &gioKetThuc, &kiTu);
			fflush(stdin);
		} while(kiemTraKiTu !=2 || kiTu !='\n' || gioKetThuc > 23 || gioKetThuc < 12);
		
		textColor(3);
		//Gio bat dau phai be hon gio ket thuc
		if(gioBatDau >= gioKetThuc) {
			printf("Gio ket thuc phai lon hon gio bat dau.\nMoi nhap lai.\n\n");
		}
		textColor(WHITE);
		
	} while(gioBatDau >= gioKetThuc);
	
	textColor(YELLOW);
	printf("\nGio bat dau: %.02f\n", gioBatDau);
	printf("Gio ket thuc: %.02f\n", gioKetThuc);
	
	tongGio = gioKetThuc - gioBatDau; //Tong so gio 
	
	if(tongGio <= baGioDau) { //Tong so gio <= 3, nguyen gia 
		tongTien = tongGio * tienBaGioDau;
	} else { //Tong so gio >3, tu gio thu 4 duoc giam gia
		tongTien = baGioDau * tienBaGioDau + (tongGio-baGioDau) * tienGioThuTu;
	}
	
	//Neu gio bat dau trong khoang 14->17 thi giam 10% tong bill
	if(gioBatDau >=14 && gioBatDau <= 17) {
		tongTien = tongTien*0.9;
	}
	
	char tongTien_str[100];
	//Them dau phay vao so
	themDauPhay(tongTien, tongTien_str);
	
	printf("Tong tien thanh toan: %s VND", tongTien_str);

	printf("\n\n");
	thoatChuongTrinh();
}

void bai4() {
	system("cls");
	textColor(RED);
	printf("Bai 4: Tinh tien dien\n\n");
	textColor(WHITE);
	
	char kiTu;
	int kiemTraKiTu,tienMotSo,bac;
	float soDien, tienDien;
	
	//Nhap so dien
	do {
		printf("Nhap vao so dien: ");
		kiemTraKiTu = scanf("%f%c", &soDien, &kiTu);
		fflush(stdin);
	}while( kiemTraKiTu !=2 || kiTu !='\n' || soDien < 0);
	
	//Kiem tra so dien, dang dung o bac nao
	if(soDien >= 0 && soDien <= 50) {
		bac = 1;
		tienMotSo = 1678;
	}else if(soDien > 50 && soDien <= 100) {
		bac = 2;
		tienMotSo = 1734;
	}else if(soDien > 100 && soDien <= 200) {
		bac = 3;
		tienMotSo = 2014;
	}else if(soDien > 200 && soDien <= 300) {
		bac = 4;
		tienMotSo = 2536;
	}else if(soDien > 300 && soDien <= 400) {
		bac = 5;
		tienMotSo = 2834;
	}else {
		bac = 6;
		tienMotSo = 2927;
	}
	
	char tienDien_str[50];
	tienDien = tienMotSo * soDien; //Tinh tien dien, theo muc gia tien bac tuong ung
	
	themDauPhay(tienDien, tienDien_str);//Them dau phay vao so
	
    //In ket qua	
	textColor(YELLOW);
	printf("\nBan dang dung dien o bac: %d\n",bac);
	printf("Tien dien can phai dong la: %s VND", tienDien_str);

	printf("\n\n");
	thoatChuongTrinh();
}

void bai5() {
	system("cls");
	textColor(RED);
	printf("Bai 5: Chuc nang doi tien\n\n");
	textColor(WHITE);
	
	int tongTien, kiemTraKiTu;
	int soDu;
	char kiTu;
	
	//Nhap so tien can doi
	do {
		printf("Nhap so tien can doi: ");
		kiemTraKiTu = scanf("%d%c", &tongTien, &kiTu);
		fflush(stdin);
	} while(kiemTraKiTu !=2 || kiTu !='\n' || tongTien <= 0);
	
	
	soDu = tongTien;
	printf("\n");
	textColor(YELLOW);
	
	//Kiem tra cac truong hop de doi tien
	while(soDu!=0) {
		if(soDu >= 500 && tongTien != 500) {
			printf("%d to 500\n", soDu/500); //Chia lay nguyen de lay so to tien tuong ung
			soDu = soDu%500; //Chia lay du de lay so tien con lai
		} else if(soDu >= 200 && tongTien != 200) {
			printf("%d to 200\n", soDu/200);
			soDu = soDu%200;
		} else if(soDu >= 100 && tongTien != 100) {
			printf("%d to 100\n", soDu/100);
			soDu = soDu%100;
		} else if(soDu >= 50 && tongTien != 50) {
			printf("%d to 50\n", soDu/50);
			soDu = soDu%50;
		} else if(soDu >= 20 && tongTien != 20) {
			printf("%d to 20\n", soDu/20);
			soDu = soDu%20;
		} else if(soDu >= 10 && tongTien != 10) {
			printf("%d to 10\n", soDu/10);
			soDu = soDu%10;;
		} else if(soDu >= 5 && tongTien != 5) {
			printf("%d to 5\n", soDu/5);
			soDu = soDu%5;
		} else if(soDu >= 2 && tongTien != 2) {
			printf("%d to 2\n", soDu/2);
			soDu = soDu%2;
		} else {
			printf("%d to 1\n", soDu/1);
			soDu = soDu%1;
		}
	}
	
	printf("\n");
	
	thoatChuongTrinh();	
}

//Khai bao  gia tri mac dinh
const int kyHanThang = 12; //Ki han vay 12 thang
const int laiMotThang = 5; //Lai 1 thang 5%/thang

void bai6() {
	system("cls");
	textColor(RED);
	printf("Bai 6: Tinh lai suat vay ngan hang, vay tra gop\n\n");
	textColor(WHITE);
	
	char kiTu;
	double tienVay, tienConLai, tienLaiHangThang = 0, tongTienLai=0, gocPhaiTra=0, gocVaLai=0;
	int kiemTraKiTu; 
	
	//Nhap so tien muon vay
	do {
		printf("Nhap vao so tien muon vay: ");
		kiemTraKiTu = scanf("%lf%c", &tienVay, &kiTu);
		fflush(stdin);
	}while( kiemTraKiTu !=2 || kiTu !='\n' || tienVay <= 0);
	
	textColor(YELLOW);
	
	char tienVay_str[50]; //khai bao bien chuoi luu gia tri tien vay ngan hang
	themDauPhay(tienVay, tienVay_str); //them dua phay vao so
	
	printf("\nSo tien muon vay: %s VND", tienVay_str);
	printf("\nLai thang: %d %%/thang\n", laiMotThang);
	printf("Ky han: %d thang\n", kyHanThang);
	
	//Goc phai tra = tien vay / ki han vay 
	gocPhaiTra =  tienVay/kyHanThang; 
	
	//Tien con lai sau khi tra tung thang
	tienConLai = tienVay; 
	
	printf("\n");
	textColor(WHITE);
	for(int i=0; i<90; i++) {
		printf("-");
	}	
	
	printf("\n");
	printf("%-10s %-20s %-20s %-20s %-20s",
		"Ky han",
		"Lai phai tra",
		"Goc phai tra",
		"So tien phai tra", 
		"So tien con lai");
		
	printf("\n");
	
	char tienLaiHangThang_str[100], gocPhaiTra_str[100], gocVaLai_str[100], tienConLai_str[100] ;
	themDauPhay(gocPhaiTra, gocPhaiTra_str);

	for(int i=1; i<= kyHanThang; i++) {
		//Tinh toan tien 
		tienLaiHangThang = tienConLai*laiMotThang*0.01;
		tongTienLai += tienLaiHangThang;
		gocVaLai = gocPhaiTra + tienLaiHangThang;
		tienConLai -= gocPhaiTra;
		
		if(tienConLai < 0 ) { //chuyen am thanh duong
			tienConLai = -tienConLai;
		}
		
		//them dau phay vao pho
		themDauPhay(tienLaiHangThang, tienLaiHangThang_str);
		themDauPhay(gocVaLai, gocVaLai_str);
		themDauPhay(tienConLai, tienConLai_str);
		
		//In bang 
		printf("%-10d %-20s %-20s %-20s %-20s",
		i, tienLaiHangThang_str, gocPhaiTra_str, gocVaLai_str, tienConLai_str);

		printf("\n");
	}
	
	for(int i=0; i<90; i++) {
		printf("-");
	}
	
	textColor(YELLOW);
	
	//Tong tien lai, tong tien lai va goc
	char tongTienLai_str[50], tongLaiGoc[50];
	themDauPhay(tongTienLai, tongTienLai_str);
	themDauPhay(tongTienLai + tienVay, tongLaiGoc);
	
	printf("\n\nTong tien lai phai tra: %s VND", tongTienLai_str);
	printf("\nTong tien goc va lai phai tra: %s VND", tongLaiGoc);

	printf("\n\n");
	thoatChuongTrinh();	
}

//Khai bao gia tri mac dinh
const double tienVayMuaOto = 500000000; //Tong tien vay
const int thoiHanVay = 24; //Ki han vay 24 nam
const float laiSuatNam = 7.2; //Lai suat 7.2%/nam

void bai7() {
	system("cls");
	textColor(RED);
	printf("Bai 7: Vay tien mua xe\n\n");
	textColor(WHITE);
	
	float phanTramVay;
	int kiemTraKiTu;
	char kiTu;
	
	//Nhap so phan tram muon vay
	do {
		printf("Nhap vao phan tram vay: ");
		kiemTraKiTu = scanf("%f%c", &phanTramVay, &kiTu);
		fflush(stdin);
	}while( kiemTraKiTu !=2 || kiTu !='\n' || phanTramVay <= 0 || phanTramVay > 100);
	
	//Tien tra lan dau
	double tienTraLanDau = tienVayMuaOto*(100-phanTramVay)*0.01;
	
	double tienTraGop=0, tienLaiHangThang= 0, tienLaiTong=0, gocVaLai = 0, gocPhaiTra=0;
	
	tienTraGop = tienVayMuaOto*phanTramVay*0.01; //Tien con lai tra gop hang nam
	gocPhaiTra =  tienTraGop/thoiHanVay; //Tien goc phai tra hang nam
	
	//Chuyen so thanh string de them dau phay
	char tienVayMuaOto_str[50], tienTraLanDau_str[50], tienTraGop_str[50];
	themDauPhay(tienVayMuaOto, tienVayMuaOto_str);
	themDauPhay(tienTraLanDau, tienTraLanDau_str);
	themDauPhay(tienTraGop, tienTraGop_str);
	
	//In cac gia tri 
	textColor(YELLOW);
	printf("\nTong tien vay: %s VND", tienVayMuaOto_str);
	printf("\nPhan tram vay: %.02f %%", phanTramVay);
	printf("\nTien phai tra lan dau: %s VND", tienTraLanDau_str);
	printf("\nTien tra gop: %s VND", tienTraGop_str);
	printf("\nLai suat: %.2f %%/nam", laiSuatNam);
	printf("\nKi han: %d nam", thoiHanVay);
	
	//In bang sao ke
	textColor(WHITE);
	printf("\n\n");
	for(int i=0; i<90; i++) {
		printf("-");
	}
	printf("\n");
	printf("%-10s %-20s %-20s %-20s %-20s",
		"Ky han",
		"Lai phai tra",
		"Goc phai tra",
		"So tien phai tra", 
		"So tien con lai");
	
	printf("\n");
	char tienLaiHangThang_str[50], gocPhaiTra_str[50], gocVaLai_str[50];
	themDauPhay(gocPhaiTra, gocPhaiTra_str);
	
	for(int i=1; i<= thoiHanVay; i++) {
		tienLaiHangThang = tienTraGop*laiSuatNam*0.01;
		tienLaiTong += tienLaiHangThang;
		gocVaLai = gocPhaiTra + tienLaiHangThang;
		tienTraGop -= gocPhaiTra;
		
		//Am thi chuyen thanh duong
		if(tienTraGop < 0) { 
			tienTraGop = -tienTraGop;	
		}
		
		//them dau phay vao so
		themDauPhay(tienLaiHangThang, tienLaiHangThang_str);
		themDauPhay(gocVaLai, gocVaLai_str);
		themDauPhay(tienTraGop, tienTraGop_str);
		
		printf("%-10d %-20s %-20s %-20s %-20s",
		i, tienLaiHangThang_str, gocPhaiTra_str, gocVaLai_str, tienTraGop_str);
		
		printf("\n");
	}
	
	for(int i=0; i<90; i++) {
		printf("-");
	}
	
	//Tong tien lai phai tra, tong tien lai va goc phai tra
	textColor(YELLOW);
	double tongTienLaiVaVay = tienLaiTong + tienVayMuaOto*phanTramVay*0.01;
	char tienLaiTong_str[50], tongTienLaiVaVay_str[50];
	
	//Them dau phay vao so
	themDauPhay(tienLaiTong, tienLaiTong_str);
	themDauPhay(tongTienLaiVaVay, tongTienLaiVaVay_str);
	
	printf("\n\nTong tien lai phai tra la: %s VND", tienLaiTong_str);
	printf("\nTong tien goc va lai phai tra la: %s VND", tongTienLaiVaVay_str );
		
	printf("\n\n");
	thoatChuongTrinh();	
}

//Dinh nghia kieu "Sinh Vien" bang structure
struct sinhVien {
	char hoTen[30];
	float diem;
	char hocLuc[15];
};

//Khoi tao du lieu co san cho danh sach sinh vien
int dsSinhVien(struct sinhVien dssv[], int *soLuong) {
	strcpy(dssv[0].hoTen, "Pham Xuan Cuong");
	dssv[0].diem = 9;
	strcpy(dssv[0].hocLuc,"Xuat Sac");
	
	strcpy(dssv[1].hoTen, "Ha Kim Oanh");
	dssv[1].diem = 10;
	strcpy(dssv[1].hocLuc,"Xuat sac");
	
	*soLuong = 2;
	
}

//Ham them so luong sinh vien vao danh sach
int themSinhVien(struct sinhVien dssv[], int *soLuongCu) {
	
	int kiemTraKiTu, soLuongMuonThem;
	char kiTu;
	
	//Nhap so luong sinh vien muon them
	do {
		printf("Nhap so luong sinh vien muon them: ");
		kiemTraKiTu = scanf("%d%c", &soLuongMuonThem, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n' || soLuongMuonThem<0);
	
	printf("\n");
	
	//so luong them = 0, out ra khoi ham 
	if(soLuongMuonThem==0) return *soLuongCu;
	
	int dem=1;
	float diem;
	
	//Nhap thong tin cua tung sinh vien
	for(int i = *soLuongCu; i < *soLuongCu + soLuongMuonThem; i++ ) {
		//Nhap ho ten sinh vien
		printf("Nhap ho ten sinh vien thu %d: ", dem);
		fflush(stdin);
		gets(dssv[i].hoTen);
//		fflush(stdin);

		//Nhap diem sinh vien 0->10
		do {
			printf("Nhap diem sinh vien thu %d: ",dem);
			kiemTraKiTu = scanf("%f%c", &dssv[i].diem, &kiTu);
			fflush(stdin);
		} while( kiemTraKiTu !=2 || kiTu !='\n' || dssv[i].diem<0 || dssv[i].diem >10);
		
		diem = dssv[i].diem;
		//Xep loai hoc luc tuong ung theo diem cua sinh vien
		if(diem >= 9) {
			strcpy(dssv[i].hocLuc, "Xuat sac");
		} else if(diem >= 8) {
			strcpy(dssv[i].hocLuc, "Gioi");
		} else if(diem >= 6.5) {
			strcpy(dssv[i].hocLuc, "Kha");
		} else if(diem >= 5) {
			strcpy(dssv[i].hocLuc, "Trung binh");
		} else {
			strcpy(dssv[i].hocLuc, "Yeu");
		}
		dem++;
		printf("\n");
	}	
	
	//tra ve so luong sinh vien trong danh sach
	return *soLuongCu + soLuongMuonThem;
}

//Ham sap xep sinh vien theo diem giam da (Dung sap xep noi bot)n
void sapXepDiemGiamDan(struct sinhVien dssv[], int soLuong) {
	struct sinhVien sv; //Khai bao kei SinhVien
	
	for(int i=0; i<soLuong; i++) {	
		for(int j=0; j<soLuong-i-1; j++) {
			if(dssv[j].diem < dssv[j+1].diem) { // Neu diem sinh vien phia truoc < diem sinh vien phia sau (doi cho)
				sv = dssv[j];
				dssv[j] = dssv[j+1];
				dssv[j+1] = sv;
			}
		}
	}
}

//Ham in thong tin cua sinh, trong danh sach sinh vien
void inDSSV(struct sinhVien dssv[], int soLuong) {
	textColor(YELLOW);
	
	//Neu so luong = 0, thi danh sach rong
	if(soLuong ==0) {
		printf("Danh sach rong\n");
	} else { //Neu so luong khac 0, thi in sinh vien theo diem giam dan
		sapXepDiemGiamDan(dssv,soLuong);
		printf("%-25s %-20s %-20s\n","Ho va ten","Diem","Hoc luc");
		textColor(WHITE);
		for(int i=0; i<soLuong; i++) {	
			printf("%-25s %-20.02f %-20s", dssv[i].hoTen, dssv[i].diem, dssv[i].hocLuc);
			printf("\n");
		}
	}
}

void bai8(struct sinhVien dssv[], int *soLuongSinhVien) {
	system("cls");
	textColor(RED);
	printf("Bai 8: Sap xep thong tin sinh vien\n\n");
	textColor(WHITE);	
	
	int soLuongMoi;
	//Goi ham them sinh vien
	soLuongMoi = themSinhVien(dssv,soLuongSinhVien);
	
	//Cap nhat lai so luong sinh vien trong danh sach
	*soLuongSinhVien = soLuongMoi; 

	//Goi ham in danh sach sinh vien
	inDSSV(dssv, *soLuongSinhVien);

	printf("\n");
	thoatChuongTrinh();	
}

//Tao 1 so ngau nhien trong khoang min -> max
int taoSoNgauNhien(int min, int max) {
	return min + rand()%(max - min +1);
}

void bai9() {
	system("cls");
	textColor(RED);
	printf("Bai 9: Game FPOLY-LOTT\n\n");
	textColor(WHITE);
	
	int kiemTraKiTu,so1,so2;
	char kiTu;
	
	printf("Nhap 2 so ngau nhien tu 01 -> 15");
	
	//Nhap so thu 1
	printf("\n\n");
	do {
		printf("Nhap so thu nhat: ");
		kiemTraKiTu = scanf("%d%c", &so1, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n' || so1 <1 || so1 > 15);
	
	//Nhap so thu 2
	do {
		printf("Nhap so thu hai: ");
		kiemTraKiTu = scanf("%d%c", &so2, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n' || so2 <1 || so2 > 15);
	
	textColor(YELLOW);
	printf("\nHai so ban chon la: %d va %d", so1,so2);
	
	int soNgauNhien1, soNgauNhien2;
	
	//tao so hat giong moi sau moi lan chay (truyen vao so giay)
	srand(time(0)); 

	//Goi ham tao so ngau nhien, tra ve so ngau nhien
	soNgauNhien1 = taoSoNgauNhien(1,15); 
	soNgauNhien2 = taoSoNgauNhien(1,15);
	
	printf("\nHai so may man la: %d va %d", soNgauNhien1, soNgauNhien2);
	printf("\n\n");
	if( (so1==soNgauNhien1 && so2==soNgauNhien2) || (so1==soNgauNhien2 && so2==soNgauNhien1)) { //Trung ca 2 so => Giai nhat
		printf("Chuc mung ban da trung giai nhat !");
	} else if(so1==soNgauNhien1 || so1==soNgauNhien2 || so2==soNgauNhien1 || so2==soNgauNhien2) { //Trung 1 so => Giai nhi
		printf("Chuc mung ban da trung giai nhi !");
	} else { //Khong trung so nao => Khong co giai
		printf("Chuc ban may man lan sau !");
	}
	
	printf("\n\n");
	thoatChuongTrinh();	
}

//Dinh nghia kieu du lieu "Phan So"
struct phanSo {
	int tuSo;
	int mauSo;
};

//Ham quy uoc phan so: ca tu so va mau so deu am -> chuyen ve duong het, tu so duong va mau so am -> chuyen thanh tu so am, mau so duong
struct phanSo quyUocPhanSo(struct phanSo ps) { //tu so va mau so deu am chuyen thanh so duong
	if(ps.tuSo<0 && ps.mauSo<0) {
		ps.tuSo = abs(ps.tuSo);
		ps.mauSo = abs(ps.mauSo);
	} else if(ps.mauSo < 0 && ps.tuSo>0) {
		ps.tuSo = -ps.tuSo;
		ps.mauSo = abs(ps.mauSo);
	}	
	return ps;
}

//Ham nhap phan so
struct phanSo nhapPhanSo() {
	int kiemTraKiTu, tuSo, mauSo;
	char kiTu;
	struct phanSo ps;
	
	//Nhap tu so
	do {
		printf("Nhap tu so: ");
		kiemTraKiTu = scanf("%d%c", &tuSo, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n');
	
	//Nhap mau so, !=0
	do {
		printf("Nhap mau so: ");
		kiemTraKiTu = scanf("%d%c", &mauSo, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n' || mauSo==0);
	
	ps.tuSo = tuSo;
	ps.mauSo = mauSo;
	
	//Goi ham quy uoc
	ps = quyUocPhanSo(ps);
	
	return ps;
}


//Ham rut gon phan so
struct phanSo rutGonPhanSo(struct phanSo ps) {
	int UCLN;
	UCLN = uocChungLonNhat( abs(ps.tuSo), abs(ps.mauSo));
	
	ps.tuSo /= UCLN;
	ps.mauSo /= UCLN;
	
	return ps;
}

//Phep nhan phan so
void phepNhanPhanSo(struct phanSo ps1, struct phanSo ps2) {
	struct phanSo tich;
	tich.tuSo = ps1.tuSo * ps2.tuSo;
	tich.mauSo = ps1.mauSo * ps2.mauSo;
	
	tich = rutGonPhanSo(tich); //Goi ham rut gon phan so
	tich = quyUocPhanSo(tich); //Goi ham quy uoc phan so
	
	//In ket qua
	if(tich.mauSo == 1) {
		printf("Phep nhan: %d/%d * %d/%d = %d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, tich.tuSo );
	} else {
		printf("Phep nhan: %d/%d * %d/%d = %d/%d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, tich.tuSo, tich.mauSo );
	}
	printf("\n");
}

//Ham chia phan so
void phepChiaPhanSo(struct phanSo ps1, struct phanSo ps2) {
	struct phanSo thuong;
	thuong.tuSo = ps1.tuSo * ps2.mauSo;
	thuong.mauSo = ps1.mauSo * ps2.tuSo;
	
	thuong = rutGonPhanSo(thuong); //Goi ham rut gon phan so
	thuong = quyUocPhanSo(thuong); //Goi ham quy uoc phan so
	
	//In ket qua
	if(thuong.mauSo == 1) {
		printf("Phep chia: %d/%d / %d/%d = %d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, thuong.tuSo );
	} else {
		printf("Phep chia: %d/%d / %d/%d = %d/%d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, thuong.tuSo, thuong.mauSo );
	}
	
	printf("\n");
}

//Tim mau so chung
int timMauSoChung(struct phanSo ps1, struct phanSo ps2) {
	int UCLN, mauSoChung;
	
	//Tim UCLN cua 2 mau so
	UCLN = uocChungLonNhat(ps1.mauSo, ps2.mauSo);
	
	//Mau so chung = BCNN
	mauSoChung = boiChungNhoNhat(ps1.mauSo, ps2.mauSo, UCLN);
	
	//Tra ve mau so chung
	return mauSoChung;
}

//Ham cong phan so
void phepCongPhanSo(struct phanSo ps1, struct phanSo ps2) {
	struct phanSo tong;
	int mauSoChung;
	
	//tim mau so chung
	mauSoChung = timMauSoChung(ps1,ps2); 
	
	//Quy dong, cong tu so
	tong.tuSo =  (mauSoChung/ps1.mauSo)*ps1.tuSo + (mauSoChung/ps2.mauSo)*ps2.tuSo ; 
	tong.mauSo = mauSoChung;
	
	tong = rutGonPhanSo(tong); //Goi ham rut gon phan so
	tong = quyUocPhanSo(tong);	//Goi ham quy uoc phan so
	
	//In ket qua
	if(tong.mauSo == 1) {
		printf("Phep cong: %d/%d + %d/%d = %d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, tong.tuSo );
	} else {
		printf("Phep cong: %d/%d + %d/%d = %d/%d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, tong.tuSo, tong.mauSo );
	}
	
	printf("\n");
}

//Ham tru phan so
void phepTruPhanSo(struct phanSo ps1, struct phanSo ps2) {
	struct phanSo hieu;
	int mauSoChung;
	
	//tim mau so chung
	mauSoChung = timMauSoChung(ps1,ps2); 
	
	//Quy dong, tru tu so
	hieu.tuSo =  (mauSoChung/ps1.mauSo)*ps1.tuSo - (mauSoChung/ps2.mauSo)*ps2.tuSo ; 
	hieu.mauSo = mauSoChung;
	
	hieu = rutGonPhanSo(hieu); //Goi ham rut gon phan so
	hieu = quyUocPhanSo(hieu);	//Goi ham quy uoc phan so
	
	//In ket qua
	if(hieu.mauSo == 1) {
		printf("Phep tru: %d/%d - %d/%d = %d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, hieu.tuSo );
	} else {
		printf("Phep tru: %d/%d - %d/%d = %d/%d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, hieu.tuSo, hieu.mauSo );
	}
	
	printf("\n");
}

void bai10() {
	system("cls");
	textColor(RED);
	printf("Bai 10: Tinh toan phan so\n\n");
	textColor(WHITE);
	
	//Khai bao 2 phan so
	struct phanSo phanSo1, phanSo2;

	//Nhap phan so
	printf("Nhap phan so thu 1");
	printf("\n");
	phanSo1 = nhapPhanSo();
	
	printf("\n");
	printf("Nhap phan so thu 2");
	printf("\n");
	phanSo2 = nhapPhanSo();
	
	//Rut gon phan so
	phanSo1 = rutGonPhanSo(phanSo1);
	phanSo2 = rutGonPhanSo(phanSo2);
	
	//In phan so
	textColor(11);
	if(phanSo1.mauSo == 1) {
		printf("\nPhan so thu 1: %d", phanSo1.tuSo);
	} else {
		printf("\nPhan so thu 1: %d/%d", phanSo1.tuSo, phanSo1.mauSo);
	}
	
	if(phanSo2.mauSo == 1) {
		printf("\nPhan so thu 2: %d", phanSo2.tuSo);
	} else {
		printf("\nPhan so thu 2: %d/%d", phanSo2.tuSo, phanSo2.mauSo);
	}
	
	textColor(YELLOW);
	printf("\n\n");
	
	//Goi ham cong
	phepCongPhanSo(phanSo1, phanSo2);
	//Goi ham tru
	phepTruPhanSo(phanSo1, phanSo2);
	//Goi ham nhan
	phepNhanPhanSo(phanSo1, phanSo2);
	//Goi ham chia
	phepChiaPhanSo(phanSo1, phanSo2);

	printf("\n");
	thoatChuongTrinh();	
}


//Ham de chon chuc nang, dieu khien bang Menu
int menu(char luaChon[][50], int soDong, int chonMenu) {
	//Mang chua mau tung dong
	int color[soDong];
	//Bien chua chuc nang dang chon
	int tamThoi = chonMenu;
	
	int chon, i;
	
	//Gan mau cho cac dong cua Menu 
	for(i=1; i<soDong; i++) {
		color[i] = WHITE; // Gan mau trang cho cac dong khong duoc chon
	}
	color[tamThoi] = RED; // Gan mau vang cho dong dang duoc chon
	
	//Di chuyen len xuong Menu
	while (1) {
		system("cls"); //Xoa man hinh
		color[0] = GREEN; 
		//To mau tung dong trong Menu
		for(i=0; i<soDong;i++) {
			textColor(color[i]);
			printf("%s\n", luaChon[i]);
		}
		
		//Bat ki tu ban phim
		chon = getch(); 
		
		//Bat phim len, xuong, enter tu ban phim
		switch(chon) {
			case 72: { // Phim mui ten len (UP)
				if(tamThoi==1) tamThoi = soDong - 1;
				else tamThoi--;
				break;
			}
			case 80: { // Phim mui ten xuong (DOWN)		
				if(tamThoi == soDong-1) tamThoi = 1;
				else tamThoi++;
				break;
			}
			case 13: { // Phim Enter
				return tamThoi; //Tra ve dong duoc chon, thoat ham
				break;
			}
		}
		
		//Gan lai mau tung dong, sau khi an phim mui ten
		for(i=1; i<soDong; i++) {
			color[i] = WHITE;
		}
		color[tamThoi] = RED;
	}
	
}

int main() {
	char luaChon[][50] = {"**********Assignment**********\n","1. Kiem tra so nguyen","2. Tim uoc chung va boi chung nho nhat",
	"3. Tinh tien cho quan Karaoke","4. Tinh tien dien","5. Chuc nang doi tien",
	"6. Tinh lai suat vay ngan hang, vay tra gop","7. Vay tien mua xe","8. Sap xep thong tin sinh vien",
	"9. Game FPOLY-LOTT","10. Tinh toan phan so","11. Thoat"};
	
	//Khai bao danh sach SinhVien
	struct sinhVien danhSachSinhVien[100];
	int soLuongSinhVien=0;
	//Khoi tao gia tri cho danh sach
	dsSinhVien(danhSachSinhVien,&soLuongSinhVien);
	
	// Tinh so dong cua Menu
	int soDong = sizeof(luaChon)/sizeof(luaChon[0]); 
	
	//Bien luu dong dang duoc chon
	int chonMenu = 1;
	do {
		// Chon chuc nang
		chonMenu = menu(luaChon,soDong,chonMenu); 
		
		//Truy cap vao tung chuc nang
		switch(chonMenu) {
			case 1: {
				bai1();
				break;
			}
			case 2: {
				bai2();
				break;
			}
			case 3: {
				bai3();
				break;
			}
			case 4: {
				bai4();
				break;
			}
			case 5: {
				bai5();
				break;
			}
			case 6: {
				bai6();
				break;
			}
			case 7: {
				bai7();
				break;
			}
			case 8: {
				//Truyen vao danh sach sinh vien + so luong sinh vien trong danh sach
				bai8(danhSachSinhVien, &soLuongSinhVien);
				break;
			}
			case 9: {
				bai9();
				break;
			}
			case 10: {
				bai10();
				break;
			}
			case 11: {
				textColor(WHITE);
				printf("-----------------------\n");
					textColor(3);
					printf("Ket thuc chuong trinh\n");
					printf("Xin chao va hen gap lai!");
					textColor(WHITE);
				break;
			}
		}
	} while(chonMenu !=11); //Chon chuc nang 11, thoat chuong trinh
}
			
			
		