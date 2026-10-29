#include <stdio.h>
#include <string.h>

int main(void) {
    char aktiviteti[150];

    printf("Cfare mesove sot? ");

    if (fgets(aktiviteti, sizeof aktiviteti, stdin) == NULL) {
        return 1;
    }

    aktiviteti[strcspn(aktiviteti, "\n")] = '\0';

    FILE *file = fopen("ditari.txt", "a");

    if (file == NULL) {
        perror("Gabim gjate hapjes");
        return 1;
    }

    fprintf(file, "Sot mesova: %s\n", aktiviteti);

    fclose(file);

    printf("Aktiviteti u shtua ne ditar.\n");

    return 0;
}
