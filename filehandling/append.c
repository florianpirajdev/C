#include <stdio.h>
#include <string.h>

int main(void) {
    char emri[100];

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

        if (strcmp(emri, "stop\n") == 0) {
            break;
        }

        fprintf(file, "%s", emri);
    }

    fclose(file);

    return 0;
}