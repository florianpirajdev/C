#include <stdio.h>
#include <string.h>

int main(void) {
    char emri[100];

    FILE *file = fopen("nxenesit.txt", "w");

    if (file == NULL) {
        printf("File-i nuk mund te hapet!\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        printf("Shkruaj emrin dhe mbiemrin e nxenesit %d: ", i + 1);

        if (fgets(emri, sizeof emri, stdin) == NULL) {
            fclose(file);
            return 1;
        }

        // Heqim karakterin e Enter-it
        emri[strcspn(emri, "\n")] = '\0';

        // Ruajme emrin ne nje rresht te ri
        if (fprintf(file, "%s\n", emri) < 0) {
            printf("Gabim gjate shkrimit!\n");
            fclose(file);
            return 1;
        }
    }

    if (fclose(file) == EOF) {
        printf("Gabim gjate ruajtjes!\n");
        return 1;
    }

    printf("Nxenesit u ruajten me sukses!\n");

    return 0;
}