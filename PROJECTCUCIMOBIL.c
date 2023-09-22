#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

void validasi(){
	int hasil1,hasil2,hasil3,hasil4;
	char username[10];
	char u1[]="admin",p1[]="1234",u2[]="owner",p2[]="1010";
    printf("\n\n\t\t   L O G I N  U S E R\n");
	printf("\t=======================================\n");
	printf("\t\t  O                 O\n");
	printf("\t\t -|-               -|-\n");
	printf("\t\t / \\               / \\\n");
	printf("\t\tOWNER             ADMIN\n");
	printf("\n\tUsername\t: ");gets(username);
  	
  	char pwd[10];
    int i;
    printf("\tPassword\t: ");
    for(i=0;i<4;i++)
    {
    pwd[i]=getch();
        if(pwd[i]!='\r')
        {
            printf("*");
        }
        if(pwd[i]==13)
            break;
    }
    hasil1=strcmp(username,u1);
  	hasil2=strcmp(pwd,p1);
	hasil3=strcmp(username,u2);
	hasil4=strcmp(pwd,p2);
    if(hasil1 == 0 && hasil2 == 0){
  		system("cls");menu();
  	}
	else if (hasil3 == 0 && hasil4 == 0) {
		system("cls");menu1();
	}
  	else{
  		printf("\n\n\tLogin Failed\n\n");system("pause");system("cls");main();
	}
}
void menu(){
    printf("*************************************\n");
	printf("*     M  A  I  N     M  E  N  U     *\n");
    printf("*************************************\n\n");
	printf("\t1. Customer\n");
	printf("\t2. Member\n");
	printf("\t3. Back\n");
	printf("\t4. Keluar\n");
	printf("\nMENU >> ");
	int menu=0;
	scanf("%d", &menu);fflush(stdin);
	while(menu>4||menu<1){
		menu=0;
		printf("\nInput salah!!\n");
		printf("---------------\n");
		printf("Masukkan Menu yang sesuai >> ");
		scanf("%d", &menu); fflush(stdin);
	}
	if(menu == 1){
		system("cls");customer();
	} else if(menu == 2){
		system("cls");member();
	}
		else if(menu == 3){
		system("cls");validasi();
	}
	 else if(menu == 4){
		system("cls");
    	printf("\n\t\t\t\t\t    +---------------------------------------+\n");
    	printf("\t\t\t\t\t    |    Selamat datang di Car Wash   |\n");
    	printf("\t\t\t\t\t    |Jalan Pasir Kaliki No. 25, Kota Bandung|\n");
    	printf("\t\t\t\t\t    |             (022) 123456              |\n");
		printf("\t\t\t\t\t    |            T H A N K Y O U            |\n");
    	printf("\t\t\t\t\t    +---------------------------------------+\n\n");
		return 0;
	}
	else{
	}
}
 
int cariMember(char cari[]){
	char noTelp[100000][12],time[20],nama[20];
	int j;
	FILE *fp;
	fp=fopen("Member.txt","r");
	int i=0;
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%s\n",time ,nama ,noTelp[i]);
		i++;
	}
	fclose(fp);
	for(j=0;j<i;j++){
		if(strcmp(cari, noTelp[j])==0){
			return 1;
		}
	}
	return -1;
}

struct customer{
	char plat[20];
	char nama[100];
	char noTelp[20];
	char paket[20];
	int harga;
};

void customer(){
	struct customer ctr;
	char next;
	int TipeMobil, bayar, Paket;
	time_t now;
	time(&now);
	printf("- C U S T O M E R -\n\n");
	printf("- Plat Nomor : ");
	scanf("%[^\n]", ctr.plat); getchar();
	printf("- Nama\t     : ");
	scanf("%[^\n]", ctr.nama); getchar();
	printf("- No Telepon : ");
	scanf("%s", ctr.noTelp); getchar();
	printf("\n\n------------------------------------------------\n");
    printf("-               T I P E  M O B I L             -\n");
	printf("------------------------------------------------\n");
    printf("-           1. Mini Bus                        -\n");
    printf("-\t\t              2. Sedan         -\n");
	printf("------------------------------------------------\n");
    printf("Pilih Tipe Mobil >> ");
    scanf("%d", &TipeMobil); getchar();
	printf("\n------------------------------------------------\n");
    printf("-                   P A K E T                  -\n");
	printf("------------------------------------------------\n");
    printf("-    1. Bagus Banget                           -\n");
    printf("-\t\t    2. Bagus                   -\n");
    printf("-\t\t\t      3. Biasa Aja     -\n");
	printf("------------------------------------------------\n");
    printf("Pilih Paket >> ");
    scanf("%d", &Paket); getchar();
    if(TipeMobil == 1 && Paket == 1){
    	ctr.harga = 120000; strcpy(ctr.paket,"Tipe 1 Paket 1");
    } else if(TipeMobil == 1 && Paket == 2){
    	ctr.harga = 70000; strcpy(ctr.paket,"Tipe 1 Paket 2");
    } else if(TipeMobil == 1 && Paket == 3){
    	ctr.harga = 50000; strcpy(ctr.paket,"Tipe 1 Paket 3");
    } else if(TipeMobil == 2 && Paket == 1){
    	ctr.harga = 100000; strcpy(ctr.paket,"Tipe 2 Paket 1");
    } else if(TipeMobil == 2 && Paket == 2){
    	ctr.harga = 60000; strcpy(ctr.paket,"Tipe 2 Paket 2");
    } else if(TipeMobil == 2 && Paket == 3){
    	ctr.harga = 40000; strcpy(ctr.paket,"Tipe 2 Paket 3");
    } else {
    	printf("Input salah!!!\n\n");
    	customer();
	}
    printf("\n------------------------------------------------\n");
    printf("- PAKET PEMBELIAN : %s\n", ctr.paket);
    printf("- Total Harga     : Rp. %d\n", ctr.harga);
    int value = cariMember(ctr.noTelp);
    if(value==1){
		ctr.harga = ctr.harga-(0.1*ctr.harga);
		printf("- Anda anggota member & mendapat Potongan 10%%\n");
		printf("- Total Harga     : Rp. %d\n", ctr.harga);
	}
	printf("------------------------------------------------\n");
    printf("- Bayar           : Rp. ");
    scanf("%d", &bayar);getchar();
    if(bayar<ctr.harga){
    	printf("- Maaf uang kurang %d\n",ctr.harga-bayar);
	}
	else{
		printf("- Uang Kembalian  : Rp. %d\n", bayar-ctr.harga);
	}
    printf("- Next Customer (Y/N): ");
    scanf("%c",&next);getchar();
    FILE *fp;
    fp=fopen("Laporan.txt","a");
    fprintf(fp,"%s#%s#%s#%s#%s#%d\n",ctime(&now),&ctr.nama,&ctr.plat,&ctr.noTelp,&ctr.paket,ctr.harga);
    fclose(fp);
	    
    if(next=='Y'||next=='y'){
    	system("cls");customer();
	}
	else if(next=='N'||next=='n'){
		system("cls");	menu();
	}
		
    
}
struct member{
	char noTelp[20];
	char nama[50];
	char time[30];
};
void member(){
	time_t now;
	time(&now);
	char noTelp[20];
	char nama[50];
	char time[30];
	char search[30];
	struct member mb[1000],temp;
	int pil,i,j,k,r,found,data;
    printf("- M E M B E R -\n\n");
    puts("1. Registrasi Member");
    puts("2. Anggota Member");
    puts("3. Menu");
    printf("--------------------\n");
	printf("Pilihan >> ");
    scanf("%d",&pil);fflush(stdin);
    
    	system("cls");
    if(pil==1){
    	puts("- R E G I S T R A S I   M E M B E R -\n");
		printf("- Nama    : ");
		scanf("%[^\n]", &nama);fflush(stdin);
		printf("- NoTelp  : ");
		scanf("%s", &noTelp);fflush(stdin);
		int value= cariMember(noTelp);
		if(value==1){
			printf("\nAnda sudah registrasi sebagai member sebelumnya!\n\n");
		} else {
			FILE *out = fopen("Member.txt", "a");
		fprintf(out, "%s#%s#%s\n",ctime(&now), nama, noTelp);
		fclose(out);
		printf("\nSELAMAT !!! Anda telah terdaftar sebagai member!\n\n");
		}
		system("pause");
		system("cls");member();
	}
	else if(pil==2){
		FILE *fp;
		fp=fopen("Member.txt","r");
		i=0;
		puts("- A N G G O T A   M E M B E R-\n");
		while(!feof(fp)){
			fscanf(fp,"%[^#]#%[^#]#%s\n",mb[i].time,mb[i].nama,mb[i].noTelp);
			i++;
	}
		fclose(fp);
		
		for(j=1;j<i;j++){
		for(k=0;k<i-j;k++){
			r = strcmp(mb[k].nama,mb[k+1].nama);
			if (r>0){
				temp=mb[k];
				mb[k]=mb[k+1];
				mb[k+1]=temp;
			}
		}
	}
        printf("-------------------------------------------------------\n");
		for(j=0;j<i;j++){
			printf("%sNama: %s\nNo Telp: %s\n\n",mb[j].time,mb[j].nama,mb[j].noTelp);
			}
        printf("-------------------------------------------------------\n");
		printf("Jumlah Member : %d Member\n\n",i);
		char mem;
		printf("Search Member?(Y/N): ");
		scanf("%c",&mem);fflush(stdin);
		if(mem=='Y'||mem=='y'){
			char notel[20];
            printf("\nPENCARIAN MEMBER\n");
			printf("Masukan No Tlp: ");
			scanf("%[^\n]",notel);
			int value = cariMember(notel);
			if(value==1){
				printf("Anggota Member\n");
			}
			else{
				printf("Bukan Anggota Member\n");
			}	
			printf("\n");
			system("pause");
    		system("cls");member();	
		}
		else{
		system("cls");	member();	
		}
		
		
	}
	
	else{
		menu();
	}
}
struct sortData{
	char time[30];
	char nama[20];
	char plat[20];
	char noTelp[20];
	char paket[20];
	char temp[20];
	int jumlah;
};

void menu1 (){
	struct sortData lp[1000];
	int i,j,total=0;
	puts("- L A P O R A N   P E M B E L I A N -\n");
	FILE *fp;
	fp=fopen("Laporan.txt","r");
	i=0;
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n",lp[i].time,lp[i].nama,lp[i].plat,lp[i].noTelp,lp[i].paket,&lp[i].jumlah);
		i++;
	}
	fclose(fp);
    
    printf("-------------------------------------------------------\n");
	for(j=0;j<i;j++){
		printf("%sNama: %s\nPlat: %s\nNo Telp: %s\n%s\nTransaksi: %d\n\n",lp[j].time, lp[j].nama, lp[j].plat, lp[j].noTelp, lp[j].paket, lp[j].jumlah);
		}
	for(j=0;j<i;j++){
		total+=lp[j].jumlah;
		}
    printf("-------------------------------------------------------\n\n");
	printf("--------------------------------");
    printf("\nJumlah Transaksi   : %d",i);
	printf("\nTotal Pemasukan    : Rp. %d\n",total);
	printf("--------------------------------");
    printf("\n");
	
    puts("1.Back");
    puts("2.Exit");
    int pil;
    puts(">>");
    scanf("%d",&pil);fflush(stdin);
    if(pil==1){
   		system("cls");
    	validasi();
	}
	else{
			system("cls");
    	printf("\n\t\t\t\t\t    +---------------------------------------+\n");
    	printf("\t\t\t\t\t    |    Selamat datang di Car Wash   |\n");
    	printf("\t\t\t\t\t    |Jalan Pasir Kaliki No. 25, Kota Bandung|\n");
    	printf("\t\t\t\t\t    |             (022) 123456              |\n");
		printf("\t\t\t\t\t    |            T H A N K Y O U            |\n");
    	printf("\t\t\t\t\t    +---------------------------------------+\n\n");
		return 0;
	}

}

int main(){
    printf("+---------------------------------------------------------------------------------------------------------------------------+");
    printf("\n|  ==========         ==         ==========           =           =           =         ==         ==========   =         = |");
    printf("\n|  =                 =  =        =          =          =         = =         =         =  =        =            =         = |");
    printf("\n|  =                =    =       =         =            =       =   =       =         =    =       =            =         = |");
    printf("\n|  =               ========      ==========              =     =     =     =         ========      ==========   =========== |");
    printf("\n|  =              =        =     =        =               =   =       =   =         =        =              =   =         = |");
    printf("\n|  =             =          =    =         =               = =         = =         =          =             =   =         = |");
    printf("\n|  ==========   =            =   =          =               =           =         =            =   ==========   =         = |");
    printf("\n+---------------------------------------------------------------------------------------------------------------------------+");
    printf("\n\t\t\t\t\t    +---------------------------------------+\n");
    printf("\t\t\t\t\t    |    Selamat datang di Car Wash   |\n");
    printf("\t\t\t\t\t    |Jalan Pasir Kaliki No. 25, Kota Bandung|\n");
    printf("\t\t\t\t\t    |             (022) 123456              |\n");
    printf("\t\t\t\t\t    +---------------------------------------+\n\n");
    validasi();
  return 0;
}
