#include <stdio.h>
#include <unistd.h> // Untuk fungsi usleep()

void printWaving(int step) {
    if (step == 0) {
        printf("   _     _   \n");
        printf("  (c).-.(c)  \n");
        printf("   / ._. \\   \n");
        printf(" __\\( Y )/__ \n");
        printf("(_.-/'-'\\-._) \n");
        printf("   ||   ||    \n");
        printf(" _.' `-' '._  \n");
        printf("(.-./`-`\\.-.)\n");
        printf(" `-'     `-'  \n");
    } else if (step == 1) {
        printf("   _     _   \n");
        printf("  (c).-.(c)  \n");
        printf("   / ._. \\ _   \n");
        printf(" __\\( Y )// )\n");
        printf("(_.-/'-' ,_/\n");
        printf("   ||   ||  \n");
        printf(" _.' `-' '._ \n");
        printf("(.-./`-`\\.-.)\n");
        printf(" `-'     `-' \n");
    } 
}

void gasBoneka(){
    int step = 0;

    while (1) {
        // Bersihkan layar
        printf("\033[H\033[J");

        // Cetak boneka dengan animasi tangan kanan melambai
        printWaving(step);

        // Atur langkah berikutnya
        step = (step + 1) % 2;

        // Tunggu sebelum iterasi berikutnya (500 ms)
        Sleep(500000);
    }
}