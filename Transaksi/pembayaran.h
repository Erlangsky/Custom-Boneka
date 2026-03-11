void tabelPembayaran();

void displayPembayaran(int highlight) {
    int totalOpsi = 3; // Total opsi di menu
    char *menuOpsi[] = {
        "   B A Y A R  P E S A N A N       ",
        "   D A T A   P E M B A Y A R A N  ",
        "   K E L U A R                    "
        
    };

    // Header Menu Pembayaran
    gotoxy(2, 26);
    printf("\033[38;5;223;48;5;204m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(7, 27);
    printf("\033[38;5;223;48;5;204mM E N U   P E M B A Y A R A N\033[0m");
    gotoxy(2, 28);
    printf("\033[38;5;223;48;5;204m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    // Menampilkan opsi menu
    for (int i = 0; i < totalOpsi; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223;38;5;204m %s \033[0m\n", menuOpsi[i]); // Highlight warna latar 204, teks 223
        } else {
            printf("\033[48;5;204;38;5;223m  %s\033[0m\n", menuOpsi[i]); // Warna teks 223, latar 204 untuk opsi biasa
        }
    }
}

void Pembayaran() {
    int pilihan = 0;

    do {
        system ("cls");
        border();
        if (role == 3){
            menuOwnerPelanggan(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayPembayaran(pilihan);
        DrawFile(63, 3, "Design/pembayaranteks.txt");
        

        char ch = getch();  // // Membaca satu karakter tanpa perlu menekan enter
            if (ch == 72) { // Panah atas
                if (pilihan > 0) pilihan--;
            } else if (ch == 80) { // Panah bawah
                if (pilihan < 5 - 1) pilihan++;
            } else if (ch == 13) { // Enter 
            switch (pilihan) {
                case 0:
                    system("cls");
                    membayar_pesanan();
                    break;
                case 1:
                    system("cls");
                    tabelPembayaran();
                    getch();
                    break;
                case 2:
                    system("cls");
                    return;
            }
        }
    } while (1); // looping terus sampe usernya milih keluar
}


void membayar_pesanan(){
    DataPesanan data;
    int pilihan;
    bool found = false;
    char confirm;
    int idBayar;
    char zonawaktu;
    char alamatDomisili[100];
    border();
    FILE *bacadata = fopen("Database/Pesanan.dat", "rb");
    if (!bacadata) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
        MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    FILE *tempPemesanan = fopen("Database/tempPemesanan.dat", "wb");
    if (!tempPemesanan) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
        MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        fclose(bacadata);
        return;
    }
    if (role == 3){
        menuOwnerPelanggan(-1);
    }else{
    menuOwnerDisplay(-1);}
        displayPembayaran(-1);
        DrawFile(63, 3, "Design/pembayaranteks.txt");
        
        baca_pesanan();
    gotoxy(47,14);
    printf("\033[48;5;204m\033[38;5;223mM A S U K K A N   I D : \033[0m");
    scanf("%d", &idBayar);

        
   while (fread(&data, sizeof(DataPesanan), 1, bacadata) == 1) {
        if (data.idPesanan == idBayar && data.statusPembayaran == false) {
            found = true;
            system("cls");
            border();
            menuOwnerDisplay(-1);
            displayPembayaran(-1);
            DrawFile(45, 2, "Design/pembayaranteks.txt");
    gotoxy(45, 14);        
    printf("\033[48;5;204m\033[38;5;223mNama Boneka     : %s\033[0m", data.nama);
    
    gotoxy(45, 15);
    printf("\033[48;5;204m\033[38;5;223mSize Boneka     : %s\033[0m", data.size);

    gotoxy(45, 16);
    printf("\033[48;5;204m\033[38;5;223mWarna Boneka    : %s\033[0m", data.warna);

    gotoxy(45, 17);
    printf("\033[48;5;204m\033[38;5;223mNama Aksesoris  : %s\033[0m", data.aksesoris);

    gotoxy(45, 18);
    printf("\033[48;5;204m\033[38;5;223mSize Aksesoris  : %s\033[0m", data.sizeAksesoris);

    gotoxy(45, 19);
    printf("\033[48;5;204m\033[38;5;223mZona Waktu      : %s\033[0m", data.zonawaktu);
    char buffer[50];
    gotoxy(45, 21);
    printf("\033[48;5;204m\033[38;5;223mTOTAL HARGA PESANAN ANDA ADALAH RP.%s\033[0m", formatNumber(data.harga,buffer));
            
    gotoxy(45, 23);
    printf("\033[48;5;204m\033[38;5;223mMasukkan alamat domisili Anda:\033[0m");

    while (getchar() != '\n'); // Membersihkan buffer input
    fgets(alamatDomisili, sizeof(alamatDomisili), stdin);
    alamatDomisili[strcspn(alamatDomisili, "\n")] = 0; // Hapus newline
    
    strcpy(data.alamat, alamatDomisili);

            gotoxy(45,25);
            printf("\033[48;5;204m\033[38;5;223mApakah Anda Yakin Ingin Membayar Pesanan Ini ? \033[0m");
            pilihan = pilihan_yn(65,27,97,27,67,28,99,28);

            

            if (pilihan == 0) {
                data.statusPembayaran = true; 
                MessageBox(NULL, "YIPPIEE!!! Pembayaran Berhasil!!!", "BERHASIL!!!",
                MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            /* bingung
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                printf("Pesanan dengan ID %d berhasil dibayar pada tanggal %02d/%02d/%04d\n", 
                       idBayar, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);*/
        
            // untuk estimasi pengiriman pesanan
            if (strcmp(data.zonawaktu, "WIB")){
                gotoxy(45,30);
                printf("\033[48;5;204m\033[38;5;223mEstimasi Pengiriman : 2 Minggu\033[0m\n");
                strcpy(data.estimasi, "2 Minggu");
            } else if (strcmp(data.zonawaktu, "WITA")){
                gotoxy(45,30);
                printf("\033[48;5;204m\033[38;5;223mEstimasi Pengiriman : 3 Minggu\033[0m\n");
                strcpy(data.estimasi, "3 Minggu");
            } else if (strcmp(data.zonawaktu, "WIT")){
                gotoxy(45,30);
                printf("\033[48;5;204m\033[38;5;223mEstimasi Pengiriman : 4 Minggu\033[0m\n");
                strcpy(data.estimasi, "4 Minggu");
            } else {
                MessageBox(NULL, "Zona Waktu Tidak Valid!", "GAGAL!",
                MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
            }
            } else {
                MessageBox(NULL, "KLIK OK^^ UNTUK KELUAR!!!", "KEMBALI KE MENU???",
                MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            }
            
        }else {
            MessageBox(NULL, "Input Tidak Valid!", "GAGAL!",
                MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        }
        fwrite(&data, sizeof(DataPesanan), 1, tempPemesanan); 
    }
    fclose(bacadata);
    fclose(tempPemesanan);

    remove("Database/Pesanan.dat");
    rename("Database/tempPemesanan.dat", "Database/Pesanan.dat");
}

void tabelPembayaran(){
    FILE *bacadataLagi = fopen("Database/Pesanan.dat", "rb");
    if (!bacadataLagi) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
        MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    FILE *bacadataLagi_aksesoris = fopen("Database/StokAksesoris.dat", "rb");
    if (!bacadataLagi_aksesoris) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
        MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        fclose(bacadataLagi);
        return;
    }

    system("cls");
    border();
    if (role == 3){
        menuOwnerPelanggan(-1);
    } else {
        menuOwnerDisplay(-1);
    }

    displayPembayaran(-1);
    DrawFile(63, 3, "Design/pembayaranteks.txt");
    

    gotoxy(47, 14);
    printf("\033[48;5;204m\033[38;5;223mL I S T   P E S A N A N :\033[0m");
    
    DataPesanan data;

    gotoxy(47, 16);
    printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m");
    gotoxy(47, 17);
    printf("\033[48;5;204m\033[38;5;223m| %-5s | %-10s | %-8s | %-8s | %-8s | %-8s | %-16s | %-24s | %-20s |\033[0m", 
           "ID", "Nama Boneka", "Size Boneka", "Warna Boneka", "Nama Aksesoris", "Size Aksesoris", "Harga", "Domisili", "Estimasi");
    gotoxy(47, 18);
    printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m");

    int baris = 19; // Baris awal untuk data

    while (fread(&data, sizeof(DataPesanan), 1, bacadataLagi)) {
        // Tambahkan kondisi untuk pelanggan
        if (role == 3 && data.simpan != idPelangganAktif) {
            continue; // Skip pesanan yang bukan milik pelanggan aktif
        }

        if (data.statusPembayaran) {
            char buffer1[50];
            gotoxy(47, baris);
            printf("\033[48;5;204m\033[38;5;223m| PBY%-2d | %-11s | %-11s | %-12s | %-14s | %-14s | %-16s | %-24s | %-20s |\033[0m", 
                   data.idPesanan,
                   data.nama, 
                   data.size, 
                   data.warna,
                   data.aksesoris,
                   data.sizeAksesoris,
                   formatNumber(data.harga,buffer1),
                   data.alamat,
                   data.estimasi);
            baris++; // Pindah ke baris berikutnya
            gotoxy(47, baris);
            printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m");
            baris++; // Pindah ke baris berikutnya
        }
    }

    fclose(bacadataLagi);
    fclose(bacadataLagi_aksesoris);
    getch();
}


