
#include <stdio.h>
#include <windows.h>
#include <time.h>

void fullscreeen();
void gotoxy(int x,int y);
void SetColorBlock(unsigned short color);
void textBox1(int x, int y, int width, int height);

int x,y,i;


void loading(int x, int y) {
	int i;
	
	gotoxy(x + 12, y-1);
	printf("LOADING");
	textBox1(x, y,30,2);
	for(i = 1; i <= 30; i++) {
		gotoxy(x + i, y + 1);
		printf("%c", 177);
		Sleep(50);
		if(i == 8 || i == 28) {
			Sleep(200);
		} else if(i == 20) {
			Sleep(400);
		}
		
	}
}

void textBox1(int x, int y, int width, int height) {
	int i, j;
	
	/* first Line */
	gotoxy(x, y);
	printf("%c", 218);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 191);
	
	/* looping for height */
	for(i = 1; i <= height; i++) {
		gotoxy(x, y + i);
		printf("%c", 179);
		
		gotoxy(x + width + 1, y + i);
		printf("%c", 179);
	}
	
	/* last line */
	printf("\n");
	gotoxy(x, y + height);
	printf("%c", 192);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 217);
}

void BoxBlock(int x, int y, int width, int height, int color) {
	int i, j;
	
	/* first Line */
	SetColorBlock(color);
	for(i = 0; i <= height; i++) {
		for(j = 0; j < width; j++) {
			gotoxy(x + j, y + i);
			printf("%c", 219);
		}
	}
}

void SetColorBlock(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}


void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void chooseBox(int x, int y, int width, int height) { //[]
	int i, j;
	
	/* first Line */
	gotoxy(x, y);
	printf("%c", 201);
	for(i = 1; i <= width; i++) {
		printf("%c", 205);
	}
	printf("%c", 187);
	
	/* last line */
	printf("\n");
	gotoxy(x, y + height);
	printf("%c", 200);
	for(i = 1; i <= width; i++) {
		printf("%c", 205);
	}
	printf("%c", 188);
}

void underline(int x, int y, char text[255]) {
	int i;
	
	gotoxy(x, y);
	printf("%s", text);
	for(i = 0; i < strlen(text); i++) {
		gotoxy(x+i, y+1);
		printf("%c", 196);
	}
}

void DrawFile(int x, int y, char filename[255]) {
	FILE *fp;
    char str[MAXCHAR];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s", filename);
    }
    i = 0;
    while (fgets(str, MAXCHAR, fp) != NULL) {
    	gotoxy(x, y + i);
        printf("%s", str);
        i++;
	}
    fclose(fp);
}

void Frame(int x, int y){
	
	int menu, i, j;
	
	system("cls");
	SetColorBlock(143); //Black Low White
	DrawFile(x+13, y-2, "ui\\titel.txt");
	
	//DrawFile(x - 29, y + 1, "text\\user.txt");
	//-------------------garis header
	
	//tutup atas bawah
	Hline(5,166,0,219);
	Hline(5,166,44,219);
	//tutup atas bawah end
	
	//bawah judul
	Hline(5,166,9,219);
	//bawah judul end
	
	//bawah selamat datang "Role"
	Hline(5,40,13,219);
	//bawah selamat datang "Role" end
	
	//tutup judul
	Vline(0,9,49,219);
	
	Vline(10,44,40,219);
	Vline(0,9,124,219);
	//tutup judul end
	
	//tutup samping
	Vline(0,44,5,219);
	Vline(0,44,166,219);
	//tutup samping end
	
	//waktu
	DateTime dateNow;

	DateTimeNow(&dateNow);
	gotoxy(134,3); printf("Tanggal : %02d - %02d - %04d", dateNow.tgl, dateNow.bulan, dateNow.tahun);
	DateTimeNow(&dateNow);
	gotoxy(136,6); printf("Pukul : %02d : %02d WIB", dateNow.hour, dateNow.min);
	//waktu end
}
