void menuDataStok();
void Laporan(){
    int pilihan = 0;

    do{
        system("cls");
        border();
        menuOwnerDisplay(-1);
        displayMenuLap(pilihan);
        DrawFile(71, 2, "Design/laporanteks.txt");
        
    
    char ch = getch();  // // Membaca satu karakter tanpa perlu menekan enter
            if (ch == 72) { // Panah atas
                if (pilihan > 0) pilihan--;
            } else if (ch == 80) { // Panah bawah
                if (pilihan < 3 - 1) pilihan++;
            } else if (ch == 13) { // Enter 
            switch (pilihan) {
                case 0:
                    system("cls");
                    PanggilFungsiLaporan();
                    break;
                case 1:
                    system("cls");
                    menuDataStok();
                    break;
                case 2:
                    system("cls");
                    return;
            }
            getch(); // Menunggu pengguna menekan tombol
        }
    } while (1); // looping terus sampe usernya milih keluar
}

void menuDataStok(){
    int pilihan = 0;

    do{
        system("cls");
        border();
        if (role == 2){
            menuOwnerAdmin(-1);
            displayLapAdmin(-1);
            displaymenuStokAdm(pilihan); }
            else{
        menuOwnerDisplay(-1);
        displayMenuLap(-1);
    displaymenuStok(pilihan); }
        
        DrawFile(71, 2, "Design/laporanteks.txt");
        
    char ch = getch();  // // Membaca satu karakter tanpa perlu menekan enter
            if (ch == 72) { // Panah atas
                if (pilihan > 0) pilihan--;
            } else if (ch == 80) { // Panah bawah
                if (pilihan < 3 - 1) pilihan++;
            } else if (ch == 13) { // Enter 
            switch (pilihan) {
                case 0:
                    system("cls");
                    border();
                    if (role == 2){
                        menuOwnerAdmin(-1);
                        displayLapAdmin(-1);
                        displaymenuStokAdm(-1);
                    }else{
                    menuOwnerDisplay(-1);
                    displayMenuLap(-1);
                    displaymenuStok(-1);}
        
        DrawFile(71, 2, "Design/laporanteks.txt");
        
                    displayTableStok();
                    break;
                case 1:
                    system("cls");
                    border(); 
                    if (role == 2){
                        menuOwnerAdmin(-1);
                        displayLapAdmin(-1);
                        displaymenuStokAdm(-1);
                    }else{
                    menuOwnerDisplay(-1);
                    displayMenuLap(-1);
                    displaymenuStok(-1);}
        
        DrawFile(71, 2, "Design/laporanteks.txt");
       
                    displayTableStok1();
                    break;
                case 2:
                    system("cls");
                    return;
            }
            getch(); // Menunggu pengguna menekan tombol
        }
    } while (1); // looping terus sampe usernya milih keluar
}
