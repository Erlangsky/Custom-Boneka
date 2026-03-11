// Deklarasi Function
void input_admin();
void read_admin();
void update_admin();
void delete_admin();
void displayTableAdmin();
void Admin();
int idOtomatis_Admin();
void printTableHeader2();
void printTableRow2(DataAdmin adm, int currentRow);
void updateNamaSandi(int *pilihan);
void update_admin();

int idOtomatis_Admin() {
    int idTerakhir = 0;

    FILE *file_id = fopen("Database/admin.dat", "rb");
    if (file_id == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
    return 1;
    } 
    
    while (fread(&adm, sizeof(adm), 1, file_id) == 1) {
        idTerakhir = adm.id; 
    }

    fclose(file_id);
    return idTerakhir + 1;
}
void displayAdmin(int highlight){
    int totalOpsi = 5; // Total opsi di menu
    char *menuOpsi[] = {
        "   I N P U T   A D M I N          ",
        "   C E K   D A T A                ",
        "   U P D A T E                    ",
        "   H A P U S                      ",
        "   K E L U A R                    "
    };
    
    gotoxy(2, 26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   A D M I N\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");
    
    for (int i = 0; i < totalOpsi; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOpsi[i]); // Highlight warna yang sama
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuOpsi[i]);
        }
    }
}

void Admin() {
    int pilihan = 0;


    do {
        system ("cls");
        border();
        if (role == 1){
            menuOwnerManajer(-1);
        }else{
        menuOwnerDisplay(-1);
        }
        displayAdmin(pilihan);
        DrawFile(69, 3, "Design/adminteks.txt");
        

        char ch = getch();  // // Membaca satu karakter tanpa perlu menekan enter
            if (ch == 72) { // Panah atas
                if (pilihan > 0) pilihan--;
            } else if (ch == 80) { // Panah bawah
                if (pilihan < 5 - 1) pilihan++;
            } else if (ch == 13) { // Enter 
            switch (pilihan) {
                case 0:
                    system("cls");
                    input_admin();
                    break;
                case 1:
                    system("cls");
                    read_admin();
                    getch();
                    break;
                case 2:
                    system("cls");
                    update_admin();
                    break;
                case 3:
                    system("cls");
                    delete_admin();
                    break;
                case 4:
                    system("cls");
                    return;
            }
 // Menunggu pengguna menekan tombol
        }
    } while (1); // looping terus sampe usernya milih keluar
}

// Fungsi untuk mengecek apakah string hanya terdiri dari spasi atau kosong
// int isWhitespace(const char *str) {
//     while (*str) {
//         if (!isspace((unsigned char)*str)) {
//             return 0; // Ada karakter yang bukan spasi
//         }
//         str++;
//     }
//     return 1; // Hanya spasi atau kosong
// }

// Function untuk menginput data customer
void input_admin() {
    int pilihan;
    bool found;
    FILE *admin = fopen("Database/admin.dat", "a+b");
    if (admin == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
        MB_OK | MB_ICONWARNING);
        return;
    }

    adm.id = idOtomatis_Admin();

    do {
        system("cls");
        border();
        if (role == 1) {
            menuOwnerManajer(-1);
        } else {
            menuOwnerDisplay(-1);
        }
        displayAdmin(pilihan);
        DrawFile(69, 3, "Design/adminteks.txt");
        DrawFile(55, 17, "Design/borderBesar.txt");
        gotoxy(64, 18);
        printf("\033[48;5;204m\033[38;5;223m%d\033[0m", adm.id);

        // Validasi input nama
        do {
            gotoxy(59, 21);
            printf("\033[48;5;204m\033[38;5;223m"); // Set background 204 dan teks 223
            scanGets(adm.nama, sizeof(adm.nama));
            printf("\033[0m"); // Reset warna
            if (strlen(adm.nama) == 0 || isWhitespace(adm.nama)) {
                gotoxy(59, 23);
                printf("\033[48;5;204m\033[38;5;223mNama tidak boleh kosong atau hanya spasi!\033[0m");
                Sleep(1000);
                clearArea(59, 23, 84, 23);
            }
        } while (strlen(adm.nama) == 0 || isWhitespace(adm.nama));

        // Validasi input sandi
        do {
            gotoxy(59, 26);
            printf("\033[48;5;204m\033[38;5;223m"); // Set background 204 dan teks 223
            scanGets(adm.sandi, sizeof(adm.sandi));
            printf("\033[0m"); // Reset warna
            if (strlen(adm.sandi) == 0 || isWhitespace(adm.sandi)) {
                gotoxy(59, 29);
                printf("\033[48;5;204m\033[38;5;223mSandi tidak boleh kosong atau hanya spasi!\033[0m");
                Sleep(1000);
                clearArea(59, 29, 85, 29);
            }
        } while (strlen(adm.sandi) == 0 || isWhitespace(adm.sandi));

        // Menyimpan data ke file
        fwrite(&adm, sizeof(adm), 1, admin);
        gotoxy(82, 29);
        printf("\033[48;5;204m\033[38;5;223mLoading\033[0m");
        loading(60, 30);

        clearArea(4, 12, 55, 13);
        gotoxy(59, 32);
        printf("\033[48;5;204m\033[38;5;223mData anda berhasil kami simpan!\033[0m");
        Sleep(1000);

        gotoxy(59, 33);
        printf("\033[48;5;204m\033[38;5;223mApakah anda ingin memasukkan data lagi?\033[0m");
        pilihan = pilihan_yn(65, 34, 97, 34, 67, 35, 99, 35);
        printf("\n");
        if (pilihan == 0) {
            found = true;
            adm.id++;
        } else if (pilihan == 1) {
            found = false;
        }
    } while (found == true);

    gotoxy(50,26 + i);
    printf("\033[48;5;204m\033[38;5;223mTekan tombol apa saja untuk kembali ke menu\033[0m");
    fclose(admin);
}
//function untuk membaca data customer
void read_admin() {
    border();
    DrawFile(69, 3, "Design/adminteks.txt");

    if (role == 1) {
        menuOwnerManajer(-1);
    } else {
        menuOwnerDisplay(-1);
    }
    displayAdmin(-1);
    admin = fopen("Database/admin.dat", "rb");
    if (admin == NULL) {
        gotoxy(50, 16);
        printf("\033[48;5;204m\033[38;5;223mError: Gagal membuka file!\033[0m");
        return;
    }

    displayTableAdmin();

    fclose(admin);
}

void printTableHeader2() {
    gotoxy(45, 14);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\033[0m\n");
    gotoxy(45, 15);
    printf("\033[48;5;204m\033[38;5;223m| %-6s | %-10s | %-10s |\033[0m\n", "ID", "Nama", "Sandi");
    gotoxy(45, 16);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\033[0m\n");
}

void printTableRow2(DataAdmin adm, int currentRow) {
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m| %-6d | %-10s | %-10s |\033[0m", adm.id, adm.nama, adm.sandi);
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\033[0m\n");
}

void displayTableAdmin() {
    FILE *admin = fopen("Database/admin.dat", "rb");
    if (admin == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    printTableHeader2();
    DataAdmin adm;
    int currentRow = 17; // Awal baris tabel
    while (fread(&adm, sizeof(adm), 1, admin)) {
        printTableRow2(adm, currentRow);
        currentRow += 2; // Pindah dua baris ke bawah
    }
    fclose(admin);
}
void updateNamaSandi(int *pilihan) {
    int totalPilihan = 3;
    char *menuUpdateBaru[] = {
        "   N A M A                        ",
        "   S A N D I                      ",
        "   N A M A   D A N   S A N D I    "
    };
    int highlight = 0;
    do {
        system("cls");
        border();
        DrawFile(69, 3, "Design/adminteks.txt");

        if (role == 1) {
            menuOwnerManajer(-1);
        } else {
            menuOwnerDisplay(-1);
        }
        displayAdmin(-1);
        displayTableAdmin();
        gotoxy(2, 34);
        printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
        gotoxy(10, 35);
        printf("\033[48;5;204m\033[38;5;223mP E M B A R U A N\033[0m");
        gotoxy(2, 36);
        printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

        for (int i = 0; i < totalPilihan; i++) {
            gotoxy(2, 37 + i);
            if (i == highlight) {
                printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuUpdateBaru[i]); // Highlight selected option
            } else {
                printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuUpdateBaru[i]); // Warna ungu untuk opsi biasa
            }
        }

        char ch = getch();
        if (ch == 72) { // Tombol panah atas
            if (highlight > 0) highlight--;
        } else if (ch == 80) { // Tombol panah bawah
            if (highlight < totalPilihan - 1) highlight++;
        } else if (ch == 13) { // Tombol Enter
            *pilihan = highlight + 1;
            return;
        }
    } while (1);
}
//function untuk mengupdate data customer
void update_admin(){
    int pilihan = 0;
    char c[10];
    do{
    updateNamaSandi(&pilihan);
    
    FILE *admin = fopen("Database/admin.dat", "rb");  // File asli
    if (admin == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    FILE *temp = fopen("Database/tempadmin.dat", "wb");  // File sementara
    if (temp == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        fclose(admin);
        return;
    } 
    
    bool found = false;
    int idUpdate;
    gotoxy(45,13);
    printf("\033[48;5;204m\033[38;5;223mMasukkan ID yang ingin di update :\033[0m");
    do{
        gotoxy(80,13);
        limitInput(c,3);
        idUpdate = atoi(c);
        if(idUpdate == 0){
            gotoxy(84,13);
            printf("\033[48;5;204m\033[38;5;223minputan tidak valid\033[0m");
            Sleep(500);
        }
        clearArea(80,13,84,13); // hapus isi tabel
        clearArea(84,13,105,13); // hapus teks inputan
    } while (idUpdate == 0);
    
    while (fread(&adm, sizeof(adm), 1, admin)){
        if (adm.id == idUpdate){
        found = true; 
        system("cls");
        DrawFile(69, 3, "Design/adminteks.txt");
        border();
        if (role == 1){
            menuOwnerManajer(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayAdmin(-1);
        gotoxy(55,15);
        printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\033[0m\n");
        gotoxy(55,16);
        printf("\033[48;5;204m\033[38;5;223m| %-6s | %-10s | %-10s | \033[0m\n", "ID", "Nama", "Sandi");
        gotoxy(55,17);
        printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\n");
        gotoxy(55,18);
        printf("\033[48;5;204m\033[38;5;223m| %-6d | %-10s | %-10s |\033[0m", adm.id, adm.nama, adm.sandi);
        gotoxy(55,19);
        printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\033[0m\n");
    
            
            if (pilihan == 1) {
                gotoxy(55,20);
                printf("\033[48;5;204m\033[38;5;223mMasukkan Nama Baru : \033[0m");
                scanf(" %[^\n]", adm.nama);
            } else if (pilihan == 2){
                gotoxy(55,21);
                printf("\033[48;5;204m\033[38;5;223mMasukkan Kata Sandi Baru : \033[0m");
                scanf(" %[^\n]", adm.sandi);
            } else if (pilihan == 3){
                gotoxy(55,20);
                printf("\033[48;5;204m\033[38;5;223mMasukkan Nama Baru : \033[0m");
                scanf(" %[^\n]", adm.nama);
                gotoxy(55,22);
                printf("\033[48;5;204m\033[38;5;223mMasukkan Kata Sandi Baru : \033[0m");
                scanf(" %[^\n]", adm.sandi);
            }
        }
    fwrite(&adm, sizeof(adm), 1, temp);
    }
    if (found) {
        gotoxy(49,24);
        printf("\033[48;5;204m\033[38;5;223mApakah ada data lagi yang ingin di update?\033[0m");
        pilihan = pilihan_yn(53,25,82,25,56,26,84,26);
        MessageBox(NULL, "DATA BERHASIL DIPERBARUI!", "Horreee", MB_OK | MB_ICONINFORMATION);
    } else {
        MessageBox(NULL, "ID TIDAK DITEMUKAN", "Peringatan", MB_OK | MB_ICONWARNING);
    }

    fclose(admin);
    fclose(temp);            

    temp = fopen("Database/tempadmin.dat","rb");
    admin = fopen("Database/admin.dat","wb");
    while (fread(&adm, sizeof(adm),1,temp)){
        fwrite(&adm, sizeof(adm), 1, admin);
    }
    fclose(admin);
    fclose(temp); 
    } while(pilihan == 0);
}

//function untuk menghapus data customer
void delete_admin() {
    int found;
    int id,pilihan;
    char c[10];

    do{
    system("cls");
    found = 0;
    // Menampilkan antarmuka
    DrawFile(69, 3, "Design/adminteks.txt");
    border();
    if (role == 1){
        menuOwnerManajer(-1);
    }else{
    menuOwnerDisplay(-1);}
    displayAdmin(-1);
    displayTableAdmin(-1);
    gotoxy(45,13);
    printf("\033[48;5;204m\033[38;5;223mMasukkan ID yang ingin di hapus :\033[0m");
    do{
        gotoxy(80,13);
        limitInput(c,3);
        id = atoi(c);
        if(id == 0){
            gotoxy(84,13);
            printf("\033[48;5;204m\033[38;5;223minputan tidak valid\033[0m");
            Sleep(500);
        }
        clearArea(80,13,84,13); // hapus isi tabel
        clearArea(84,13,105,13); // hapus teks inputan
    } while (id == 0);

    // Membuka file asli untuk membaca
    FILE *admin = fopen("Database/admin.dat", "rb");
    if (admin == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
        MB_OK | MB_ICONWARNING);
        return;
    }

    // Membuka file sementara untuk menulis
    FILE *temp = fopen("Database/tempadmin.dat", "wb");
    if (temp == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
        MB_OK | MB_ICONWARNING);
        fclose(admin);
        return;
    }

    // Membaca data dari file asli dan menulis ulang ke file sementara
    while (fread(&adm, sizeof(adm), 1, admin) == 1) {
        if (adm.id == id) {
        clearArea(45,13,84,35);
        found = 1;
        gotoxy(55,15);
        printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\033[0m\n");
        gotoxy(55,16);
        printf("\033[48;5;204m\033[38;5;223m| %-6s | %-10s | %-10s |\033[0m\n", "ID", "Nama", "Sandi");
        gotoxy(55,17);
        printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\033[0m\n");
        gotoxy(55,18);
        printf("\033[48;5;204m\033[38;5;223m| %-6d | %-10s | %-10s |\033[0m", adm.id, adm.nama, adm.sandi);
        gotoxy(55,19);
        printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|\033[0m\n");
        gotoxy(49,21);
        printf("\033[48;5;204m\033[38;5;223mApakah anda yakin ingin menghapus data tersebut?\033[0m");
        pilihan = pilihan_yn(53,22,82,22,56,23,84,23);
            if (pilihan == 0){
                found = 2;
                continue;
            } else {
                found = 2;
            }
        }
        fwrite(&adm, sizeof(adm), 1, temp); // Menulis data yang tidak dihapus ke file sementara
    }

    // Jika ditemukan, hapus file asli dan ganti dengan file sementara
    if (found == 0) {
        MessageBox(NULL, "ID TIDAK DITEMUKAN", "Peringatan",
        MB_OK | MB_ICONWARNING);
    } else if(found == 2) {
        MessageBox(NULL, "DATA TERHAPUS", "YEYYYYY",
            MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        clearArea(49,20,110,36);
        gotoxy(49,21);
        printf("\033[48;5;204m\033[38;5;223mApakah ada data yang ingin di hapus lagi?\033[0m");
        pilihan = pilihan_yn(53,22,82,22,56,23,84,23);
    }
    
    fclose(admin);
    fclose(temp);

    temp = fopen("Database/tempadmin.dat","rb");
    admin = fopen("Database/admin.dat","wb");
    while (fread(&adm, sizeof(adm),1,temp)){
        fwrite(&adm, sizeof(adm), 1, admin);
    }
    fclose(admin);
    fclose(temp); 
    } while(pilihan == 0);

    gotoxy(50,26 + i);
    printf("\033[48;5;204m\033[38;5;223mTekan tombol apa saja untuk kembali ke menu\033[0m");
    fclose(admin);
    fclose(temp);
}