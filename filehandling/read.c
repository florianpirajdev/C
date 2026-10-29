#include <stdio.h>

int main(void) {
    char emri[100];

    FILE *file = fopen("nxenesit.txt", "r");

    if (file == NULL) {
        printf("File-i nuk mund te hapet!\n");
        return 1;
    }

    while (fgets(emri, sizeof emri, file) != NULL) {
        printf("%s", emri);
    }

    fclose(file);

    return 0;
}