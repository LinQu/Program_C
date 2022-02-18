MasterKWN Karyawan;
FILE *DataKWN;

void LoginPage(int x, int y);
void TextLogin(int x);

void TextLogin(int x) {
	
	char username[50], pword[50];
	

	underline(80, 21, "Silahkan Login!!");

	gotoxy(73,25); fflush(stdin);printf("Username :");
	
	for(i=85;i<=99;i++)
	{
		gotoxy(i,26); fflush(stdin);printf("%c",205);
	}
	///username end
	
	///password start
	gotoxy(73,28); fflush(stdin);printf("Password :");
	
	for(i=85;i<=99;i++)
	{
		gotoxy(i,29); fflush(stdin);printf("%c",205);
	}
	//password end
	
	gotoxy(82, 38);printf("[0] Keluar");
	gotoxy(85,25);getteks(username,15);
	if(strcmp("0", username) == 0)
	{
    	gotoxy(10, 45); exit(0);
	}
	gotoxy(85,28);getpass(pword,15);
	DataKWN=fopen("karyawan.dat", "rb+");
	while (fread(&Karyawan,sizeof(Karyawan),1,DataKWN)==1)
			{	
				if((strcmp(username,Karyawan.user)==0) && (strcmp(pword,Karyawan.pass)==0))
				{
					MessageBox(NULL, "Selamat Datang Kasir!","Selamat Datang",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
					strcpy(IDKasir, Karyawan.user);
					strcpy(NMKasir, Karyawan.Nama);
//					runtuh(176);
					Kasir();
					break;
				}
			}
	if(strcmp(username,"admin")==0 && strcmp(pword,"admin")==0){
		MessageBox(NULL,"Selamat Datang Admin","Login Berhasil", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	Admin();
	}else if(strcmp(username,"pemilik")==0 && strcmp(pword,"pemilik")==0){
		MessageBox(NULL,"Selamat Datang pemilik","Login Berhasil", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	Pemilik();
	}
	else {
		MessageBox(NULL,"Username atau Password Salah!!","Login Gagal", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
		
		LoginPage(53,4);
	}
	
}

void LoginPage(int x, int y) {
	int menu;
	
	system("cls");
	system("color 8F");

	//SetColorBlock(7); //Black Low White
	BoxBlock(49, 1, 75, 14, 0);//blok judul
	//BoxBlock(51, 3, 70, 7,5);
	SetColorBlock(15);
	DrawFile(x+3, y-2, "ui\\titel.txt");
	DrawFile(x + 20, y-2 + 8, "ui\\logintitle.txt");

	SetColorBlock(143);
	textBox1(x+5, y + 14, 56, 16);
	TextLogin(75);
	BoxBlock(x+5, y+18, 1, 2, 15);
	BoxBlock(x+5, y+24, 1, 2, 15);
	

	
	
}
