int idotomatis();
void Pemesanan();
void displayMenuSidebar(int highlight);
void updateStokAksesoris1(int idAksesoris, int idSize);
void updateStokBoneka1(int idBoneka, int idSize, int idWarna); 
void isidata_pesanan();
void tampil_harga_boneka(int pilihan);
void tampil_harga_aksesori(int pilihan);
void mengisi_alamat(DataPesanan *data);
void baca_pesanan();
void update_pesanan();
void delete_pesanan();
void membayar_pesanan();

//Validasi id otomatis mulai dari angka 1
int idotomatis() {
    FILE *idd;
    DataPesanan data;
    
    int IdTerakhir = 0;
    
    idd = fopen("Database/Pesanan.dat", "rb");
    if (idd == NULL) {
        return 1;
    }

    while (fread(&data, sizeof(data), 1, idd) == 1) {
        IdTerakhir = data.idPesanan; 
    }

    fclose(idd);
    return IdTerakhir + 1;
}

// Fungsi untuk memindahkan kursor

// Fungsi untuk menampilkan menu sidebar
// Fungsi untuk menampilkan menu sidebar dengan tampilan yang seragam
void displayMenuSidebar(int highlight) {
    char *menuOptions[] = {
        "   M E M E S A N   B O N E K A    ",
        "   L I S T   P E S A N A N        ",
        "   H A P U S   P E S A N A N      ",
        "   E X I T                        "
        
        
    };
    int totalOptions = 4;
    int i; // Deklarasi variabel `i`

    // Header Menu Utama
    gotoxy(2, 26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(7, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   P E M E S A N A N\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    // Menu Utama
    for (i = 0; i < totalOptions; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m %s \033[0m\n", menuOptions[i]); // Highlight
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuOptions[i]); // Warna teks
        }
    }
}

// void Masukid() {
//     if (cust.id <= 0) { // Validasi ID pelanggan
//         printf("Error: ID pelanggan tidak valid.\n");
//         return;
//     }
    
//     idCust = cust.id; // Menyimpan ID pelanggan aktif
//     printf("DEBUG: ID pelanggan aktif = %d\n", idCust);
// }
// Fungsi utama untuk menangani pemesanan
void Pemesanan() {
    int pilihan = 0;

    do {
        system("cls");
        border();
        if (role == 3){
            menuOwnerPelanggan(-1);
        }else{
        menuOwnerDisplay(-1);}
        displayMenuSidebar(pilihan);
        DrawFile(45, 2, "Design/pemesanan.txt");
        

        char ch = getch();
        if (ch == 72) { // Panah atas
            if (pilihan > 0) pilihan--;
        } else if (ch == 80) { // Panah bawah
            if (pilihan < 4 - 1) pilihan++;
        } else if (ch == 13) { // Enter
            switch (pilihan) {
                case 0:
                    system("cls");
                    isidata_pesanan();
                    break;
                case 1:
                    system("cls");
                    baca_pesanan();
                    break;
                case 2:
                    system("cls");
                    delete_pesanan();
                    break;
                case 3:
                    system("cls");
                    return;
            }
            getch(); // Menunggu pengguna menekan tombol
        }
    } while (1);
}


// void updateStokBoneka1(int idBoneka, int idSize, int idWarna) {
//     FILE *file = fopen("Database/StokBoneka.dat", "r+b");
//     if (!file) {
//         perror("Error membuka file StokBoneka.dat");
//         return;
//     }

//     DataBoneka boneka;
//     int found = 0;

//     // Baca file dan perbarui stok
//     while (fread(&boneka, sizeof(DataBoneka), 1, file)) {
//         if (boneka.id == idBoneka) {
//             found = 1;

//             // Update stok sesuai ukuran dan warna
//             switch (idSize) {
//                 case 1: // SMALL (S)
//                     if (idWarna == 1) boneka.stokUnguS--;
//                     else if (idWarna == 2) boneka.stokPinkS--;
//                     else if (idWarna == 3) boneka.stokBiruS--;
//                     break;
//                 case 2: // MEDIUM (M)
//                     if (idWarna == 1) boneka.stokUnguM--;
//                     else if (idWarna == 2) boneka.stokPinkM--;
//                     else if (idWarna == 3) boneka.stokBiruM--;
//                     break;
//                 case 3: // LARGE (L)
//                     if (idWarna == 1) boneka.stokUnguL--;
//                     else if (idWarna == 2) boneka.stokPinkL--;
//                     else if (idWarna == 3) boneka.stokBiruL--;
//                     break;
//             }

//             boneka.totalStok--;

//             // Tulis kembali ke file
//             fseek(file, -sizeof(DataBoneka), SEEK_CUR);
//             fwrite(&boneka, sizeof(DataBoneka), 1, file);
//             break;
//         }
//     }

//     fclose(file);

//     if (!found) {
//         printf("Error: Boneka dengan ID %d tidak ditemukan!\n", idBoneka);
//     }
// }



// Fungsi untuk memperbarui stok boneka
void updateStokBoneka1(int idJenis, int idSize, int idWarna) {
    FILE *file = fopen("Database/StokBoneka.dat", "rb+");
    if (!file) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    DataBoneka boneka;
    int found = 0;

    while (fread(&boneka, sizeof(DataBoneka), 1, file)) {
        if (boneka.id == idJenis) {
            found = 1;

            // Update stok sesuai ukuran dan warna
            switch (idSize) {
                case 0: // SMALL
                    if (idWarna == 0) boneka.stokUnguS--;
                    else if (idWarna == 1) boneka.stokPinkS--;
                    else if (idWarna == 2) boneka.stokBiruS--;
                    boneka.stokS--;
                    break;
                case 1: // MEDIUM
                    if (idWarna == 0) boneka.stokUnguM--;
                    else if (idWarna == 1) boneka.stokPinkM--;
                    else if (idWarna == 2) boneka.stokBiruM--;
                    boneka.stokM--;
                    break;
                case 2: // LARGE
                    if (idWarna == 0) boneka.stokUnguL--;
                    else if (idWarna == 1) boneka.stokPinkL--;
                    else if (idWarna == 2) boneka.stokBiruL--;
                    boneka.stokL--;
                    break;
            }

            boneka.totalStok--;

            // Tulis kembali ke file
            fseek(file, -sizeof(DataBoneka), SEEK_CUR);
            fwrite(&boneka, sizeof(DataBoneka), 1, file);
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("\033[48;5;204m\033[38;5;223mError: Boneka dengan ID %d tidak ditemukan!\033[0m\n", idJenis);
    }
}

// Fungsi untuk memperbarui stok aksesoris
void updateStokAksesoris1(int idAksesoris, int idSize) {
    FILE *file = fopen("Database/StokAksesoris.dat", "rb+");
    if (!file) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    DataAksesoris aksesori;
    int found = 0;

    while (fread(&aksesori, sizeof(DataAksesoris), 1, file)){
        if (aksesori.id == idAksesoris) {
            found = 1;

            // Update stok sesuai ukuran
            switch (idSize) {
                case 0: aksesori.stokS--; break; // SMALL
                case 1: aksesori.stokM--; break; // MEDIUM
                case 2: aksesori.stokL--; break; // LARGE
            }

            aksesori.totalStok--;

            // Tulis kembali ke file
            fseek(file, -sizeof(DataAksesoris), SEEK_CUR);
            fwrite(&aksesori, sizeof(DataAksesoris), 1, file);
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Error: Aksesoris dengan ID %d tidak ditemukan!\n", idAksesoris);
    }
}

// Fungsi untuk memasukkan data pesanan
void isidata_pesanan() {
    DataPesanan newData;

    DataBoneka boneka;
    DataAksesoris aksesori;
    newData.idPesanan = idotomatis(); // Fungsi untuk generate ID otomatis
    newData.statusPembayaran = false;
    newData.simpan = idPelangganAktif;
    char *zonawaktuindo[50];
    FILE *filePesanan = fopen("Database/Pesanan.dat", "ab");
    if (!filePesanan) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    FILE *fileStokBoneka = fopen("Database/StokBoneka.dat", "rb+");
    if (!fileStokBoneka) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        fclose(filePesanan);
        return;
    }

    FILE *fileStokAksesoris = fopen("Database/StokAksesoris.dat", "rb+");
    if (!fileStokAksesoris) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        fclose(filePesanan);
        fclose(fileStokBoneka);
        return;
    }

// Pilih Jenis Boneka
const char *menuJenis[] = {"Beruang", "Kelinci", "Kucing"};
int totalJenis = 3;
int choose1 = 0;

do {
    system("cls");
    border();
    displayMenuSidebar(-1);
    if (role == 3) {
        menuOwnerPelanggan(-1);
    } else {
        menuOwnerDisplay(-1);
    }
    DrawFile(45, 2, "Design/pemesanan.txt");

    gotoxy(41, 14);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    
    gotoxy(41, 15);
    printf("\033[48;5;204m\033[38;5;223m\t\t\t\t\t\t\tK U S T O M   B O N E K A - J E N I S\033[0m");

    gotoxy(41, 16);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");

    // Tampilkan menu jenis boneka
    for (int i = 0; i < totalJenis; i++) {
        gotoxy(42, 18 + i);
        if (i == choose1) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuJenis[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuJenis[i]);
        }
    }

    char ch = getch();
    if (ch == 72 && choose1 > 0) choose1--; // Panah atas
    else if (ch == 80 && choose1 < totalJenis - 1) choose1++; // Panah bawah
    else if (ch == 13) { // Enter
        newData.idJenis = choose1 + 1;
        strcpy(newData.nama, menuJenis[choose1]);

        // Cek stok boneka setelah pemilihan
        fseek(fileStokBoneka, (newData.idJenis - 1) * sizeof(DataBoneka), SEEK_SET);
        if (fread(&boneka, sizeof(DataBoneka), 1, fileStokBoneka) != 1) {
            printf("Gagal Membaca Data Boneka!!!\n");
            fclose(filePesanan);
            fclose(fileStokBoneka);
            fclose(fileStokAksesoris);
            return;
        }

        // Cek apakah stok tersedia
        if (boneka.totalStok <= 0) {
            MessageBox(NULL, "Stok untuk jenis boneka ini habis!!!", "PERINGATAN!!!", MB_OK | MB_ICONWARNING);
            continue; // Kembali ke menu pemilihan jenis boneka
        }
        break; // Keluar dari loop jika stok tersedia
    }
} while (1);
const char *menuSize[] = {"Small (S)", "Medium (M)", "Large (L)"};
int totalSize = 3;
int choose2 = 0;
int hargaB = 0;

do {
    system("cls");
    border();
    displayMenuSidebar(-1);
    if (role == 3) {
        menuOwnerPelanggan(-1);
    } else {
        menuOwnerDisplay(-1);
    }
    DrawFile(45, 2, "Design/pemesanan.txt");

    gotoxy(41, 14);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");

    gotoxy(41, 15);
    printf("\033[48;5;204m\033[38;5;223m\t\t\t\t\t\t\tK U S T O M   B O N E K A - S I Z E\033[0m");

    gotoxy(41, 16);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");

    // Tampilkan menu ukuran boneka
    for (int i = 0; i < totalSize; i++) {
        gotoxy(42, 18 + i);
        if (i == choose2) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuSize[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuSize[i]);
        }
    }

    char ch = getch();
    if (ch == 72 && choose2 > 0) choose2--; // Panah atas
    else if (ch == 80 && choose2 < totalSize - 1) choose2++; // Panah bawah
    else if (ch == 13) { // Enter
        newData.idSize = choose2;
        strcpy(newData.size, menuSize[choose2]);

        // Cek stok ukuran boneka setelah pemilihan
        rewind(fileStokBoneka); // Kembali ke awal file
        while (fread(&boneka, sizeof(DataBoneka), 1, fileStokBoneka)) {
            if (boneka.id == newData.idJenis) {
                break; // Temukan data boneka yang sesuai
            }
        }

        // Cek apakah stok ukuran boneka tersedia
        int stokCukup = 0;
        if (choose2 == 0) { // Small
            stokCukup = boneka.stokS >= 1;
        } else if (choose2 == 1) { // Medium
            stokCukup = boneka.stokM >= 0;
        } else if (choose2 == 2) { // Large
            stokCukup = boneka.stokL >= 0;
        }

        if (!stokCukup) {
            MessageBox(NULL, "Stok untuk ukuran boneka ini tidak mencukupi!!!", "PERINGATAN!!!", MB_OK | MB_ICONWARNING);
            continue; // Kembali ke menu pemilihan ukuran boneka
        }

        // Set harga berdasarkan ukuran boneka
        if (choose2 == 0) hargaB = boneka.hargaS;
        else if (choose2 == 1) hargaB = boneka.hargaM;
        else if (choose2 == 2) hargaB = boneka.hargaL;

        break; // Keluar dari loop jika stok ukuran boneka tersedia
    }
} while (1);
    // Pilih Warna Boneka
    const char *menuWarna[] = {"Ungu", "Pink", "Biru"};
    int totalWarna = 3;
    int choose3 = 0;
    
    do {
        system("cls");
        border();
        displayMenuSidebar(-1);
        if (role == 3) {
            menuOwnerPelanggan(-1);
        } else {
            menuOwnerDisplay(-1);
        }
        DrawFile(45, 2, "Design/pemesanan.txt");
        
        gotoxy(41, 14);
        printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    
        gotoxy(41, 15);
        printf("\033[48;5;204m\033[38;5;223m\t\t\t\t\t\t\tK U S T O M   B O N E K A - W A R N A\033[0m");
    
        gotoxy(41, 16);
        printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    
        // Tampilkan menu warna boneka
        for (int i = 0; i < totalWarna; i++) {
            gotoxy(42, 18 + i);
            if (i == choose3) {
                printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuWarna[i]);
            } else {
                printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuWarna[i]);
            }
        }
    
        char ch = getch();
        if (ch == 72 && choose3 > 0) choose3--; // Panah atas
        else if (ch == 80 && choose3 < totalWarna - 1) choose3++; // Panah bawah
        else if (ch == 13) { // Enter
            newData.idWarna = choose3;
            strcpy(newData.warna, menuWarna[choose3]);
    
            // Cek stok warna setelah pemilihan
            fseek(fileStokBoneka, (newData.idJenis - 1) * sizeof(DataBoneka), SEEK_SET);
            if (fread(&boneka, sizeof(DataBoneka), 1, fileStokBoneka) != 1) {
                printf("Gagal Membaca Data Boneka!!!\n");
                fclose(filePesanan);
                fclose(fileStokBoneka);
                fclose(fileStokAksesoris);
                return;
            }
    
            // Cek apakah stok warna tersedia
            int stokCukup = 0;
            switch (choose3) {
                case 0: // Ungu
                    stokCukup = boneka.stokUnguS > 0 || boneka.stokUnguM > 0 || boneka.stokUnguL > 0;
                    break;
                case 1: // Pink
                    stokCukup = boneka.stokPinkS > 0 || boneka.stokPinkM > 0 || boneka.stokPinkL > 0;
                    break;
                case 2: // Biru
                    stokCukup = boneka.stokBiruS > 0 || boneka.stokBiruM > 0 || boneka.stokBiruL > 0;
                    break;
            }
    
            if (!stokCukup) {
                MessageBox(NULL, "Stok untuk warna ini tidak mencukupi!!!", "PERINGATAN!!!", MB_OK | MB_ICONWARNING);
                continue; // Kembali ke menu pemilihan warna
            }
            break; // Keluar dari loop jika stok warna tersedia
        }
    } while (1);

    // Pilih Aksesoris
    const char *menuAksesoris[] = {"Topi", "Pita", "Kumis", "Done"};
    int totalAksesoris = 4;
    int choose4 = 0;
    int hargaA = 0;

do {
    system("cls");
    border();
    displayMenuSidebar(-1);
    if (role == 3) {
        menuOwnerPelanggan(-1);
    } else {
        menuOwnerDisplay(-1);
    }
    DrawFile(45, 2, "Design/pemesanan.txt");
    
    gotoxy(41, 14);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");

    gotoxy(41, 15);
    printf("\033[48;5;204m\033[38;5;223m\t\t\t\t\t\t\tK U S T O M   B O N E K A - A K S E S O R I S\033[0m");

    gotoxy(41, 16);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");

    // Tampilkan menu aksesoris
    for (int i = 0; i < totalAksesoris; i++) {
        gotoxy(42, 18 + i);
        if (i == choose4) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuAksesoris[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuAksesoris[i]);
        }
    }

    char ch = getch();
    if (ch == 72 && choose4 > 0) choose4--; // Panah atas
    else if (ch == 80 && choose4 < totalAksesoris - 1) choose4++; // Panah bawah
    else if (ch == 13) { // Enter
        if (choose4 == 3) { // DONE
            newData.idAksesoris = -1;
            strcpy(newData.aksesoris, "-");
            strcpy(newData.sizeAksesoris, "-");
            break;
        } else {
            newData.idAksesoris = choose4 + 1;
            strcpy(newData.aksesoris, menuAksesoris[choose4]);

            // Cek stok aksesori setelah pemilihan
            fseek(fileStokAksesoris, (newData.idAksesoris - 1) * sizeof(DataAksesoris), SEEK_SET);
            if (fread(&aksesori, sizeof(DataAksesoris), 1, fileStokAksesoris) != 1) {
                printf("Gagal Membaca Data Aksesoris!!!\n");
                fclose(filePesanan);
                fclose(fileStokBoneka);
                fclose(fileStokAksesoris);
                return;
            }

            // Cek apakah stok aksesori tersedia
            if (aksesori.totalStok <= 0) {
                MessageBox(NULL, "Stok untuk aksesori ini habis!!!", "PERINGATAN!!!", MB_OK | MB_ICONWARNING);
                continue; // Kembali ke menu pemilihan aksesori
            }
            break; // Keluar dari loop jika stok aksesori tersedia
        }
    }
} while (1);
    // Pilih Ukuran Aksesoris
    if (newData.idAksesoris != -1) {
        const char *menuSizeAksesoris[] = {"Small (S)", "Medium (M)", "Large (L)"};
        int totalSizeAksesoris = 3;
        int choose5 = 0;
    
        do {
            system("cls");
            border();
            displayMenuSidebar(-1);
            if (role == 3) {
                menuOwnerPelanggan(-1);
            } else {
                menuOwnerDisplay(-1);
            }
            DrawFile(45, 2, "Design/pemesanan.txt");
            
            gotoxy(41, 14);
            printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
        
            gotoxy(41, 15);
            printf("\033[48;5;204m\033[38;5;223m\t\t\t\t\t\tK U S T O M   B O N E K A - S I Z E   A K S E S O R I S\033[0m");
        
            gotoxy(41, 16);
            printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
        
            // Tampilkan menu ukuran aksesoris
            for (int i = 0; i < totalSizeAksesoris; i++) {
                gotoxy(42, 18 + i);
                if (i == choose5) {
                    printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuSizeAksesoris[i]);
                } else {
                    printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuSizeAksesoris[i]);
                }
            }
    
            tampil_harga_aksesori(choose4);
            char ch = getch();
            if (ch == 72 && choose5 > 0) choose5--; // Panah atas
            else if (ch == 80 && choose5 < totalSizeAksesoris - 1) choose5++; // Panah bawah
            else if (ch == 13) { // Enter
                newData.idSizeAksesoris = choose5;
                strcpy(newData.sizeAksesoris, menuSizeAksesoris[choose5]);
    
                // Cek stok ukuran aksesori setelah pemilihan
                rewind(fileStokAksesoris); // Kembali ke awal file
                while (fread(&aksesori, sizeof(DataAksesoris), 1, fileStokAksesoris)) {
                    if (aksesori.id == newData.idAksesoris) {
                        break; // Temukan data aksesoris yang sesuai
                    }
                }
    
                // Cek apakah stok ukuran aksesori tersedia
                int stokCukup = 0;
                if (choose5 == 0) { // Small
                    stokCukup = aksesori.stokS > 0;
                } else if (choose5 == 1) { // Medium
                    stokCukup = aksesori.stokM > 0;
                } else if (choose5 == 2) { // Large
                    stokCukup = aksesori.stokL > 0;
                }
    
                if (!stokCukup) {
                    MessageBox(NULL, "Stok untuk ukuran aksesori ini tidak mencukupi!!!", "PERINGATAN!!!", MB_OK | MB_ICONWARNING);
                    continue; // Kembali ke menu pemilihan ukuran aksesori
                }
    
                // Set harga berdasarkan ukuran aksesoris
                if (choose5 == 0) hargaA = aksesori.hargaS;
                else if (choose5 == 1) hargaA = aksesori.hargaM;
                else if (choose5 == 2) hargaA = aksesori.hargaL;
    
                break; // Keluar dari loop jika stok ukuran aksesori tersedia
            }
        } while (1);
    }
    mengisi_alamat(&newData);
    // Hitung Total Harga
    int totHarga = hargaB + hargaA;
    newData.harga = totHarga;
    // newData.simpan = cust.id;
    // Simpan Data Pesanan
    fwrite(&newData, sizeof(DataPesanan), 1, filePesanan);

    // Update Stok Boneka
    updateStokBoneka1(newData.idJenis, newData.idSize, newData.idWarna);

    // Update Stok Aksesoris (jika ada)
    if (newData.idAksesoris != -1) {
        updateStokAksesoris1(newData.idAksesoris, newData.idSizeAksesoris);
    }
    MessageBox(NULL, "DATA PESANAN BERHASIL TERSIMPAN", "YEYYYYY",
    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    // Tutup File
    fclose(filePesanan);
    fclose(fileStokBoneka);
    fclose(fileStokAksesoris);
}
void tampil_harga_boneka(int pilihan){
    FILE *bonekas = fopen ("Database/StokBoneka.dat", "rb");
    DataBoneka boneka;
    if (bonekas == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }
    while (fread(&boneka,sizeof(DataBoneka),1,bonekas) == 1){
        if (pilihan == 0 && boneka.id == 1) {
            gotoxy(75,18);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaS);
            gotoxy(75,19);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaM);
            gotoxy(75,20);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaL);
        } else if (pilihan == 1 && boneka.id == 2) {
            gotoxy(75,18);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaS);
            gotoxy(75,19);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaM);
            gotoxy(75,20);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaL);
        } else if (pilihan == 2 && boneka.id == 3) {
            gotoxy(75,18);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaS);
            gotoxy(75,19);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaM);
            gotoxy(75,20);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", boneka.hargaL);
        }
    }
    fclose(bonekas);
}

void tampil_harga_aksesori(int pilihan){
    FILE *aksesoriss = fopen ("Database/StokAksesoris.dat", "rb");
    DataAksesoris aksesoris;
    if (aksesoriss == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }
    while (fread(&aksesoris,sizeof(DataAksesoris),1,aksesoriss) == 1){
        if (pilihan == 0 && aksesoris.id == 1) {
            gotoxy(75,18);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaS);
            gotoxy(75,19);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaM);
            gotoxy(75,20);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaL);
        } else if (pilihan == 1 && aksesoris.id == 2) {
            gotoxy(75,18);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaS);
            gotoxy(75,19);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaM);
            gotoxy(75,20);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaL);
        } else if (pilihan == 2 && aksesoris.id == 3) {
            gotoxy(75,18);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaS);
            gotoxy(75,19);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaM);
            gotoxy(75,20);
            printf("\033[38;5;223;48;5;204mRp %d\033[0m\n", aksesoris.hargaL);
        }
    }
    fclose(aksesoriss);
}
void mengisi_alamat(DataPesanan *data){
    const char *menuZonaWaktu[] = {"Waktu Indonesia Barat (WIB)  ","Waktu Indonesia Tengah (WITA)","Waktu Indonesia Timur (WIT)  "};
    int totalSizeAksesoris = 3;
    int choose6 = 0;

        do {
        system("cls");
        border();
        displayMenuSidebar(-1);
        if (role == 3){
            menuOwnerPelanggan(-1);
        }else{
        menuOwnerDisplay(-1);}
        DrawFile(45, 2, "Design/pemesanan.txt");
        
        gotoxy(41, 14);
        printf("\033[38;5;223;48;5;204m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");

        gotoxy(41, 15);
        printf("\033[38;5;223;48;5;204m\t\t\t\t\t\tK U S T O M   B O N E K A - Z O N A   W A K T U\033[0m");

        gotoxy(41, 16);
        printf("\033[38;5;223;48;5;204m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");

        for (int i = 0; i < totalSizeAksesoris; i++) {
            gotoxy(42, 18 + i);
            if (i == choose6) {
                printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuZonaWaktu[i]); // Highlight pink muda dengan teks hitam
            } else {
                printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menuZonaWaktu[i]); // Warna teks 223 dengan background 204
            }
        }

        char ch = getch();
        if (ch == 72 && choose6 > 0) {
            choose6--;
        } else if (ch == 80 && choose6 < totalSizeAksesoris - 1) {
            choose6++;
        } else if (ch == 13) {       
            // mengembalikan data zona waktu ke file
            strcpy(data->zonawaktu, menuZonaWaktu[choose6]);
            break;
        }
    } while (1);
}


void baca_pesanan() {
    FILE *bacadata = fopen("Database/Pesanan.dat", "rb");
    if (!bacadata) {
        MessageBox(NULL, "Error Membuka File Pesanan!", "GAGAL!", MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }
    border();
    DataPesanan data = {0};

    displayMenuSidebar(-1);
    if (role == 3) {
        menuOwnerPelanggan(-1);
    } else {
        menuOwnerDisplay(-1);
    }

    DrawFile(45, 2, "Design/pemesanan.txt");
    
    gotoxy(47, 16);
    printf("\033[38;5;223;48;5;204m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");

    gotoxy(47, 17);
    printf("\033[38;5;223;48;5;204m| %-2s | %-10s | %-8s | %-8s | %-8s | %-8s | %-29s | %-15s | %-24s |\033[0m\n", 
        "ID", "Nama Boneka", "Size Boneka", "Warna Boneka", "Nama Aksesoris", "Size Aksesoris", "Zona Waktu", "Harga", "Status Pembayaran");

    gotoxy(47, 18);
    printf("\033[38;5;223;48;5;204m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");

    int row = 19;
    while (fread(&data, sizeof(DataPesanan), 1, bacadata) == 1) {
        if (role == 3 && data.simpan != idPelangganAktif) {
            continue;
        }
        char buffer1[50];
        gotoxy(47, row++);
        printf("\033[38;5;223;48;5;204m| %-2d | %-11s | %-11s | %-12s | %-14s | %-14s | %-20s | %-15s | %-24s |\033[0m\n", 
            data.idPesanan,
            data.nama, 
            data.size, 
            data.warna,
            data.aksesoris,
            data.sizeAksesoris,
            data.zonawaktu,
            formatNumber(data.harga, buffer1),
            data.statusPembayaran ? "Terbayar" : "Belum Terbayar"
        );

        gotoxy(47, row++);
        printf("\033[38;5;223;48;5;204m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");
    }
    fclose(bacadata);
}


// void baca_pesanan() {
//     FILE *bacadata = fopen("Database/Pesanan.dat", "rb");
//     if (!bacadata) {
//         MessageBox(NULL, "Error Membuka File Pesanan!", "GAGAL!", MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
//         return;
//     }

//     DataPesanan data;
//     data.idCust = 0;
//     displayMenuSidebar(-1);

//     // Debug: Periksa role dan idPelangganAktif
//     printf("Debug: role = %d, idPelangganAktif = %d\n", role, idPelangganAktif);

//     // Role-based menu display
//     if (role == 3) {
//         data.idCust = idPelangganAktif;
//         menuOwnerPelanggan(-1);
//     } else {
//         menuOwnerDisplay(-1);
//     }

//     // Draw table header
//     DrawFile(45, 2, "Design/pemesanan.txt");
//     border();
//     gotoxy(47, 14);
//     printf("\033[38;5;165mD  A T A   P E S A N A N  :\033[0m\n");

//     gotoxy(47, 16);
//     printf("\033[38;5;165m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");

//     gotoxy(47, 17);
//     printf("\033[38;5;165m| %-2s | %-10s | %-8s | %-8s | %-8s | %-8s | %-29s | %-15s | %-24s |\033[0m\n", 
//         "ID", "Nama Boneka", "Size Boneka", "Warna Boneka", "Nama Aksesoris", "Size Aksesoris", "Zona Waktu", "Harga", "Status Pembayaran");

//     gotoxy(47, 18);
//     printf("\033[38;5;165m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");

//     // Display order data
//     int row = 19;
//     while (fread(&data, sizeof(data), 1, bacadata) == 1) {
//         // Debug: Periksa data yang dibaca
//         printf("Debug: data.idCust = %d, data.idPesanan = %d\n", data.idCust, data.idPesanan);

//         if (role == 3 && data.idCust != idPelangganAktif) {
//             continue; // Skip orders not belonging to the active customer
//         }

//         gotoxy(47, row++);
//         printf("\033[38;5;165m| %-2d | %-11s | %-11s | %-12s | %-14s | %-14s | %-20s | %-15d | %-24s |\033[0m\n", 
//             data.idPesanan,
//             data.nama, 
//             data.size, 
//             data.warna,
//             data.aksesoris,
//             data.sizeAksesoris,
//             data.zonawaktu,
//             data.harga,
//             data.statusPembayaran ? "Terbayar" : "Belum Terbayar"
//         );

//         gotoxy(47, row++);
//         printf("\033[38;5;165m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");
//     }

//     fclose(bacadata);

    // Wait for user input
//     gotoxy(47, row + 2);
//     printf("Tekan sembarang tombol untuk melanjutkan...");
//     getch();
// }

void tabelDoang(){
FILE *bacadata = fopen("Database/Pesanan.dat", "rb");
    if (!bacadata) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
        MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    FILE *bacadata_aksesoris = fopen("Database/StokAksesoris.dat", "rb");
    if (!bacadata_aksesoris) {
        MessageBox(NULL, "Error Membuka File!", "GAGAL!",
        MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }
    DataPesanan data;

    gotoxy(47, 16);
    printf("\033[38;5;165m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");

    gotoxy(47, 17);
    printf("\033[38;5;165m| %-2s | %-10s | %-8s | %-8s | %-8s | %-8s | %-29s | %-15s | %-24s |\033[0m\n", 
        "ID", "Nama Boneka", "Size Boneka", "Warna Boneka", "Nama Aksesoris", "Size Aksesoris", "Zona Waktu", "Harga", "Status Pembayaran");

    gotoxy(47, 18);
    printf("\033[38;5;165m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");

    int row = 19; // Untuk tracking posisi y-axis
    while (fread(&data, sizeof(data), 1, bacadata)) {
        char buffer[50];
        gotoxy(47, row++);
        printf("\033[38;5;165m| %-2d | %-11s | %-11s | %-12s | %-14s | %-14s | %-20s | %-15s | %-24s |\033[0m\n", 
            data.idPesanan,
            data.nama, 
            data.size, 
            data.warna,
            data.aksesoris,
            data.sizeAksesoris,
            data.zonawaktu,
            formatNumber(data.harga, buffer),
            data.idPesanan ? "Terbayar" : "Belum Terbayar"
        );
    gotoxy(47, row++);
    printf("\033[38;5;165m|----|-------------|-------------|--------------|----------------|----------------|-------------------------------|-----------------|--------------------------|\033[0m\n");
}

    
    fclose(bacadata);
}
void update_pesanan() {
    DataPesanan data;
    int idUpdate, pilihan;
    bool found = false;

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

printf("\033[48;5;204m\033[38;5;223mMasukkan ID pesanan yang ingin diupdate: \033[0m");
scanf("%d", &idUpdate);

while (fread(&data, sizeof(DataPesanan), 1, bacadata) == 1) {
    if (data.idPesanan == idUpdate) {
        found = true;

        printf("Data saat ini:\n");
        printf("\nNama Boneka :  %s\nSize Boneka : %s\nWarna Boneka  : %s\nNama Aksesoris  : %s\nSize Aksesoris  : %s\n",
               data.nama, data.size, data.warna, data.aksesoris, data.sizeAksesoris);

        printf("\nPilih data yang ingin diupdate:\n");
        printf("1. Nama Boneka\n");
        printf("2. Size Boneka\n");
        printf("3. Warna Boneka\n");
        printf("4. Nama Aksesoris\n");
        printf("5. Size Aksesoris\n");
        printf("Pilihan (1-5) : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Nama boneka baru (Beruang/Kelinci/Kucing) : ");
                scanf("%s", data.nama);
                break;
            case 2:
                printf("Size boneka baru (L/M/S) : ");
                scanf("%s", data.size);
                break;
            case 3:
                printf("Warna boneka baru (Ungu/Pink/Biru) : ");
                scanf("%s", data.warna);
                break;
            case 4:
                printf("Nama aksesoris baru (Topi/Pita/Kumis) : ");
                scanf("%s", data.aksesoris);
                break;
            case 5:
                printf("Size aksesoris baru (L/M/S) : ");
                scanf("%s", data.sizeAksesoris);
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    }
    fwrite(&data, sizeof(DataPesanan), 1, tempPemesanan);
}

fclose(bacadata);
fclose(tempPemesanan);

    if (found) {
        remove("Database/Pesanan.dat");
        rename("Database/tempPemesanan.dat", "Database/Pesanan.dat");
        printf("Data berhasil diperbarui.\n");
    } else {
        MessageBox(NULL, "ID TIDAK DITEMUKAN", "Peringatan",
            MB_OK | MB_ICONWARNING);
        remove("Database/tempPemesanan.dat");
    }
}
void delete_pesanan() {
    border();
    displayMenuSidebar(-1);
    if (role == 3){
        menuOwnerPelanggan(-1);
    }else{
        menuOwnerDisplay(-1);
    }
    DrawFile(45, 2, "Design/pemesanan.txt");
    
    DataPesanan data;
    bool found = false;
    int idDelete;
    char dummy;
    int pilihan;
    gotoxy(47,14);
    printf("\033[48;5;204m\033[38;5;223mM A S U K K A N   I D : \033[0m");
    scanf("%d", &idDelete);

    FILE *bacadata = fopen("Database/Pesanan.dat", "rb");
    if (!bacadata) {
        MessageBox(NULL, "Waduh!!! Tidak Ada File yang Tersimpan", "GAGAL!", MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }
    
    FILE *tempPemesanan = fopen("Database/tempPemesanan.dat", "wb");
    if (!tempPemesanan) {
        MessageBox(NULL, "Waduh!!! Tidak Dapat Membuat File Sementara", "GAGAL! Operasi Gagal!", MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        fclose(bacadata);
        return;
    }

    while (fread(&data, sizeof(DataPesanan), 1, bacadata) == 1) {
        if (data.idPesanan == idDelete) {
            found = true;
            gotoxy(55,24);
            printf("\033[48;5;204m\033[38;5;223mApakah anda yakin ingin menghapus pesanan tersebut?\033[0m");        
            pilihan = pilihan_yn(65,25,97,25,67,26,99,26);
            if (pilihan == 0){
                continue;
            }
        }
        fwrite(&data, sizeof(DataPesanan), 1, tempPemesanan); 
    }

    fclose(bacadata);
    fclose(tempPemesanan);

    if (found) {
        remove("Database/Pesanan.dat");
        rename("Database/tempPemesanan.dat", "Database/Pesanan.dat");
    }
}
