int pilihan_yn(int b1,int by1,int b2,int by2,int x1,int y1,int x2,int y2);
int isWhitespace(const char *str);
char* formatNumber(int number, char* buffer);
void ReadPassword(char *password, int maxLen);
void DrawFile(int x, int y, char filename[255]);
void clearArea(int startX, int startY, int endX, int endY);
void scanGets(char *buffer, int bufferSize);
void limitInput(char *variabel,char count);
void gotoxy(int x, int y);
void desainPojok();
void border();
void getchW();
void fullscreen();
void luar();
// void putAt(int x, int y, const char *text);
// void printAt(int x, int y, const char *format, ...);

// Fungsi untuk mengecek apakah string hanya terdiri dari spasi atau kosong
int isWhitespace(const char *str) {
    while (*str) {
        if (!isspace((unsigned char)*str)) {
            return 0; // Ada karakter yang bukan spasi
        }
        str++;
    }
    return 1; // Hanya spasi atau kosong
}

void ReadPassword(char *password, int maxLen) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch(); // Membaca karakter tanpa menampilkan di layar

        if (ch == '\r') { // Jika Enter ditekan
            password[i] = '\0'; // Akhiri string
            break;
        } else if (ch == '\b') { // Jika Backspace ditekan
            if (i > 0) {
                i--;
                printf("\b \b"); // Hapus bintang di layar
            }
        } else if (i < maxLen - 1) { // Jika masih ada ruang untuk karakter baru
            password[i++] = ch;
            printf("*");
        }
    }
}

char* formatNumber(int number, char* buffer) {
    char rawNumber[20];
    sprintf(rawNumber, "%d", number);
    
    int length = strlen(rawNumber);
    int commaCount = (length - 1) / 3;
    int resultIndex = 0;
    
    for(int i = 0; i < length; i++) {
        if(i > 0 && (length - i) % 3 == 0) {
            buffer[resultIndex++] = '.';
        }
        buffer[resultIndex++] = rawNumber[i];
    }
    buffer[resultIndex] = '\0';
    
    return buffer;
}

void fullscreen() {
    // Mengaktifkan mode layar penuh dengan menekan tombol Alt+Enter
    keybd_event(VK_MENU, 0x38, 0, 0); // Tekan tombol Alt
    keybd_event(VK_RETURN, 0x1C, 0, 0); // Tekan tombol Enter
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0); // Lepaskan tombol Enter
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); // Lepaskan tombol Alt

    // Mendapatkan informasi konsol saat ini
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Mendapatkan ukuran layar fisik
    int screenWidth = GetSystemMetrics(SM_CXSCREEN); // Lebar layar
    int screenHeight = GetSystemMetrics(SM_CYSCREEN); // Tinggi layar

    // Ukuran font default konsol adalah 8x16
    int fontWidth = 8;
    int fontHeight = 16;

    // Sesuaikan dengan layar ASUS TUF GAMING A15 (1920x1080)
    int columns = 208;  // Jumlah kolom berdasarkan lebar layar 1920 / 8
    int rows = 67;      // Jumlah baris berdasarkan tinggi layar 1080 / 16

    // Menyesuaikan ukuran buffer untuk menghindari scroll
    COORD bufferSize;
    bufferSize.X = columns;
    bufferSize.Y = rows;

    // Menentukan ukuran jendela konsol agar sesuai dengan buffer
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = columns - 1;
    windowSize.Bottom = rows - 1;

    // Menyesuaikan ukuran buffer dan jendela konsol
    SetConsoleScreenBufferSize(hConsole, bufferSize);
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    // Opsional: Mengatur warna latar belakang konsol (misalnya, latar belakang hijau, teks hitam)
    
}

void DrawFile(int x, int y, char filename[255]) {
    FILE *fp;
    char str[500];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file"); 
        return; 
    }

    i = 0;
    while (fgets(str, 500, fp) != NULL) {
        gotoxy(x, y + i);
        // Mengatur warna latar belakang ke 177 dan warna teks ke 165
        printf("\033[48;5;204m\033[38;5;223m%s\033[0m", str);
        i++;
    }
    fclose(fp);
}

// Fungsi untuk desain atas
void desainPojok() {
    // Memanggil DrawFile untuk file yang sudah ada
    DrawFile(162, 1, "Design/atas kanan.txt");
    DrawFile(2, 1, "Design/atas kiri.txt");
    DrawFile(2, 42, "Design/bawah kiri.txt");
    DrawFile(162, 42, "Design/bawah kanan.txt");
}
void loading(int x,int y){
    for (i = 1; i <= 50; i++){
        gotoxy(x + i,y);
        printf("▌");
        if(i % 10 == 0) Sleep(500);
    }
}
void bg() {
    char buffer[211];
    memset(buffer, ' ', sizeof(buffer) - 1);
    buffer[210] = '\0'; // Null-terminate string

    printf("\033[48;5;204m");  // Mengatur warna background
    for (int i = 0; i < 54; i++) {
        gotoxy(0, i);  // Pindahkan kursor ke awal baris
        printf("%s", buffer);
    }
    printf("\033[0m"); // Reset warna
}

void border(){
    bg() ;
    luar();
    printf("\033[48;5;223m");
    int x= 57;
    int y = 208;

    for (int i = 2; i <= 208; i++) {
            gotoxy(i, 11);
            printf(" ");
        }
    for (int i = 12; i <= 52; i++) {
            gotoxy(38, i);
            printf("   ");
        }
        printf("\033[0m");
}

void luar(){
    printf("\033[48;5;223m");
    for (int i = 0; i<=209;i++){
        gotoxy(i,0);
        printf(" ");
        gotoxy(i,53);
        printf(" ");
    }

    for (int i = 0; i<=52;i++){
        gotoxy(0,i);
        printf("  ");
        gotoxy(209,i);
        printf("  ");
    }
        printf("\033[0m");
}

void limitInput(char *variabel,char count){
    char ch;
    for (i = 0; i < count; i++){
        ch = getch();
        if(ch == 13 || ch == 8) break; // ENTER dan BACKSPACE-> Selesai Input
        variabel[i] = ch;
        printf("%c", ch);
    }
    variabel[i] = '\0'; 
}


void getchW(){
    keybd_event('A', 0, 0, 0);          // Menekan tombol
    keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Melepaskan tombol
    getch();
}

// Fungsi untuk memindahkan kursor
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void scanGets(char *buffer, int bufferSize) {
    fflush(stdin);  // membersihkan  buffer yang menyebabkan kesalahan input
    fgets(buffer, bufferSize, stdin); // Mengambil input dari pengguna
    // Hapus karakter newline yang mungkin terbaca di akhir input
    buffer[strcspn(buffer, "\n")] = 0;// Menghapus newline dari input
}

void clearArea(int startX, int startY, int endX, int endY) {
    int x,y;
    for (x = startX; x <= endX; x++) {  // Iterasi untuk setiap baris dalam rentang
        for (y = startY; y <= endY; y++) {  // Iterasi untuk setiap kolom dalam rentang
            gotoxy(x,y);
            printf("\033[48;5;204m\033[38;5;223m \033[0m\n");
        }
    }
}

int pilihan_yn(int b1,int by1,int b2,int by2,int x1,int y1,int x2,int y2){
    int pilihan = 0;

    do {
        DrawFile(b1,by1,"Design/borderKecil.txt");
        DrawFile(b2,by2,"Design/borderKecil.txt");
        gotoxy(x1,y1);
        printf("\033[48;5;204m\033[38;5;223mIya\033[0m");
        gotoxy(x2,y2);
        printf("\033[48;5;204m\033[38;5;223mTidak\033[0m");

        if (pilihan == 0){
            gotoxy(x1,y1);
            printf("\033[48;5;223m\033[38;5;204mIya\033[0m"); // Highlight selected option
        } else {
            gotoxy(x2,y2);
            printf("\033[48;5;223m\033[38;5;204mTidak\033[0m"); // Highlight selected option
        }

        char ch = getch();  // // Membaca satu karakter tanpa perlu menekan enter
            if (ch == 75) { // Panah kiri
                if (pilihan > 0) pilihan--;
            } else if (ch == 77) { // Panah kanan
                if (pilihan < 1) pilihan++;
            } else if (ch == 13) { // Enter 
                return pilihan;
                break;
            }
    } while (1);
}

void SetColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}
// Fungsi untuk memindahkan kursor ke posisi tertentu dan mencetak teks
// void putAt(int x, int y, const char *text) {
//     gotoxy(x, y);        // Pindahkan kursor ke posisi yang diinginkan
//     printf("%s", text);  // Cetak teks pada posisi tersebut
// }

// void printAt(int x, int y, const char *format, ...) {
//     va_list variabel;
//     va_start(variabel, format);

//     gotoxy(x, y);  // Memindahkan kursor ke posisi yang diinginkan

//     vprintf(format, variabel);  // Mencetak output yang sesuai dengan format

//     va_end(variabel);
// }