#include <stdio.h>

int main(void) {
    char emri[100];

    // Hapim file-in per shkrim
    FILE *file = fopen("nxenesit.txt", "w");

    if (file == NULL) {
        printf("File-i nuk mund te hapet!\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        printf("Shkruaj emrin dhe mbiemrin e nxenesit %d: ", i + 1);

        // Lexojme emrin bashke me hapesirat dhe Enter-in
        if (fgets(emri, sizeof emri, stdin) == NULL) {
            break;
        }

        // Shkruajme emrin ne file
        fprintf(file, "%s", emri);
    }

    // Mbyllim file-in
    fclose(file);

    printf("Shkrimi ne file perfundoi!\n");

    return 0;
}