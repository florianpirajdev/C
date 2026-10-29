#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BYTES 100

int main(void) {
    char teksti[MAX_BYTES];
    size_t gjatesia = 0;

    // Fillojme me 1 byte per stringun bosh.
    char *buffer = malloc(1);

    if (buffer == NULL) {
        printf("Gabim ne memorie!\n");
        return 1;
    }

    buffer[0] = '\0';

    while (1) {
        printf("Shkruaj tekst (ose stop): ");

        // Lexojme nje rresht, perfshire hapesirat.
        if (fgets(teksti, sizeof teksti, stdin) == NULL) {
            break;
        }

        // Heqim Enter-in nga teksti.
        teksti[strcspn(teksti, "\n")] = '\0';
        size_t gjatesiaTekstit = strlen(teksti);

        // Refuzojme hyrjen me 99 ose me shume bytes tekst.
        // Lexojme dhe hedhim poshte pjesen e mbetur deri te Enter-i.
        if (gjatesiaTekstit == MAX_BYTES - 1) {
            int karakteri = getchar();

            while (karakteri != '\n' && karakteri != EOF) {
                karakteri = getchar();
            }

            printf("Teksti eshte shume i gjate!\n");
            continue;
        }

        if (strcmp(teksti, "stop") == 0) {
            break;
        }

        // Anashkalojme rreshtin bosh.
        if (gjatesiaTekstit == 0) {
            continue;
        }

        // Teksti ekzistues + teksti i ri + hapesira + '\0'.
        size_t madhesia = gjatesia + gjatesiaTekstit + 2;

        if (madhesia > MAX_BYTES) {
            printf("Nuk ka vend! Kufiri eshte 100 bytes.\n");
            continue;
        }

        // Zmadhojme memorien duke ruajtur tekstin ekzistues.
        char *temp = realloc(buffer, madhesia);

        if (temp == NULL) {
            printf("Gabim ne memorie!\n");
            free(buffer);
            return 1;
        }

        buffer = temp;

        // strcat vendos automatikisht '\0' ne fund.
        strcat(buffer, teksti);
        strcat(buffer, " ");

        gjatesia = gjatesia + gjatesiaTekstit + 1;

        printf("Bufferi: \"%s\"\n", buffer);
        printf("Memoria: %zu / %d bytes\n\n", madhesia, MAX_BYTES);
    }

    printf("\nTeksti perfundimtar: \"%s\"\n", buffer);

    free(buffer);
    return 0;
}
