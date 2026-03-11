
void menu_OAdmin(){

    int pilihan = 0;
    int msgResult;
    do{
    system("cls");
    border();
    DrawFile(69, 3, "Design/adminteks.txt");
    
    menuOwnerAdmin(pilihan);
    
    char ch = getch();  
        if (ch == 72) { 
            if (pilihan > 0) 
            pilihan--;
        } else if (ch == 80) { 
            if (pilihan < 5 - 1) 
            pilihan++;
        } else if (ch == 13) {
            switch (pilihan)
            {
            case 0:
                system("cls");
                Boneka();
                break;
            
            case 1:
                system("cls");
                Aksesori();
                break;
                
            case 2:
                system("cls");
                LaporanAdm();
                break;

            case 3:
                system("cls");
                deleteCust();
                 break;
            
            case 4 :
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



