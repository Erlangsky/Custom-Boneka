DataBoneka Array[100];

void isidata();
void cekdata();
void updateStokBoneka();
void displayTableStok();
void delete_boneka();
void printTableHeader();
void printTableRow(DataBoneka data, int currentRow);
void Boneka();
void displayPembaruan(int highlight);
void displayMenu(int highlight);
void displayJnsBnk(int highlight);
void pilihJenisPembaruan(int *pilihan);


void displayMenu(int highlight) {
    int totalOptions = 5;
    char *menuOptions[] = {
        "   I N P U T   S T O K            ",
        "   C E K   S T O K                ",
        "   P E R B A R U I                ",
        "   H A P U S                      ",
        "   K E L U A R                    "
        
    };
    gotoxy(2, 26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   B O N E K A\033[0m");
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
void Boneka() {
    int pilihan = 0;
    
    do {
        system("cls");
        border();
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayMenu(pilihan);
        DrawFile(85, 3, "Design/bonekateks.txt");
        
        char ch = getch();  
            if (ch == 72) { 
                if (pilihan > 0) pilihan--;
            } else if (ch == 80) { 
                if (pilihan < 5 - 1) pilihan++;
            } else if (ch == 13) { 
            switch (pilihan) {
                case 0:
                    system("cls");
                    isidata();
                    break;
                case 1:
                    system("cls");
                    cekdata();
                    getch();
                    break;
                case 2:
                    system("cls");
                    updateStokBoneka();
                    break;
                case 3:
                    system("cls");
                    delete_boneka();
                    break;
                case 4:
                system("cls");
                    printf("Terima kasih! Keluar dari program.\n");
                    return;
            }
        }
    } while (1); 
}

void displayJnsBnk(int highlight) {
    int totalJenis = 4;
    char *menuJenis[] = {
        "   B E R U A N G                  ",
        "   K E L I N C I                  ",
        "   K U C I N G                    ",
        "   K E M B A L I                  "
    };
    gotoxy(2, 32);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 33);
    printf("\033[48;5;204m\033[38;5;223mJ E N I S   B O N E K A\033[0m");
    gotoxy(2, 34);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalJenis; i++) {
        gotoxy(2, 35 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuJenis[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuJenis[i]); // Warna ungu untuk opsi biasa
        }
    }
}

void isidata() {
    FILE *fileStokBoneka = fopen("Database/StokBoneka.dat", "ab"); 
    if (!fileStokBoneka) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }
    int choose1 = 0;
	
    do {
        system("cls");
        border();
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
            menuOwnerDisplay(-1);
        }
        displayMenu(-1);
        displayJnsBnk(choose1);
        DrawFile(85, 3, "Design/bonekateks.txt");

        int kodeBoneka;

        char ch = getch();  
        if (ch == 72) { 
            if (choose1 > 0) choose1--;
        } else if (ch == 80) { 
            if (choose1 < 4 - 1) choose1++;
        } else if (ch == 13) { 
            if (choose1 == 3) {
                fclose(fileStokBoneka);
                return;
            }
            DataBoneka newData;
            switch (choose1) {
                case 0:
                    system("cls");
                    newData.id = 1; 
                    strcpy(newData.nama, "Beruang");
                    break;
                case 1:
                    system("cls");
                    newData.id = 2; 
                    strcpy(newData.nama, "Kelinci");
                    break;
                case 2:
                    system("cls");
                    newData.id = 3; 
                    strcpy(newData.nama, "Kucing");
                    break;
                case 3:
                    system("cls");
                    return;
            }

            bool isDuplicate = false;
            FILE *readFile = fopen("Database/StokBoneka.dat", "rb");
            if (!readFile) {
                MessageBox(NULL, "Error Membuka File", "GAGAL!",
                    MB_OK | MB_ICONWARNING);
                fclose(fileStokBoneka);
                printf("\033[48;5;204m\033[38;5;223mTekan tombol apapun untuk kembali ke menu sebelumnya...\033[0m\n");
                getch();
                return;
            }

            DataBoneka temp;
            while (fread(&temp, sizeof(DataBoneka), 1, readFile)) {
                if (strcmp(temp.nama, newData.nama) == 0) {  
                    isDuplicate = true;
                    break;
                }
            }
            fclose(readFile);

            if (isDuplicate) {
                printf("\033[48;5;204m\033[38;5;223mID boneka sudah ada, coba pilih menu update atau delete apabila ingin mengedit stok.\033[0m\n");
                printf("\033[48;5;204m\033[38;5;223mTekan tombol apapun untuk kembali ke menu sebelumnya...\033[0m\n");
                getch();
                continue;
            }

            system("cls");
            border();
            menuOwnerDisplay(-1);
            displayMenu(-1);
            DrawFile(85, 3, "Design/bonekateks.txt");

            do {
                gotoxy(50, 15);
                printf("\033[48;5;204m\033[38;5;223mT O T A L   S T O K (%s) : \033[0m", newData.nama);
                while (scanf("%d", &newData.totalStok) != 1 || newData.totalStok < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n'); 
                }

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
            printf("\033[48;5;204m\033[38;5;223mD I S T R I B U S I   H A R G A :\033[0m");

            gotoxy(50, 21);
            printf("\033[48;5;204m\033[38;5;223mHarga Boneka %s Ukuran S: \033[0m", newData.nama);
            while (scanf("%d", &newData.hargaS) != 1 || newData.hargaS < 0) {
                MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                while (getchar() != '\n'); 
            }

            gotoxy(50, 22);
            printf("\033[48;5;204m\033[38;5;223mHarga Boneka %s Ukuran M: \033[0m", newData.nama);
            while (scanf("%d", &newData.hargaM) != 1 || newData.hargaM < 0) {
                MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                while (getchar() != '\n'); 
            }

            gotoxy(50, 23);
            printf("\033[48;5;204m\033[38;5;223mHarga Boneka %s Ukuran L: \033[0m", newData.nama);
            while (scanf("%d", &newData.hargaL) != 1 || newData.hargaL < 0) {
                MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                while (getchar() != '\n'); 
            }

            gotoxy(50, 25);
            printf("\033[48;5;204m\033[38;5;223mD I S T R I B U S I   S T O K   S :\033[0m");
            do {
                gotoxy(50, 26);
                printf("\033[48;5;204m\033[38;5;223mStok Ungu: \033[0m");
                while (scanf("%d", &newData.stokUnguS) != 1 || newData.stokUnguS < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                gotoxy(50, 27);
                printf("\033[48;5;204m\033[38;5;223mStok Pink: \033[0m");
                while (scanf("%d", &newData.stokPinkS) != 1 || newData.stokPinkS < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                gotoxy(50, 28);
                printf("\033[48;5;204m\033[38;5;223mStok Biru: \033[0m");
                while (scanf("%d", &newData.stokBiruS) != 1 || newData.stokBiruS < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                if (newData.stokUnguS + newData.stokPinkS + newData.stokBiruS != newData.stokS) {
                    MessageBox(NULL, "TOTAL STOK TIDAK SESUAI! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                }
            } while (newData.stokUnguS + newData.stokPinkS + newData.stokBiruS != newData.stokS);

            gotoxy(50, 30);
            printf("\033[48;5;204m\033[38;5;223mD I S T R I B U S I   S T O K   M :\033[0m");
            do {
                gotoxy(50, 31);
                printf("\033[48;5;204m\033[38;5;223mStok Ungu: \033[0m");
                while (scanf("%d", &newData.stokUnguM) != 1 || newData.stokUnguM < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                gotoxy(50, 32);
                printf("\033[48;5;204m\033[38;5;223mStok Pink: \033[0m");
                while (scanf("%d", &newData.stokPinkM) != 1 || newData.stokPinkM < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                gotoxy(50, 33);
                printf("\033[48;5;204m\033[38;5;223mStok Biru: \033[0m");
                while (scanf("%d", &newData.stokBiruM) != 1 || newData.stokBiruM < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                if (newData.stokUnguM + newData.stokPinkM + newData.stokBiruM != newData.stokM) {
                    MessageBox(NULL, "TOTAL STOK TIDAK SESUAI! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                }
            } while (newData.stokUnguM + newData.stokPinkM + newData.stokBiruM != newData.stokM);

            gotoxy(50, 35);
            printf("\033[48;5;204m\033[38;5;223mD I S T R I B U S I   S T O K   L :\033[0m");
            do {
                gotoxy(50, 36);
                printf("\033[48;5;204m\033[38;5;223mStok Ungu: \033[0m");
                while (scanf("%d", &newData.stokUnguL) != 1 || newData.stokUnguL < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                gotoxy(50, 37);
                printf("\033[48;5;204m\033[38;5;223mStok Pink: \033[0m");
                while (scanf("%d", &newData.stokPinkL) != 1 || newData.stokPinkL < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                gotoxy(50, 38);
                printf("\033[48;5;204m\033[38;5;223mStok Biru: \033[0m");
                while (scanf("%d", &newData.stokBiruL) != 1 || newData.stokBiruL < 0) {
                    MessageBox(NULL, "MASUKKAN INVALID! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                    while (getchar() != '\n');
                }

                if (newData.stokUnguL + newData.stokPinkL + newData.stokBiruL != newData.stokL) {
                    MessageBox(NULL, "TOTAL STOK TIDAK SESUAI! COBA LAGI!", "Peringatan", MB_OK | MB_ICONWARNING);
                }
            } while (newData.stokUnguL + newData.stokPinkL + newData.stokBiruL != newData.stokL);

            fwrite(&newData, sizeof(DataBoneka), 1, fileStokBoneka);
            MessageBox(NULL, "DATA BERHASIL DISIMPAN! LAKUKAN PENGECEKAN TERLEBIH DAHULU SEBELUM INPUT DATA BARU!", "Horreee", MB_OK | MB_ICONINFORMATION);

            getch();
        } 
    } while (1);
    fclose(fileStokBoneka);
}


void printTableRow(DataBoneka data, int currentRow) {
    char buffer1[50], buffer2[50], buffer3[50];
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m| %-6d | %-10s | %-10s | %-10d | %-10d | %-10d | %-10d | %-10s |\033[0m", 
           data.id, data.nama, "S", data.stokS, data.stokUnguS, data.stokPinkS, data.stokBiruS, formatNumber(data.hargaS, buffer1));
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|        |            |------------|------------|--------------------------------------|------------|\033[0m");
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|        |            | %-10s | %-10d | %-10d | %-10d | %-10d | %-10s |\033[0m", 
           "M", data.stokM, data.stokUnguM, data.stokPinkM, data.stokBiruM, formatNumber(data.hargaM,buffer2));
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|        |            |------------|------------|--------------------------------------|------------|\033[0m");
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|        |            | %-10s | %-10d | %-10d | %-10d | %-10d | %-10s |\033[0m", 
           "L", data.stokL, data.stokUnguL, data.stokPinkL, data.stokBiruL, formatNumber(data.hargaL,buffer3));
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|------------|--------------------------------------|------------|\033[0m");
}

void shellSortByID(DataBoneka arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            DataBoneka temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].id > temp.id; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printTableHeader() {
    gotoxy(45, 14);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|------------|--------------------------------------|------------|\033[0m\n");
    gotoxy(45, 15);
    printf("\033[48;5;204m\033[38;5;223m| %-6s | %-10s | %-10s | %-10s | %-36s | %-10s |\033[0m\n", "ID", "Nama", "Ukuran", "Total Stok", "Warna", "Harga");
    gotoxy(45, 16);
    printf("\033[48;5;204m\033[38;5;223m|        |            |            |            |--------------------------------------|            |\033[0m\n");
    gotoxy(45, 17);
    printf("\033[48;5;204m\033[38;5;223m|        |            |            |            | %-10s | %-10s | %-10s |            |\033[0m\n", "Ungu", "Pink", "Biru");
    gotoxy(45, 18);
    printf("\033[48;5;204m\033[38;5;223m|--------|------------|------------|------------|--------------------------------------|------------|\033[0m\n");
}
void cekdata() {
    border();
    DrawFile(85, 3, "Design/bonekateks.txt");
    
    if (role == 2){
        menuOwnerAdmin(-1);
    }else{
    menuOwnerDisplay(-1);}
    displayMenu(-1);
    FILE *CustomerData = fopen("Database/StokBoneka.dat", "rb");
    if (!CustomerData) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    displayTableStok();

    fclose(CustomerData);
}

void displayTableStok() {
    FILE *CustomerData = fopen("Database/StokBoneka.dat", "rb");
    if (!CustomerData) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    printTableHeader();

    DataBoneka data[100];  // Asumsi maksimal 100 data
    int count = 0;
    
    // Baca semua data ke dalam array
    while (fread(&data[count], sizeof(DataBoneka), 1, CustomerData)) {
        count++;
    }
    fclose(CustomerData); // Tutup file setelah membaca semua data

    // Mengurutkan data berdasarkan ID
    shellSortByID(data, count);

    int currentRow = 19; // Baris awal di bawah header
    for (int i = 0; i < count; i++) {
        printTableRow(data[i], currentRow);
        currentRow += 6; // Pindah ke baris berikutnya (setiap data memakan 6 baris)
    }
}

void displayPembaruan(int highlight) {
    int totalPilihan = 3;
    char *menuPembaruan[] = {
        "   S T O K                        ",
        "   H A R G A                      ",
        "   K E L U A R                    "
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
            printf("\033[48;5;223m\033[38;5;204m%s\033[0m\n", menuPembaruan[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuPembaruan[i]); // Warna ungu untuk opsi biasa
        }
    }
}

void pilihJenisPembaruan(int *pilihan) {
    int totalPilihan = 3;

    int highlight = 0;
    do {
        system("cls");
        border();
        DrawFile(85, 3, "Design/bonekateks.txt");
        
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayTableStok();
        displayMenu(-1);
        displayPembaruan(highlight);

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

void displayPembaruanBnk(int highlight) {
    int totalPilihan = 3;
    char *menuPembaruan[] = {
        "   B E R U A N G                  ",
        "   K U C I N G                    ",
        "   K E L I N C I                  "
    };
    gotoxy(2, 34);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(6, 35);
    printf("\033[48;5;204m\033[38;5;223mP E M B A R U A N   B O N E K A\033[0m");
    gotoxy(2, 36);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalPilihan; i++) {
        gotoxy(2, 37 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m%s\033[0m\n", menuPembaruan[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuPembaruan[i]); // Warna ungu untuk opsi biasa
        }
    }
}


void pilihJenisPembaruanBnk(int *pilihan) {
    int totalPilihan = 3;

    int highlight = 0;
    do {
        system("cls");
        border();
        DrawFile(85, 3, "Design/bonekateks.txt");
        
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayTableStok();
        displayMenu(-1);
        displayPembaruanBnk(highlight);

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


void displayPembaruanSz(int highlight) {
    int totalPilihan = 4;
    char *menuPembaruan[] = {
        "   S I Z E   S                    ",
        "   S I Z E   M                    ",
        "   S I Z E   L                    ",
        "   S E L U R U H   S I Z E        "
    };
    gotoxy(2, 34);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(7, 35);
    printf("\033[48;5;204m\033[38;5;223mP E M B A R U A N   S I Z E\033[0m");
    gotoxy(2, 36);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalPilihan; i++) {
        gotoxy(2, 37 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m%s\033[0m\n", menuPembaruan[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuPembaruan[i]); // Warna ungu untuk opsi biasa
        }
    }
}

void pilihJenisPembaruanSz(int *pilihan) {
    int totalPilihan = 4;

    int highlight = 0;
    do {
        clearArea(2,34,12,40);
        border();
        DrawFile(85, 3, "Design/bonekateks.txt");
        
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
        menuOwnerDisplay(-1);}
        // displayTableStok(-1);
        displayMenu(-1);
        displayPembaruanSz(highlight);

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


void displayPembaruanWrn(int highlight) {
    int totalPilihan = 4;
    char *menuPembaruan[] = {
        "   B I R U                        ",
        "   U N G U                        ",
        "   P I N K                        ",
        "   S E L U R U H   W A R N A       "
    };
    gotoxy(2, 34);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(7, 35);
    printf("\033[48;5;204m\033[38;5;223mP E M B A R U A N   S I Z E\033[0m");
    gotoxy(2, 36);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalPilihan; i++) {
        gotoxy(2, 37 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m%s\033[0m\n", menuPembaruan[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuPembaruan[i]); // Warna ungu untuk opsi biasa
        }
    }
}

void pilihJenisPembaruanWrn(int *pilihan) {
    int totalPilihan = 4;

    int highlight = 0;
    do {
        clearArea(2,34,12,40);
        border();
        DrawFile(85, 3, "Design/bonekateks.txt");
        
        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
        menuOwnerDisplay(-1);}
        // displayTableStok(-1);
        displayMenu(-1);
        displayPembaruanWrn(highlight);

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



void updateStokBoneka() {
    
    int mainPilihan = 0;
    pilihJenisPembaruan(&mainPilihan);
    
    int stokSBaru, hargaSBaru, stokUnguSBaru, stokPinkSBaru, stokBiruSBaru;
    int stokMBaru, hargaMBaru, stokUnguMBaru, stokPinkMBaru, stokBiruMBaru;
    int stokLBaru, hargaLBaru, stokUnguLBaru, stokPinkLBaru, stokBiruLBaru;
    FILE *fileStokBoneka = fopen("Database/StokBoneka.dat", "rb");
    FILE *tempFile = fopen("Database/tempFile.dat", "wb");

    if (!fileStokBoneka || !tempFile) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }
int bonekaPilihan = 0;
 
    bool found = false;
    pilihJenisPembaruanBnk(&bonekaPilihan);
    int idUpdate = bonekaPilihan;
    gotoxy(45, 13);
    // printf("Input ID boneka yang ingin diupdate: ");
    // scanf("%d", &idUpdate);

    DataBoneka dataBaru;

while (fread(&dataBaru, sizeof(DataBoneka), 1, fileStokBoneka) == 1) {

    if (dataBaru.id == idUpdate) {
        MessageBox(NULL, "ID STOK DITEMUKAN!", "Horreee", MB_OK | MB_ICONINFORMATION);
        found = true;
        system("cls");
        border();
        DrawFile(85, 3, "Design/bonekateks.txt");

        if (role == 2){
            menuOwnerAdmin(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayMenu(-1);
        char buffer1[50], buffer2[50], buffer3[50];

        gotoxy(55, 15);
        printf("\033[48;5;204m\033[38;5;223m ID           : %d \033[0m", dataBaru.id);
        
        gotoxy(55, 16);
        printf("\033[48;5;204m\033[38;5;223m Nama         : %s \033[0m", dataBaru.nama);
        
        gotoxy(55, 17);
        printf("\033[48;5;204m\033[38;5;223m Harga Ukuran S    : %-15s \033[0m", formatNumber(dataBaru.hargaS, buffer1));
        gotoxy(85, 17);
        printf("\033[48;5;204m\033[38;5;223m Harga Ukuran M    : %-15s \033[0m", formatNumber(dataBaru.hargaM, buffer2));
        gotoxy(120, 17);
        printf("\033[48;5;204m\033[38;5;223m Harga Ukuran L    : %-15s \033[0m", formatNumber(dataBaru.hargaL, buffer3));
        
        gotoxy(55, 18);
        printf("\033[48;5;204m\033[38;5;223m Stok Ukuran S     : %-15d \033[0m", dataBaru.stokS);
        gotoxy(85, 18);
        printf("\033[48;5;204m\033[38;5;223m Stok Ukuran M     : %-15d \033[0m", dataBaru.stokM);
        gotoxy(120, 18);
        printf("\033[48;5;204m\033[38;5;223m Stok Ukuran L     : %-15d \033[0m", dataBaru.stokL);
        
        gotoxy(55, 19);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Ungu S : %-15d \033[0m", dataBaru.stokUnguS);
        gotoxy(85, 19);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Ungu M : %-15d \033[0m", dataBaru.stokUnguM);
        gotoxy(120, 19);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Ungu L : %-15d \033[0m", dataBaru.stokUnguL);
        
        gotoxy(55, 20);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Pink S : %-15d \033[0m", dataBaru.stokPinkS);
        gotoxy(85, 20);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Pink M : %-15d \033[0m", dataBaru.stokPinkM);
        gotoxy(120, 20);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Pink L : %-15d \033[0m", dataBaru.stokPinkL);
        
        gotoxy(55, 21);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Biru S : %-15d \033[0m", dataBaru.stokBiruS);
        gotoxy(85, 21);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Biru M : %-15d \033[0m", dataBaru.stokBiruM);
        gotoxy(120, 21);
        printf("\033[48;5;204m\033[38;5;223m Stok Warna Biru L : %-15d \033[0m", dataBaru.stokBiruL);

if (mainPilihan == 1) {
    int pilihan1 = 0;
    int pilihan2 = 0;
  pilihJenisPembaruanSz(&pilihan1);
    pilihJenisPembaruanWrn(&pilihan2);  
    if (pilihan1 == 1 || pilihan1 == 2 || pilihan1 == 3 || pilihan1 == 4) {
        if (pilihan2 == 1) { // Warna Biru
            if (pilihan1 == 1) { // Ukuran S
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruS);
            } else if (pilihan1 == 2) { // Ukuran M
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruM);
            } else if (pilihan1 == 3) { // Ukuran L
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruL);
            } else if (pilihan1 == 4) { // Semua Ukuran
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruS);
                gotoxy(55, 25);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruM);
                gotoxy(55, 26);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruL);
            }
        } else if (pilihan2 == 2) { // Warna Ungu
            if (pilihan1 == 1) { // Ukuran S
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguS);
            } else if (pilihan1 == 2) { // Ukuran M
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguM);
            } else if (pilihan1 == 3) { // Ukuran L
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguL);
            } else if (pilihan1 == 4) { // Semua Ukuran
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguS);
                gotoxy(55, 25);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguM);
                gotoxy(55, 26);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguL);
            }
        } else if (pilihan2 == 3) { // Warna Pink
            if (pilihan1 == 1) { // Ukuran S
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkS);
            } else if (pilihan1 == 2) { // Ukuran M
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkM);
            } else if (pilihan1 == 3) { // Ukuran L
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkL);
            } else if (pilihan1 == 4) { // Semua Ukuran
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkS);
                gotoxy(55, 25);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkM);
                gotoxy(55, 26);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkL);
            }
        } else if (pilihan2 == 4) { // Semua Warna
            if (pilihan1 == 1) { // Ukuran S
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruS);
                gotoxy(55, 25);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguS);
                gotoxy(55, 26);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkS);
            } else if (pilihan1 == 2) { // Ukuran M
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruM);
                gotoxy(55, 25);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguM);
                gotoxy(55, 26);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkM);
            } else if (pilihan1 == 3) { // Ukuran L
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruL);
                gotoxy(55, 25);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguL);
                gotoxy(55, 26);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkL);
            } else if (pilihan1 == 4) { // Semua Ukuran dan Semua Warna
                gotoxy(55, 24);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruS);
                gotoxy(55, 25);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguS);
                gotoxy(55, 26);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (S) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkS);
                gotoxy(55, 27);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruM);
                gotoxy(55, 28);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguM);
                gotoxy(55, 29);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (M) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkM);
                gotoxy(55, 30);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna biru (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokBiruL);
                gotoxy(55, 31);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna ungu (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokUnguL);
                gotoxy(55, 32);
                printf("\x1b[38;5;223;48;5;204mInput jumlah stok warna pink (L) : \x1b[0m");
                scanf("%d", &dataBaru.stokPinkL);
            }
        }

        // Update total stok per ukuran
        dataBaru.stokS = dataBaru.stokBiruS + dataBaru.stokUnguS + dataBaru.stokPinkS;
        dataBaru.stokM = dataBaru.stokBiruM + dataBaru.stokUnguM + dataBaru.stokPinkM;
        dataBaru.stokL = dataBaru.stokBiruL + dataBaru.stokUnguL + dataBaru.stokPinkL;
    }
}
        
        else if (mainPilihan == 2) {
            gotoxy(55, 24);
            printf("\x1b[38;5;223;48;5;204mInput harga ukuran S baru: \x1b[0m");
            scanf("%d", &hargaSBaru);
            
            gotoxy(55, 25);
            printf("\x1b[38;5;223;48;5;204mInput harga ukuran M baru: \x1b[0m");
            scanf("%d", &hargaMBaru);
            
            gotoxy(55, 26);
            printf("\x1b[38;5;223;48;5;204mInput harga ukuran L baru: \x1b[0m");
            scanf("%d", &hargaLBaru);
        
            dataBaru.hargaS = hargaSBaru;
            dataBaru.hargaM = hargaMBaru;
            dataBaru.hargaL = hargaLBaru;
        }
        
        else if (mainPilihan == 3) {
            return;
        }
    }

    fwrite(&dataBaru, sizeof(DataBoneka), 1, tempFile);
}

fclose(fileStokBoneka);
fclose(tempFile);

remove("Database/StokBoneka.dat");
rename("Database/tempFile.dat", "Database/StokBoneka.dat");

if (found) {
    MessageBox(NULL, "DATA BERHASIL DIPERBARUI!", "Horreee", MB_OK | MB_ICONINFORMATION);
} else {
    MessageBox(NULL, "ID TIDAK DITEMUKAN", "Peringatan", MB_OK | MB_ICONWARNING);
}
}

void delete_boneka() {
    FILE *fileStokBoneka = fopen("Database/StokBoneka.dat", "rb");
    if (!fileStokBoneka) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    int o = 0;
    while (fread(&Array[o], sizeof(DataBoneka), 1, fileStokBoneka) == 1) {
        o++;
    }
    fclose(fileStokBoneka);

    int idToDelete;
    border();
    DrawFile(85, 3, "Design/bonekateks.txt");

    if (role == 2) {
        menuOwnerAdmin(-1);
    } else {
        menuOwnerDisplay(-1);
    }
    displayMenu(-1);
    displayTableStok(-1);
    gotoxy(45, 13);
    printf("\033[48;5;204m\033[38;5;223mMasukan ID Boneka yang Ingin dihapus:\033[0m");
    scanf("%d", &idToDelete);

    int found = 0;
    FILE *fileStokBonekaWrite = fopen("Database/StokBoneka.dat", "wb");
    if (!fileStokBonekaWrite) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    for (int i = 0; i < o; i++) {
        if (Array[i].id == idToDelete) {
            // Ubah data yang ingin dihapus menjadi 0 atau nilai lain yang menandakan "dihapus"
            Array[i].stokS = 0;  // Mengosongkan jumlah S
            Array[i].stokM = 0;  // Mengosongkan jumlah M
            Array[i].stokL = 0;  // Mengosongkan jumlah L
            Array[i].stokUnguS = 0;  // Mengosongkan jumlah ungu S
            Array[i].stokBiruS = 0;  // Mengosongkan jumlah biru S
            Array[i].stokPinkS = 0;  // Mengosongkan jumlah pink S
            Array[i].stokUnguM = 0;  // Mengosongkan jumlah ungu M
            Array[i].stokBiruM = 0;  // Mengosongkan jumlah biru M
            Array[i].stokPinkM = 0;  // Mengosongkan jumlah pink M
            Array[i].stokBiruL = 0;  // Mengosongkan jumlah ungu L
            Array[i].stokUnguL = 0;  // Mengosongkan jumlah biru L
            Array[i].stokPinkL = 0;  // Mengosongkan jumlah pink L
            Array[i].hargaS = 0.0;  // Mengosongkan harga S
            Array[i].hargaM = 0.0;  // Mengosongkan harga M
            Array[i].hargaL = 0.0;  // Mengosongkan harga L
            found = 1;
        }
        fwrite(&Array[i], sizeof(DataBoneka), 1, fileStokBonekaWrite);
    }

    fclose(fileStokBonekaWrite);
    if (found) {
        MessageBox(NULL, "DATA TERHAPUS", "YEYYYYY", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        border();
        DrawFile(85, 3, "Design/bonekateks.txt");

        if (role == 2) {
            menuOwnerAdmin(-1);
        } else {
            menuOwnerDisplay(-1);
        }
        displayMenu(-1);
        displayTableStok(-1);
    } else {
        MessageBox(NULL, "DATA TIDAK DITEMUKAN", "Peringatan", MB_OK | MB_ICONWARNING);
    }

    getch();
}