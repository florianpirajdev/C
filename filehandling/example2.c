#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMRI_LENDEVE 5

int main(void) {
    char emriMbiemri[100];
    int notat[NUMRI_LENDEVE];

    const char *lendet[NUMRI_LENDEVE] = {
        "Gjuhe shqipe",
        "Matematike",
        "TIK",
        "Anglisht",
        "Muzike"
    };

    // "a" shton ne fund, pa fshire te dhenat ekzistuese.
    FILE *file = fopen("nxenesit.txt", "a");

    if (file == NULL) {
        perror("Skedari nuk mund te hapet");
        return 1;
    }

    while (1) {
        printf("\nEmri dhe mbiemri (ose stop): ");

        if (fgets(emriMbiemri, sizeof emriMbiemri, stdin) == NULL) {
            break;
        }

        // Kontrollojme nese emri e tejkalon bufferin.
        if (strchr(emriMbiemri, '\n') == NULL && !feof(stdin)) {
            int karakteri;

            while ((karakteri = getchar()) != '\n' &&
                   karakteri != EOF) {
                // Largojme pjesen e mbetur te inputit.
            }

            printf("Emri eshte shume i gjate. Provo perseri.\n");
            continue;
        }

        // Heqim Enter-in nga emri.
        emriMbiemri[strcspn(emriMbiemri, "\r\n")] = '\0';

        if (strcmp(emriMbiemri, "stop") == 0) {
            break;
        }

        // Nuk pranojme emer bosh ose vetem me hapesira.
        if (emriMbiemri[strspn(emriMbiemri, " \t")] == '\0') {
            printf("Emri nuk mund te jete bosh.\n");
            continue;
        }

        int shuma = 0;

        for (int i = 0; i < NUMRI_LENDEVE; i++) {
            char inputi[100];

            while (1) {
                printf("Nota ne %s (1-5): ", lendet[i]);

                if (fgets(inputi, sizeof inputi, stdin) == NULL) {
                    // Nxenesi i paperfunduar nuk ruhet.
                    fclose(file);
                    return 0;
                }

                if (strchr(inputi, '\n') == NULL && !feof(stdin)) {
                    int karakteri;

                    while ((karakteri = getchar()) != '\n' &&
                           karakteri != EOF) {
                    }

                    printf("Input shume i gjate. Provo perseri.\n");
                    continue;
                }

                char *fundi;
                long nota = strtol(inputi, &fundi, 10);

                // Kalojme hapesirat pas numrit.
                while (*fundi == ' ' || *fundi == '\t' ||
                       *fundi == '\r' || *fundi == '\n') {
                    fundi++;
                }

                if (fundi == inputi || *fundi != '\0' ||
                    nota < 1 || nota > 5) {
                    printf("Shkruaj nje note te plote nga 1 deri ne 5.\n");
                    continue;
                }

                notat[i] = (int)nota;
                shuma += notat[i];

                break;
            }
        }

        double mesatarja = (double)shuma / NUMRI_LENDEVE;

        // Te gjitha te dhenat shkruhen ne nje rresht.
        int rezultati = fprintf(
            file,
            "%s | Shqip: %d | Matematike: %d | TIK: %d | "
            "Anglisht: %d | Muzike: %d | Mesatarja: %.2f\n",
            emriMbiemri,
            notat[0],
            notat[1],
            notat[2],
            notat[3],
            notat[4],
            mesatarja
        );

        if (rezultati < 0 || fflush(file) == EOF) {
            perror("Gabim gjate ruajtjes");
            fclose(file);
            return 1;
        }

        printf("Nxenesi u ruajt! Mesatarja: %.2f\n", mesatarja);
    }

    if (fclose(file) == EOF) {
        perror("Gabim gjate mbylljes se skedarit");
        return 1;
    }

    printf("Programi perfundoi.\n");

    return 0;
}
