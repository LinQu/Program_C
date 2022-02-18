

typedef struct {
	int tgl, bulan, tahun, hour, min, sec;
} DateTime;

DateTime Now;

typedef struct {
		int ID;
		char Nama[50];
		char NoTelp[13];
		char alamat[150];
		char user[10];
		char pass[10];
		}MasterKWN;
				
typedef struct {
		int id;
		char kode[10];
		char namab[50];
		int hargab;
		}DataBensin;
		
typedef enum {
	false = 0,
	true = 1
} bool;

bool found;

typedef struct {int ID,IDkas;
				char kdtr[100];
				char jenis[100];
				char bensin[100];
				float liter;
				int status,Totbayar,sispem;
				int harga,dpel,mpel,ypel;
				}DaftarTransaksi;

	
void DateTimeNow(DateTime *TglOutput) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	TglOutput->tgl = tm.tm_mday;
	TglOutput->bulan = tm.tm_mon+1;
	TglOutput->tahun = tm.tm_year+1900;
	TglOutput->sec = tm.tm_sec;
	TglOutput->min = tm.tm_min;
	TglOutput->hour = tm.tm_hour;
}







