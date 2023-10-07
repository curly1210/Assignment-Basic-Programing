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

void soNguyenTo(int x) {
	int dem=0;
	if(x <= 1 ) {
		printf("%d khong phai la so nguyen to\n", x);
	} else  {
		for(int i=2; i<x; i++) {
			if(x%i==0) {
				dem++;
				break;
			}
		}
		
		if(dem==0 || x==2) {
			printf("%d la so nguyen to\n",x);
		} else {
			printf("%d khong phai la so nguyen to\n", x);
		}
	}
}

void soChinhPhuong(int x) {
	int soChinhPhuong=0;
	for(int i=0; i<=(x/2+1); i++) {
		if(i*i == x) {
			soChinhPhuong = 1;
			break;
		}
	}
	
	if(soChinhPhuong) {
		printf("%d la so chinh phuong", x);
	} else {
		printf("%d khong phai la so chinh phuong", x);
	}
}

void themDauPhay(int n) {

    if (n < 1000) {
        printf ("%d", n);
        return;
    }
    themDauPhay(n/1000);
    printf (",%03d", n%1000);
}

void inSo(float so) {
	int viTriCatSauDauPhay;
	char soGoc[20], truocDauPhay[20], sauDauPhay[4];

	sprintf(soGoc, "%.02f", so); // chuyen int sang char
	printf("\nchieu dai: %d\n", strlen(soGoc));
	
	//sao chep chuoi goc 
	for(int i=0; i<strlen(soGoc); i++) {
		truocDauPhay[i] = soGoc[i];
	}

	//tach chuoi sau dau phay
	viTriCatSauDauPhay = strlen(soGoc) - 3;
	strncpy(sauDauPhay, soGoc + viTriCatSauDauPhay, 3);

	//tach chuoi truoc dau phay
	strtok(truocDauPhay,".");
	
	themDauPhay(atoi(truocDauPhay)); //goi ham them dau phay cho so int, so truoc dau phay

	printf("%s VND\n\n", sauDauPhay); //them so sau dau phay
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
	} while( kiemTraKiTu !=2 || kiTu !='\n');
	
	printf("\n");
	textColor(YELLOW);
	if(x==(int)x) {
		printf("%0.f la so nguyen\n", x);
		soNguyenTo((int)x);
		soChinhPhuong((int)x);
	} else {
		printf("%.2f khong phai la so nguyen\n",x);
		printf("%.2f khong phai la so nguyen to\n",x);
		printf("%.2f khong phai la so chinh phuong\n",x);
	}
	
	printf("\n\n");
	thoatChuongTrinh();
}

int uocChungLonNhat(int a, int b) {
	int temp, UCLN;
	if(a>b) {
		temp = a;
		a = b;
		b = temp;
	}
	
	for(int i=a; i>=1; i--) {
		if(a%i==0 && b%i==0) {
			UCLN = i;
			break;
		}
	}
	
	return UCLN;
}

int boiChungNhoNhat(int a, int b, int UCLN) {
	return (a*b)/UCLN;
}

void bai2() {
	int a,b, temp, kiemTraKiTu, UCLN=1, BCNN=1;
	char kiTu;
	system("cls");
	textColor(RED);
	printf("Bai 2: Tim uoc chung va boi chung nho nhat\n\n");
	
	textColor(WHITE);
	do {
		printf("Nhap so a: ");
		kiemTraKiTu = scanf("%d%c", &a, &kiTu);
		fflush(stdin);
	} while(kiemTraKiTu !=2 || kiTu !='\n' || a<=0);
		
	do {
		printf("Nhap so b: ");
		kiemTraKiTu = scanf("%d%c", &b, &kiTu);
		fflush(stdin);
	} while(kiemTraKiTu !=2 || kiTu !='\n' || a<=0);
	
	
	UCLN = uocChungLonNhat(a,b);
	
	BCNN = boiChungNhoNhat(a,b,UCLN);
	
	printf("\nHai so %d va %d\n\n", a, b);
	
	printf("Uoc chung lon nhat la: %d\n", UCLN);
	printf("Boi chung nho nhat la: %d\n\n", BCNN);
	
	thoatChuongTrinh();
}

void bai3() {
	
	float gioBatDau, gioKetThuc, kiemTraKiTu, tienBaGioDau = 150000, tienGioThuTu = 105000;
	float tongGio = 0, tongTien=0, baGioDau = 3;
	char kiTu;
	system("cls");
	textColor(RED);
	printf("Bai 3: Tinh tien cho quan Karaoke\n\n");
	
	textColor(YELLOW);
	printf("Quan hoat dong trong khoang tu 12h -> 23h\n\n");
	
	textColor(WHITE);
	
	do {
		
		do {
			printf("Nhap gio bat dau: ");
			kiemTraKiTu = scanf("%f%c", &gioBatDau, &kiTu);
			fflush(stdin);
		} while(kiemTraKiTu !=2 || kiTu !='\n' || gioBatDau > 22 || gioBatDau < 12);
		
		do {
			printf("Nhap gio ket thuc: ");
			kiemTraKiTu = scanf("%f%c", &gioKetThuc, &kiTu);
			fflush(stdin);
		} while(kiemTraKiTu !=2 || kiTu !='\n' || gioKetThuc > 23 || gioKetThuc < 12);
		
	} while(gioBatDau >= gioKetThuc);
	
	textColor(YELLOW);
	printf("\nGio bat dau: %.02f\n", gioBatDau);
	printf("Gio ket thuc: %.02f\n", gioKetThuc);
	
	tongGio = gioKetThuc - gioBatDau;
	if(tongGio <= baGioDau) {
		tongTien = tongGio * tienBaGioDau;
	} else {
		tongTien = baGioDau * tienBaGioDau + (tongGio-baGioDau) * tienGioThuTu;
	}
	
	if(gioBatDau >=14 && gioBatDau <= 17) {
		tongTien = tongTien*0.9;
	}
	
	printf("Tong tien thanh toan: ");
//	printf("Tong tien thanh toan: %.2f", tongTien);

	inSo(tongTien);

	thoatChuongTrinh();
}

void bai4() {
	char kiTu;
	int kiemTraKiTu,tienMotSo,bac;
	float soDien, tienDien;
	
	system("cls");
	
	textColor(RED);
	printf("Bai 4: Tinh tien dien\n\n");
	textColor(WHITE);
	
	do {
		printf("Nhap vao so dien: ");
		kiemTraKiTu = scanf("%f%c", &soDien, &kiTu);
		fflush(stdin);
	}while( kiemTraKiTu !=2 || kiTu !='\n' || soDien < 0);
	
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
	
	tienDien = soDien * tienMotSo;
	
	textColor(YELLOW);
	printf("\nBan dang dung dien o bac: %d\n",bac);
	printf("Tien dien can phai dong la: ", tienDien);
	inSo(tienDien);
	
	thoatChuongTrinh();
}

void bai5() {
	system("cls");
	textColor(RED);
	printf("Bai 5: Chuc nang doi tien\n\n");
	
	int tongTien, kiemTraKiTu;
	int soDu;
	char kiTu;
	
	textColor(WHITE);
	do {
		printf("Nhap so tien can doi: ");
		kiemTraKiTu = scanf("%d%c", &tongTien, &kiTu);
		fflush(stdin);
	} while(kiemTraKiTu !=2 || kiTu !='\n' || tongTien <= 0);
	
	soDu = tongTien;
	printf("\n");
	textColor(YELLOW);
	while(soDu!=0) {
		if(soDu >= 500 && tongTien != 500) {
			printf("%d to 500\n", soDu/500);
			soDu = soDu%500;
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

const int kyHanThang = 12;
const int laiMotThang = 5;

void bai6() {
	system("cls");
	textColor(RED);
	printf("Bai 6: Tinh lai suat vay ngan hang, vay tra gop\n\n");
	textColor(WHITE);
	
	char kiTu;
	double tienVay, tienConLai, tienLaiHangThang = 0, tongTienLai=0, gocPhaiTra=0, gocVaLai=0;
	int kiemTraKiTu; 
	
	do {
		printf("Nhap vao so tien muon vay: ");
		kiemTraKiTu = scanf("%lf%c", &tienVay, &kiTu);
		fflush(stdin);
	}while( kiemTraKiTu !=2 || kiTu !='\n' || tienVay <= 0);
	
	textColor(YELLOW);
	printf("\nSo tien muon vay: %.02lf VND", tienVay);
	printf("\nLai thang: %d %%/thang\n", laiMotThang);
	printf("Ky han: %d thang\n", kyHanThang);
	
	gocPhaiTra = tienVay/kyHanThang;
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
	for(int i=1; i<= kyHanThang; i++) {
		tienLaiHangThang = tienConLai*laiMotThang*0.01;
		tongTienLai += tienLaiHangThang;
		gocVaLai = gocPhaiTra + tienLaiHangThang;
		tienConLai -= gocPhaiTra;
		printf("%-10d %-20.02lf %-20.02lf %-20.02lf %-20.02lf",
		i, tienLaiHangThang, gocPhaiTra, gocVaLai, fabs(tienConLai));
		printf("\n");
	}
	
	for(int i=0; i<90; i++) {
		printf("-");
	}
	
	textColor(YELLOW);
	printf("\n\nTong tien lai phai tra: %.02lf VND", tongTienLai);
	printf("\nTong tien goc va lai phai tra: %.02lf VND", tongTienLai + tienVay);

	printf("\n\n");
	thoatChuongTrinh();	
}

const double tienVayMuaOto = 500000000;
const int thoiHanVay = 24;
const double laiSuatNam = 7.2;

void bai7() {
	system("cls");
	textColor(RED);
	printf("Bai 7: Vay tien mua xe\n\n");
	textColor(WHITE);
	
	float phanTramVay;
	int kiemTraKiTu;
	char kiTu;
	
	do {
		printf("Nhap vao phan tram vay: ");
		kiemTraKiTu = scanf("%f%c", &phanTramVay, &kiTu);
		fflush(stdin);
	}while( kiemTraKiTu !=2 || kiTu !='\n' || phanTramVay <= 0 || phanTramVay > 100);
	
	double tienTraLanDau = tienVayMuaOto*(100-phanTramVay)*0.01;
	double tienTraGop=0, tienLaiHangThang= 0, tienLaiTong=0, gocVaLai = 0, gocPhaiTra=0;
	tienTraGop = tienVayMuaOto*phanTramVay*0.01;
	gocPhaiTra =  tienTraGop/thoiHanVay;
	
	textColor(YELLOW);
	printf("\nTong tien vay: %.02lf VND", tienVayMuaOto);
	printf("\nPhan tram vay: %.02lf %%", phanTramVay);
	printf("\nTien phai tra lan dau: %.02lf VND", tienTraLanDau);
	printf("\nTien tra gop: %.2lf VND", tienTraGop);
	printf("\nLai suat: %.2f %%/nam", laiSuatNam);
	printf("\nKi han: %d nam", thoiHanVay);
	
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
	for(int i=1; i<= thoiHanVay; i++) {
		tienLaiHangThang = tienTraGop*laiSuatNam*0.01;
		tienLaiTong += tienLaiHangThang;
		gocVaLai = gocPhaiTra + tienLaiHangThang;
		tienTraGop -= gocPhaiTra;
		printf("%-10d %-20.02lf %-20.02lf %-20.02lf %-20.02lf",
		i, tienLaiHangThang, gocPhaiTra, gocVaLai, fabs(tienTraGop));
		printf("\n");
	}
	
	for(int i=0; i<90; i++) {
		printf("-");
	}
	
	textColor(YELLOW);
	printf("\n\nTong tien lai phai tra la: %.02lf VND", tienLaiTong);
	printf("\nTong tien goc va lai phai tra la: %.02lf VND", tienLaiTong + tienVayMuaOto*phanTramVay*0.01 );
		
	printf("\n\n");
	thoatChuongTrinh();	
}

struct sinhVien {
	char hoTen[30];
	float diem;
	char hocLuc[15];
};

int dsSinhVien(struct sinhVien dssv[], int *soLuong) {
	strcpy(dssv[0].hoTen, "Pham Xuan Cuong");
	dssv[0].diem = 9;
	strcpy(dssv[0].hocLuc,"Xuat Sac");
	
	strcpy(dssv[1].hoTen, "Ha Kim Oanh");
	dssv[1].diem = 10;
	strcpy(dssv[1].hocLuc,"Xuat sac");
	
	*soLuong = 2;
	
}

int themSinhVien(struct sinhVien dssv[], int *soLuongCu) {
	
	int kiemTraKiTu, soLuongMuonThem;
//	int soLuongCu;
	char kiTu;
	
//	soLuongCu = *soLuong;
	do {
		printf("Nhap so luong sinh vien muon them: ");
		kiemTraKiTu = scanf("%d%c", &soLuongMuonThem, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n' || soLuongMuonThem<0);
	
	printf("\n");
	if(soLuongMuonThem==0) return *soLuongCu;
	
	int dem=1;
	float diem;

	for(int i = *soLuongCu; i < *soLuongCu + soLuongMuonThem; i++ ) {
		printf("Nhap ho ten sinh vien thu %d: ", dem);
		fflush(stdin);
		gets(dssv[i].hoTen);
//		fflush(stdin);
		do {
			printf("Nhap diem sinh vien thu %d: ",dem);
			kiemTraKiTu = scanf("%f%c", &dssv[i].diem, &kiTu);
			fflush(stdin);
		} while( kiemTraKiTu !=2 || kiTu !='\n' || dssv[i].diem<0 || dssv[i].diem >10);
		
		diem = dssv[i].diem;
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
	
	return *soLuongCu + soLuongMuonThem;
}

void sapXepDiemGiamDan(struct sinhVien dssv[], int soLuong) {
	struct sinhVien sv;
	for(int i=0; i<soLuong; i++) {	
		for(int j=0; j<soLuong-i-1; j++) {
			if(dssv[j].diem < dssv[j+1].diem) {
				sv = dssv[j];
				dssv[j] = dssv[j+1];
				dssv[j+1] = sv;
			}
		}
	}
}

void inDSSV(struct sinhVien dssv[], int soLuong) {
	textColor(YELLOW);
	if(soLuong ==0) {
		printf("Danh sach rong\n");
	} else {
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
	soLuongMoi = themSinhVien(dssv,soLuongSinhVien);
	*soLuongSinhVien = soLuongMoi; 

//	printf("\n");
	inDSSV(dssv, *soLuongSinhVien);

	printf("\n");
	thoatChuongTrinh();	
}

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
	
	printf("\n\n");
	do {
		printf("Nhap so thu nhat: ");
		kiemTraKiTu = scanf("%d%c", &so1, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n' || so1 <1 || so1 > 15);
	
	do {
		printf("Nhap so thu hai: ");
		kiemTraKiTu = scanf("%d%c", &so2, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n' || so2 <1 || so2 > 15);
	
	textColor(YELLOW);
	printf("\nHai so ban chon la: %d va %d", so1,so2);
	
	int soNgauNhien1, soNgauNhien2;
	srand(time(0)); //tao so hat giong moi sau moi lan chay (truyen vao so giay)
//	soNgauNhien1 = 9;
//	soNgauNhien2 = 2;
	soNgauNhien1 = taoSoNgauNhien(1,15);
	soNgauNhien2 = taoSoNgauNhien(1,15);
	
	printf("\nHai so may man la: %d va %d", soNgauNhien1, soNgauNhien2);
	printf("\n\n");
	if( (so1==soNgauNhien1 && so2==soNgauNhien2) || (so1==soNgauNhien2 && so2==soNgauNhien1)) {
		printf("Chuc mung ban da trung giai nhat !");
	} else if(so1==soNgauNhien1 || so1==soNgauNhien2 || so2==soNgauNhien1 || so2==soNgauNhien2) {
		printf("Chuc mung ban da trung giai nhi !");
	} else {
		printf("Chuc ban may man lan sau !");
	}
	
	printf("\n\n");
	thoatChuongTrinh();	
}

struct phanSo {
	int tuSo;
	int mauSo;
};

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

struct phanSo nhapPhanSo() {
	int kiemTraKiTu, tuSo, mauSo;
	char kiTu;
	struct phanSo ps;
	
	do {
		printf("Nhap tu so: ");
		kiemTraKiTu = scanf("%d%c", &tuSo, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n');
	
	do {
		printf("Nhap mau so: ");
		kiemTraKiTu = scanf("%d%c", &mauSo, &kiTu);
		fflush(stdin);
	} while( kiemTraKiTu !=2 || kiTu !='\n' || mauSo==0);
	
	ps.tuSo = tuSo;
	ps.mauSo = mauSo;
	
	ps = quyUocPhanSo(ps);
	
	return ps;
}



struct phanSo rutGonPhanSo(struct phanSo ps) {
	int UCLN;
	UCLN = uocChungLonNhat( abs(ps.tuSo), abs(ps.mauSo));
	
	ps.tuSo /= UCLN;
	ps.mauSo /= UCLN;
	
	return ps;
}

void phepNhanPhanSo(struct phanSo ps1, struct phanSo ps2) {
	struct phanSo tich;
	tich.tuSo = ps1.tuSo * ps2.tuSo;
	tich.mauSo = ps1.mauSo * ps2.mauSo;
	
	tich = rutGonPhanSo(tich);
	tich = quyUocPhanSo(tich);
	
	if(tich.mauSo == 1) {
		printf("Phep nhan: %d/%d * %d/%d = %d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, tich.tuSo );
	} else {
		printf("Phep nhan: %d/%d * %d/%d = %d/%d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, tich.tuSo, tich.mauSo );
	}
	printf("\n");
}

void phepChiaPhanSo(struct phanSo ps1, struct phanSo ps2) {
	struct phanSo thuong;
	thuong.tuSo = ps1.tuSo * ps2.mauSo;
	thuong.mauSo = ps1.mauSo * ps2.tuSo;
	
	thuong = rutGonPhanSo(thuong);
	thuong = quyUocPhanSo(thuong);
	
	if(thuong.mauSo == 1) {
		printf("Phep chia: %d/%d / %d/%d = %d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, thuong.tuSo );
	} else {
		printf("Phep chia: %d/%d / %d/%d = %d/%d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, thuong.tuSo, thuong.mauSo );
	}
	
	printf("\n");
}

int timMauSoChung(struct phanSo ps1, struct phanSo ps2) {
	int UCLN, mauSoChung;
	UCLN = uocChungLonNhat(ps1.mauSo, ps2.mauSo);
	mauSoChung = boiChungNhoNhat(ps1.mauSo, ps2.mauSo, UCLN);
	
	return mauSoChung;
}

void phepCongPhanSo(struct phanSo ps1, struct phanSo ps2) {
	struct phanSo tong;
	int mauSoChung;
	
	mauSoChung = timMauSoChung(ps1,ps2); //tim mau so chung
	
	tong.tuSo =  (mauSoChung/ps1.mauSo)*ps1.tuSo + (mauSoChung/ps2.mauSo)*ps2.tuSo ; //Quy dong, cong tu so
	tong.mauSo = mauSoChung;
	
	tong = rutGonPhanSo(tong);
	tong = quyUocPhanSo(tong);
	
	if(tong.mauSo == 1) {
		printf("Phep cong: %d/%d + %d/%d = %d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, tong.tuSo );
	} else {
		printf("Phep cong: %d/%d + %d/%d = %d/%d", 
		ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo, tong.tuSo, tong.mauSo );
	}
	
	printf("\n");
}

void phepTruPhanSo(struct phanSo ps1, struct phanSo ps2) {
	struct phanSo hieu;
	int mauSoChung;
	
	mauSoChung = timMauSoChung(ps1,ps2); //tim mau so chung
	
	hieu.tuSo =  (mauSoChung/ps1.mauSo)*ps1.tuSo - (mauSoChung/ps2.mauSo)*ps2.tuSo ; //Quy dong, tru tu so
	hieu.mauSo = mauSoChung;
	
	hieu = rutGonPhanSo(hieu);
	hieu = quyUocPhanSo(hieu);
	
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
	
	//Tich 
	phepCongPhanSo(phanSo1, phanSo2);
	phepTruPhanSo(phanSo1, phanSo2);
	phepNhanPhanSo(phanSo1, phanSo2);
	phepChiaPhanSo(phanSo1, phanSo2);

	printf("\n");
	thoatChuongTrinh();	
}


//Ham de chon chuc nang, dieu khien bang Menu
int menu(char luaChon[][50], int soDong, int chonMenu) {
	int color[soDong];
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
	
	struct sinhVien danhSachSinhVien[100];
	int soLuongSinhVien=0;
	dsSinhVien(danhSachSinhVien,&soLuongSinhVien);
	
	int soDong = sizeof(luaChon)/sizeof(luaChon[0]); // Tinh so dong cua Menu

	int chonMenu = 1;
	do {
		chonMenu = menu(luaChon,soDong,chonMenu); // Chon chuc nang
		
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
				bai8(danhSachSinhVien, &soLuongSinhVien);
				printf("\nsoLuongSinhVien: %d", soLuongSinhVien);
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
	} while(chonMenu !=11); //
}
			
			
		