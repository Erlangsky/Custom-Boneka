// Fungsi Selection Sort berdasarkan harga
void selectionSortByHargaPesanan(DataPesanan arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].harga > arr[maxIndex].harga) { // Urutkan dari harga terbesar
                maxIndex = j;
            }
        }
        // Swap elemen
        if (maxIndex != i) {
            DataPesanan temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

// Fungsi membaca dan menampilkan pesanan dengan sorting berdasarkan harga
void baca_pesanan_mahal() {
    FILE *bacadata = fopen("Database/Pesanan.dat", "rb");
    if (!bacadata) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
                   MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    DataPesanan pesanan[100]; // Asumsi maksimal 100 data
    int count = 0;

    // Baca seluruh data dari file ke dalam array
    while (fread(&pesanan[count], sizeof(DataPesanan), 1, bacadata)) {
        count++;
    }
    fclose(bacadata);

    // Urutkan berdasarkan harga dari yang paling mahal
    selectionSortByHargaPesanan(pesanan, count);

    // Cetak header tabel
    printf("\nData Pesanan (diurutkan dari harga tertinggi):\n");
    printf("|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\n");
    printf("| %-2s | %-10s | %-8s | %-8s | %-8s | %-8s | %-29s | %-15s | %-24s |\n",
           "ID", "Nama Boneka", "Size Boneka", "Warna Boneka", "Nama Aksesoris",
           "Size Aksesoris", "Zona Waktu", "Harga", "Status Pembayaran");
    printf("|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\n");

    // Cetak data pesanan yang sudah diurutkan
    for (int i = 0; i < count; i++) {
        printf("| %-2d | %-11s | %-11s | %-12s | %-14s | %-14s | %-20s | %-15d | %-24s |\n",
               pesanan[i].idPesanan,
               pesanan[i].nama,
               pesanan[i].size,
               pesanan[i].warna,
               pesanan[i].aksesoris,
               pesanan[i].sizeAksesoris,
               pesanan[i].zonawaktu,
               pesanan[i].harga,
               pesanan[i].statusPembayaran ? "Terbayar" : "Belum Terbayar");
        printf("|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\n");
    }

    getch();
}


// Fungsi Selection Sort berdasarkan harga
void selectionSortByHargaPesanan2(DataPesanan arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // GUNAKAN minIndex UNTUK MENCARI HARGA TERMURAH
        for (int j = i + 1; j < n; j++) {
            if (arr[j].harga < arr[minIndex].harga) { // Cari harga TERENDAH
                minIndex = j;
            }
        }
        // Swap elemen jika ditemukan harga lebih kecil
        if (minIndex != i) {
            DataPesanan temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}


// Fungsi membaca dan menampilkan pesanan dengan sorting berdasarkan harga
void baca_pesanan_murah() {
    FILE *bacadata = fopen("Database/Pesanan.dat", "rb");
    if (!bacadata) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
                   MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    DataPesanan pesanan[100]; // Asumsi maksimal 100 data
    int count = 0;

    // Baca seluruh data dari file ke dalam array
    while (fread(&pesanan[count], sizeof(DataPesanan), 1, bacadata)) {
        count++;
    }
    fclose(bacadata);

    // Urutkan berdasarkan harga dari yang paling mahal
    selectionSortByHargaPesanan2(pesanan, count);

    // Cetak header tabel
    printf("\nData Pesanan (diurutkan dari harga tertinggi):\n");
    printf("|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\n");
    printf("| %-2s | %-10s | %-8s | %-8s | %-8s | %-8s | %-29s | %-15s | %-24s |\n",
           "ID", "Nama Boneka", "Size Boneka", "Warna Boneka", "Nama Aksesoris",
           "Size Aksesoris", "Zona Waktu", "Harga", "Status Pembayaran");
    printf("|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\n");

    // Cetak data pesanan yang sudah diurutkan
    for (int i = 0; i < count; i++) {
        printf("| %-2d | %-11s | %-11s | %-12s | %-14s | %-14s | %-20s | %-15d | %-24s |\n",
               pesanan[i].idPesanan,
               pesanan[i].nama,
               pesanan[i].size,
               pesanan[i].warna,
               pesanan[i].aksesoris,
               pesanan[i].sizeAksesoris,
               pesanan[i].zonawaktu,
               pesanan[i].harga,
               pesanan[i].statusPembayaran ? "Terbayar" : "Belum Terbayar");
        printf("|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\n");
    }

    getch();
}
