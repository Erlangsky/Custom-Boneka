// Deklarasi Function
void inputCust();
void readCust();
void displayPelanggan(int highlight);
void displayPelangganAsli(int highlight);
void updateCust();
void deleteCust();
void Pelanggan();
void PelangganAsli();
int validasiTelp(const char *telepon);
void displayTableCust();
void printTableHeaderCust();
void printTableRowCust(int currentRow,int j);
void displayTableCustAsli();
void printTableRowCustAsli(customer cust, int currentRow);
void updatePelanggan(int *pilihan);
int arrayDataCustomer();
void displayDeletedRequests();

customer dataPelanggan[MAX_PELANGGAN];
customer data[100];

int arrayDataCustomer(){
    dataCust = fopen("Database/CRUDCust.dat", "rb");
    if (dataCust == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return 1;
    }

    i = 0;
    while(fread(&cust, sizeof(cust), 1, dataCust) == 1){
        data[i++] = cust;
    }
    
    return i;
    
    fclose(dataCust);
}

void displayPelanggan(int highlight){
    int totalOpsi = 5; 
    char *menuOpsi[] = {
        "   I N P U T   C U S T O M E R    ",
        "   C E K   D A T A                ",
        "   P E R B A R U I                ",
        "   H A P U S   D A T A            ",
        "   K E L U A R                    "
    };
    gotoxy(2,26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   P E L A N G G A N\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalOpsi; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s\033[0m\n", menuOpsi[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuOpsi[i]);
        }
    }
}

void displayPelangganAsli(int highlight){
    int totalOpsi = 4; 
    char *menuOpsi[] = {
        "   D E T A I L   P R O F I L    ",
        "   P E R B A R U I              ",
        "   H A P U S   D A T A          ",
        "   K E L U A R                  "
    };
    gotoxy(2,26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   P E L A N G G A N\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalOpsi; i++) {
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOpsi[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s \033[0m\n", menuOpsi[i]);
        }
    }
}

void Pelanggan() {
    int pilihan = 0;
    // Total opsi di menu
    // int msgResult;
    

    do {
        system("cls");
        border();
        menuOwnerDisplay(-1);
        displayPelanggan(pilihan);
        DrawFile(50, 3, "Design/pelangganteks.txt");
        
        
        char ch = getch();  // Membaca satu karakter tanpa perlu menekan enter
        if (ch == 72) { // Panah atas
            if (pilihan > 0) pilihan--;
        } else if (ch == 80) { // Panah bawah
            if (pilihan < 5 - 1) pilihan++;
        } else if (ch == 13) { // Enter
            switch (pilihan) {
                case 0: // Input Data Customer
                    system("cls");
                    inputCust();
                    break;
                case 1: // Cek Data Customer
                    system("cls");
                    readCust();
                    break;
                case 2: // Update Data Customer
                    system("cls");
                    updateCust();
                    break;
                case 3: // Delete Data Customer
                    system("cls");
                    deleteCust();
                    break;
                case 4:
                    system("cls");
                    return;
                default:
                    MessageBox(NULL, "PILIHAN TIDAK VALID!!!", "Coba Lagi Yaaaaa",
                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
            }
        }
    } while (1); // Looping terus sampai user memilih keluar
}


void PelangganAsli() {
    int pilihan = 0;
    // Total opsi di menu
    
    do {
        system("cls");
        border();
        menuOwnerPelanggan(-1);
        displayPelangganAsli(pilihan);
        DrawFile(50, 3, "Design/pelangganteks.txt");
        
        char ch = getch();  // Membaca satu karakter tanpa perlu menekan enter
        if (ch == 72) { // Panah atas
            if (pilihan > 0) pilihan--;
        } else if (ch == 80) { // Panah bawah
            if (pilihan < 5 - 1) pilihan++;
        } else if (ch == 13) { // Enter
            switch (pilihan) {
                case 0: // Input Data Customer
                    system("cls");
                    readCust();
                    break;
                case 1: // Update Data Customer
                    system("cls");
                    updateCust();
                    break;
                case 2: // Delete Data Customer
                    system("cls");
                    deleteCust();
                    break;
                case 3:
                    system("cls");
                    return;
                default:
                    MessageBox(NULL, "PILIHAN TIDAK VALID!!!", "Coba Lagi Yaaaaa",
                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
            }
        }
    } while (1); // Looping terus sampai user memilih keluar
}

// Validasi untuk ID otomatis mulai dari angka 1
int idOtomatisCustomer() {
    customer cust;
    int idTerakhir = 0;

    dataCust = fopen("Database/CRUDCust.dat", "rb");
    if (dataCust == NULL) {
        return 1;
    } while (fread(&cust, sizeof(cust), 1, dataCust) == 1) {
        idTerakhir = cust.id; 
    }
    fclose(dataCust);
    return idTerakhir + 1;
}


// Function untuk menginput data customer
void inputCust(){
    int pilihan;
    bool found;
    FILE *dataCust;
    customer cust;
    
    dataCust = fopen("Database/CRUDCust.dat", "a+b");
    if (dataCust == NULL){
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }
    cust.id = idOtomatisCustomer();

    do{
        system("cls");
        border();
        DrawFile(55,17,"Design/borderPel.txt");
        menuOwnerDisplay(-1);
        displayPelanggan(-1);
        DrawFile(50, 3, "Design/pelangganteks.txt");
        
        gotoxy(64,18);
        printf("\033[48;5;204m\033[38;5;223m%d\033[0m", cust.id);
        do{
            gotoxy(59, 21);
            scanGets(cust.nama, sizeof(cust.nama));
            if (strlen(cust.nama) == 0) {
                gotoxy(59,23);
                printf("\033[48;5;204m\033[38;5;223mNama tidak boleh kosong!\033[0m");
                Sleep(1000);
                clearArea(59,23,65,23);
            }
        } while (strlen(cust.nama) == 0);

        do {
        gotoxy(59,26);
        fgets(cust.telepon, sizeof(cust.telepon), stdin);
        cust.telepon[strcspn(cust.telepon, "\n")] = '\0';
        if (!validasiTelp(cust.telepon) == 0){
            gotoxy(59,28);
            printf("\033[48;5;204m\033[38;5;223mNomor tidak boleh kosong\033[0m");
            Sleep(1000);
            clearArea(59,28,84,28);
            clearArea(59,26,84,26);
        } else if (!validasiTelp(cust.telepon)) {
            gotoxy(59,28);
            printf("\033[48;5;204m\033[38;5;223mNomor telepon tidak valid.\033[0m\n");
            Sleep(1000);
            clearArea(59,28,84,28);
            clearArea(59,26,110,26);
        }
        } while (!validasiTelp(cust.telepon));
        do{
        gotoxy(59, 31);
        scanGets(cust.sandi, sizeof(cust.sandi));
        if (strlen(cust.sandi) == 0) {
            gotoxy(59,33);
            printf("\033[48;5;204m\033[38;5;223mSandi tidak boleh kosong!\033[0m");
            Sleep(1000);
            clearArea(59,33,100,33);
        }
        found = false;
        } while(strlen(cust.sandi) == 0);

        fwrite(&cust, sizeof(cust), 1, dataCust);
        
        gotoxy(82,34);
        printf("\033[48;5;204m\033[38;5;223mLoading\033[0m");
        loading(60,35);

        // clearArea(4,12,55,13);
        gotoxy(59,37);
        printf("\033[48;5;204m\033[38;5;223mData anda berhasil kami simpan !\033[0m");
        Sleep(1000);
        
        gotoxy(59,38);
        printf("\033[48;5;204m\033[38;5;223mApakah anda ingin memasukkan data lagi ?\033[0m");
        pilihan = pilihan_yn(65,39,97,39,67,40,99,40);
        printf("\n");
            if (pilihan == 0){
                found = true;
                cust.id++;
            } else if (pilihan == 1){
                found = false;
            }
    } while (found == true);
    fclose(dataCust);
    gotoxy(59,42);
    printf("\033[48;5;204m\033[38;5;223mTekan tombol apa saja untuk kembali ke menu\033[0m");
    fclose(dataCust);
}

// Function untuk membaca data customer
void  readCust() {
    border();
    DrawFile(50, 3, "Design/pelangganteks.txt"); // Menggambar antarmuka
    
    FILE *dataCust = fopen("Database/CRUDCust.dat", "rb");
    if (dataCust == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }
    if (role == 3){
        menuOwnerPelanggan(-1);
        displayPelangganAsli(-1);
        displayTableCustAsli();
        getch();
    }else{
    menuOwnerDisplay(-1);
    displayPelanggan(-1);

    displayTableCust(); // Menampilkan tabel data customer
    }
    fclose(dataCust);
}
void printTableHeaderCust() {
    gotoxy(45, 14);
    printf("\033[48;5;204m\033[38;5;223m--------------------------------------------------------------\033[0m\n");
    gotoxy(45, 15);
    printf("\033[48;5;204m\033[38;5;223m| %-4s | %-15s | %-15s | %-15s |\033[0m\n", "ID", "NAMA CUSTOMER", "NO TELEPON", "SANDI");
    gotoxy(45, 16);
    printf("\033[48;5;204m\033[38;5;223m--------------------------------------------------------------\033[0m\n");
}         

void printTableRowCust(int currentRow, int j) {
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m| %-4d | %-15s | %-15s | %-15s |\033[0m\n", 
            data[j].id, 
            data[j].nama, 
            data[j].telepon, 
            data[j].sandi);
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m--------------------------------------------------------------\033[0m\n");
}

void printTableRowCustAsli(customer cust, int currentRow) {
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m| %-4d | %-15s | %-15s | %-15s |\033[0m\n", 
           cust.id, 
           cust.nama, 
           cust.telepon, 
           cust.sandi);
    gotoxy(45, currentRow++);
    printf("\033[48;5;204m\033[38;5;223m--------------------------------------------------------------\033[0m\n");
}

void displayTableCustAsli() {
    FILE *dataCust = fopen("Database/CRUDCust.dat", "rb");
    if (dataCust == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }
    printTableHeaderCust(); 
    int currentRow = 17;
    int dataDitemukan = 0;
    while (fread(&cust, sizeof(cust), 1, dataCust)) {
        if (cust.id == idPelangganAktif) {
            printTableRowCustAsli(cust, currentRow);
            currentRow += 2;
            dataDitemukan = 1;
            break;
        } else if (role == 4) {
            printTableRowCustAsli(cust, currentRow);
            currentRow += 2;
            dataDitemukan = 1;
        }
    }
    fclose(dataCust);
    if (!dataDitemukan) {
        gotoxy(45, currentRow);
        printf("\033[48;5;204m\033[38;5;223m| %-50s |\033[0m\n", "Tidak ada data pelanggan yang sesuai!");
        gotoxy(45, currentRow + 1);
        printf("\033[48;5;204m\033[38;5;223m--------------------------------------------------------------\033[0m\n");
    }
}

void displayTableCust() {
    FILE *dataCust = fopen("Database/CRUDCust.dat", "rb");
    if (dataCust == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }
    bool found = false;
    int limit = arrayDataCustomer();
    int currentRow = 17;
    int currentPage = 0;
    const int dataPerPage = 5;
    int totalPages = (limit + dataPerPage - 1) / dataPerPage;
    printTableHeaderCust();
    while (!found) {
        clearArea(45, 17, 147, 28);
        int startIndex = currentPage * dataPerPage;
        int endIndex = (currentPage + 1) * dataPerPage < limit ? (currentPage + 1) * dataPerPage : limit;
        
        for (int i = startIndex; i < endIndex; i++) {
            printTableRowCust(currentRow, i);
            currentRow += 2;
        }
        
        gotoxy(45, currentRow);
        printf("\033[48;5;204m\033[38;5;223mHalaman %d dari %d\033[0m", currentPage + 1, totalPages);
        gotoxy(45, currentRow + 1);
        printf("\033[48;5;204m\033[38;5;223mTekan panah kiri untuk halaman sebelumnya, panah kanan untuk halaman berikutnya, Enter untuk keluar.\033[0m");
        currentRow = 17;
        char ch = getch();
        if (ch == 75) {
            if (currentPage > 0) currentPage--;
        } else if (ch == 77) {
            if (currentPage < totalPages - 1) currentPage++;
        } else if (ch == 13) {
            found = true;
        }
    }
    fclose(dataCust);
}
void updatePelanggan(int *pilihan){
    int totalPilihan = 3;
    char *menuUpdateBaru[] = {
        "   N A M A                        ",
        "   N O M O R   T E L P O N        ",
        "   S A N D I                      ",
        
    };
    int highlight = 0;
    do {
    system("cls");
    border();
    DrawFile(50, 3, "Design/pelangganteks.txt"); // Menggambar antarmuka
    
    if (role == 3){
        menuOwnerPelanggan(-1);
        displayPelangganAsli(-1);
        displayTableCustAsli();

    }else{
    menuOwnerDisplay(-1);
    displayPelanggan(-1);
    displayTableCust();
    }
        
    
    gotoxy(2, 34);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 35);
    printf("\033[48;5;204m\033[38;5;223mP E M B A R U A N\033[0m");
    gotoxy(2, 36);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalPilihan; i++) {
        gotoxy(2, 37 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuUpdateBaru[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s \033[0m\n", menuUpdateBaru[i]);
        }
    }

        
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

void updateCust() {
    char c[10];
    FILE *dataCust;
    FILE *tempCust;
    int pilihan = 0;
    
    do{
        updatePelanggan(&pilihan);
        bool found = false;
        int idUpdate;

        dataCust = fopen("Database/CRUDCust.dat", "rb");
        if(dataCust == NULL){
            MessageBox(NULL, "Waduh!!! Tidak ada file yang tersimpan!!!", "GAGAL UPDATE!",
                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            return;
        }

        tempCust = fopen("Database/tempCust.dat", "wb");
        if(tempCust == NULL){
            MessageBox(NULL, "Waduh!!! Tidak ada file yang tersimpan!!! ", "GAGAL UPDATE!",
                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            fclose(dataCust);
            return;
        }

        gotoxy(45,13);
        printf("\033[48;5;204m\033[38;5;223mMasukkan ID yang ingin di update: \033[0m");
        do{
            gotoxy(80,13);
            limitInput(c,3);
            idUpdate = atoi(c);
            if(idUpdate == 0){
                gotoxy(84,13);
                printf("\033[48;5;204m\033[38;5;223minputan tidak valid\033[0m");
                Sleep(500);
            }
            clearArea(80,13,84,13);
            clearArea(84,13,105,13);
        } while (idUpdate == 0);

        
        while (fread(&cust, sizeof(cust), 1, dataCust) == 1) {
            if (cust.id == idUpdate){
                found = true;
                system("cls");
                border();
                DrawFile(50, 3, "Design/pelangganteks.txt");
                
                if (role == 2){
                    menuOwnerPelanggan(-1);
                } else{
                menuOwnerDisplay(-1);
                displayPelanggan(-1);
                }    
                gotoxy(55,15);
                printf("\033[48;5;204m\033[38;5;223m|--------|------------|--------------|--------------|\033[0m\n");
                gotoxy(55,16);
                printf("\033[48;5;204m\033[38;5;223m| %-6s | %-10s | %-15s| %-15s |\033[0m\n", "ID", "Nama","Telepon", "Sandi");
                gotoxy(55,17);
                printf("\033[48;5;204m\033[38;5;223m|--------|------------|--------------|--------------|\033[0m\n");
                gotoxy(55,18);
                printf("\033[48;5;204m\033[38;5;223m| %-6d | %-10s | %-15s| %-15s |\033[0m", cust.id, cust.nama,cust.telepon, cust.sandi);
                gotoxy(55,19);
                printf("\033[48;5;204m\033[38;5;223m|--------|------------|--------------|--------------|\033[0m\n");

                if(pilihan == 1){
                    gotoxy(45,20);
                    printf("\033[48;5;204m\033[38;5;223mMasukkan Nama Baru : \033[0m\n");
                    gotoxy(67,20);
                    scanf(" %[^\n]", cust.nama);
                } else if(pilihan == 2){
                    gotoxy(45,20);
                    printf("\033[48;5;204m\033[38;5;223mMasukkan Nomor Telepon Baru : \033[0m\n");
                    gotoxy(77,20);
                    scanf("%s", cust.telepon);
                } else if(pilihan == 3){
                    gotoxy(45,20);
                    printf("\033[48;5;204m\033[38;5;223mMasukkan Kata Sandi Baru : \033[0m\n");
                    gotoxy(73,20);
                    scanf(" %[^\n]", cust.sandi);
                }
            }
            fwrite(&cust, sizeof(cust), 1, tempCust);
        }

        fclose(dataCust);
        fclose(tempCust);

        temp = fopen("Database/tempCust.dat","rb");
        dataCust = fopen("Database/CRUDCust.dat","wb");
        while (fread(&cust, sizeof(cust),1,temp)){
            fwrite(&cust, sizeof(cust), 1, dataCust);
        }
        fclose(temp);
        fclose(dataCust);
    } while(pilihan == 0);

    gotoxy(50,26 + i);
    printf("\033[48;5;204m\033[38;5;223mTekan tombol apa saja untuk kembali ke menu\033[0m");
}
// Function untuk menghapus data customer
void deleteCust() {
    FILE *dataCust;
    FILE *tempCust;
    FILE *hpsCust;
    char c[10];
    int idDelete;
    int pilihan;
    int found;
    do{
        found = 0;
        system("cls");
        border();

        
        if (role == 3) {
            // Jika pelanggan ingin menghapus akunnya sendiri (role == 3)
            menuOwnerPelanggan(-1);
            displayPelangganAsli(-1);
            DrawFile(50, 3, "Design/pelangganteks.txt"); // Menggambar antarmuka
            hpsCust = fopen("Database/hpsCust.dat", "wb");
            if (hpsCust == NULL) {
                MessageBox(NULL, "Error Membuka File", "GAGAL!",
                    MB_OK | MB_ICONWARNING);
                return;
            }

            gotoxy(45, 13);
            printf("\033[48;5;204m\033[38;5;223mMasukkan ID yang ingin dihapus: \033[0m\n");
            do{
                gotoxy(80,13);
                limitInput(c,3);
                id = atoi(c);
                if(id == 0){
                    gotoxy(84,13);
                    printf("\033[48;5;204m\033[38;5;223mInputan tidak valid\033[0m\n");
                    Sleep(500);
                }
                clearArea(80,13,84,13);
                clearArea(84,13,105,13);
            } while (id == 0);
            gotoxy(45, 14);
            printf("\033[48;5;204m\033[38;5;223mApakah Anda yakin ingin menghapus akun Anda?\033[0m\n");
            pilihan = pilihan_yn(53, 19, 82, 19, 56, 20, 84, 20);
            
            if (pilihan == 0) {
                fwrite(&idDelete, sizeof(idDelete), 1, hpsCust);
                fclose(hpsCust);
                MessageBox(NULL, "Permintaan Anda Telah Kami Kirim! \nAkun Akan Segera Dihapus Oleh Admin! \nSilahkan Log Out!", 
                        "BERHASIL!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                return;
            } else {
                fclose(hpsCust);
                return;
            }
        } else {
            // Jika admin ingin menghapus pelanggan (role != 3)
            menuOwnerAdmin(-1);
            DrawFile(69, 3, "Design/adminteks.txt");
            // displayTableCust();
            displayDeletedRequests();
            gotoxy(45, 13);
            printf("\033[48;5;204m\033[38;5;223mMasukkan ID pelanggan yang ingin dihapus: \033[0m\n");
            do{
                gotoxy(87,13);
                limitInput(c,3);
                idDelete = atoi(c);
                if(idDelete == 0){
                    gotoxy(91,13);
                    printf("\033[48;5;204m\033[38;5;223mInputan tidak valid\033[0m\n");
                    Sleep(500);
                }
                clearArea(87,13,91,13);
                clearArea(91,13,135,13);
            } while (idDelete == 0);

            dataCust = fopen("Database/CRUDCust.dat", "rb");
            if (dataCust == NULL) {
                MessageBox(NULL, "Error Membuka File", "GAGAL!",
                    MB_OK | MB_ICONWARNING);
                return;
            }

            tempCust = fopen("Database/tempCust.dat", "wb");
            if (tempCust == NULL) {
                MessageBox(NULL, "Error Membuka File", "GAGAL!",
                    MB_OK | MB_ICONWARNING);
                fclose(dataCust);
                return;
            }
            
            while (fread(&cust, sizeof(customer), 1, dataCust) == 1) {
                if (cust.id == idDelete) {
                    found = 1;
                    clearArea(43,12,145,30);
                    gotoxy(55, 15);
                    printf("\033[48;5;204m\033[38;5;223mApakah Anda yakin ingin menghapus data tersebut?\033[0m\n");
                    pilihan = pilihan_yn(63, 22, 92, 22, 66, 23, 94, 23);
                    if(pilihan == 0){
                        found = 2;
                        continue;
                    }else{
                        break;
                    }
                }
                fwrite(&cust, sizeof(customer), 1, tempCust);
            }
            
            fclose(dataCust);
            fclose(tempCust);

            temp = fopen("Database/tempCust.dat","rb");
            dataCust = fopen("Database/CRUDCust.dat","wb");
            while (fread(&cust, sizeof(cust),1,temp)){
                fwrite(&cust, sizeof(cust), 1, dataCust);
            }
            
            fclose(temp);
            fclose(dataCust);

            if (found == 2) {
                clearArea(55, 20, 110, 36);
                gotoxy(55, 21);
                printf("\033[48;5;204m\033[38;5;223mData pelanggan berhasil dihapus!\033[0m\n");
                MessageBox(NULL, "Data pelanggan berhasil dihapus!", "BERHASIL!",
                        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                   break; 
            }
        }
    } while (1);
}

void displayDeletedRequests() {
    FILE *hpsCust, *custData, *tempHpsCust;
    int id, validIDs[100], validCount = 0; // Buffer untuk ID yang masih valid
    int row = 17; // Posisi awal tampilan tabel
    bool found = false;

    hpsCust = fopen("Database/hpsCust.dat", "rb");

    gotoxy(150, 14);
    printf("\033[48;5;204m\033[38;5;223m==================================\033[0m");
    gotoxy(150, 15);
    printf("\033[48;5;204m\033[38;5;223m| I N B O X   H A P U S   A K U N |\033[0m");
    gotoxy(150, 16);
    printf("\033[48;5;204m\033[38;5;223m==================================\033[0m");

    if (hpsCust == NULL) {
        gotoxy(150, 17);
        printf("\033[48;5;204m\033[38;5;223m|   Tidak Ada Permintaan!         |\033[0m");
        gotoxy(150, 18);
        printf("\033[48;5;204m\033[38;5;223m==================================\033[0m");
        return;
    }

    // Baca semua ID dalam hpsCust.dat
    while (fread(&id, sizeof(int), 1, hpsCust) == 1) {
        // Periksa apakah ID masih ada di CRUDCust.dat
        custData = fopen("Database/CRUDCust.dat", "rb");
        if (custData != NULL) {
            customer cust;
            bool exists = false;
            while (fread(&cust, sizeof(customer), 1, custData) == 1) {
                if (cust.id == id) {
                    exists = true;
                    break;
                }
            }
            fclose(custData);

            // Simpan hanya jika ID masih ada di data pelanggan
            if (exists) {
                validIDs[validCount++] = id;
                found = true;
            }
        }
    }
    fclose(hpsCust);

    // Tulis ulang file hpsCust.dat hanya dengan ID yang masih valid
    tempHpsCust = fopen("Database/tempHpsCust.dat", "wb");
    for (int i = 0; i < validCount; i++) {
        fwrite(&validIDs[i], sizeof(int), 1, tempHpsCust);
    }
    fclose(tempHpsCust);

    // Ganti file lama dengan file baru yang sudah diperbarui
    tempHpsCust = fopen("Database/tempHpsCust.dat","rb");
    hpsCust = fopen("Database/hpsCust.dat","wb");
    while (fread(&cust, sizeof(cust),1,tempHpsCust)){
        fwrite(&cust, sizeof(cust), 1, hpsCust);
    }
    
    fclose(temp);
    fclose(dataCust);

    // Tampilkan daftar ID yang masih valid
    if (!found) {
        gotoxy(150, 17);
        printf("\033[48;5;204m\033[38;5;223m|   Tidak Ada Permintaan!         |\033[0m");
        gotoxy(150, 18);
        printf("\033[48;5;204m\033[38;5;223m==================================\033[0m");
    } else {
        for (int i = 0; i < validCount; i++) {
            gotoxy(150, row++);
            printf("\033[48;5;204m\033[38;5;223m|   ID    |         %d            |\033[0m", validIDs[i]);
            
            gotoxy(150, row++);
            printf("\033[48;5;204m\033[38;5;223m==================================\033[0m");
        }
        
    }
}

