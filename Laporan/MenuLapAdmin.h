void LaporanAdm(){
    int pilihan = 0;

    do{
        system("cls");
        border();
        menuOwnerAdmin(-1);
        displayLapAdmin(pilihan);
        DrawFile(71, 2, "Design/laporanteks.txt");
        
    
    char ch = getch();  // // Membaca satu karakter tanpa perlu menekan enter
            if (ch == 72) { // Panah atas
                if (pilihan > 0) pilihan--;
            } else if (ch == 80) { // Panah bawah
                if (pilihan < 4 - 1) pilihan++;
            } else if (ch == 13) { // Enter 
            switch (pilihan) {
                case 0:
                    system("cls");
                    tabelPembayaranMahal();
                    break;
                case 1:
                    system("cls");
                    PanggilFungsiLaporan();
                    break;
                case 2:
                    system("cls");
                    menuDataStok();
                    break;
                case 3:
                    system("cls");
                    return;
            }
            getch(); // Menunggu pengguna menekan tombol
        }
    } while (1); // looping terus sampe usernya milih keluar
}
