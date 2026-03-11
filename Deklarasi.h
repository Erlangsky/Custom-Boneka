#include <stdio.h> //printf dan scanff
#include <conio.h> //getch
#include <windows.h> //massagebox = sleep
#include <unistd.h> //system interface = sleep
#include <stdlib.h> //managemen memori = atoy exit
#include <string.h> //mengambil data tsring = strcmp, strlen,strcpy
#include <time.h> //waktu
#include <stdbool.h> //untuk bolean
#include <ctype.h> //jenis char
#ifndef VALIDASI_NO_TELP_H
#define VALIDASI_NO_TELP_H
#define MAX_PHONE_LENGTH 13  // Maksimal panjang nomor telepon
#define MIN_PHONE_LENGTH 10  // Minimal panjang nomor telepon

int validasiTelp(const char *telepon) {
    int panjang = strlen(telepon);

    // Cek panjang nomor telepon
    if (panjang < MIN_PHONE_LENGTH || panjang > MAX_PHONE_LENGTH) {
        return 0;  // Panjang tidak valid
    }

    // Cek apakah hanya berisi digit
    for (int i = 0; i < panjang; i++) {
        if (!isdigit(telepon[i])) {
            return 0;  // Karakter bukan angka ditemukan
        }
    }

    return 1;  // Nomor telepon valid
}

#endif


//FILE Master manajer
FILE *manajer;
//FILE Master Admins 
FILE *admin;
//FILE Master Pelanggan
FILE *dataCust;
FILE *pesan; 
//FILE temp
FILE *temp;
char opsi;
int id;
char nama[20];
char sandi[20];
//Deklarasi Global Master Boneka dan Aksesori
// int stokBaru;
// int hargaBaru;
// bool found;
int i;
int count;
int role;  // 0 = Manajer, 1 = Admin, 2 = Pelanggan
int plzhps;
int idPelangganAktif = -1;
#define MAX_PELANGGAN 100
int idCust=-1;

typedef struct {
    int id;
    char nama[50];
    int totalStok;
    int stokS, stokM, stokL;
    int hargaS, hargaM, hargaL;
} DataAksesoris;


typedef struct {
    int id;
    char nama[50];
    int totalStok;
    int stokS, stokM, stokL;
    int stokUnguS, stokPinkS, stokBiruS;
    int stokUnguM, stokPinkM, stokBiruM;
    int stokUnguL, stokPinkL, stokBiruL;
    int hargaS, hargaM, hargaL;
} DataBoneka;

typedef struct{
    int id;
    
    char nama[50];
    char sandi[50];
    char telepon[15];
    char alamat[100]; 
} customer;
customer cust;
typedef struct {
    int simpan;
    int idJenis;
    int idSize;
    int idWarna;
    int idAksesoris;
    int idSizeAksesoris;
    int idPesanan;
    int harga;
    char size[50];
    char warna[50];
    char nama[50];
    char aksesoris[50];
    char sizeAksesoris[50];
    char zonawaktu[50];
    char alamat[100];
    char estimasi[100];
    bool statusPembayaran;
} DataPesanan;

typedef struct{
    int id;
    char nama[25];
    int jumlah;
    int TotalHarga;
}Datalaporan;

typedef struct{
    int id;
    char nama[50];
    char sandi[50];
}DataAdmin;
DataAdmin adm;

typedef struct{
    int id;
    char nama[50];
    char sandi[50];
}DataManajer;
DataManajer mnj;

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void enable_ansi_support() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    // Check if the handle is valid
    if (hOut == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Invalid handle\n");
        return;
    }

    // Get the current console mode
    if (!GetConsoleMode(hOut, &dwMode)) {
        fprintf(stderr, "Failed to get console mode\n");
        return;
    }

    // Enable ANSI escape sequence processing
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) {
        fprintf(stderr, "Failed to set console mode\n");
    }
}


// typedef struct{
//     customer biodata;
//     DataPemesanan detail;
// }DataPembayaran;
// DataPembayaran pmb;

// typedef struct{
//     DataPembayaran laporan1;
//     DataPemesanan laporan2;
// }DataLaporan;
// DataLaporan lpr;