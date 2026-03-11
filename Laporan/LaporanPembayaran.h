// Fungsi Bubble Sort untuk mengurutkan berdasarkan harga (termahal ke termurah)
void bubbleSortByHarga(DataPesanan arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].harga < arr[j + 1].harga) { // Tukar jika harga lebih kecil
                DataPesanan temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk membaca pesanan dengan pembayaran yang sudah dilakukan & mengurutkan berdasarkan harga tertinggi
void tabelPembayaranMahal() {
    FILE *bacadataLagi = fopen("Database/Pesanan.dat", "rb");
    if (!bacadataLagi) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
                   MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }
    system("cls");
    menuOwnerAdmin(-1);
    if (role == 2){
        menuOwnerAdmin(-1);
        displayLapAdmin(-1);
    }else{
    menuOwnerDisplay(-1);
    displayMenuLap(-1);}
    border();
    DrawFile(71, 2, "Design/laporanteks.txt");
    
    DataPesanan pesanan[100]; // Asumsi maksimal 100 pesanan
    int count = 0;

    // Baca seluruh data dari file ke dalam array
    while (fread(&pesanan[count], sizeof(DataPesanan), 1, bacadataLagi)) {
        if (pesanan[count].statusPembayaran) { // Hanya ambil yang sudah terbayar
            count++;
        }
    }
    fclose(bacadataLagi);

    // Urutkan menggunakan Bubble Sort berdasarkan harga (termahal ke termurah)
    bubbleSortByHarga(pesanan, count);

    // Cetak tabel setelah sorting
    gotoxy(47,14);
    printf("\033[48;5;204m\033[38;5;223mData Pembayaran Kasar :\033[0m\n");
    gotoxy(47, 16);
    printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m");
    gotoxy(47, 17);
    printf("\033[48;5;204m\033[38;5;223m| %-5s | %-10s | %-8s | %-8s | %-8s | %-8s | %-16s | %-24s | %-20s |\033[0m",
           "ID", "Nama Boneka", "Size Boneka", "Warna Boneka", "Nama Aksesoris",
           "Size Aksesoris", "Harga", "Domisili", "Estimasi");
    gotoxy(47, 18);
    printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m");

    // Cetak data pesanan yang sudah diurutkan
    int baris = 19;
    for (int i = 0; i < count; i++) {
        gotoxy(47, baris);
        printf("\033[48;5;204m\033[38;5;223m| PBY%-2d | %-11s | %-11s | %-12s | %-14s | %-14s | %-16d | %-24s | %-20s |\033[0m\n",
               pesanan[i].idPesanan,
               pesanan[i].nama,
               pesanan[i].size,
               pesanan[i].warna,
               pesanan[i].aksesoris,
               pesanan[i].sizeAksesoris,
               pesanan[i].harga,
               pesanan[i].alamat,
               pesanan[i].estimasi);
               baris++; // Pindah ke baris berikutnya
               gotoxy(47, baris);
        printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m\n");
        baris++;
    }

    getch();
}


// Fungsi Bubble Sort untuk mengurutkan berdasarkan harga (termurah ke termahal)
void bubbleSortByHarga2(DataPesanan arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].harga > arr[j + 1].harga) { // Tukar jika harga lebih besar
                DataPesanan temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk membaca pesanan dengan pembayaran yang sudah dilakukan & mengurutkan berdasarkan harga termurah
void tabelPembayaranMurah() {
    FILE *bacadataLagi = fopen("Database/Pesanan.dat", "rb");
    if (!bacadataLagi) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
                   MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    DataPesanan pesanan[100]; // Asumsi maksimal 100 pesanan
    int count = 0;

    // Baca seluruh data dari file ke dalam array
    while (fread(&pesanan[count], sizeof(DataPesanan), 1, bacadataLagi)) {
        if (pesanan[count].statusPembayaran) { // Hanya ambil yang sudah terbayar
            count++;
        }
    }
    fclose(bacadataLagi);

    // Urutkan menggunakan Bubble Sort berdasarkan harga (termurah ke termahal)
    bubbleSortByHarga2(pesanan, count);

    // Cetak tabel setelah sorting
    printf("\033[48;5;204m\033[38;5;223m\nData Pesanan (Diurutkan dari harga termurah):\033[0m\n");
    printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m\n");
    printf("\033[48;5;204m\033[38;5;223m| %-5s | %-10s | %-8s | %-8s | %-8s | %-8s | %-16s | %-24s | %-20s |\033[0m\n",
           "ID", "Nama Boneka", "Size Boneka", "Warna Boneka", "Nama Aksesoris",
           "Size Aksesoris", "Harga", "Domisili", "Estimasi");
    printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m\n");

    // Cetak data pesanan yang sudah diurutkan
    for (int i = 0; i < count; i++) {
        printf("\033[48;5;204m\033[38;5;223m| PBY%-2d | %-11s | %-11s | %-12s | %-14s | %-14s | %-16d | %-24s | %-20s |\033[0m\n",
               pesanan[i].idPesanan,
               pesanan[i].nama,
               pesanan[i].size,
               pesanan[i].warna,
               pesanan[i].aksesoris,
               pesanan[i].sizeAksesoris,
               pesanan[i].harga,
               pesanan[i].alamat,
               pesanan[i].estimasi);
        printf("\033[48;5;204m\033[38;5;223m|-------|-------------|-------------|--------------|----------------|----------------|------------------|--------------------------|----------------------|\033[0m\n");
    }

    getch();
}
