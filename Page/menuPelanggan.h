

void menu_OPel(){

    int pilihan = 0;
    int msgResult;
    do{
    system("cls");
    border();
    DrawFile(50, 3, "Design/pelangganteks.txt");
    
    menuOwnerPelanggan(pilihan);
    
    char ch = getch();  
        if (ch == 72) { 
            if (pilihan > 0) 
            pilihan--;
        } else if (ch == 80) { 
            if (pilihan < 4 - 1) 
            pilihan++;
        } else if (ch == 13) {
            switch (pilihan)
            {
            case 0:
                system("cls");
                
                PelangganAsli();
                break;
            
            case 1:
                system("cls");
                Pemesanan();
                break;
                
            case 2:
                system("cls");
                Pembayaran();
                break;

            case 3:
                system("cls");
                msgResult = MessageBox(NULL, "KLIK OK UNTUK KELUAR", "Keluar???",
                    MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    
                    if (msgResult == IDOK) { // Jika OK ditekan
                        return; // Keluar dari program
                    }
                    // Jika X ditekan atau Cancel ditekan, kembali ke menu
                    break;
                
            default:
                printf("Masukkan input yang valid");
                break;
            }
        } 
    }while(1);
}

