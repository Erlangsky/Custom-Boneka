void login();
void menu_owner();
void menu_user();
void login_manajer();
void login_admin();
void login_pelanggan();
void desainPojok();
int pilihan_SS(int b1,int by1,int b2,int by2,int x1,int y1,int x2,int y2);
int pilihan_rl(int b1,int by1,int b2,int by2, int b3, int by3, int x1,int y1,int x2,int y2, int x3, int y3);
void inputAwal();
void inputCustAwl();

#include "menuAdmin.h"
#include "menuManajer.h"
#include "menuPelanggan.h"

char username[50];
char password[50];
time_t waktu;
int i;

void login(){
    do    {
    system("cls");
    
    bg();
    luar();
    desainPojok();
    gotoxy(14,47);
    
    DrawFile(50, 10, "Design/logodpn.txt");
    DrawFile(50, 18, "Design/kotaklogin.txt");
    gotoxy(70, 23);
    printf("\033[48;5;204m\033[38;5;223m\t\t\tM A S U K K A N   D A T A   A K U N\033[0m\n");
    gotoxy(70, 25);
    printf("\033[48;5;204m\033[38;5;223m\t\t\tUsername : \033[0m");
    gotoxy(99,25);
    scanGets(username,sizeof(username));
        if (strlen(username) == 0|| isWhitespace(username)){
            MessageBox(NULL, "Harap isi kolom username terlebih dahulu", "Terdapat Kesalahan",
            MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        } else {
            gotoxy(70,26);
            printf("\033[48;5;204m\033[38;5;223m\t\t\tPassword : \033[0m");
            gotoxy(99,26);
            ReadPassword(password, sizeof(password));
            // scanGets(password, sizeof(password));
            if (strlen(password) == 0|| isWhitespace(password)){
                MessageBox(NULL, "Harap kolom sandi di isi", "Terdapat Kesalahan",
                MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            }
        }
    } while(strlen(password) == 0 || strlen(username) == 0 || isWhitespace(username) || isWhitespace(password));

    if(strcmp(username,"Owner") == 0 && strcmp(password,"Ownerkita") == 0 ){
        
        menu_owner();
    } else {
        
        menu_user();
    }
}

void menu_owner(){
    role = 4;
    int pilihan = 0;
    int msgResult;
    
    do{
    system("cls");
    luar();
    border();
    DrawFile(48, 2, "Design/welcome.txt");
    
    menuOwnerDisplay(pilihan);
    
    char ch = getch();  
        if (ch == 72) { 
            if (pilihan > 0) 
            pilihan--;
        } else if (ch == 80) { 
            if (pilihan < 9 - 1) 
            pilihan++;
        } else if (ch == 13) {
            switch (pilihan)
            {
            case 0:
                system("cls");
                Manajer();
                break;
            
            case 1:
                system("cls");
                Admin();
                break;
            
            case 2:
                system("cls");
                Pelanggan();
                break;
            
            case 3 :
                system("cls");
                Boneka();
                break;
            
            case 4:
                system("cls");
                Aksesori();
                break;

            case 5:
                system("cls");
                Pemesanan();
                break;
                
            case 6:
                system("cls");
                Pembayaran();
                break;
                
            case 7:
                system("cls");
                Laporan();
                break;

            case 8:
                system("cls");
                msgResult = MessageBox(NULL, "KLIK OK UNTUK KELUAR", "Keluar???",
                MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    
                if (msgResult == IDOK)  // Jika OK ditekan
                return; // Keluar dari program
                break;  // Jika X ditekan atau Cancel ditekan, kembali ke menu
            }
        } 
    }while(1);
}
void menu_user(){
    int pilihan = 0;
    char ch;
    desainPojok();
    do{    
    system("cls");
    bg();
    luar();
    desainPojok();
    DrawFile(50, 10, "Design/logodpn.txt");
    DrawFile(50, 18, "Design/kotaklogin.txt");
    gotoxy(70,23);
    printf("\033[48;5;204m\033[38;5;223m\t\t\t S I G N    I N    S E B A G A I\033[0m\n");  
    // gotoxy(66,17);

    pilihan = pilihan_rl(75,26,95,26,115,26,76,27,96,27,116,27);
    if(pilihan == 0 ){
        system("cls");
        role = 1;
        login_manajer();
        login();
    } else if (pilihan ==1){
        system("cls");
        role = 2;
        login_admin();
        login();
    } else {
        system("cls");
        role = 3;
        login_pelanggan();
        login();
    }
    // for (i = 0; i < 3; i++) {
    //     gotoxy(73,19 + i);
    //     if (i == pilihan) {
    //         printf(">\033[48;2;0;255;255m %s\033[0m<", menu[i]); // Highlight selected option
    //     } else {
    //         printf("  %s", menu[i]);
    //     }
    // }
    // for (i = 18; i < 23; i++){
    //     gotoxy(90,i);
    //     printf("||");
    // };   
    waktu = time(NULL);
    gotoxy(53,18);
    printf("\033[1;32mWaktu login : \033[0m");
    gotoxy(80,18);
    printf("\033[1;33m%s\033[0m", strtok(ctime(&waktu), "\n"));
    // char ch = getch();  
    //     if (ch == 72) { 
    //         if (pilihan > 0) 
    //         pilihan--;
    //     } else if (ch == 80) { 
    //         if (pilihan < 3 - 1) 
    //         pilihan++;
    //     } else if (ch == 13) {
    //         switch (pilihan){
    //         case 0:
    //             system("cls");
    //             role = 1;
    //             login_manajer();
    //             login();
    //             break;
            
    //         case 1:
    //             system("cls");
    //             role = 2;
    //             login_admin();
    //             login();
    //             break;
            
    //         case 2:
    //             system("cls");
    //             role = 3;
    //             login_pelanggan();
    //             login();
    //             break;
    //         }
    //     } 
    }while(1);
}


void login_manajer(){
    bool found = false;
    manajer = fopen("Database/manajer.dat","rb");
    while (fread(&mnj, sizeof(mnj), 1, manajer) == 1) {
        if (strcmp(mnj.nama, username) == 0) { // Cek apakah username cocok
            found = true;
            if (strcmp(mnj.sandi, password) == 0) { // Cek apakah password cocok
                menu_OMnj();// Login sukses
                break;
            } else {
                MessageBox(NULL, "Password anda salah", "Terdapat Kesalahan",
                MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            }
        }
    }
    fclose(manajer);
    if (!found) {
        MessageBox(NULL, "Data tidak ditemukan", "Terdapat Kesalahan",
        MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
    }
}

void login_admin(){
    bool found = false;
    admin = fopen("Database/admin.dat","rb");
    while (fread(&adm, sizeof(adm), 1, admin) == 1) {
        if (strcmp(adm.nama, username) == 0) { // Cek apakah username cocok
            found = true;
            if (strcmp(adm.sandi, password) == 0) { // Cek apakah password cocok
                menu_OAdmin(); // Login sukses
                break;
            } else {
                MessageBox(NULL, "Password anda salah", "Terdapat Kesalahan",
                MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            }
        }
    }
    fclose(admin);
    if (!found) {
        MessageBox(NULL, "Data tidak ditemukan", "Terdapat Kesalahan",
        MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
    }
}

void login_pelanggan(){
    bool found = false;
    dataCust = fopen("Database/CRUDCust.dat","rb");
    while (fread(&cust, sizeof(cust), 1, dataCust) == 1) {
        if (strcmp(cust.nama, username) == 0) { // Cek apakah username cocok
            found = true;
            if (strcmp(cust.sandi, password) == 0) { // Cek apakah password cocok
                idPelangganAktif = cust.id;
                
                menu_OPel (); // Login sukses
                break;
            } else {
                MessageBox(NULL, "Password anda salah", "Terdapat Kesalahan",
                MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            }
        }
    }
    fclose(manajer);
    if (!found) {
        MessageBox(NULL, "Data tidak ditemukan", "Terdapat Kesalahan",
        MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
    }
}


void inputAwal(){
    
    while(1){
    system("cls");
    bg() ;
    luar();
    desainPojok();
    DrawFile(50, 10, "Design/logodpn.txt");
    DrawFile(50, 18, "Design/kotaklogin.txt");
    gotoxy(70,23);
    printf("\033[48;5;204m\033[38;5;223m\t\t\tH A I   B O N E K A   L O V E R S^^\033[0m\n");
    gotoxy(70,25);

    int pilihan = pilihan_SS(84,28,117,28,85,29,118,29);
        if(pilihan == 0 ){
            login();
        } else {
            inputCustAwl();
        }
    }
}

int pilihan_SS(int b1,int by1,int b2,int by2,int x1,int y1,int x2,int y2){
    int pilihan = 0;

    do{
        DrawFile(b1,by1,"Design/borderKecil.txt");
        DrawFile(b2,by2,"Design/borderKecil.txt");
        gotoxy(x1,y1);
        printf("\033[48;5;204m\033[38;5;223mSign In\033[0m");
        gotoxy(x2,y2);
        printf("\033[48;5;204m\033[38;5;223mSign Up\033[0m");

        if (pilihan == 0){
            gotoxy(x1,y1);
            printf("\033[48;5;223m\033[38;5;204mSign In\033[0m"); // Highlight selected option
            } else {
            gotoxy(x2,y2);
            printf("\033[48;5;223m\033[38;5;204mSign Up\033[0m"); // Highlight selected option
            }
            
            char ch = getch();  // // Membaca satu karakter tanpa perlu menekan enter
            if (ch == 75) { // Panah atas
            if (pilihan > 0) pilihan--;
            } else if (ch == 77) { // Panah bawah
            if (pilihan < 1) pilihan++;
            } else if (ch == 13) { // Enter 
            return pilihan;
            break;
            }
     } while (1);
}
        
void inputCustAwl(){
    bg() ;
    luar();
    int pilihan;
    bool found;
    FILE *dataCust;
    customer cust;
    
    dataCust = fopen("Database/CRUDCust.dat", "a+b");
    if (dataCust == NULL){
        MessageBox(NULL, "Yahh...Gagal membuka file!!!", "GAGAL!",
        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY); // MessageBox itu nanti muncul notif kyk kotak gitu
    return;
    }
    system("cls");
    bg() ;
    luar();
    desainPojok();
    DrawFile(70,20,"Design/borderPel.txt");
    DrawFile(50, 10, "Design/logodpn.txt");
    
    do{
        cust.id = idOtomatisCustomer();
        gotoxy(79,21);
        printf("%d", cust.id);
        gotoxy(75,24);
        scanf(" %[^\n]s", cust.nama);

    do {
        gotoxy(75,29);
        scanf("%s", cust.telepon);
        if (!validasiTelp(cust.telepon)) {
            MessageBox(NULL, "Nomor Telpon Tidak Valid", "Terdapat Kesalahan",
                MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            Sleep(1000);
            clearArea(75,29,120,29);
        }
    } while (!validasiTelp(cust.telepon));
    gotoxy(75, 34);
    scanf(" %[^\n]s", cust.sandi);
    fwrite(&cust, sizeof(cust), 1, dataCust);
    
    gotoxy(96,38);
    printf("Loading");
    loading(73,39);

    clearArea(4,12,55,13);
    gotoxy(74,41);
    printf("\033[48;5;204m\033[38;5;223mData anda berhasil kami simpan !\033[0m");
    Sleep(1000);
    
    
    // printAt(59,38,"Apakah anda ingin memasukkan data lagi ?");
    // pilihan = pilihan_yn(65,39,97,39,67,40,99,40);
    // printf("\n");
    //     if (pilihan == 0){
    //         found = true;
    //         cust.id++;
    //     } else if (pilihan == 1){
            found = false;
        // }
    } while (found == true);
    fclose(dataCust);
}

int pilihan_rl(int b1,int by1,int b2,int by2, int b3, int by3, int x1,int y1,int x2,int y2, int x3, int y3){
    int pilihan = 0;

    do {
        DrawFile(b1,by1,"Design/borderKecil2.txt");
        DrawFile(b2,by2,"Design/borderKecil2.txt");
        DrawFile(b3,by3,"Design/borderKecil2.txt");
        gotoxy(x1,y1);
        printf("\033[48;5;204m\033[38;5;223m  Manajer  \033[0m");
        gotoxy(x2,y2);
        printf("\033[48;5;204m\033[38;5;223m   Admin   \033[0m");
        gotoxy(x3,y3);
        printf("\033[48;5;204m\033[38;5;223m Pelanggan \033[0m");


        gotoxy(x1, y1);
        if (pilihan == 0)
            printf("\033[48;5;223m\033[38;5;204m  Manajer  \033[0m");
        else
        printf("\033[48;5;204m\033[38;5;223m  Manajer  \033[0m");

        gotoxy(x2, y2);
        if (pilihan == 1)
            printf("\033[48;5;223m\033[38;5;204m   Admin   \033[0m");
        else
        printf("\033[48;5;204m\033[38;5;223m   Admin   \033[0m");

        gotoxy(x3, y3);
        if (pilihan == 2)
            printf("\033[48;5;223m\033[38;5;204m Pelanggan \033[0m");
        else
        printf("\033[48;5;204m\033[38;5;223m Pelanggan \033[0m");
              
        char ch = getch();  // // Membaca satu karakter tanpa perlu menekan enter
            if (ch == 75) { // Panah atas
                if (pilihan > 0) pilihan--;
            } else if (ch == 77) { // Panah bawah
                if (pilihan < 2) pilihan++;
            } else if (ch == 13) { // Enter 
                return pilihan;
                break;
            }
    } while (1);
}
