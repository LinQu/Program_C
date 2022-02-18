FILE *TempRiwayat;

void RiwayatSort()
{
// Deklarasi //
	int TotalTransaksi;
	TotalTransaksi = 0;
	int j,i;
	char rp[25];

	int count=1, baris=14, kolom=49;
	
	//Algorithm	
	underline(kolom, baris+3, "DAFTAR TRANSAKSI");	
	gotoxy(kolom, baris+5);printf("No.   Kode Transaksi  Bensin           Nominal         Keluaran Liter 	   Tanggal Transaksi");	
	
	TempRiwayat = fopen("sortingriwayat.dat", "rb");
	fread(&Transaksi, sizeof(Transaksi), 1, TempRiwayat);
	while(!feof(ArsTransaksi))
	{
		count++;
		baris++;
		gotoxy(kolom, baris+5);
		printf("%i", Transaksi.ID);
		//menampilkan Nomor
		
		gotoxy(kolom+6, baris+5);
		printf("%s", Transaksi.kdtr);
		//menampilkan kode transaksi
		
		gotoxy(kolom+22, baris+5);
		printf("%s", Transaksi.jenis);
		//menampilkan nama bensin

		gotoxy(kolom+39, baris+5);
		rupiah(Transaksi.Totbayar, rp);
		printf("Rp %s", rp);
		//menampilkan total harga

		gotoxy(kolom+55, baris+5);
		printf("%.2f", Transaksi.liter); printf(" Liter");
		//menampilkan nama bensin

		gotoxy(kolom+74, baris+5);
		printf("%i - %i - %i ", Transaksi.dpel, Transaksi.mpel, Transaksi.ypel);
		//menampilkan tanggal

		

				TotalTransaksi = TotalTransaksi + Transaksi.Totbayar;
		fread(&Transaksi, sizeof(Transaksi), 1, TempRiwayat);
	}
	fclose(TempRiwayat);
	rupiah(TotalTransaksi, rp);
	gotoxy(kolom, baris+7);printf("Total Pendapatan :");
	gotoxy(kolom, baris+8);printf("Rp. %s", rp);
	gotoxy(kolom, baris+10);printf("Tekan apa saja untuk kembali...");
	getch();
	Pemilik();
}

void LaporanTransaksiBln()
{
	// Deklarasi //
	#define Nmaks 100
	int CekBulan;
	int CekTahun;
	int hari;
		int dd,mm,yy;
	time_t rawtime;
	struct tm *info;
	int baris = 14, kolom = 49;
		
	struct hasil
	{
	       int tahun;
	       int bulan;
	       int hari;
	       int jam;
	       int menit;
	       int detik;
	}waktu;
	time_t t1 = time(0);
	struct tm * now = localtime( & t1 );
	
	waktu.tahun=now->tm_year+1900;
	waktu.bulan=now->tm_mon+1;
	waktu.hari=now->tm_mday;
	waktu.jam=now->tm_hour;
	waktu.menit=now->tm_min;
	waktu.detik=now->tm_sec;


	
	// Algoritma //
	underline(kolom, baris-3, "LIHAT LAPORAN TRANSAKSI BULANAN");
	gotoxy(kolom, baris);printf("Masukkan Bulan : "); scanf("%d", &CekBulan);
	gotoxy(kolom+40, baris);printf("Masukkan Tahun : "); scanf("%d", &CekTahun);
	
	ArsTransaksi = fopen("arsTransaksi.dat", "rb");
	TempRiwayat = fopen("sortingriwayat.dat", "wb");
	
	fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi);
	hari = Transaksi.dpel - waktu.hari;
	while(!feof(ArsTransaksi))
	{
		if((CekBulan == Transaksi.mpel) && (CekTahun == Transaksi.ypel))
		{
			fwrite(&Transaksi, sizeof(Transaksi), 1, TempRiwayat);
		}
		fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi);
	}
	
	fclose(ArsTransaksi);
	fclose(TempRiwayat);
	RiwayatSort();
}

void LaporanTransaksiThn()
{
	// Deklarasi //
	#define Nmaks 100
	int CekBulan;
	int CekTahun;
	int hari;
		int dd,mm,yy;
	time_t rawtime;
	struct tm *info;
	int baris = 14, kolom = 49;
		
	struct hasil
	{
	       int tahun;
	       int bulan;
	       int hari;
	       int jam;
	       int menit;
	       int detik;
	}waktu;
	time_t t1 = time(0);
	struct tm * now = localtime( & t1 );
	
	waktu.tahun=now->tm_year+1900;
	waktu.bulan=now->tm_mon+1;
	waktu.hari=now->tm_mday;
	waktu.jam=now->tm_hour;
	waktu.menit=now->tm_min;
	waktu.detik=now->tm_sec;


	
	// Algoritma //
	underline(kolom, baris-3, "LIHAT LAPORAN TRANSAKSI TAHUNAN");
	gotoxy(kolom, baris);printf("Masukkan Tahun : "); scanf("%d", &CekTahun);
	
	ArsTransaksi = fopen("arsTransaksi.dat", "rb");
	TempRiwayat = fopen("sortingriwayat.dat", "wb");
	
	fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi);
	hari = Transaksi.dpel - waktu.hari;
	while(!feof(ArsTransaksi))
	{
		if(CekTahun == Transaksi.ypel)
		{
			fwrite(&Transaksi, sizeof(Transaksi), 1, TempRiwayat);
		}
		fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi);
	}
	
	fclose(ArsTransaksi);
	fclose(TempRiwayat);
	RiwayatSort();
}
