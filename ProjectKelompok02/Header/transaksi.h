

DaftarTransaksi Transaksi;	// (peubah untuk menampung pembacaan data transaksi) 
FILE *ArsTransaksi;			// (arsip data transaksi)

void BuatTransaksi(){
    /* DECLARATION: */
	/* all names that are used locally declared here */
    time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int lastid=0,intkode,ces,harga;
	char Kode[25], transaksi[25],rp[25];
	char kodepkt[25];
	int baris = 14, kolom = 49;

    /* ALGORITHM: */
	/* all programs instruction are written here */
    TesTampil();
	ArsTransaksi = fopen("arsTransaksi.dat", "ab+");
    while(fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi)==1)
	{
		lastid=Transaksi.ID;
	}
    lastid++;
	sprintf(Kode, "%i", lastid);
	strcpy(transaksi, "TRS");
	strcpy(Kode, strcat(transaksi, Kode));
	textbox(6,baris-1,baris+1,kolom-2,100);

    gotoxy(kolom,baris);printf("Kode Transaksi\t: "); printf("%s",Kode);Transaksi.ID=lastid;strcpy(Transaksi.kdtr,Kode);fflush(stdin);// rekam ID
	gotoxy(kolom,baris+3);printf("Kode Bensin\t: BNS");
	gotoxy(kolom,baris+6);printf ("Jenis Bensin\t: ");
	gotoxy(kolom,baris+9);printf ("Harga\t\t: Rp ");
	gotoxy(kolom,baris+12);printf ("Nominal\t: Rp ");
	gotoxy(kolom,baris+15);printf ("Keluaran Liter :  ");
	
	

	do{
				
				if((DataBBM=fopen("arsbensin.dat","rb"))==NULL)
				{
					MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
					Kasir();
				}
				gotoxy(kolom+20,baris+3);getnum(&intkode,1); //masukan Bensin yang dipilih
				sprintf(Kode,"%i",intkode);					
				strcpy(kodepkt,"BNS");
				strcpy(Kode,strcat(kodepkt,Kode));
				strcpy(Transaksi.bensin, Kode);
				ces=0;
				found = false;	
				fread(&Bensin, sizeof(Bensin),1, DataBBM);			
				while((!found)&&(!feof(DataBBM)))
				{
					
					if (strcmp(Bensin.kode,Kode)==0)
					{
						found = true;
					}
				}				//found or EOF (ArsTransaksi)
				if(found==true)	//menampilkan Bensin yang dipilih
				{					 		
						gotoxy(kolom+17,baris+6);printf ("%s", Bensin.namab);
						rupiah(Bensin.hargab,rp);
						gotoxy(kolom+20,baris+9);printf ("%s",rp);
						strcpy(Transaksi.jenis,Bensin.namab);
						harga=Bensin.hargab;
						ces++;
						break;
					
				}
				if (ces==0) {
					
					MessageBox(NULL, "Bensin belum tersedia","Peringatan",MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
					Kasir();
				}
		}
		while(ces == 0);
		fclose(DataBBM);
		//------------------------------------------pembayaran start--------------------------------------------
	/* Declaration */
	int a=0,bayar,sis;
	int nominal1;
	float nominal;
	float liter;
	
	/* Algorithm */
	gotoxy(kolom+20,baris+12);getRp(&nominal1, 1, 20, 69, 26);
	nominal = nominal1;
	liter =  nominal / Bensin.hargab;
	gotoxy(kolom+17,baris+15);printf("%.2f",liter);printf(" Liter");

	Transaksi.liter = liter;
	Transaksi.harga = nominal;
//---------------------------------------Tanggalan Start-----------------------------------------
	/* Declaration */
	int dd,mm,yy;
	time_t rawtime;
	struct tm *info;
		
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
	
	int valid1=0,valid2=0;

	textbox(4,baris+17,baris+19,kolom-2,100);
	gotoxy(kolom,baris+18);printf("Tanggal Transaksi: %i - %i - %i",waktu.hari,waktu.bulan,waktu.tahun); // tanggal hari ini
	Transaksi.dpel=waktu.hari;
	Transaksi.mpel=waktu.bulan;
	Transaksi.ypel=waktu.tahun;
//------------------------------------------Tanggalan end-----------------------------------------------

	Transaksi.Totbayar = Transaksi.harga;
	rupiah(Transaksi.Totbayar, rp);
	gotoxy(kolom,baris+21);printf("Total Harga      : Rp %s", rp);
	
	Bayarr:
	gotoxy(kolom,baris+24);printf("Bayar            : Rp ");
	gotoxy(kolom,baris+27);printf("Kembalian	  : Rp ");
	gotoxy(kolom+22,baris+24); fflush(stdin); getRp(&bayar, 1, 10, kolom+22, baris+24);
	
	fflush(stdin);
			while(1)
			{
				fflush(stdin);
				if(bayar>=Transaksi.Totbayar){
					
					break;
				} else {
					MessageBox(NULL, "Uang Kurang!!","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
					goto Bayarr;
				}
				
			}
			Transaksi.sispem = Transaksi.Totbayar-bayar;
			if(Transaksi.sispem>0)
			{
				
				rupiah(Transaksi.sispem,rp);
				}else
				{
				Transaksi.sispem=Transaksi.sispem*(-1);
				rupiah(Transaksi.sispem,rp);
				Transaksi.sispem=0;	
				}
	gotoxy(kolom+22,baris+27);printf("%s", rp);	
//-------------------------------------------------pembayaran end---------------------------------------------------

//----------------------------------------------------kasir-----------------------------------------------------
	fwrite(&Transaksi, sizeof(Transaksi),1,ArsTransaksi);fflush(stdin);
	fclose(ArsTransaksi);	// tutup arsip
	MessageBox(NULL, "Transaksi berhasil","Berhasil",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	Kasir();
}

void LaporanTransaksi()
{
	/* DECLARATION */
	char harga[100];
	int count = 1;
	int baris = 14, kolom = 49;
	char rp[100];
	int IDkas;
	
	/* ALGORITHM */
	underline(kolom, baris-3, "DAFTAR TRANSAKSI");
	gotoxy(kolom, baris);printf("No.   Kode Transaksi  Bensin           Nominal         Keluaran Liter 	   Tanggal Transaksi");
	if((ArsTransaksi=fopen("arsTransaksi.dat","rb"))==NULL)
	{
		MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
	
	while(fread(&Transaksi, sizeof(Transaksi),1, ArsTransaksi)==1)
	{
		count++;
		baris++;
		//...........fill baris
		gotoxy(kolom, baris);
		if (Transaksi.ID<10);
		{
			printf(" ");
		}
		gotoxy(kolom, baris);
		printf("%i", Transaksi.ID);
		//menampilkan Nomor
		
		gotoxy(kolom+6, baris);
		printf("%s", Transaksi.kdtr);
		//menampilkan kode transaksi
		
		gotoxy(kolom+22, baris);
		printf("%s", Transaksi.jenis);
		//menampilkan nama bensin

		gotoxy(kolom+39, baris);
		rupiah(Transaksi.Totbayar, rp);
		printf("Rp %s", rp);
		//menampilkan total harga

		gotoxy(kolom+55, baris);
		printf("%.2f", Transaksi.liter); printf(" Liter");
		//menampilkan nama bensin

		gotoxy(kolom+74, baris);
		printf("%i - %i - %i ", Transaksi.dpel, Transaksi.mpel, Transaksi.ypel);
		//menampilkan tanggal
		

		
	}
	gotoxy(kolom, baris+2); printf("Tekan apa saja untuk kembali...");
	getch();
	Kasir();
	fclose(ArsTransaksi);
}
