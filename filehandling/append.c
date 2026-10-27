#include <stdio.h>
#include <string.h>

int main(void) {
    char emri[100];
    int numri = 0;

    FILE *file = fopen("nxenesit.txt", "a");

    if (file == NULL) {
        printf("File-i nuk mund te hapet!\n");
        return 1;
    }

    while (1) {
        printf("Shkruaj emrin dhe mbiemrin (ose stop): ");

        if (fgets(emri, sizeof emri, stdin) == NULL) {
            break;
        }

        // Heqim karakterin e Enter-it
        emri[strcspn(emri, "\n")] = '\0';

        // Perfundon pa e ruajtur fjalen stop
        if (strcmp(emri, "stop") == 0) {
            break;
        }

        // Nuk ruajme rreshta bosh
        if (emri[0] == '\0') {
            printf("Emri nuk mund te jete bosh!\n");
            continue;
        }

        if (fprintf(file, "%s\n", emri) < 0) {
            printf("Gabim gjate shkrimit!\n");
            fclose(file);
            return 1;
        }

        numri++;

        printf("Emri u shtua ne liste.\n");
    }

    if (fclose(file) == EOF) {
        printf("Gabim gjate ruajtjes!\n");
        return 1;
    }

    printf("\nU shtuan %d nxenes te rinj.\n", numri);

    return 0;
}