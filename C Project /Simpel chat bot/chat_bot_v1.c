
#include <stdio.h>
#include <string.h>

// Definisi kode warna ANSI
#define RESET "\033[0m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define RED "\033[0;31m"

// Fungsi menanggapi input pengguna
void chatbotResponse(const char *input, const char *userName) {
    if (strcmp(input, "hai") == 0 || strcmp(input, "halo") == 0) {
        printf("\n");
        printf(GREEN "Chatbot: Hai %s! Apa kabar? \n" RESET, userName);
    } else if (strcmp(input, "siapa kamu") == 0) {
        printf("\n");
        printf(GREEN "Chatbot: Saya adalah chatbot sederhana, senang bertemu denganmu, %s!\n" RESET, userName);
    } else if (strcmp(input, "apa kabar") == 0) {
        printf("\n");
        printf(GREEN "Chatbot: Saya baik, %s. Terima kasih sudah bertanya!\n" RESET, userName);
    } else if (strcmp(input, "bye") == 0 || strcmp(input, "selamat tinggal") == 0) {
       printf("\n");
        printf(RED "Chatbot: Selamat tinggal, %s! Semoga harimu menyenangkan.\n" RESET, userName);
    } else {
        printf(GREEN "Chatbot: Maaf %s, saya belum mengerti apa yang Anda maksud.\n" RESET, userName);
    }
}

int main() {
    char userName[50];
    char input[100];
    
    printf("Simpel Ai project by Calvin, perintah: \n");
    printf("• hai/halo \n");
    printf("• siapa kamu \n");
    printf("• apa kabar \n");
    printf("• bye , EXIT \n");
    printf("\n");

    // Meminta pengguna memasukkan nama
    printf(CYAN "siapa nama Anda?\n" RESET);
    printf(BLUE "Anda: " RESET);
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = '\0'; // Menghapus karakter newline

    printf("\n");
    printf(CYAN "Chatbot: Senang bertemu denganmu %s, \n  ketik perintah yang tersedia  \n" RESET, userName);

    // Loop percakapan
    while (1) {
        printf("\n");
        printf(BLUE "Anda: " RESET);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Menghapus karakter newline

        // Keluar jika pengguna mengetik "bye"
        if (strcmp(input, "bye") == 0) {
            printf(RED "Chatbot: Sampai jumpa lagi, %s!\n" RESET, userName);
            break;
        }

        // Respon chatbot
        chatbotResponse(input, userName);
    }

    return 0;
}
