DataPesanan data1[100];
Datalaporan laporan[100];
Datalaporan laporan2[100];
DataBoneka bonekaa;
DataAksesoris aksesorii;
DataPesanan pesanan;
int total1,total2;

void ProsesLaporanAksesoris(DataPesanan data1[], Datalaporan laporan[], int isi);
void BubbleSortByHargaTerendah(Datalaporan laporan[]);
void BacaDataPesanan(DataPesanan data1[], int *isi, int *total);
void ProsesLaporanBoneka(DataPesanan data1[], Datalaporan laporan[], int isi);
void TampilkanLaporanBoneka(Datalaporan laporan[], int total);
void TampilkanLaporanAksesori(Datalaporan laporan2[], int total);
void PanggilFungsiLaporan();

void BacaDataPesanan(DataPesanan data1[], int *isi, int *total) {
    FILE *Filepesanan = fopen("Database/Pesanan.dat", "rb");
    if (!Filepesanan) {
        printf("Gagal membuka file pesanan.\n");
        return;
    }
    while (fread(&pesanan, sizeof(pesanan), 1, Filepesanan) == 1) {
        if (pesanan.statusPembayaran) {
            data1[(*isi)++] = pesanan;
            *total += pesanan.harga;
        }
    }
    fclose(Filepesanan);
}

void ProsesLaporanBoneka(DataPesanan data1[], Datalaporan laporan[], int isi) {
    FILE *file = fopen("Database/StokBoneka.dat", "rb");
    if (!file) {
        printf("Gagal membuka file .\n");
        return;
    }
    for (i = 0; i < isi; i++){
        memset(&laporan[i], 0, sizeof(laporan[i]));
    }

    char *boneka[] = {"Beruang", "Kelinci", "Kucing"};
    for (int i = 0; i < 3; i++) {
        strcpy(laporan[i].nama, boneka[i]);
    }

    for (i = 0; i < isi; i++){
        for (int j = 0; j < 3; j++){
            if(strcmp(data1[i].nama,boneka[j]) == 0){
                laporan[i].jumlah++;
            }
        }
    }

    while (fread(&bonekaa, sizeof(bonekaa), 1, file) == 1){
        for (i = 0; i < isi; i++){
            if(data1[i].idJenis == bonekaa.id){
                int tempHarga = 0;
                if (data1[i].idSize == 0) {
                    tempHarga = bonekaa.hargaS;
                } else if (data1[i].idSize == 1) {
                    tempHarga = bonekaa.hargaM;
                } else if (data1[i].idSize == 2) {
                    tempHarga = bonekaa.hargaL;
                }
                
                laporan[i].TotalHarga += tempHarga;
            }
        }
    }

    total1 = 0;
    for (int i = 0; i < 3; i++) {
        total1 += laporan[i].TotalHarga;
    }

    fclose(file);
}

void ProsesLaporanAksesoris(DataPesanan data1[], Datalaporan laporan[], int isi) {
    FILE *file = fopen("Database/StokAksesoris.dat", "rb");
    if (!file) {
        printf("Gagal membuka file.\n");
        return;
    }
    for (i = 0; i < isi; i++){
        memset(&laporan[i], 0, sizeof(laporan[i]));
    }

    char *aksesoris[] = {"Topi", "Pita", "Kumis"};
    for (int i = 0; i < 3; i++) {
        strcpy(laporan2[i].nama, aksesoris[i]);
    }
    
    for (i = 0; i < isi; i++){
        for (int j = 0; j < 3; j++){
            if(strcmp(data1[i].aksesoris,aksesoris[j]) == 0){
                laporan2[i].jumlah++;
            }
        }
    }

    while (fread(&aksesorii, sizeof(aksesorii), 1, file) == 1){
        for (i = 0; i < isi; i++){
            if(data1[i].idJenis == aksesorii.id){
                int tempHarga = 0;
                if (data1[i].idSize == 0) {
                    tempHarga = aksesorii.hargaS;
                } else if (data1[i].idSize == 1) {
                    tempHarga = aksesorii.hargaM;
                } else if (data1[i].idSize == 2) {
                    tempHarga = aksesorii.hargaL;
                }
                
                laporan2[i].TotalHarga += tempHarga;
            }
        }
    }
    total2 = 0;
    for (int i = 0; i < 3; i++) {
        total2 += laporan2[i].TotalHarga;
    }
    fclose(file);
}

void BubbleSortByHargaTerendah(Datalaporan laporan[]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (laporan[j].TotalHarga > laporan[j + 1].TotalHarga) {
                Datalaporan temp = laporan[j];
                laporan[j] = laporan[j + 1];
                laporan[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (laporan2[j].TotalHarga > laporan2[j + 1].TotalHarga) {
                Datalaporan temp = laporan2[j];
                laporan2[j] = laporan2[j + 1];
                laporan2[j + 1] = temp;
            }
        }
    }
}

void TampilkanLaporanBoneka(Datalaporan laporan[], int total) {
    gotoxy(47, 14); printf("\033[38;5;223;48;5;204m ===== Data Laporan Boneka =====\033[0m\n");
    gotoxy(47, 15); printf("\033[38;5;223;48;5;204m|--------|--------------|------------|----------------|\033[0m\n");
    gotoxy(47, 16); printf("\033[38;5;223;48;5;204m| %-6s | %-10s | %-10s | %-14s |\033[0m\n", "No", "Jenis Boneka", "Terjual", "Total Harga");
    gotoxy(47, 17); printf("\033[38;5;223;48;5;204m|--------|--------------|------------|----------------|\033[0m\n");
    int row = 18;
    for (int i = 0; i < 3; i++){
        gotoxy(47, row++);
        printf("\033[38;5;223;48;5;204m| %-6d | %-12s | %-10d | Rp.%-11d |\033[0m\n",
        i + 1, laporan[i].nama, laporan[i].jumlah,laporan[i].TotalHarga);
        gotoxy(47, row++); printf("\033[38;5;223;48;5;204m|--------|--------------|------------|----------------|\033[0m\n");
    }
    gotoxy(47, row++); printf("\033[38;5;223;48;5;204m|         Total Harga Boneka         | Rp.%d           |\033[0m\n",total1);
    gotoxy(47, row); printf("\033[38;5;223;48;5;204m|------------------------------------|----------------|\033[0m\n");

    // gotoxy(47, 29); printf("\033[38;5;223;48;5;204m======================Detail Laporan======================\033[0m\n");
    // for (int i = 1; i <= 3; i++) {
    //     gotoxy(47, 25 + (i * 6));
    //     printf("\033[38;5;223;48;5;204m< %s > \033[0m\n", laporan[i].boneka);
    //     gotoxy(47, 26 + (i * 6));
    //     printf("\033[38;5;223;48;5;204mJumlah %s yang terjual: %d\033[0m\n", laporan[i].boneka, laporan[i].jumlah);
    //     gotoxy(47, 27 + (i * 6));
    //     printf("\033[38;5;223;48;5;204mJumlah Topi yang terjual: %d\033[0m\n", laporan[i].topi);
    //     gotoxy(47, 28 + (i * 6));
    //     printf("\033[38;5;223;48;5;204mJumlah Kumis yang terjual: %d\033[0m\n", laporan[i].kumis);
    //     gotoxy(47, 29 + (i * 6));
    //     printf("\033[38;5;223;48;5;204mJumlah Pita yang terjual: %d\033[0m\n", laporan[i].pita);
    //     gotoxy(47, 30 + (i * 6));
    // }
}

void TampilkanLaporanAksesori(Datalaporan laporan2[], int total){
    gotoxy(47, 27); printf("\033[38;5;223;48;5;204m ===== Data Laporan Aksesoris =====\033[0m\n");
    gotoxy(47, 28); printf("\033[38;5;223;48;5;204m|--------|-----------------|------------|----------------|\033[0m\n");
    gotoxy(47, 29); printf("\033[38;5;223;48;5;204m| %-6s | %-10s | %-10s | %-14s |\033[0m\n", "No", "Jenis aksesoris", "Terjual", "Total Harga");
    gotoxy(47, 30); printf("\033[38;5;223;48;5;204m|--------|-----------------|------------|----------------|\033[0m\n");
    int row = 31;
    for (int i = 0; i < 3; i++){
        gotoxy(47, row++);
        printf("\033[38;5;223;48;5;204m| %-6d | %-15s | %-10d | Rp.%-11d |\033[0m\n",
        i + 1, laporan2[i].nama, laporan2[i].jumlah,laporan2[i].TotalHarga);
        gotoxy(47, row++); printf("\033[38;5;223;48;5;204m|--------|-----------------|------------|----------------|\033[0m\n");
    }
    gotoxy(47, row++); printf("\033[38;5;223;48;5;204m|          Total Harga Aksesoris        | Rp.%d            |\033[0m\n",total2);
    gotoxy(47, row); printf("\033[38;5;223;48;5;204m|---------------------------------------|----------------|\033[0m\n");
}

void PanggilFungsiLaporan() {
    int isi = 0;
    int total = 0;
    system("cls");
    border();
    if(role == 1){
        menuOwnerManajer(-1);
        displayLapMnj(-1);
    }else if (role == 2){
        menuOwnerAdmin(-1);
        displayLapAdmin(-1);
    }else{
    menuOwnerDisplay(-1);
    displayMenuLap(-1);}
    
    DrawFile(71, 2, "Design/laporanteks.txt");

    BacaDataPesanan(data1, &isi, &total);
    ProsesLaporanBoneka(data1, laporan, isi);
    ProsesLaporanAksesoris(data1, laporan2, isi);
    BubbleSortByHargaTerendah(laporan);
    TampilkanLaporanBoneka(laporan, total);
    TampilkanLaporanAksesori(laporan2, total);
}