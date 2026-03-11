#include "Deklarasi.h"
#include "Fungsi.h"
#include "Page/menu.h"
#include "Transaksi/pemesanan.h"
#include "Transaksi/pembayaran.h"
#include "Laporan/Laporan.h"
#include "Laporan/LaporanPemesanan.h"
#include "Laporan/LaporanPembayaran.h"
#include "Laporan/MenuLaporan.h"
#include "Laporan/MenuLapAdmin.h"
#include "Laporan/MenuLapMnj.h"
#include "Page/Login.h"
#include "Design/bonekaGerak.c"

int main (){
    enable_ansi_support();
    SetConsoleOutputCP(CP_UTF8);
    inputAwal();
    getchar();
    getchar();
}