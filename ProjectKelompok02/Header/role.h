#include "MasterKaryawan.h"
#include "MasterBensin.h"
#include "transaksi.h"
#include "laporan.h"

FILE *admin;

Admin(){
	system("cls");
	int menu;
	
	Frame(43,3);
	DrawFile(8, 1, "ui\\ADMIN.txt");
	gotoxy(13,11);printf("Selamat Datang Admin");
	gotoxy(13,16);printf("Menu Master :");
	gotoxy(13,18);printf("1. Master Karyawan"); 
	gotoxy(13,20);printf("2. Master Bensin"); 
	gotoxy(13,24);printf("3. Log Out");
	gotoxy(13,28);printf("Pilih Menu : ");
	chooseBox(26, 27, 3, 2);
	gotoxy(28,28);
	getnum(&menu,1);
	switch(menu){
		case 1: MenuKaryawan(); break;
		case 2: MenuBensin(); break;
		case 3: LoginPage(53, 4); break;
		default : MessageBox(NULL, "Masukkan hanya angka 1-4","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY); Admin();
	}while(menu!=4);
}

Pemilik()
{
	//DECLARATION
	int menu;
	
	//ALGORITHM
	Frame(43, 3);
	DrawFile(7, 1, "ui\\PEMILIK.txt");
	gotoxy(12,11);printf("Selamat Datang Pemilik");
	gotoxy(9,18);printf("1. Laporan Transaksi Bulanan");
	gotoxy(9,20);printf("2. Laporan Transaksi Tahunan");
	gotoxy(9,22);printf("3. Log Out");
	gotoxy(9,26);printf("Pilih Menu : "); 
	chooseBox(22, 25, 3, 2);
	gotoxy(24,26);
	IsiMenu:
	getnum(&menu,1);
	switch(menu)
	{
		case 1 : LaporanTransaksiBln(48, 2); break;
		case 2 : LaporanTransaksiThn(48, 2); break;
		case 3 : LoginPage(53, 4);
		default : MessageBox(NULL, "Masukkan hanya angka 1-3","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY); Pemilik();
	}while(menu!=3);
}

Kasir()
{
	//DECLARATION
	int menu;
	
	//ALGORITHM
	Frame(43, 3);
	DrawFile(8, 1, "ui\\KASIR.txt");
	gotoxy(13,11);printf("Selamat Datang %s",NMKasir); 
	gotoxy(10,16);printf("1. Buat Transaksi");
	gotoxy(10,18);printf("2. Lihat Riwayat Transaksi");
	gotoxy(10,20);printf("3. Log Out");
	gotoxy(10,24);printf("Pilih Menu : "); 
	chooseBox(23, 23, 3, 2);
	gotoxy(25,24);
	IsiMenu:
	getnum(&menu,1);
	switch(menu)
	{
		case 1 : BuatTransaksi(); break;
		case 2 : LaporanTransaksi(); break;
		case 3 : LoginPage(53, 4);  
		default : MessageBox(NULL, "Masukkan hanya angka 1-3","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY); Kasir();
	}while(menu!=3);
}