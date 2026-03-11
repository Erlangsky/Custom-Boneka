DataAksesoris Array1[100];

void isidata_aksesori();
void cekdata_aksesori();
void updateStokAksesoris();
void delete_aksesori();
void printTableHeader1();
void displayTableStok1();
void printTableRow1(DataAksesoris data, int currentRow);
void Aksesori();
void pilihJenisPembaruanAks(int *pilihan);
void displayPembaruanAks(int highlight);
void displayJnsAks (int choose1);
void displayAksesoris(int highlight);
// void displayToyImage1(int id);
#define MAX_AKSESORIS 100 

void displayAksesoris(int highlight) {
    int totalOptions = 5;
    char *menuOptions[] = {
        "   I N P U T   S T O K           ",
        "   C E K   S T O K               ",
        "   P E R B A R U I               ",
        "   H A P U S                     ",
        "   K E L U A R                   "
    };
    gotoxy(2, 26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   A K S E S O R I S\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalOptions; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOptions[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuOptions[i]); // Warna ungu untuk opsi biasa
        }
    }
}

void Aksesori(){
    int pilihan = 0;

    do {
        system ("cls");
        border();
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayAksesoris(pilihan);
        DrawFile(61, 3, "Design/aksesoristeks.txt");
        

        char ch = getch();  
            if (ch == 72) { 
                if (pilihan > 0) pilihan--;
            } else if (ch == 80) { 
                if (pilihan < 5 - 1) pilihan++;
            } else if (ch == 13) { 
            switch (pilihan) {
                case 0:
                    system("cls");
                    isidata_aksesori();
                    break;
                case 1:
                    system("cls");
                    cekdata_aksesori();
                    getch();
                    break;
                case 2:
                    system("cls");
                    updateStokAksesoris();
                    break;
                case 3:
                    system("cls");
                    delete_aksesori();
                    break;
                case 4:
                system("cls");
                    return;
            }
        }
    } while (1); 
}

void displayJnsAks(int choose1) {
    int totalJenis = 4;
    char *menuJenis[] = {
        "   T O P I                     ",
        "   P I T A                     ",
        "   K U M I S                   ",
        "   K E M B A L I               "
    };
    gotoxy(2, 32);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 33);
    printf("\033[48;5;204m\033[38;5;223mJ E N I S   A K S E S O R I S\033[0m");
    gotoxy(2, 34);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalJenis; i++) {
        gotoxy(2, 35 + i);
        if (i == choose1) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuJenis[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuJenis[i]); // Warna ungu untuk opsi biasa
        }
    }
}
void isidata_aksesori() {
    FILE *fileStokAksesoris = fopen("Database/StokAksesoris.dat", "ab"); 
    if (!fileStokAksesoris) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }int choose1 = 0;
    
    do {
        system("cls");
        border();
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
            menuOwnerDisplay(-1);
        }
        displayAksesoris(-1);
        displayJnsAks(choose1);
        DrawFile(61, 3, "Design/aksesoristeks.txt");
        

        char ch = getch();  
        if (ch == 72) { 
            if (choose1 > 0) choose1--;
        } else if (ch == 80) { 
            if (choose1 < 4 - 1) choose1++;
        } else if (ch == 13) { 
            if (choose1 == 3) {
                fclose(fileStokAksesoris);
                return;
            }

            DataAksesoris newData;

            switch (choose1) {
                case 0:
                    system("cls");
                    newData.id = 1; 
                    strcpy(newData.nama, "Topi");
                    break;
                case 1:
                    system("cls");
                    newData.id = 2; 
                    strcpy(newData.nama, "Pita");
                    break;
                case 2:
                    system("cls");
                    newData.id = 3; 
                    strcpy(newData.nama, "Kumis");
                    break;
                case 3:
                    system("cls");
                    return;
            }
            
            bool isDuplicate = false;
            FILE *readFile = fopen("Database/StokAksesoris.dat", "rb");
            if (!readFile) {
                MessageBox(NULL, "Error Membuka File", "GAGAL!",
                    MB_OK | MB_ICONWARNING);
                fclose(fileStokAksesoris);
                printf("\033[48;5;204m\033[38;5;223mTekan tombol apapun untuk kembali ke menu sebelumnya...\033[0m\n");
                getch();
                return;
            }

            DataAksesoris temp;
            while (fread(&temp, sizeof(DataAksesoris), 1, readFile)) {
                if (strcmp(temp.nama, newData.nama) == 0) {  
                    isDuplicate = true;
                    break;
                }
            }
            fclose(readFile);

            if (isDuplicate) {
                printf("\033[48;5;204m\033[38;5;223mID aksesoris sudah ada, coba pilih menu update atau delete apabila ingin mengedit stok.\033[0m\n");
                printf("\033[48;5;204m\033[38;5;223mTekan tombol apapun untuk kembali ke menu sebelumnya...\033[0m\n");
                getch();
                continue;
            }
            system("cls");
            border();
            menuOwnerDisplay(-1);
            displayAksesoris(-1);
            DrawFile(61, 3, "Design/aksesoristeks.txt");
            
            gotoxy(50, 15);
            printf("\033[48;5;204m\033[38;5;223mT O T A L   A K S E S O R I S (%s): \033[0m", newData.nama);
            while (scanf("%d", &newData.totalStok) != 1 || newData.totalStok < 0) {
                MessageBox(NULL, "MASUKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                while (getchar() != '\n'); 
            }
            do {
                gotoxy(50, 16);
                printf("\033[48;5;204m\033[38;5;223mStok Ukuran S %s: \033[0m", newData.nama);
                while (scanf("%d", &newData.stokS) != 1 || newData.stokS < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n'); 
                }
                gotoxy(50, 17);
                printf("\033[48;5;204m\033[38;5;223mStok Ukuran M %s: \033[0m", newData.nama);
                while (scanf("%d", &newData.stokM) != 1 || newData.stokM < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n'); 
                }
                gotoxy(50, 18);
                printf("\033[48;5;204m\033[38;5;223mStok Ukuran L %s: \033[0m", newData.nama);
                while (scanf("%d", &newData.stokL) != 1 || newData.stokL < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n'); 
                }
                if (newData.stokS + newData.stokM + newData.stokL != newData.totalStok) {
                    MessageBox(NULL, "TOTAL STOK TIDAK SESUAI! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                }
            } while (newData.stokS + newData.stokM + newData.stokL != newData.totalStok);
            gotoxy(50, 20);
            printf("D I S T R I B U S I   H A R G A :");
                gotoxy(50, 21);
                printf("Harga Aksesori %s Ukuran S : ", newData.nama);
                while (scanf("%d", &newData.hargaS) != 1 || newData.hargaS < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n'); 
                }
                gotoxy(50, 22);
                printf("Harga Aksesoris %s Ukuran M : ", newData.nama);
                while (scanf("%d", &newData.hargaM) != 1 || newData.hargaM < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n'); 
                }
                gotoxy(50, 23);
                printf("Harga Aksesoris %s Ukuran L : ", newData.nama);
                while (scanf("%d", &newData.hargaL) != 1 || newData.hargaL < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n'); 
                }

            fwrite(&newData, sizeof(DataAksesoris), 1, fileStokAksesoris);
            MessageBox(NULL, "DATA BERHASIL DISIMPAN! LAKUKAN PENGECEKAN TERLEBIH DAHULU SEBELUM INPUT DATA BARU!", "Horreee", MB_OK | MB_ICONINFORMATION);
            getch();
        }
    } while (1); 

    fclose(fileStokAksesoris);
}

void cekdata_aksesori() {
    DrawFile(85, 3, "Design/bonekateks.txt");
    border();
    if (role == 2){
        menuOwnerAdmin(-1);
    }else{
    menuOwnerDisplay(-1);}
    displayAksesoris(-1);
    FILE *CustomerData = fopen("Database/StokAksesoris.dat", "rb");
    if (!CustomerData) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }
    displayTableStok1();

    fclose(CustomerData);
}

// Fungsi Insertion Sort untuk mengurutkan data berdasarkan ID
void insertionSortByID(DataAksesoris arr[], int n) {
    for (int i = 1; i < n; i++) {
        DataAksesoris temp = arr[i];
        int j = i - 1;
        
        // Geser elemen yang lebih besar dari temp ke kanan
        while (j >= 0 && arr[j].id > temp.id) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printTableHeader1() {

    gotoxy(45, 14);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|------------|------------|\033[0m\n");
    gotoxy(45, 15);
    printf("\033[48;5;204m\033[38;5;223m| %-6s | %-10s | %-10s | %-10s | %-10s |\033[0m\n", "ID", "Nama", "Ukuran", "Total Stok", "Harga");
    gotoxy(45, 16);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|------------|------------|\033[0m\n");
}
void printTableRow1(DataAksesoris data, int currentRow) {
    char buffer1[50], buffer2[50],buffer3[50];
    // Baris pertama: data untuk ukuran S
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m| %-6d | %-10s | %-10s | %-10d | %-10s |\033[0m", data.id, data.nama, "S", data.stokS, formatNumber(data.hargaS,buffer1));

    // Garis pembatas untuk ukuran S ke M
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|        |            |------------|------------|------------|\033[0m");

    // Baris kedua: data untuk ukuran M
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|        |            | %-10s | %-10d | %-10s |\033[0m", "M", data.stokM, formatNumber(data.hargaM,buffer2));

    // Garis pembatas untuk ukuran M ke L
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|        |            |------------|------------|------------|\033[0m");

    // Baris ketiga: data untuk ukuran L
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|        |            | %-10s | %-10d | %-10s |\033[0m", "L", data.stokL, formatNumber(data.hargaL,buffer3));

    // Garis akhir
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|------------|------------|\033[0m");
}

void displayTableStok1() {
    FILE *CustomerData = fopen("Database/StokAksesoris.dat", "rb");
    if (!CustomerData) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
        MB_OK | MB_ICONWARNING);
        return;
    }

    DataAksesoris data[MAX_AKSESORIS]; // Array untuk menyimpan data dari file
    int count = 0;

    // Membaca data dari file ke dalam array
    while (fread(&data[count], sizeof(DataAksesoris), 1, CustomerData)) {
        count++;
    }
    fclose(CustomerData);

    // Urutkan data berdasarkan ID menggunakan insertion sort
    insertionSortByID(data, count);

    // Tampilkan tabel setelah data diurutkan
    printTableHeader1();
    int currentRow = 17;
    for (int i = 0; i < count; i++) {
        printTableRow1(data[i], currentRow);
        currentRow += 6;
    }
}
void displayPembaruanAks(int highlight) {
    int totalPilihan = 3;
    char *menuPembaruan[] = {
        "   S T O K                          ",
        "   H A R G A                        ",
        "   S T O K   D A N   H A R G A      ",
    };

    gotoxy(2, 34);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 35);
    printf("\033[48;5;204m\033[38;5;223mP E M B A R U A N\033[0m");
    gotoxy(2, 36);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalPilihan; i++) {
        gotoxy(2, 37 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuPembaruan[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuPembaruan[i]); // Warna ungu untuk opsi biasa
        }
    }
}

void pilihJenisPembaruanAks(int *pilihan) {
    int totalPilihan = 3;
    char *menuPembaruan[] = {
        "   S T O K                        ",
        "   H A R G A                      ",
        "   S T O K   D A N   H A R G A    ",
        
    };
    
    int highlight = 0;
    do {
        system("cls");
        border();
        DrawFile(61, 3, "Design/aksesoristeks.txt");
        
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayTableStok1();
        displayAksesoris(-1);
        displayPembaruanAks(highlight);
        char ch = getch();  
        if (ch == 72) { 
            if (highlight > 0) highlight--;
        } else if (ch == 80) { 
            if (highlight < totalPilihan - 1) highlight++;
        } else if (ch == 13) { 
            *pilihan = highlight + 1;
            return;
        }
    } while (1);
}

void updateStokAksesoris() {
    int pilihan = 0;
    pilihJenisPembaruanAks(&pilihan);
    int stokSBaru, hargaSBaru;
    int stokMBaru, hargaMBaru;
    int stokLBaru, hargaLBaru;
    FILE *fileStokAksesoris = fopen("Database/StokAksesoris.dat", "rb");
    FILE *NewFile = fopen("Database/NewFile.dat", "wb");

    if (!fileStokAksesoris || !NewFile) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
        MB_OK | MB_ICONWARNING);
        return;
    }

    int idUpdate;
    bool found = false;
    gotoxy(45,13);
    printf("\033[48;5;204m\033[38;5;223mInput ID Aksesoris yang ingin diupdate: \033[0m");
    scanf("%d", &idUpdate);

    DataAksesoris dataBaru;

    while (fread(&dataBaru, sizeof(DataAksesoris), 1, fileStokAksesoris) == 1) {
        if (dataBaru.id == idUpdate && !found) {
            MessageBox(NULL, "ID STOK DITEMUKAN!", "Horreee", MB_OK | MB_ICONINFORMATION);
            found = true;
            system("cls");
            border();
            DrawFile(61, 3, "Design/aksesoristeks.txt");
            
            displayPembaruanAks(-1);
            if (role == 2){
                menuOwnerAdmin(-1);
            } else {
                menuOwnerDisplay(-1);
            }
            char buffer3[50], buffer4[50], buffer5[50];
            displayAksesoris(-1);
            gotoxy(55,15);
            printf("\033[48;5;204m\033[38;5;223mID           : %d\033[0m\n", dataBaru.id);
            gotoxy(55,16);
            printf("\033[48;5;204m\033[38;5;223mNama         : %s\033[0m\n", dataBaru.nama);
            gotoxy(55,17);
            printf("\033[48;5;204m\033[38;5;223mHarga Ukuran S    : %-1sd\033[0m", formatNumber(dataBaru.hargaS, buffer3));
            gotoxy(85,17);
            printf("\033[48;5;204m\033[38;5;223mHarga Ukuran M    : %-1sd\033[0m", formatNumber(dataBaru.hargaM, buffer4));
            gotoxy(120,17);
            printf("\033[48;5;204m\033[38;5;223mHarga Ukuran L   : %-15s\033[0m", formatNumber(dataBaru.hargaL, buffer5));
            gotoxy(55,18);
            printf("\033[48;5;204m\033[38;5;223mStok Ukuran S     : %-15d\033[0m", dataBaru.stokS);
            gotoxy(85,18);
            printf("\033[48;5;204m\033[38;5;223mStok Ukuran M     : %-15d\033[0m", dataBaru.stokM);
            gotoxy(120,18);
            printf("\033[48;5;204m\033[38;5;223mStok Ukuran L    : %-15d\033[0m", dataBaru.stokL);

            if (pilihan == 1 || pilihan == 3){
                gotoxy(55,21);
                printf("\033[48;5;204m\033[38;5;223mInput jumlah stok ukuran S baru : \033[0m");
                scanf("%d", &stokSBaru);
                gotoxy(55,22);
                printf("\033[48;5;204m\033[38;5;223mInput jumlah stok ukuran M baru : \033[0m");
                scanf("%d", &stokMBaru);
                gotoxy(55,23);
                printf("\033[48;5;204m\033[38;5;223mInput jumlah stok ukuran L baru : \033[0m");
                scanf("%d", &stokLBaru);

                dataBaru.stokS = stokSBaru;
                dataBaru.stokM = stokMBaru;
                dataBaru.stokL = stokLBaru;
            }
            if (pilihan == 2 || pilihan == 3){
                gotoxy(55,25);
                printf("\033[48;5;204m\033[38;5;223mInput harga ukuran S Baru    : \033[0m");
                scanf("%d", &hargaSBaru);
                gotoxy(55,26);
                printf("\033[48;5;204m\033[38;5;223mInput harga ukuran M baru    : \033[0m");
                scanf("%d", &hargaMBaru);
                gotoxy(55,27);
                printf("\033[48;5;204m\033[38;5;223mInput harga ukuran L baru    : \033[0m");
                scanf("%d", &hargaLBaru);

                dataBaru.hargaS = hargaSBaru;
                dataBaru.hargaM = hargaMBaru;
                dataBaru.hargaL = hargaLBaru;
            }
        }
        fwrite(&dataBaru, sizeof(DataAksesoris), 1, NewFile);
    }
    fclose(fileStokAksesoris);
    fclose(NewFile);

    remove("Database/StokAksesoris.dat");
    rename("Database/NewFile.dat", "Database/StokAksesoris.dat");

    if (found) {
        MessageBox(NULL, "DATA BERHASIL DIPERBARUI!", "Horreee", 
        MB_OK | MB_ICONINFORMATION);
    } else {
        MessageBox(NULL, "ID TIDAK DITEMUKAN", "Peringatan", 
        MB_OK | MB_ICONWARNING);
    }
}

void delete_aksesori() {
    FILE *fileStokAksesoris = fopen("Database/StokAksesoris.dat", "rb");
    if (!fileStokAksesoris) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    int o = 0;
    while (fread(&Array1[o], sizeof(DataAksesoris), 1, fileStokAksesoris) == 1) {
        o++;
    }
    fclose(fileStokAksesoris);

    int idToDelete;
    border();
    DrawFile(61, 3, "Design/aksesoristeks.txt");

    if (role == 2) {
        menuOwnerAdmin(-1);
    } else {
        menuOwnerDisplay(-1);
    }
    displayAksesoris(-1);
    displayTableStok1(-1);
    gotoxy(45, 13);
    printf("\033[48;5;204m\033[38;5;223mMasukan ID Aksesoris yang Ingin dihapus:\033[0m");
    scanf("%d", &idToDelete);

    int found = 0;
    FILE *fileStokAksesorisWrite = fopen("Database/StokAksesoris.dat", "wb");
    if (!fileStokAksesorisWrite) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
        MB_OK | MB_ICONWARNING);
        return;
    }

    for (int i = 0; i < o; i++) {
        if (Array1[i].id == idToDelete) {
            Array1[i].stokS = 0;  // Mengosongkan jumlah S
            Array1[i].stokM = 0;  // Mengosongkan jumlah M
            Array1[i].stokL = 0;  // Mengosongkan jumlah L
            Array1[i].hargaS = 0.0;  // Mengosongkan harga S
            Array1[i].hargaM = 0.0;  // Mengosongkan harga M
            Array1[i].hargaL = 0.0;  // Mengosongkan harga L
            found = 1;
        }
        fwrite(&Array1[i], sizeof(DataAksesoris), 1, fileStokAksesorisWrite);
    }

    fclose(fileStokAksesorisWrite);
    if (found) {
        MessageBox(NULL, "DATA TERHAPUS", "YEYYYYY", 
        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        border();
        DrawFile(61, 3, "Design/aksesoristeks.txt");

        menuOwnerDisplay(-1);
        displayAksesoris(-1);
        displayTableStok1(-1);
    } else {
        MessageBox(NULL, "ID TIDAK DITEMUKAN", "Peringatan", 
        MB_OK | MB_ICONWARNING);
    }
    getch();
}