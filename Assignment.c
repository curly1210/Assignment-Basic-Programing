#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

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
	
	//sao chep chuoi goc 
	for(int i=0; i<strlen(soGoc); i++) {
		truocDauPhay[i] = soGoc[i];
	}

	//tach chuoi sau dau phay
	viTriCatSauDauPhay = strlen(soGoc) - 3;
	strncpy(sauDauPhay, soGoc + viTriCatSauDauPhay, 3);
//	printf("%s\n", sauDauPhay);
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
	} while(kiemTraKiTu !=2 || kiTu !='\n');
		
	do {
		printf("Nhap so b: ");
		kiemTraKiTu = scanf("%d%c", &b, &kiTu);
		fflush(stdin);
	} while(kiemTraKiTu !=2 || kiTu !='\n');
	
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
	
	BCNN = (a*b)/UCLN;
	
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

void bai6() {
	system("cls");
	textColor(RED);
	printf("Bai 6: Tinh lai suat vay ngan hang, vay tra gop\n\n");
	
	thoatChuongTrinh();	
}

void bai7() {
	system("cls");
	textColor(RED);
	printf("Bai 7: Vay tien mua xe\n\n");
	
	thoatChuongTrinh();	
}

void bai8() {
	system("cls");
	textColor(RED);
	printf("Bai 8: Sap xep thong tin sinh vien\n\n");
	
	thoatChuongTrinh();	
}

void bai9() {
	system("cls");
	textColor(RED);
	printf("Bai 9: Game FPOLY-LOTT\n\n");
	
	thoatChuongTrinh();	
}

void bai10() {
	system("cls");
	textColor(RED);
	printf("Bai 10: Tinh toan phan so\n\n");
	
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

//Bien toan cuc, chuc nang dang chon
int chonMenu = 1;

int main() {
	char luaChon[][50] = {"**********Assignment**********\n","1. Kiem tra so nguyen","2. Tim uoc chung va boi chung nho nhat",
	"3. Tinh tien cho quan Karaoke","4. Tinh tien dien","5. Chuc nang doi tien",
	"6. Tinh lai suat vay ngan hang, vay tra gop","7. Vay tien mua xe","8. Sap xep thong tin sinh vien",
	"9. Game FPOLY-LOTT","10. Tinh toan phan so","11. Thoat"};
	
	int soDong = sizeof(luaChon)/sizeof(luaChon[0]); // Tinh so dong cua Menu

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
				bai8();
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
			
			
		