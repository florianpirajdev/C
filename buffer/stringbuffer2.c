#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BYTES 100

int main(void) {
    char vlera[MAX_BYTES];

    // Rezervojme fillimisht 1 byte per '\0'
    char *buffer = malloc(1);

    if (buffer == NULL) {
        printf("Gabim ne rezervimin e memories!\n");
        return 1;
    }

    buffer[0] = '\0';

    // Gjatesia e tekstit ne buffer, pa '\0'
    size_t gjatesia = 0;

    while (1) {
        printf("Shkruaj tekst (ose stop): ");

        // Lexojme nje rresht, perfshire hapesirat
        if (fgets(vlera, sizeof vlera, stdin) == NULL) {
            break;
        }

        // Nese mungon '\n', kontrollojme pjesen e mbetur
        if (strchr(vlera, '\n') == NULL) {
            int karakteri = getchar();

            if (karakteri != '\n' && karakteri != EOF) {
                // Zbrazim pjesen e mbetur te rreshtit
                while ((karakteri = getchar()) != '\n'
                       && karakteri != EOF) {
                }

                printf("Teksti eshte shume i gjate!\n\n");
                continue;
            }
        }

        // Heqim karakterin e Enter-it
        vlera[strcspn(vlera, "\n")] = '\0';

        if (strcmp(vlera, "stop") == 0) {
            break;
        }

        // Anashkalojme rreshtin bosh
        if (vlera[0] == '\0') {
            continue;
        }

        size_t gjatesiaVleres = strlen(vlera);

        // Teksti aktual + teksti i ri + hapesira + '\0'
        size_t bytesNevojiten = gjatesia + gjatesiaVleres + 2;

        if (bytesNevojiten > MAX_BYTES) {
            printf("Nuk ka vend per kete tekst!\n");
            printf("Kufiri eshte %d bytes, perfshire '\\0'.\n\n",
                   MAX_BYTES);
            continue;
        }

        // Zmadhojme bufferin sipas nevojes
        char *temporary = realloc(buffer, bytesNevojiten);

        if (temporary == NULL) {
            printf("Gabim ne zmadhimin e bufferit!\n");
            free(buffer);
            return 1;
        }

        buffer = temporary;

        // Shtojme tekstin dhe nje hapesire ne fund
        strcat(buffer, vlera);
        strcat(buffer, " ");

        gjatesia = gjatesia + gjatesiaVleres + 1;

        printf("Bufferi: \"%s\"\n", buffer);
        printf("Memoria e rezervuar: %zu / %d bytes\n\n",
               bytesNevojiten, MAX_BYTES);
    }

    printf("\nTeksti perfundimtar: \"%s\"\n", buffer);

    free(buffer);

    return 0;
}