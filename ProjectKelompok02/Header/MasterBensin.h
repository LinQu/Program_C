DataBensin Bensin;
FILE  *DataBBM;	//File Arsip Data Bensin
FILE  *temp;	//File Arsip untuk temporary	
void AddBensin(){
	int n,i;
	int lastid = 0;
    
	char Kode[5], code[25];
	/* ALGORITHM: */
    /* all program’s instructions are written here */
	DataBBM = fopen("arsbensin.dat", "ab+");
   
  while(!feof(DataBBM)){
		fread(&Bensin, sizeof (Bensin), 1, DataBBM);
		lastid=Bensin.id;
	}
		lastid++;
		sprintf(Kode,"%i",lastid);
		strcpy(code,"BNS");
		strcpy(Kode,strcat(code,Kode));
		textbox(3,13,15,47,100);

		gotoxy(49,14);printf("Kode Bensin\t: "); printf("%s",Kode);  Bensin.id = lastid; strcpy(Bensin.kode,Kode);fflush(stdin);// rekam ID 
		gotoxy(49,17);printf("Jenis Bensin \t: "); 	
		gotoxy(49,20);printf("Harga Bensin\t: Rp "); 

		
		gotoxy(66,17);getteks(Bensin.namab,100);// rekam nama bensin ke dalam Arsbensin
		gotoxy(69,20);getRp(&Bensin.hargab, 1, 20, 69, 20);  // rekam harga bensin ke dalam ArsBensin
		fwrite(&Bensin, sizeof(Bensin), 1, DataBBM);			
        MessageBox(NULL, "Data Bensin berhasil ditambahkan","Berhasil",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	

	fclose(DataBBM);
    MenuBensin();
}

void UpdateBensin(){
    	/* DECLARATION: */
	int CariID;			//variabel id yang ingin dicari
	char harga[100];	//variabel agar harga ada titik 3 digit
	int Pilihan;		//memilih apa yang ingin diubah
	bool found;
;
	
	/* ALGORITHM: */
	TesTampil();
	underline(49, 11, "UBAH DATA BENSIN");
	textbox(3,13,15,47,100);
	gotoxy(49,14);printf("Kode\t\t: BSN");
	gotoxy(49,17);printf("Nama Barang\t: ");
	gotoxy(49,20);printf("Harga\t\t: Rp ");
	gotoxy(69,14);getnum(&CariID, 3);	//Masukkan ID yang mau diupdate
	DataBBM = fopen("arsbensin.dat", "rb");	//buka arsip Bensin
	temp = fopen("temp.dat", "wb");	//buka arsip temp
	found = false;
	fread(&Bensin, sizeof(Bensin),1,DataBBM);
	while((!found) && (!feof(DataBBM))){
		if (Bensin.id == CariID){
			found = true;
			break;
		} else {
			fwrite(&Bensin, sizeof(Bensin),1,temp);
		}
		fread(&Bensin, sizeof(Bensin),1,DataBBM);
	}
	if(found == true){
		gotoxy(66,17);printf("%s", Bensin.namab);
		rupiah(Bensin.hargab, harga);	
		gotoxy(69,20);printf("%s", harga);
		gotoxy(49,26);printf("Data apa yang ingin diubah?");
		gotoxy(49,28);printf("1. Nama");
		gotoxy(64,28);printf("2. Harga");
		gotoxy(64,30);printf("3. Keluar");
		gotoxy(49,32);printf("Pilih : "); getnum(&Pilihan,1);	
		if(Pilihan == 1){
			gotoxy(49,34);printf("Nama Bensin : "); getteks(Bensin.namab,25);
			fwrite(&Bensin, sizeof(Bensin),1,temp);
			fread(&Bensin, sizeof(Bensin),1,DataBBM);
			while(!feof(DataBBM))	
			{
				fwrite(&Bensin, sizeof(Bensin),1,temp);
				fread(&Bensin, sizeof(Bensin),1,DataBBM);
			}
		} else if(Pilihan == 2){
			gotoxy(49,34);printf("Harga : Rp  "); gotoxy(60,34); fflush(stdin); getRp(&Bensin.hargab, 1, 20, 60, 34);
			fwrite(&Bensin, sizeof(Bensin),1,temp);
			fread(&Bensin, sizeof(Bensin),1,DataBBM);
			while(!feof(DataBBM))
			{
				fwrite(&Bensin, sizeof(Bensin),1,temp);
				fread(&Bensin, sizeof(Bensin),1,DataBBM);
			}
		
		} else if(Pilihan == 3){
			system("cls");MenuBensin();
		}
	} else {
		MessageBox(NULL, "Data yang anda cari tidak ada", "Peringatan", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
		MenuBensin();
	}
	fclose(DataBBM);
	fclose(temp);		
	
	temp = fopen("temp.dat", "rb");
	DataBBM = fopen("arsbensin.dat", "wb");	//buka arsip bensin
	
	fread(&Bensin, sizeof(Bensin),1,temp);
	while(!feof(temp)){
		fwrite(&Bensin, sizeof(Bensin),1,DataBBM);
		fread(&Bensin, sizeof(Bensin),1,temp);
	}
	
	fclose(DataBBM);
	fclose(temp);
	MessageBox(NULL, "Data berhasil diubah","Berhasil",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
}

void HapusBensin(){
	 	/* DECLARATION: */
	int CariID;			//variabel id yang ingin dicari
	char yakin[100];
	char harga[100];	//variabel agar harga ada titik 3 digit
	int Pilihan;		//memilih apa yang ingin diubah
	bool found;

	
	/* ALGORITHM: */
	TesTampil();
	underline(49, 11, "HAPUS DATA BENSIN");
	textbox(3,13,15,47,100);
	gotoxy(49,14);printf("Kode\t\t: BSN");
	gotoxy(49,17);printf("Nama Barang\t: ");
	gotoxy(49,20);printf("Harga\t\t: Rp ");
	gotoxy(69,14);getnum(&CariID, 3);	//Masukkan ID yang mau diupdate
	DataBBM = fopen("arsbensin.dat", "rb");	//buka arsip Bensin
	temp = fopen("temp.dat", "wb");	//buka arsip temp
	found = false;
	
	while((!found) && (!feof(DataBBM))){
		fread(&Bensin, sizeof(Bensin),1,DataBBM);
		if (Bensin.id == CariID){
			found = true;
			break;
		} else {
			fwrite(&Bensin, sizeof(Bensin),1,temp);
		}

	}
	if(found == true){
		gotoxy(66,17);printf("%s", Bensin.namab);
		rupiah(Bensin.hargab, harga);
		gotoxy(69,20);printf("%s", harga);

		fread(&Bensin, sizeof(Bensin),1,DataBBM);
		while(!feof(DataBBM))
			{
			fwrite(&Bensin, sizeof(Bensin),1,temp);
			fread(&Bensin, sizeof(Bensin),1,DataBBM);
			}
		
	} else {
		MessageBox(NULL, "Data yang anda cari tidak ada", "Peringatan", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
		MenuBensin();
	}
	fclose(DataBBM);
	fclose(temp);

	gotoxy(49,26);printf("Yakin ingin menghapus data (Y/N)? ");
	getteks(yakin, 100);
	
	if(strcmp("Y", yakin) == 0 || strcmp("y", yakin) == 0){
		temp = fopen("temp.dat", "rb");
		DataBBM = fopen("arsbensin.dat", "wb");
	
		fread(&Bensin, sizeof(Bensin),1,temp);
		while(!feof(temp))
		{
			fwrite(&Bensin, sizeof(Bensin),1,DataBBM);
			fread(&Bensin, sizeof(Bensin),1,temp);
		}
	
		fclose(DataBBM);
		fclose(temp);
		MessageBox(NULL, "Data berhasil dihapus","Berhasil",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuBensin();
	} else {
		MessageBox(NULL, "Data tidak jadi dihapus","Peringatan",MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
		MenuBensin();
	}
	
}

void TampilBensin(){
	char rp[50];
    int count = 1;
	int baris = 14, kolom = 49;
	
	underline(kolom, baris-2, "DAFTAR HARGA");
	gotoxy(kolom,baris);printf("Kode   Nama Bensin                  Harga/Liter    ");
	if((DataBBM=fopen("arsbensin.dat","rb"))==NULL)
	{
		MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuBensin();
	}
	while(fread(&Bensin, sizeof(Bensin),1, DataBBM)==1){
		count++;
		baris++;
		//.............fill baris;
		gotoxy(kolom, baris+1);
		printf("%s", Bensin.kode);
		//menampilkan kode bensin
		
		gotoxy(kolom+7, baris+1);
		
		printf("%s", Bensin.namab);
		//menampilkan nama bensin
		
		gotoxy(kolom+38, baris+1);
		rupiah(Bensin.hargab,rp);
		printf("Rp %s", rp);
		//menampilkan harga bensin
		
	}
	gotoxy(kolom, baris+3); printf("Tekan apa saja untuk kembali...");
	getch();
	MenuBensin();
	
	fclose(DataBBM);
}

void TesTampil(){
	char rp[100];
	int count = 1;
	int baris = 14, kolom = 49;
	underline(kolom+80, baris-2, "DAFTAR HARGA");	
	gotoxy(kolom+80,baris);printf("Kode   Nama Bensin     Harga/Liter");
	if((DataBBM=fopen("arsbensin.dat","rb"))==NULL)
	{
		MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuBensin();
	}
	while(fread(&Bensin, sizeof(Bensin),1, DataBBM)==1){
		count++;
		baris++;
		//.............fill baris;
		gotoxy(kolom+80, baris+1);
		printf("%s", Bensin.kode);
		//menampilkan kode bensin
		
		gotoxy(kolom+87, baris+1);
		printf("%s", Bensin.namab);
		//menampilkan nama bensin
		
		
		gotoxy(kolom+103, baris+1);
		rupiah(Bensin.hargab,rp);
		printf("Rp %s", rp);
		//menampilkan harga bensin
		
	}

	
	fclose(DataBBM);
	

}

MenuBensin(){
/* DECLARATION: */
    /* all names that are used locally declared here */
	int ch;
	//ListLogin();

	/* ALGORITHM: */
    /* all program’s instructions are written here */
		do{
            Frame(43,3);
			DrawFile(8, 1, "ui\\ADMIN.txt");
			gotoxy(13,11);printf("Selamat Datang Admin");
            gotoxy(13,16);printf("Master Karyawan");
			gotoxy(13,18);printf("1.Input Data Bensin");
			gotoxy(13,20);printf("2.Update Data Bensin");
			gotoxy(13,22);printf("3.Hapus Data Bensin");
			gotoxy(13,24);printf("4.Tampil Data Bensin");
			gotoxy(13,26);printf("0.Kembali");
			
			gotoxy(13,28);printf("Pilih Menu : ");
			chooseBox(26, 27, 3, 2);
			gotoxy(28,28);
            getnum(&ch,1);
			switch(ch){
				case 1:
					AddBensin();
				break;
				case 2:
					UpdateBensin();
				break;
				case 3:
					HapusBensin();
				break;
				case 4:
					TampilBensin();
					//TesTampil();
				break;
                case 0:
                    Admin();
			}
			
		}while(ch!=0);
			
			return 0;
			
	}
