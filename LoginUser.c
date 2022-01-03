/*PROGRAM Login*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8


struct user{
	char username[50];
	char password[50];
}user;

FILE *ArsUser;


void gotoxy(int x, int y){
                COORD coord;
                coord.X = x;
                coord.Y = y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void takeinput(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch) - 1] = 0;
}

void takepassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		} else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
			}else{
				pwd[i++] = ch;
				printf("* \b");
		}
	}
	
}

void userdaftar(){
	
	ArsUser = fopen("UserData.dat","ab+");
	printf("\nNew Username	: ");	takeinput(user.username);	
	printf("New Password	: ");	takepassword(user.password);
	fwrite(&user,sizeof(struct user),1,ArsUser);
	fclose(ArsUser);
}

void tampilakun(){
	ArsUser = fopen("UserData.dat","rb");
	while(fread(&user, sizeof(struct user),1, ArsUser)){
	printf("\nNew Username	: %s",user.username);	
	printf("\nNew Password	: %s",user.password);
}
fclose(ArsUser);
}
void userlogin(){
	char username[50];
	char pword[50];
	int UserFound = 0;
	
	struct user usr;
	printf("Username	: ");	takeinput(username);
	printf("Password	: ");	takepassword(pword);
	
	ArsUser = fopen("UserData.dat","rb+");
	while(fread(&usr, sizeof(struct user),1, ArsUser)){
		if(!strcmp(usr.username,username)){
			if(!strcmp(usr.password,pword)){
				system("cls");
				printf("\nLogin Berhasil");
			}else {
				
				printf("\nInvalid Password");
			}
			UserFound = 1;
		}
	}
	if(!UserFound){
		printf("\nAccount Tidak Terdaftar");
		
	}
	fclose(ArsUser);
}

void fullscreen()
{
	keybd_event(VK_MENU,0x36,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

int main(){
	
	fullscreen();
	system("color 0b");
	int ch;
	do{
	
	gotoxy(70,12);printf("1.SIGN UP\n");
	gotoxy(70,13);printf("2.LOGIN\n");
	gotoxy(70,14);printf("0.EXIT\n\n");
	
	gotoxy(70,16);printf("Pilih salah satu : ");	scanf("%d",&ch);	fflush(stdin);
	system("cls");
	switch(ch){
		case 1:
			userdaftar();
		break;
		case 2:
			userlogin();
		break;
		case 3:
			tampilakun();
		break;
		
	}	
}while(ch!=0);
	return 0;
}


