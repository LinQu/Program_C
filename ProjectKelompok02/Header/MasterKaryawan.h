MasterKWN Karyawan;

FILE *DataKWN;  //FIle Arsip Untuk Master Karyawan
FILE *temp;     //FILE Arsip untuk temporary

void AddKaryawan(){
	int n,i;
	int lastid = 0;
	char Kode[5], code[25];
	/* ALGORITHM: */
    /* all program’s instructions are written here */
	DataKWN = fopen("karyawan.dat", "ab+");
   
  while(!feof(DataKWN)){
		fread(&Karyawan, sizeof (Karyawan), 1, DataKWN);
		lastid=Karyawan.ID;
	}
		lastid++;
		sprintf(Kode,"%i",lastid);
		strcpy(code,"KWN");
		strcpy(Kode,strcat(code,Kode));
		textbox(6,13,15,47,100);

		gotoxy(49,14);printf("ID Karyawan\t: "); printf("%i",lastid); Karyawan.ID=lastid;fflush(stdin);// rekam ID 
		gotoxy(49,17);printf("Nama Karyawan \t: "); 	
		gotoxy(49,20);printf("No Handphone\t: "); 
		gotoxy(49,23);printf("Alamat \t: "); 	
		gotoxy(49,26);printf("Username\t: "); 	
		gotoxy(49,29);printf("Password\t: "); 	
		
		gotoxy(66,17);getalpha(Karyawan.Nama,100);fflush(stdin);// rekam nama karyawan ke dalam ArsKaryawan
		gotoxy(66,20);getteksnummin(Karyawan.NoTelp, 12,13);  fflush(stdin);// rekam no telepon karyawan ke dalam ArsKaryawan
		gotoxy(66,23);getteks(Karyawan.alamat, 100); fflush(stdin);// rekam alamat karyawan ke dalam ArsKaryawan
		gotoxy(66,26);printf("%s",Kode); strcpy(Karyawan.user,Kode); fflush(stdin);// rekam username akun karyawan ke dalam ArsKaryawan
		gotoxy(66,29);getteks(Karyawan.pass, 100); fflush(stdin);// rekam password akun karyawan ke dalam ArsKaryawan
		fwrite(&Karyawan, sizeof(Karyawan), 1, DataKWN);
	

	fclose(DataKWN);
}

void UpdateKaryawan(){
	/* DECLARATION: */
	int CariID;			//variabel id yang ingin dicari
	int Pilihan;		//memilih apa yang ingin diubah
	bool found;
;
	
	/* ALGORITHM: */
	underline(49, 11, "UBAH DATA KARYAWAN");
	textbox(5,13,15,47,100);
	gotoxy(49,14);printf("ID\t\t: ");
	gotoxy(49,17);printf("Nama karyawan\t: ");
	gotoxy(49,20);printf("No Handphone\t: ");
	gotoxy(49,23);printf("Alamat karyawan: ");
	gotoxy(49,26);printf("Password\t: ");
	gotoxy(66,14);getnum(&CariID, 3);	//Masukkan ID yang mau diupdate
	DataKWN = fopen("karyawan.dat", "rb");	//buka arsip Karyawan
	temp = fopen("temp.dat", "wb");	//buka arsip temp
	found = false;
	fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
	while((!found) && (!feof(DataKWN))){
		if (Karyawan.ID == CariID){
			found = true;
			break;
		} else {
			fwrite(&Karyawan, sizeof(Karyawan),1,temp);
		}
		fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
	}
	if(found == true){
		gotoxy(66,17);printf("%s", Karyawan.Nama);
		gotoxy(66,20);printf("%s", Karyawan.NoTelp);
		gotoxy(66,23);printf("%s", Karyawan.alamat);
		gotoxy(66,26);printf("%s", Karyawan.pass);
		gotoxy(104,14);printf("Data apa yang ingin diubah?");
		gotoxy(104,16);printf("1. Nama");
		gotoxy(104,18);printf("2. No Handphone");
		gotoxy(120,16);printf("3. Alamat");
		gotoxy(120,18);printf("4. Password");
		gotoxy(113,20);printf("5. Keluar");
		gotoxy(104,22);printf("Pilih : "); getnum(&Pilihan,1);	
		if(Pilihan == 1){
			gotoxy(104,24);printf("Nama Karyawan : "); getteks(Karyawan.Nama,25);
			fwrite(&Karyawan, sizeof(Karyawan),1,temp);
			fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
			while(!feof(DataKWN))
			{
				fwrite(&Karyawan, sizeof(Karyawan),1,temp);
				fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
			}
		} else if(Pilihan == 2){
			gotoxy(104,24);printf("No Handphone :  "); gotoxy(115,24); getteksnummin(Karyawan.NoTelp, 12,13);  fflush(stdin);
			fwrite(&Karyawan, sizeof(Karyawan),1,temp);
			fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
			while(!feof(DataKWN))
			{
				fwrite(&Karyawan, sizeof(Karyawan),1,temp);
				fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
			}
		
		} else if(Pilihan == 3){
			gotoxy(104,24);printf("Alamat :  "); gotoxy(115,24); getteks(Karyawan.alamat, 100); fflush(stdin);
			fwrite(&Karyawan, sizeof(Karyawan),1,temp);
			fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
			while(!feof(DataKWN))
			{
				fwrite(&Karyawan, sizeof(Karyawan),1,temp);
				fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
			}
		}else if(Pilihan == 4){
			gotoxy(104,24);printf("Password :  "); gotoxy(115,24); getteks(Karyawan.pass, 100); fflush(stdin);
			fwrite(&Karyawan, sizeof(Karyawan),1,temp);
			fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
			while(!feof(DataKWN))
			{
				fwrite(&Karyawan, sizeof(Karyawan),1,temp);
				fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
			}
		}
		else if(Pilihan == 5){
			system("cls");MenuKaryawan();
		}
	} else {
		MessageBox(NULL, "Data yang anda cari tidak ada", "Peringatan", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
		MenuKaryawan();
	}
	fclose(DataKWN);
	fclose(temp);		
	
	temp = fopen("temp.dat", "rb");
	DataKWN = fopen("karyawan.dat", "wb");	//buka arsip Karyawan
	
	fread(&Karyawan, sizeof(Karyawan),1,temp);
	while(!feof(temp)){
		fwrite(&Karyawan, sizeof(Karyawan),1,DataKWN);
		fread(&Karyawan, sizeof(Karyawan),1,temp);
	}
	
	fclose(DataKWN);
	fclose(temp);
	MessageBox(NULL, "Data berhasil diubah","Berhasil",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
}
void TampilKaryawan(){
	int count = 1;
	int baris = 14, kolom = 49;
	gotoxy(kolom,baris-1);printf("Kode   Nama Karyawan                  No Handphone    Alamat                 Username   Password");
	if((DataKWN=fopen("karyawan.dat","rb"))==NULL)
	{
		MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuKaryawan();
	}
	while(fread(&Karyawan, sizeof(Karyawan),1, DataKWN)==1){
		count++;
		baris++;
		//.............fill baris;
		gotoxy(kolom, baris);
		printf("%i", Karyawan.ID);
		//menampilkan nomor
		
		gotoxy(kolom+7, baris);
		printf("%s", Karyawan.Nama);
		//menampilkan nama Karyawan
		
		gotoxy(kolom+38, baris);
		printf("%s", Karyawan.NoTelp);
		//menampilkan nomor telepon karyawan
		
		gotoxy(kolom+54, baris);
		printf("%s", Karyawan.alamat);
		//menampilkan alamat karyawan
		
		gotoxy(kolom+77, baris);
		printf("%s", Karyawan.user);
		//menampilkan username akun karyawan
		
		gotoxy(kolom+88, baris);
		printf("%s", Karyawan.pass);
		//menampilkan password akun karyawan
	}
	gotoxy(kolom, baris+2); printf("Tekan apa saja untuk kembali...");
	getch();
	MenuKaryawan();
	
	fclose(DataKWN);
}

void HapusKaryawan(){
	/* DECLARATION: */
	char yakin[100];
	int CariID;			//variabel id yang ingin dicari
	int Pilihan;		//memilih apa yang ingin diubah
	bool found;
;
	
	/* ALGORITHM: */
	underline(49, 11, "UBAH DATA KARYAWAN");
	textbox(5,13,15,47,100);
	gotoxy(49,14);printf("ID\t\t: ");
	gotoxy(49,17);printf("Nama karyawan\t: ");
	gotoxy(49,20);printf("No Handphone\t: ");
	gotoxy(49,23);printf("Alamat karyawan: ");
	gotoxy(49,26);printf("Password\t: ");
	gotoxy(66,14);getnum(&CariID, 3);	//Masukkan ID yang mau diupdate
	DataKWN = fopen("karyawan.dat", "rb");	//buka arsip Karyawan
	temp = fopen("temp.dat", "wb");	//buka arsip temp
	found = false;
	
	while((!found) && (!feof(DataKWN))){
		fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
		if (Karyawan.ID == CariID){
			found = true;
			break;
		} else {
			fwrite(&Karyawan, sizeof(Karyawan),1,temp);
		}

	}
	if(found == true){
		gotoxy(66,17);printf("%s", Karyawan.Nama);
		gotoxy(66,20);printf("%s", Karyawan.NoTelp);
		gotoxy(66,23);printf("%s", Karyawan.alamat);
		gotoxy(66,26);printf("%s", Karyawan.pass);

		fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
		while(!feof(DataKWN)){
		fwrite(&Karyawan, sizeof(Karyawan),1,temp);
		fread(&Karyawan, sizeof(Karyawan),1,DataKWN);
	}
	} else {
		MessageBox(NULL, "Data yang anda cari tidak ada", "Peringatan", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
		MenuKaryawan();
	}
	fclose(DataKWN);
	fclose(temp);		
	
	gotoxy(49,28);printf("Yakin ingin menghapus data (Y/N)? ");
	getteks(yakin, 100);
	
	if(strcmp("Y", yakin) == 0 || strcmp("y", yakin) == 0){
		temp = fopen("temp.dat", "rb");
		DataKWN = fopen("karyawan.dat", "wb");
	
		fread(&Karyawan, sizeof(Karyawan),1,temp);
		while(!feof(temp))
		{
			fwrite(&Karyawan, sizeof(Karyawan),1,DataKWN);
			fread(&Karyawan, sizeof(Karyawan),1,temp);
		}
	
		fclose(DataKWN);
		fclose(temp);
		MessageBox(NULL, "Data berhasil dihapus","Berhasil",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuKaryawan();
	} else {
		MessageBox(NULL, "Data tidak jadi dihapus","Peringatan",MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
		MenuKaryawan();
	}
}



MenuKaryawan(){
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
			gotoxy(13,18);printf("1.Input Data Karyawan");
			gotoxy(13,20);printf("2.Update Data Karyawan");
			gotoxy(13,22);printf("3.Hapus Data Karyawan");
			gotoxy(13,24);printf("4.Tampil Data Karyawan");
			gotoxy(13,26);printf("0.Kembali");
			gotoxy(13,28);printf("Pilih Menu : ");
			chooseBox(26, 27, 3, 2);
			gotoxy(28,28);
            getnum(&ch,1);
			switch(ch){
				case 1:
					AddKaryawan();
				break;
				case 2:
					UpdateKaryawan();
				break;
				case 3:
					HapusKaryawan();
				break;
				case 4:
					TampilKaryawan();
				break;
                case 0:
                    Admin();
			}
			
		}while(ch!=0);
			
			return 0;
			
	}
