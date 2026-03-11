// Deklarasi Function
void Manajer();
void input_manajer();         
void read_manajer();
void pilihan_update(DataManajer *manajer);
void update_manajer();
void delete_manajer();
int idOtomatis_Manajer();
void displayMenuManajer(int highlight);



int idOtomatis_Manajer() {
    int idTerakhir = 0;

    FILE *file_id = fopen("Database/manajer.dat", "rb");
    if (file_id == NULL) {
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return 1;
    } 
    
    while (fread(&mnj, sizeof(mnj), 1, file_id) == 1) {
        idTerakhir = mnj.id; 
    }

    fclose(file_id);
    return idTerakhir + 1;
}

void displayMenuManajer(int highlight) {
    int totalOpsi = 5;
    char *menuOpsi[] = {
        "   I N P U T   D A T A           ",
        "   C E K   D A T A               ",
        "   U P D A T E                   ",
        "   D E L E T E                   ",
        "   K E L U A R                   "
    };
    gotoxy(2, 26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   M A N A J E R\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalOpsi; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOpsi[i]); // Highlight
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s \033[0m\n", menuOpsi[i]); // Opsi biasa
        }
    }
}

void Manajer() {
    int pilihan = 0;

    do {
        system("cls");
        border();
        if (role == 1){
            menuOwnerManajer(-1);
        }else{
            menuOwnerDisplay(-1);
        }
        displayMenuManajer(pilihan);
        DrawFile(60, 3, "Design/manajerteks.txt");
        
        char ch = getch();  
        if (ch == 72) { // Panah atas
            if (pilihan > 0) pilihan--;
        } else if (ch == 80) { // Panah bawah
            if (pilihan < 5 - 1) pilihan++;
        } else if (ch == 13) { // Enter 
            switch (pilihan) {
                case 0:
                    system("cls");
                    input_manajer();
                    break;
                case 1:
                    system("cls");
                    read_manajer();
                    break;
                case 2:
                    system("cls");
                    update_manajer();
                    break;
                case 3:
                    system("cls");
                    delete_manajer();                                  
                    break;
                case 4:
                    system("cls");
                    return;
            }
            getch(); // Menunggu pengguna menekan tombol
        }
    } while (1); // looping terus sampe usernya milih keluar
}

void input_manajer(){
    int pilihan;
    bool found;
    manajer = fopen("Database/manajer.dat", "a+b");
    if (manajer == NULL){
        gotoxy(50,16);
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }

    mnj.id = idOtomatis_Manajer();

    do {
        system("cls");
        border();
        if (role == 1){
            menuOwnerManajer(-1);
        }else{
            menuOwnerDisplay(-1);
        }
        displayMenuManajer(pilihan);
        DrawFile(65, 3, "Design/manajerteks.txt");
   
        DrawFile(55,17,"Design/borderBesar.txt");
        gotoxy(64,18);
        printf("\033[48;5;204m\033[38;5;223m%d\033[0m", mnj.id);
        do{
            gotoxy(59, 21);
            printf("\033[48;5;204m\033[38;5;223m");
            scanGets(mnj.nama, sizeof(mnj.nama));
            if (strlen(mnj.nama) == 0) {
                gotoxy(59,23);
                printf("\033[48;5;204m\033[38;5;223mNama tidak boleh kosong!\033[0m");
                Sleep(1000);
                clearArea(59,23,84,23);
            }
        } while (strlen(mnj.nama) == 0);

        do{
            gotoxy(59, 26);
            printf("\033[48;5;204m\033[38;5;223m");
            scanGets(mnj.sandi, sizeof(mnj.sandi));
            if (strlen(mnj.sandi) == 0) {
                gotoxy(59,29);
                printf("\033[48;5;204m\033[38;5;223mSandi tidak boleh kosong!\033[0m");
                Sleep(1000);
                clearArea(59,29,85,29);
            }
        } while(strlen(mnj.sandi) == 0);

        fwrite(&mnj, sizeof(mnj), 1, manajer);
        gotoxy(82,29);
        printf("\033[48;5;204m\033[38;5;223mLoading\033[0m");
        loading(60,30);

        clearArea(4,12,55,13);
        gotoxy(59,32);
        printf("\033[48;5;204m\033[38;5;223mData anda berhasil kami simpan !\033[0m");
        Sleep(1000);

        gotoxy(59,33);
        printf("\033[48;5;204m\033[38;5;223mApakah anda ingin memasukkan data lagi ?\033[0m");
        pilihan = pilihan_yn(65,34,97,34,67,35,99,35);
        printf("\n");
        if (pilihan == 0){
            found = true;
            mnj.id++;
        } else if (pilihan == 1){
            found = false;
        }
    } while (found == true);
    gotoxy(59,42);
    printf("\033[48;5;204m\033[38;5;223mTekan tombol apa saja untuk kembali ke menu\033[0m");
    fclose(manajer);
}

void read_manajer(){
    border();
    DrawFile(60, 3, "Design/manajerteks.txt");
    
    if (role == 1){
        menuOwnerManajer(-1);
    }else{
        menuOwnerDisplay(-1);
    }
    displayMenuManajer(-1);
    FILE *manajer = fopen ("Database/manajer.dat", "rb");
    if(manajer == NULL){
        gotoxy(50,16);
        MessageBox(NULL, "Error Membuka File", "GAGAL!",
            MB_OK | MB_ICONWARNING);
        return;
    }
    i = 0;
    // Header tabel
    gotoxy(50,16);
    printf("\033[48;5;204m\033[38;5;223m+----+---------+-------------------------+-------------------------+\033[0m");
    gotoxy(50,17);
    printf("\033[48;5;204m\033[38;5;223m| No |    ID   |           Nama          |          Sandi          |\033[0m");
    gotoxy(50,18);
    printf("\033[48;5;204m\033[38;5;223m+----+---------+-------------------------+-------------------------+\033[0m");
    
    // Iterasi untuk mencetak setiap baris data
    while (fread(&mnj,sizeof(mnj),1,manajer)){
        i++;
        gotoxy(50,18 + i);
        printf("\033[48;5;204m\033[38;5;223m| %-2d | KARY%-3d | %-23s | %-23s |\033[0m", 
                i,
                mnj.id,
                mnj.nama, 
                mnj.sandi);
    }
    
    // Footer tabel
    gotoxy(50,19 + i);
    printf("\033[48;5;204m\033[38;5;223m+----+---------+-------------------------+-------------------------+\033[0m");
    fclose(manajer);
}

void pilihan_update(DataManajer *manajer){
    int pilihan = 0;
    char *menuOpsi[] = {
        "   U S E R N A M E                ",
        "   P A S S W O R D                ",
        "   K E D U A N Y A                "
    };

    do {
        gotoxy(2,34);
        printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
        gotoxy(10,35);
        printf("\033[48;5;204m\033[38;5;223mP E M B A R U A N\033[0m");
        gotoxy(2,36);
        printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

        for (int i = 0; i < 3; i++) {
            gotoxy(2, 37 + i);
            if (i == pilihan) {
                printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOpsi[i]); // Highlight
            } else {
                printf("\033[48;5;204m\033[38;5;223m  %s \033[0m\n", menuOpsi[i]); // Opsi biasa
            }
        }

        char ch = getch();  
        if (ch == 72) { // Panah atas
            if (pilihan > 0) pilihan--;
        } else if (ch == 80) { // Panah bawah
            if (pilihan < 3 - 1) pilihan++;
        } else if (ch == 13) { // Enter 
            switch (pilihan){
                case 0:
                    clearArea(45,13,130,50);
                    gotoxy(47,13);
                    printf("\033[48;5;204m\033[38;5;223mMasukkan username yang ingin diubah :\033[0m");
                    DrawFile(45,14,"Design/borderPanjang.txt");
                    gotoxy(46,15);
                    scanGets(mnj.nama,sizeof(mnj.nama));
                    gotoxy(45,17);
                    printf("\033[48;5;204m\033[38;5;223mData berhasil diperbarui.\033[0m");
                    Sleep(500);
                    return;
                
                case 1:
                    clearArea(45,13,130,50);
                    gotoxy(47,13);
                    printf("\033[48;5;204m\033[38;5;223mMasukkan sandi yang ingin diubah :\033[0m");
                    DrawFile(45,14,"Design/borderPanjang.txt");
                    gotoxy(46,15);
                    scanGets(mnj.sandi,sizeof(mnj.sandi));
                    gotoxy(45,17);
                    printf("\033[48;5;204m\033[38;5;223mData berhasil diperbarui.\033[0m");
                    Sleep(500);
                    return;

                case 2:
                    clearArea(45,13,130,50);
                    gotoxy(47,13);
                    printf("\033[48;5;204m\033[38;5;223mMasukkan username yang ingin diubah :\033[0m");
                    DrawFile(45,14,"Design/borderPanjang.txt");
                    gotoxy(47,17);
                    printf("\033[48;5;204m\033[38;5;223mMasukkan sandi yang ingin diubah :\033[0m");
                    DrawFile(45,18,"Design/borderPanjang.txt");
                    gotoxy(46,15);
                    scanGets(mnj.nama,sizeof(mnj.nama));
                    gotoxy(46,19);
                    scanGets(mnj.sandi,sizeof(mnj.sandi));
                    gotoxy(45,21);
                    printf("\033[48;5;204m\033[38;5;223mData berhasil diperbarui.\033[0m");
                    Sleep(500);
                    return;
            }
        }
    } while (1);
}

void update_manajer(){
    int found;
    int idUpdate;
    char c[10];
    int pilihan; 

    i = 0;
    while (fread(&mnj, sizeof(mnj), 1, manajer)){
        i++;
    }

    do {
        system("cls");
        if (role == 1){
            menuOwnerManajer(-1);
        }else{
            menuOwnerDisplay(-1);
        }
        displayMenuManajer(-1);
        manajer = fopen("Database/manajer.dat", "rb"); 
        if(manajer == NULL){
            gotoxy(50,16);
            MessageBox(NULL, "Error Membuka File", "GAGAL!",
                MB_OK | MB_ICONWARNING);
            return;
        }
    
        temp = fopen("Database/temp.dat", "wb"); 
        if(temp == NULL){
            gotoxy(50,16);
            MessageBox(NULL, "Error Membuka File", "GAGAL!",
                MB_OK | MB_ICONWARNING);
            fclose(manajer);
            return;
        }
        clearArea(49,14,150,19 + i);
        clearArea(49,12,150,28);
        read_manajer();
        gotoxy(49,14);
        printf("\033[48;5;204m\033[38;5;223mMasukkan Nomor ID yang ingin diupdate : \033[0m");
        DrawFile(90,13,"Design/borderKecil.txt");
        do{
            gotoxy(94,14);
            limitInput(c,3);
            idUpdate = atoi(c);
            if(idUpdate == 0){
                gotoxy(102,14);
                printf("\033[48;5;204m\033[38;5;223minputan tidak valid\033[0m");
                Sleep(500);
            }
            clearArea(94,14,97,14); 
            clearArea(102,14,122,14); 
        } while (idUpdate == 0);

        rewind(manajer);
        found = 0;
        while (fread(&mnj, sizeof(mnj), 1, manajer)){
            if (mnj.id == idUpdate){
                found = 1;
                clearArea(45,13,130,50);
                gotoxy(49,14);
                printf("\033[48;5;204m\033[38;5;223m+---------+-------------------------+-------------------------+\033[0m");
                gotoxy(49,15);
                printf("\033[48;5;204m\033[38;5;223m|    ID   |           Nama          |          Sandi          |\033[0m");
                gotoxy(49,16);
                printf("\033[48;5;204m\033[38;5;223m+---------+-------------------------+-------------------------+\033[0m");
                gotoxy(49,17);
                printf("\033[48;5;204m\033[38;5;223m| KARY%-3d | %-23s | %-23s |\033[0m", 
                        mnj.id,
                        mnj.nama, 
                        mnj.sandi);
                gotoxy(49,18);
                printf("\033[48;5;204m\033[38;5;223m+---------+-------------------------+-------------------------+\033[0m");
                gotoxy(49,20);
                printf("\033[48;5;204m\033[38;5;223mApakah data tersebut yang ingin di update?\033[0m");
                pilihan = pilihan_yn(53,22,82,22,56,23,84,23);
                if (pilihan == 0){
                    found = 2;
                    pilihan_update(&mnj);
                }
            }
            fwrite(&mnj, sizeof(mnj), 1, temp);
        }

        if (found == 0) {
            gotoxy(102,14);
            printf("\033[48;5;204m\033[38;5;223mID %d tidak ditemukan.\033[0m", idUpdate);
        } else if (found == 2) {
            gotoxy(49,24);
            printf("\033[48;5;204m\033[38;5;223mApakah ada data lagi yang ingin di update?\033[0m");
            pilihan = pilihan_yn(53,25,82,25,56,26,84,26);
        }

    fclose(manajer);
    fclose(temp); 
    temp = fopen("Database/temp.dat","rb");
    manajer = fopen("Database/manajer.dat","wb");
    while (fread(&mnj, sizeof(mnj),1,temp)){
        fwrite(&mnj, sizeof(mnj), 1, manajer);
    }
    fclose(manajer);
    fclose(temp); 
    } while (pilihan == 0);
    fclose(manajer);
    fclose(temp);         

    gotoxy(50,26 + i);
    printf("\033[48;5;204m\033[38;5;223mTekan tombol apa saja untuk kembali ke menu\033[0m");
}

//function untuk menghapus data customer
void delete_manajer(){
    int found;
    int idUpdate;
    char c[10];
    int pilihan;

    i = 0;
    while (fread(&mnj, sizeof(mnj), 1, manajer)){
        i++;
    }

    do {
        system("cls");
        if (role == 1){
            menuOwnerManajer(-1);
        }else{
            menuOwnerDisplay(-1);
        }
        displayMenuManajer(-1);
        manajer = fopen("Database/manajer.dat", "rb");
        if(manajer == NULL){
            gotoxy(50,16);
            MessageBox(NULL, "Error Membuka File", "GAGAL!",
                MB_OK | MB_ICONWARNING);
            return;
        }
    
        temp = fopen("Database/temp.dat", "wb");
        if(temp == NULL){
            gotoxy(50,16);
            MessageBox(NULL, "Error Membuka File", "GAGAL!",
                MB_OK | MB_ICONWARNING);
            fclose(manajer);
            return;
        }

        clearArea(49,14,150,19 + i);
        clearArea(49,12,150,28);
        read_manajer();
        gotoxy(49,14);
        printf("\033[48;5;204m\033[38;5;223mMasukkan Nomor ID yang ingin dihapus : \033[0m");
        DrawFile(90,13,"Design/borderKecil.txt");
        do{
            gotoxy(94,14);
            limitInput(c,3);
            idUpdate = atoi(c);
            if(idUpdate == 0){
                gotoxy(102,14);
                printf("\033[48;5;204m\033[38;5;223minputan tidak valid\033[0m");
                Sleep(500);
            }
            clearArea(94,14,97,14);
            clearArea(102,14,122,14);
        } while (idUpdate == 0);

        rewind(manajer);
        found = 0;
        while (fread(&mnj, sizeof(mnj), 1, manajer)){
            if (mnj.id == idUpdate){
                found = 1;
                clearArea(45,13,130,50);
                gotoxy(49,14);
                printf("\033[48;5;204m\033[38;5;223m+---------+-------------------------+-------------------------+\033[0m");
                gotoxy(49,15);
                printf("\033[48;5;204m\033[38;5;223m|    ID   |           Nama          |          Sandi          |\033[0m");
                gotoxy(49,16);
                printf("\033[48;5;204m\033[38;5;223m+---------+-------------------------+-------------------------+\033[0m");
                gotoxy(49,17);
                printf("\033[48;5;204m\033[38;5;223m| KARY%-3d | %-23s | %-23s |\033[0m", 
                        mnj.id,
                        mnj.nama, 
                        mnj.sandi);
                gotoxy(49,18);
                printf("\033[48;5;204m\033[38;5;223m+---------+-------------------------+-------------------------+\033[0m");
                gotoxy(49,20);
                printf("\033[48;5;204m\033[38;5;223mApakah anda yakin ingin menghapus data tersebut?\033[0m");
                pilihan = pilihan_yn(53,22,82,22,56,23,84,23);
                if (pilihan == 0){
                    found = 2;
                    continue;
                }
            }
            fwrite(&mnj, sizeof(mnj), 1, temp);
        }

        if (found == 0) {
            MessageBox(NULL, "ID TIDAK DITEMUKAN", "Peringatan",
            MB_OK | MB_ICONWARNING);
        } else if (found == 2) {
            MessageBox(NULL, "DATA TERHAPUS", "YEYYYYY",
                MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(50,20,110,36);
            gotoxy(49,20);
            printf("\033[48;5;204m\033[38;5;223mApakah ada data yang ingin di hapus lagi?\033[0m");
            pilihan = pilihan_yn(53,22,82,22,56,23,84,23);
        }

        fclose(manajer);
        fclose(temp);
        temp = fopen("Database/temp.dat","rb");
        manajer = fopen("Database/manajer.dat","wb");
        while (fread(&mnj, sizeof(mnj),1,temp)){
            fwrite(&mnj, sizeof(mnj), 1, manajer);
        }
        fclose(manajer);
        fclose(temp);
    } while (pilihan == 0);
    
    gotoxy(50,26 + i);
    printf("\033[48;5;204m\033[38;5;223mTekan tombol apa saja untuk kembali ke menu\033[0m");
    fclose(manajer);
    fclose(temp);
}