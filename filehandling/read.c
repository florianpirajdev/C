#include <stdio.h>
#include <string.h>

int main(void) {
    char emri[100];
    int numri = 0;

    FILE *file = fopen("nxenesit.txt", "r");

    if (file == NULL) {
        printf("File-i nuk mund te hapet!\n");
        return 1;
    }

    while (fgets(emri, sizeof emri, file) != NULL) {
        // Heqim karakterin e fundit te rreshtit
        emri[strcspn(emri, "\n")] = '\0';

        numri++;

        printf("%d. %s\n", numri, emri);
    }

    if (ferror(file)) {
        printf("Gabim gjate leximit!\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("\nGjithsej: %d nxenes\n", numri);

    return 0;
}