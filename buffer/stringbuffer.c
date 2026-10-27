#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BYTES 100

int main(void) {
    char vlera[100];

    // Fillimisht rezervojme vetem 1 byte per '\0'
    char *buffer = malloc(1);

    if (buffer == NULL) {
        printf("Gabim ne rezervimin e memories!\n");
        return 1;
    }

    buffer[0] = '\0';

    // Numri i byteve te perdorur, pa perfshire '\0'
    size_t gjatesia = 0;

    while (1) {
        printf("Shkruaj nje vlere (ose stop): ");

        // Lexojme nje fjale ose numer, deri ne 99 karaktere
        if (scanf("%99s", vlera) != 1) {
            break;
        }

        if (strcmp(vlera, "stop") == 0) {
            break;
        }

        size_t gjatesiaVleres = strlen(vlera);

        // Teksti aktual + vlera e re + hapesira + '\0'
        size_t bytesNevojiten = gjatesia + gjatesiaVleres + 2;

        if (bytesNevojiten > MAX_BYTES) {
            printf("Nuk ka vend per kete vlere! Kufiri eshte 100 bytes.\n");
            continue;
        }

        char *temporary = realloc(buffer, bytesNevojiten);

        if (temporary == NULL) {
            printf("Gabim ne zmadhimin e bufferit!\n");
            free(buffer);
            return 1;
        }

        buffer = temporary;

        // Shtojme vleren dhe nje hapesire pas saj
        strcat(buffer, vlera);
        strcat(buffer, " ");

        gjatesia = gjatesia + gjatesiaVleres + 1;

        printf("Bufferi: \"%s\"\n", buffer);
        printf("Memoria e rezervuar: %zu / 100 bytes\n\n",
               bytesNevojiten);
    }

    printf("\nTeksti perfundimtar: \"%s\"\n", buffer);

    free(buffer);

    return 0;
}