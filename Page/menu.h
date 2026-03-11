void menuOwnerDisplay(int highlight);
void menuOwnerManajer (int highlight);
void menuOwnerAdmin (int highlight);
void menuOwnerPelanggan (int highlight);
void displayMenuLap(int highlight);
void displaymenuStok(int highlight);
void displaymenuStokAdm(int highlight);
void displayLapMnj(int highlight);
void displayLapAdmin(int highlight);

#include "../Master/Manajer.h"
#include "../Master/Admin.h"
#include "../Master/Pelanggan.h"
#include "../Master/Boneka.h"
#include "../Master/Aksesori.h"

// ======= Menu Display Pelanggan ======
void menuOwnerPelanggan(int highlight) {
    DrawFile(2, 13, "Design/boneka.txt");
    char *menu[] = {
        "   C E K   P R O F I L            ",
        "   P E M E S A N A N              ",
        "   P E M B A Y A R A N            ",
        "   K E L U A R                    "
        
    };
    gotoxy(2, 19);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 20);
    printf("\033[48;5;204m\033[38;5;223mM E N U   U T A M A\033[0m");
    gotoxy(2, 21);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");
    for (int i = 0; i < 4; i++) {
        gotoxy(2, 22 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menu[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menu[i]);
        }
    }
}

// =====Menu Owner=====
void menuOwnerDisplay(int highlight) {
    char *menu[] = {
        "   M A N A G E R                  ",
        "   A D M I N                      ",
        "   P E L A N G G A N              ",
        "   B O N E K A                    ",
        "   A K S E S O R I S              ",
        "   P E M E S A N A N              ",
        "   P E M B A Y A R A N            ",
        "   L A P O R A N                  ",
        "   K E L U A R                    "
        
        
    };
    gotoxy(2, 14);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 15);
    printf("\033[48;5;204m\033[38;5;223mM E N U   U T A M A\033[0m");
    gotoxy(2, 16);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");
    for (int i = 0; i < 9; i++) {
        gotoxy(2, 17 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s\033[0m\n", menu[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menu[i]);
        }
    }
}

// =====Menu Manajer Pada Owner======
void menuOwnerManajer(int highlight) {
    DrawFile(2, 13, "Design/boneka.txt");
    char *menu[] = {
        "   D A T A   A D M I N            ",
        "   D A T A   M A N A J E R        ",
        "   L A P O R A N                  ",
        "   K E L U A R                    "
        
    };
    gotoxy(2, 19);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 20);
    printf("\033[48;5;204m\033[38;5;223mM E N U   U T A M A\033[0m");
    gotoxy(2, 21);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");
    for (int i = 0; i < 4; i++) {
        gotoxy(2, 22 + i);
        if (i == highlight) {
            printf(" \033[48;5;223m\033[38;5;204m  %s\033[0m<\n", menu[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menu[i]);
        }
    }
}

// =====Menu Admin pada Owner=====
void menuOwnerAdmin(int highlight) {
    DrawFile(2, 13, "Design/boneka.txt");
    char *menu[] = {
        "   B O N E K A                     ",
        "   A K S E S O R I S               ",
        "   L A P O R A N                   ",
        "   P E R M I N T A A N   H A P U S ",
        "   K E L U A R                     "
        
    };
    gotoxy(2, 19);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 20);
    printf("\033[48;5;204m\033[38;5;223mM E N U   U T A M A\033[0m");
    gotoxy(2, 21);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");
    for (int i = 0; i < 5; i++) {
        gotoxy(2, 22 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menu[i]); // Highlight selected option
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s\033[0m\n", menu[i]);
        }
    }
}
// =====Menu Laporan=====
void displayMenuLap(int highlight) {
    int totalOpsi = 3;
    char *menuOpsi[] = {
        "   L A P   P E M E S A N A N     ",
        "   D A T A   S T O K             ",
        "   K E L U A R                   "
    };

    // Header menu
    gotoxy(2, 26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   L A P O R A N\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalOpsi; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOpsi[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s \033[0m\n", menuOpsi[i]);
        }
    }
}

// =====Menu Data Stok=====
void displaymenuStok(int highlight) {
    int totalOpsi = 3;
    char *menuOpsi[] = {
        "   B O N E K A                   ",
        "   A K S E S O R I S             ",
        "   K E L U A R                   "
        
    };

    // Header menu
    gotoxy(2, 32);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 33);
    printf("\033[48;5;204m\033[38;5;223mM E N U   D A T A   S T O K\033[0m");
    gotoxy(2, 34);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalOpsi; i++) {
        gotoxy(2, 35 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOpsi[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s \033[0m\n", menuOpsi[i]);
        }
    }
}

// =====Menu Data Stok Admin=====
void displaymenuStokAdm(int highlight) {
    displaymenuStok(highlight); // Sama seperti menu stok biasa
}

// =====Menu Laporan Manajer=====
void displayLapMnj(int highlight) {
    int totalOpsi = 3;
    char *menuOpsi[] = {
        "   L A P   A K H I R              ",
        "   D A T A   S T O K              ",
        "   K E L U A R                    "
        
    };

    // Header menu
    gotoxy(2, 26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   L A P O R A N\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalOpsi; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOpsi[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s \033[0m\n", menuOpsi[i]);
        }
    }
}

// =====Menu Laporan Admin=====
void displayLapAdmin(int highlight) {
    int totalOpsi = 4;
    char *menuOpsi[] = {
        "   L A P   P E M B A Y A R A N    ",
        "   L A P   A K H I R              ",
        "   D A T A   S T O K              ",
        "   K E L U A R                    "
    };

    // Header menu
    gotoxy(2, 26);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m");
    gotoxy(10, 27);
    printf("\033[48;5;204m\033[38;5;223mM E N U   L A P O R A N\033[0m");
    gotoxy(2, 28);
    printf("\033[48;5;204m\033[38;5;223m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n");

    for (int i = 0; i < totalOpsi; i++) {
        gotoxy(2, 29 + i);
        if (i == highlight) {
            printf("\033[48;5;223m\033[38;5;204m  %s \033[0m\n", menuOpsi[i]);
        } else {
            printf("\033[48;5;204m\033[38;5;223m  %s \033[0m\n", menuOpsi[i]);
        }
    }
}
