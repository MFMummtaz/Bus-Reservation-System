#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h> 

#define BROWN_TEXT "\x1B[38;2;89;60;31m"

bool arr[2] = {true, false};
static bool condition;
int Harga[] = {50000, 45000, 44000, 26000, 32000};
int rutebus, hargatiket, banyaktiket, param; 
int keyPressed = 0;
int temp = 1;
int n, j, hitung, mode;
int bkEKS, bkBUS, bkEKO, skEKS, skBUS, skEKO, ykEKS, ykBUS, ykEKO, slkEKS, slkBUS, slkEKO, bakEKS, bakBUS, bakEKO;
char rute[20];

void menuPembatalan();
void printTiket();
void isidata();
void info();
void pembayaran();
void pemesanan();
void pembatalan();
void printStruk();
int kelas(int);

struct {
	char namapelanggan[100][30], notelp[100][30], nokepend[100][30];
	int harga [100];
} datapelanggan;

typedef struct {
	char desti[30], plat[30], keberangkatan[5];
	int kursiEKS, kursiBUS, kursiEKO, EKONOMI, BUSINESS, EKSEKUTIF;
} databus;

databus BANDUNG, SEMARANG, YOGYAKARTA, SOLO, BANTEN; 

int main () { //fungsi utama
	int num, i, b;
	char z;
	isidata();
	
	while (temp == 1){
		bkEKS  = BANDUNG.kursiEKS;
		bkBUS  = BANDUNG.kursiBUS;
		bkEKO  = BANDUNG.kursiEKO;
		skEKS  = SEMARANG.kursiEKS;
		skBUS  = SEMARANG.kursiBUS;
		skEKO  = SEMARANG.kursiEKO;
		ykEKS  = YOGYAKARTA.kursiEKS;
		ykBUS  = YOGYAKARTA.kursiBUS;
		ykEKO  = YOGYAKARTA.kursiEKO;
		slkEKS = SOLO.kursiEKS;
		slkBUS = SOLO.kursiBUS;
		slkEKO = SOLO.kursiEKO;
		bakEKS = BANTEN.kursiEKS;
		bakBUS = BANTEN.kursiBUS;
		bakEKO = BANTEN.kursiEKO;
		temp++;
	}

		while (1){
			while (1){
				system ("cls");
				system ("Color E3");
				
				printf("\n\n\n\n\n\n\n\n\n\n");
				printf (BROWN_TEXT"\t\t\t              \\        / ___ |  ___  ___         ___\n");                                                                                                                                  		    printf ("\t\t\t               \\  /\\  / |___|| /    /   \\ /\\/\\  |___|\n");                                                                                                                                       
			    printf ("\t\t\t                \\/  \\/  \\___ | \\___ \\___//    \\ \\___\n");
				    
			 	printf("\n\n\n\n\t\t\t\t\t    Tekan 1 untuk Memulai ==> ");
			 	scanf("%d", &b);
			 	
			   	if (b == 7 || b == 1){
					system ("cls");
					printf ("\t\t");
					printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading");
					printf ("\n\n\n\n\t\t\t\t      ");
				 	
					for(i = 0 ; i < 43 ; i++) {
						printf("=");
						Sleep(10);
					}
					Sleep(500);				   	
			   		break;
				}
				
				else {
			    	system ("cls");
			    	printf("\nn\n\n\n\n\n\n\n\n\t\t\t\t\t   !!! Input Tidak Dikenali !!!\n");
			    	getch();
				}
			}
			if (b == 7){
				break;
			}
				
		    do {	
				system ("cls");
			 	printf ("\t\t\t\t");
			 	
				for(i = 0 ; i < 49 ; i++) {
					printf("=");
				  	Sleep(5);
			 	} 
				 	
				printf (BROWN_TEXT"\n\t\t\t\t\t\tPemesanan Tiket Bus\t\t");
				printf ("\n\t\t\t\t\t\t   BENDER TRAVEL\t\t");
				printf ("\n\t\t\t\t\t      CABANG DEPOK (Jatijajar)\n");
				printf ("\t\t\t\t");
					
				for(i = 0 ; i < 49 ; i++) {
					printf("=");
					Sleep(5);
				}
					
				printf("\n\n");
				printf("\t\t\t\t\t[1] => Informasi Bus\n");
				Sleep(70);
			    printf("\n");
			    printf("\t\t\t\t\t[2] => Pemesanan Tiket\n");
			    Sleep(70);
			    printf("\n");
			    printf("\t\t\t\t\t[3] => Pembayaran Tiket\n");
			    Sleep(70);
			    printf("\n");
			    printf("\t\t\t\t\t[4] => Pembatalan Reservasi Bus\n");
			    Sleep(70);
			    printf("\n");
			    printf("\t\t\t\t\t[5] => Print Tiket\n");
			    Sleep(70);
			    printf("\n");
			    printf("\t\t\t\t\t[6] => Exit (Harap keluarkan program setelah pemakaian)\n\n");
			    Sleep(70);	    
			    printf("========================================================================================================================\n\n");
			    printf("\t\t\tMasukan Angka Pilihan Anda : ");
			    scanf("%d", &num);
				    
			    while (num > 6 || num < 1) {
			    	printf("\n\t\t\t\t\t   !!! Input Tidak Dikenali !!!\n");
				    printf("\n\t\t\tMasukan Pilihan Anda : ");
				    scanf("%d", &num);	    	
				}
						
			    switch(num) {
				    case 1:
						info();
						temp = 2;
						keyPressed = 0;
				        break;
				    case 2:
				        pemesanan();
				        condition = arr[0];
				        keyPressed = 0;
				        break;
				    case 3:
				        pembayaran();
				        condition = arr[1];
				        keyPressed = 0;
				        break;
				    case 4:
				        pembatalan();
				        keyPressed = 0;
				        break;
				    case 5:
				    	printStruk();
				    	keyPressed = 0;
				    	break;
			    }
					
			} while(num != 6);
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n       ----------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t\tTerimakasih Sudah Menggunakan Jasa Kami\n\n");
		    printf("\t\t\t\t\t\t     Selamat Jalan!\n");
		    printf("       ----------------------------------------------------------------------------------------------------------\n");
		    Sleep(3000);
			n++;					
		}		

		system("cls");
		printf("\n\t\tBerikut merupakan riwayat pemesanan sebelum mesin di reset : \n");
		for(i = 0; i < n; i++){
			printf("\n\n\t\t\tNama\t\t\t\t: %s\n", datapelanggan.namapelanggan[i]);
			printf("\t\t\tNomor Identitas\t\t\t: %s\n", datapelanggan.nokepend[i]);
			printf("\t\t\tNomor Telefon\t\t\t: %s\n", datapelanggan.notelp[i]);
			printf("\t\t\tNominal harga pemesanan\t\t: %d\n", datapelanggan.harga[i]);
			printf("\n");
		}
		
		getch();
		system("cls");
	    printf("\n\n\n\n\n\n\n\n\n\n       ----------------------------------------------------------------------------------------------------------\n");
	    printf("\t\t\t\t\tProgram ditutup\n\n");
	    printf("\t\t\t\t\t\tHave a nice day!\n");
	    printf("       ----------------------------------------------------------------------------------------------------------\n");
	    Sleep(1000);
	    return 0;
}

void isidata(){ //fungsi untuk mengisi data bus
	BANDUNG.EKSEKUTIF = 120000;
	BANDUNG.BUSINESS = 70000;
	BANDUNG.EKONOMI = 50000;
	BANDUNG.kursiEKS = 27;
	BANDUNG.kursiBUS = 27;
	BANDUNG.kursiEKO = 27;
	strcpy(BANDUNG.desti, "DEPOK - BANDUNG");
	strcpy(BANDUNG.plat, "B 1492 ECD");
	strcpy(BANDUNG.keberangkatan, "09.00");
	
	SEMARANG.EKSEKUTIF = 115000;
	SEMARANG.BUSINESS = 65000;
	SEMARANG.EKONOMI = 45000;
	SEMARANG.kursiEKS = 30;
	SEMARANG.kursiBUS = 30;
	SEMARANG.kursiEKO = 30;
	strcpy(SEMARANG.desti, "DEPOK - SEMARANG");
	strcpy(SEMARANG.plat, "B 1435 RFD");
	strcpy(SEMARANG.keberangkatan, "11.00");

	YOGYAKARTA.EKSEKUTIF = 114000;
	YOGYAKARTA.BUSINESS = 64000;
	YOGYAKARTA.EKONOMI = 44000;
	YOGYAKARTA.kursiEKS = 25;
	YOGYAKARTA.kursiBUS = 25;
	YOGYAKARTA.kursiEKO = 25;
	strcpy(YOGYAKARTA.desti, "DEPOK - YOGYAKARTA");
	strcpy(YOGYAKARTA.plat, "B 1234 EFR");
	strcpy(YOGYAKARTA.keberangkatan, "21.00");

	SOLO.EKSEKUTIF = 96000;
	SOLO.BUSINESS = 46000;
	SOLO.EKONOMI = 26000;
	SOLO.kursiEKS = 22;
	SOLO.kursiBUS = 22;
	SOLO.kursiEKO = 22;
	strcpy(SOLO.desti, "DEPOK - SOLO");
	strcpy(SOLO.plat, "B 1365 RED");
	strcpy(SOLO.keberangkatan, "01.00");

	BANTEN.EKSEKUTIF = 102000;
	BANTEN.BUSINESS = 52000;
	BANTEN.EKONOMI = 32000;
	BANTEN.kursiEKS = 34;
	BANTEN.kursiBUS = 34;
	BANTEN.kursiEKO = 34;
	strcpy(BANTEN.desti, "DEPOK - BANTEN");
	strcpy(BANTEN.plat, "B 1365 RED");
	strcpy(BANTEN.keberangkatan, "04.00");		
}

void info(){ //fungsi untuk menampilkan ketersediaan bus
	while (keyPressed != 13) {	
		system("cls");
		printf("\n\n\t\t\t\t|\t\tInformasi Ketersediaan Bus\t\t|\n\n\n");
		printf("------------------------------------------------------------------------------------------------------------------------");
		printf("\n\tNO PLAT\t\t    DESTINASI\t\tEKSEKUTIF (cap.)    BUSINESS (cap.)      EKONOMI(cap.)   KEBERANGKATAN");
		printf("\n------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n       %s\t%s\t\t  %d (%d)\t      %d (%d)\t  %d (%d)\t     %s\n", BANDUNG.plat, BANDUNG.desti, BANDUNG.EKSEKUTIF, bkEKS, BANDUNG.BUSINESS, bkBUS, BANDUNG.EKONOMI, bkEKO, BANDUNG.keberangkatan);
		printf("\n       %s\t%s\t  %d (%d)\t      %d (%d)\t  %d (%d)\t     %s\n", SEMARANG.plat, SEMARANG.desti, SEMARANG.EKSEKUTIF, skEKS, SEMARANG.BUSINESS, skBUS, SEMARANG.EKONOMI, skEKO, SEMARANG.keberangkatan);
		printf("\n       %s\t%s\t  %d (%d)\t      %d (%d)\t  %d (%d)\t     %s\n", YOGYAKARTA.plat, YOGYAKARTA.desti, YOGYAKARTA.EKSEKUTIF, ykEKS, YOGYAKARTA.BUSINESS, ykBUS, YOGYAKARTA.EKONOMI, ykEKO, YOGYAKARTA.keberangkatan);
		printf("\n       %s\t%s\t\t  %d (%d)\t      %d (%d)\t  %d (%d)\t     %s\n", SOLO.plat, SOLO.desti, SOLO.EKSEKUTIF, slkEKS, SOLO.BUSINESS, slkBUS, SOLO.EKONOMI, slkEKO, SOLO.keberangkatan);
		printf("\n       %s\t%s\t\t  %d (%d)\t      %d (%d)\t  %d (%d)\t     %s\n", BANTEN.plat, BANTEN.desti, BANTEN.EKSEKUTIF, bakEKS, BANTEN.BUSINESS, bakBUS, BANTEN.EKONOMI, bakEKO, BANTEN.keberangkatan);
		printf("\n\n\t\t\t\t\tTekan enter untuk kembali ke menu utama");
		keyPressed = getch();	 
	}	
}

void pemesanan(){ //fungsi untuk mengisi nama dan tujuan pemesanan bus
	system("cls");
	int pesanan, i;
	char temp;
	if (condition == false) {
		printf("\n\n\n\n\n\t\t\t\t\tMasukan nama anda : ");
		scanf("%c", &temp);
		scanf("%[^\n]s", datapelanggan.namapelanggan[n]);
		printf("\n\n\t\t\t\t\tMasukan no KTP / Passport anda : ");
		scanf("%s", datapelanggan.nokepend[n]);
		printf("\n\n\t\t\t\t\tMasukan nomor telepon anda : ");
		scanf("%s", datapelanggan.notelp[n]);		
		
		while (pesanan != 1){
			if (pesanan == 2 || pesanan == 3 || pesanan == 4 || pesanan == 5){
				break;
			}
			system("cls");	
			printf("\n\t\t\t\t    ===========================================");
			printf("\n\n\t\t\t\t\t\tMENU PEMESANAN BUS\n");
			printf("\n\t\t\t\t    ===========================================");
			
			printf("\n\n\t\t       (1) \t%s\t\t        \t\t     %s\t\t\n", BANDUNG.desti, BANDUNG.keberangkatan);
			printf("\n\t\t       (2) \t%s\t        \t\t     %s\t\t\n", SEMARANG.desti, SEMARANG.keberangkatan);
			printf("\n\t\t       (3) \t%s\t  \t      \t\t     %s\t\t\n", YOGYAKARTA.desti, YOGYAKARTA.keberangkatan);
			printf("\n\t\t       (4) \t%s\t\t  \t      \t\t     %s\t\t\n", SOLO.desti, SOLO.keberangkatan);
			printf("\n\t\t       (5) \t%s\t\t  \t      \t\t     %s\t\t\n", BANTEN.desti, BANTEN.keberangkatan);
			
			printf("\n\t\t\t\t    ===========================================");
			printf("\n\n\t\t\t\t\tPilih angka tujuan anda : ");
			scanf("%d", &pesanan);
		}
		
		switch(pesanan) {
  			case 1:
   				rutebus = 0;
  				hargatiket = kelas(rutebus);	
				strcpy(rute, BANDUNG.desti);			
   				break;
			case 2:
   				rutebus = 1;
  				hargatiket = kelas(rutebus);
  				strcpy(rute, SEMARANG.desti);
				break;
			case 3:
   				rutebus = 2;
   				strcpy(rute, YOGYAKARTA.desti);
  				hargatiket = kelas(rutebus);
   				break;
  			case 4:
   				rutebus = 3;
   				strcpy(rute, SOLO.desti);
  				hargatiket = kelas(rutebus);
	   			break;
			case 5:
   				rutebus = 4;
   				strcpy(rute, BANTEN.desti);
  				hargatiket = kelas(rutebus);
	   			break;
		}
		datapelanggan.harga[j] = hargatiket;
		j++;
	}
	else{
		printf("\n\n\t\t\t\t\tAnda sudah melakukan pemesanan tiket!");
		Sleep(1000);
  		printf("\n\t\t\t\tSilahkan melakukan pembayaran dan mencetak tiket anda terlebih dahulu\njika anda ingin memesan tiket lagi");
 		getch();
	}
	system ("cls");
	printf ("\t\t");
	printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading");
	printf ("\n\n\n\n\t\t\t\t      ");
 	
	for(i = 0 ; i < 43 ; i++) {
		printf("=");
		Sleep(10);
	} Sleep (500);
}
	
int kelas(int A){ //fungsi untuk meminta jumlah tiket dan kelas bus yang diinginkan
	param = A;
	int total, jenis1;
	int kelasBus[3] = {0, 20000, 50000};
	while (1){
	    system("cls");
		printf("\n\n\n\n\t\t\t\t       ===========================================");
		printf("\n\n\t\t\t\t\t   Jumlah tiket yang ingin dipesan : ");
		scanf("%d", &banyaktiket);
		if(banyaktiket > 0){	
			break;
		}
		else if(banyaktiket <= 0) {
			system("cls");
			printf("\n\n\t\tHanya masukan angka bernilai lebih dari nol!");
			getch();
		}
	}
	while (1){
		system("cls");
		printf("\n\n\n\n\t\t\t\t       ===========================================");	
		printf("\n\n\t\t\t\t\tPILIHAN KELAS BUS : \n");
		printf("\n\t\t\t\t\t1. Ekonomi\n");
		printf("\n\t\t\t\t\t2. Bisnis\n");
		printf("\n\t\t\t\t\t3. Eksekutif\n");
		printf("\n\t\t\t\t       ===========================================");
		printf("\n\n\t\t\t\t\tPilih Kelas Bus yang Diinginkan : ");
		scanf ("%d",&jenis1);
		if (jenis1 == 1 || jenis1 == 2 || jenis1 == 3){
			break;	
		}		
	}
	switch(jenis1) {
		case 1:
	    	jenis1 = kelasBus[0];
	    	mode = 1;
			if(param == 0){
			   	bkEKS = bkEKS - banyaktiket;
			}
			else if(param == 1){
			   	skEKS = skEKS - banyaktiket;
			}
			else if(param == 2){
			   	ykEKS = ykEKS - banyaktiket;
			}
			else if(param == 3){
			   	slkEKS = slkEKS - banyaktiket;
			}
			else if(param = 4){
			   	bakEKS = bakEKS - banyaktiket;
			}		    	
	    	break;
		case 2:
	    	jenis1 = kelasBus[1];
	    	mode = 2;
			if(param == 0){
				bkBUS = bkBUS - banyaktiket;
			}
			else if(param == 1){
				skBUS = skBUS - banyaktiket;
			}
			else if(param == 2){
				ykBUS = ykBUS - banyaktiket;
			}
			else if(param == 3){
	    		slkBUS = slkBUS - banyaktiket;
			}
			else if(param == 4){
	    		bakBUS = bakBUS - banyaktiket;
			}			    	    	
	    	break;
		case 3:
	    	jenis1 = kelasBus[2];
	    	mode = 3;
	    	if(param == 0){
				bkEKO = bkEKO - banyaktiket;
			}
			else if(param == 1){
				skEKO -= banyaktiket;
			}
			else if(param == 2){
	    		ykEKO = ykEKO - banyaktiket;
			}
			else if(param == 3){
	    		slkEKO = slkEKO - banyaktiket;
			}
			else if(param == 4){
	    		bakEKO = bakEKO - banyaktiket;
			}
	    	break;
	}
	total = (Harga[A] + jenis1)*banyaktiket;
	return total;
}

void pembayaran(){ //fungsi untuk melakukan pembayaran tiket yang sudah dipesan
	system("cls");
	int inputMetode, inputPIN, i;
	
	if(condition == true) {
		while (keyPressed != 13) {
			system ("cls");
			printf("\n\t\t\t\t       ===========================================");
			printf("\n\n\t\t\t\t\t\t   MENU PEMBAYARAN BUS\n");
			printf("\n\t\t\t\t       ===========================================");
		
			printf("\n\n\n\n\n\t\t\t\t\t Total Harga Tiket Anda \t: Rp.%d", hargatiket);
			printf("\n\t\t\t\t\t Jumlah Tiket Anda \t\t: %d", banyaktiket);
			printf("\n\t\t\t\t\t Atas nama \t\t\t: %s", datapelanggan.namapelanggan[n]);			
			printf("\n\t\t\t\t\t Tujuan \t\t\t: %s", rute);
		
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTekan Enter untuk Lanjutkan Pembayaran");
	    	keyPressed = getch();
		}   
		while (1){
			system("cls");
			printf("\n\t\t\t\t    ===========================================");
			printf("\n\n\t\t\t\t\t\tMENU PEMBAYARAN BUS\n");
			printf("\n\t\t\t\t    ===========================================");
			printf("\n\n\n\t\t\t\t\t\tPilih Metode Pembayaran!");
			printf("\n\n\n\t\t\t\t\t\t====> 1. Tunai");
			printf("\n\t\t\t\t\t\t====> 2. Non-Tunai");
			
			printf("\n\n\t\t\t\tMasukkan Metode Pembayaran Anda! ==>  ");
			scanf("%d", &inputMetode);	
			if (inputMetode == 1 || inputMetode == 2){
				break;
			}		
		}

		if(inputMetode == 1){
			printf("\n\n\n\t\t\t\t\tNilai Pembayaran Anda ==> Rp.%d ", hargatiket);
			printf("\n\n\n\t\t\t\t        Silahkan lanjutkan pembayaran anda");	
		} 
		
		else if(inputMetode == 2){
			printf("\n\t\t\tSilahkan transfer nominal pembayaran pada Virtual Account berikut ini");
			printf("\n\n\t\t\t\t\t\t\t |||");
			printf("\n\t\t\t\t\t\t\t |||");
			printf("\n\t\t\t\t\t\t\t |||");
			printf("\n\t\t\t\t\t\t       *******");
			printf("\n\t\t\t\t\t\t        *****");
			printf("\n\t\t\t\t\t\t         ***");
			printf("\n\t\t\t\t\t\t          *");
			printf("\n\n\t\t\t\t\t\t2987-3443-9898-0094");
			printf("\n\n\t\t\t\t\tNominal Pembayaran Anda! ==> Rp.%d ", hargatiket);			
		}
		
		getch();
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
		if(hitung == 0){
			printf("PIN Print Anda : 12345");
		} 
		else if(hitung == 1){
			printf("PIN Print Anda : 23456");
		} 
		else if(hitung == 2){
			printf("PIN Print Anda : 34567");
		} 				
		getch();
		system("cls");
		
		printf ("\t\t");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading");
		printf ("\n\n\n\n\t\t\t\t      ");
 	
		for(i = 0 ; i < 43 ; i++) {
			printf("=");
			Sleep(10);
		}
		Sleep(500);		
		
	} else {
		while (keyPressed != 13) {
			printf("\n\n\t\t\t     Lakukan Pemesanan Tiket pada Menu Pemesanan Tiket terlebih dahulu!");
			printf("\n\n\t\t\t\t        Tekan Enter untuk kembali ke Menu Awal");
			keyPressed = getch();
		}
	}	
}

void printStruk(){ //fungsi untuk mengkonfirmasi bahwa pelanggan sudah membayar
	char PINbanding[10];
	system("cls");
	printf("\n\n\n\n\t\t\t\tMasukan PIN Konfirmasi Pembayaran : ");
	scanf("%s", &PINbanding);
	if (hitung == 0){
		if (strcmp(PINbanding, "12345") == 0){
			while (keyPressed != 13) {
				system("cls");
				printf("\n\n\n\n\t\t\t\t    ===========================================");
				printf("\n\n\t\t\t\t\t   Pembayaran Sudah Terkonfirmasi!\n");
				printf("\n\t\t\t\t    ===========================================");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Klik Enter untuk Print Tiket");
				keyPressed = getch();
			}
			keyPressed = 0;
			while (keyPressed != 13) {
				system("cls");	
				printTiket();
				hitung++;
				keyPressed = getch();
			}	
		}
		else {
			while (keyPressed != 13) {
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t         PIN Salah!");
				printf("\n\n\t\t\t\t\t     Klik Enter untuk Kembalik ke Menu");
				keyPressed = getch();
			}			
		}
				
	}
	else if (hitung == 1){
		if (strcmp(PINbanding, "23456") == 0){
			while (keyPressed != 13) {
				system("cls");
				printf("\n\n\n\n\t\t\t\t    ===========================================");
				printf("\n\n\t\t\t\t\t   Pembayaran Sudah Terkonfirmasi!\n");
				printf("\n\t\t\t\t    ===========================================");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Klik Enter untuk Print Tiket");
				keyPressed = getch();
				
			}
			keyPressed = 0;
			while (keyPressed != 13) {
				system("cls");	
				printTiket();
				hitung++;
				keyPressed = getch();
			}	
		}
		else {
			while (keyPressed != 13) {
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t         PIN Salah!");
				printf("\n\n\t\t\t\t\t     Klik Enter untuk Kembalik ke Menu");
				keyPressed = getch();
			}						
		}			
	}
	
	else if (hitung == 2){
		if (strcmp(PINbanding, "34567") == 0){
			while (keyPressed != 13) {
				system("cls");
				printf("\n\n\n\n\t\t\t\t    ===========================================");
				printf("\n\n\t\t\t\t\t   Pembayaran Sudah Terkonfirmasi!\n");
				printf("\n\t\t\t\t    ===========================================");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Klik Enter untuk Print Tiket");
				keyPressed = getch();
			}
			keyPressed = 0;
			while (keyPressed != 13) {
				system("cls");	
				printTiket();
				hitung = 0;					
				keyPressed = getch();
			}				
		}
		else {
			while (keyPressed != 13) {
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t         PIN Salah!");
				printf("\n\n\t\t\t\t\t     Klik Enter untuk Kembalik ke Menu");
				keyPressed = getch();
			}	
		}	
	}
}

void printTiket(){ //fungsi untuk mencetak tiket yang dipesan
	int count;
	printf("\n\n\t\t\t\t   ==============   TIKET RESERVASI BUS   ==============");
	for(count=0; count < banyaktiket; count++){
		printf("\n\n\n\n\n\n\t\t\t\t\t======================================\n");
		printf("\t\t\t\t\t				    \n");
		printf("\t\t\t\t\t Nama 	\t: %s 	    \n", datapelanggan.namapelanggan[n]);
		printf("\t\t\t\t\t				    \n");
		printf("\t\t\t\t\t Tujuan 	: %s 	\n", rute);
		printf("\t\t\t\t\t				    \n");
		printf("\t\t\t\t\t Tiket no 	: %d\n", count+1);
		printf("\t\t\t\t\t				    \n");
		printf("\t\t\t\t\t======================================");
	}
}

void pembatalan(){ //fungsi untuk melakukan pembatalan tiket yang sudah dipesan
	int opsiBatal;
	char alasanBatal[99];
	system("cls");
	if(condition == true) {
		system("cls");
		printf("\n\t\t\t\t\t===========================================");
		printf("\n\n\t\t\t\t\t\tMENU PEMBATALAN PEMESANAN BUS\n");
		printf("\n\t\t\t\t\t===========================================");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tKlik Apapun untuk lanjutkan Proses Pembatalan");
		getch();
		
		system("cls");
		
		printf("\n\t\t\t\t\t===========================================");
		printf("\n\n\t\t\t\t\t\tMENU PEMBATALAN PEMESANAN BUS\n");
		printf("\n\t\t\t\t\t===========================================");
		
		printf("\n\n\n\t\t\t\t\tAlasan Pembatalan Reservasi : \n\n\n");
		printf("\n\t\t\t\t\t\t[1] ==> Salah Memilih Tujuan\n");
		printf("\n\t\t\t\t\t\t[2] ==> Salah Memilih Jadwal\n");
		printf("\n\t\t\t\t\t\t[3] ==> Salah Memasukkan Nama dan Jumalh Tiket\n");
		printf("\n\t\t\t\t\t\t[4] ==> Lain Lain\n");
		printf("\n\t\t\t\t\t\t    ==> ");
		scanf("%d", &opsiBatal);
		
		if(opsiBatal == 4){
			printf("\n\t\t\t\t\t\t    Masukkan Alasan Pembatalan Anda ==> ");
			scanf("%s", &alasanBatal);
			getch();
			menuPembatalan();
			
		} else if(opsiBatal >= 1 || opsiBatal <= 3){	
			menuPembatalan();
		}
	} 
	
	else {
		while (keyPressed != 13) {
			printf("\n\n\t\t\t     Lakukan Pemesanan Tiket pada Menu Pemesanan Tiket terlebih dahulu!");
			printf("\n\n\t\t\t\t        Tekan Enter untuk kembali ke Menu Awal");
			keyPressed = getch();
		}
	}
}

void menuPembatalan(){ //fungsi untuk mengkonfirmasi proses pembatalan 
	char yesorno[5];
	int i;
	system("cls");
	printf("\n\t\t\t\t\t===========================================");
	printf("\n\n\t\t\t\t\t\tMENU PEMBATALAN PEMESANAN BUS\n");
	printf("\n\t\t\t\t\t===========================================");
	
	printf("\n\n\n\n\t\t\t\t\tPembatalan Untuk Bus dengan Tujuan : %s", rute);
	printf("\n\n\t\t\t\t\tAtas Nama : %s", datapelanggan.namapelanggan[n]);
	printf("\n\n\t\t\t\t\tJumlah Tiket yang dibatalkan: %d", banyaktiket);
	
	printf("\n\n\n\n\n\t\t\t\t\tLanjutkan Pembatalan? [Y/N] ");
	scanf("\n\t\t\t\t %s", &yesorno);
	
	system ("cls");
	printf ("\t\t");
	printf ("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading");
	printf ("\n\n\n\n\t\t\t\t      ");	
	
	for(i = 0 ; i < 43 ; i++) {
		printf("=");
		Sleep(10);
	}	
	Sleep(500);
	
	if((strcmp(yesorno, "y") == 0) || (strcmp(yesorno, "Y") == 0)) {
		condition = arr[1];
 		strcpy(datapelanggan.namapelanggan[n], "CANCELED");
 		strcpy(datapelanggan.nokepend[n], "CANCELED");
 		strcpy(datapelanggan.notelp[n], "CANCELED");
 		datapelanggan.harga[n] = 0;
		system("cls");
		
		printf("\n\t\t\t\t\t===========================================");
		printf("\n\n\t\t\t\t\tPEMBATALAN RESERVASI BUS SUDAH TERKONFIRMASI\n");
		printf("\n\t\t\t\t\t===========================================");	
		
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Reservasi Bus Anda Telah diBatalkan");
		getch();
		if (mode == 1){
			if(param == 0){
				bkEKS = bkEKS + banyaktiket;
			}
			else if(param == 1){
				skEKS = skEKS + banyaktiket;
			}
			else if(param == 2){
				ykEKS = ykEKS + banyaktiket;
			}
			else if(param == 3){
				slkEKS = slkEKS + banyaktiket;
			}
			else if(param = 4){
				bakEKS = bakEKS + banyaktiket;
			}	
		}
		else if (mode == 2){
			if(param == 0){
				bkBUS = bkBUS + banyaktiket;
			}
			else if(param == 1){
				skBUS = skBUS + banyaktiket;
			}
			else if(param == 2){
				ykBUS = ykBUS + banyaktiket;
			}
			else if(param == 3){
				slkBUS = slkBUS + banyaktiket;
			}
			else if(param == 4){
				bakBUS = bakBUS + banyaktiket;
			}		
		}
		else if (mode == 3){
			if(param == 0){
				bkEKO = bkEKO + banyaktiket;
			}
			else if(param == 1){
				skEKO = skEKO + banyaktiket;
			}
			else if(param == 2){
			    ykEKO = ykEKO + banyaktiket;
			}
			else if(param == 3){
			    slkEKO = slkEKO + banyaktiket;
			}
			else if(param == 4){
			    bakEKO = bakEKO + banyaktiket;
			}
		}	
	}	
}
