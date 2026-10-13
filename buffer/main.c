
#include <stdio.h>
#include <string.h>

// Shembulli 1 - Buffer me numra
void bufferNumra() {
    int buffer[5];
    int pozicioni = 0;

    while (pozicioni < 5) {
        int numri;

        printf("Shkruaj nje numer: ");
        if (scanf("%d", &numri) != 1) {
            printf("Input i pavlefshem!\n");
            return;
        }

        buffer[pozicioni] = numri;
        pozicioni++;

        printf("Vende te lira: %d\n", 5 - pozicioni);
    }

    printf("\nALERT: Buffer-i eshte mbushur!\n");

    printf("Numrat e ruajtur: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", buffer[i]);
    }

    printf("\n");
}

// Shembulli 2 - Buffer me emra (2D)
void bufferEmra2D() {
    char buffer[5][20];
    int pozicioni = 0;

    while (pozicioni < 5) {
        printf("Shkruaj emrin: ");
        if (scanf("%19s", buffer[pozicioni]) != 1) {
            printf("Input i pavlefshem!\n");
            return;
        }

        pozicioni++;

        printf("Vende te lira: %d\n", 5 - pozicioni);
    }

    printf("\nALERT: Buffer-i eshte mbushur!\n");

    printf("Emrat e ruajtur:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, buffer[i]);
    }
}

// Shembulli 3 - Buffer nje dimensional
void bufferEmra1D() {
    char buffer[30] = "";
    char emri[20];

    while (1) {
        size_t hapesira = sizeof(buffer) - strlen(buffer) - 1;

        printf("\nShkruaj emrin: ");
        if (scanf("%19s", emri) != 1) {
            printf("Input i pavlefshem!\n");
            return;
        }

        size_t nevojitet = strlen(emri) + 1;

        if (nevojitet > hapesira) {
            printf("\nALERT: Nuk ka vend te mjaftueshem!\n");
            break;
        }

        strcat(buffer, emri);
        strcat(buffer, " ");

        printf("Buffer: %s\n", buffer);
        printf("Hapesira e lire: %zu\n",
               sizeof(buffer) - strlen(buffer) - 1);
    }

    printf("\nEmrat e ruajtur: %s\n", buffer);
}

// Programi kryesor
int main() {
    int zgjedhja;

    do {
        printf("\n===== BUFFER NE C =====\n");
        printf("1. Buffer me numra\n");
        printf("2. Buffer me emra (2D)\n");
        printf("3. Buffer me emra (1D)\n");
        printf("0. Dil\n");

        printf("Zgjedhja: ");
        if (scanf("%d", &zgjedhja) != 1) {
            printf("Zgjedhje e pavlefshme!\n");
            break;
        }

        if (zgjedhja == 1) {
            bufferNumra();
        }
        else if (zgjedhja == 2) {
            bufferEmra2D();
        }
        else if (zgjedhja == 3) {
            bufferEmra1D();
        }
        else if (zgjedhja == 0) {
            printf("Programi perfundoi.\n");
        }
        else {
            printf("Zgjedhje e pavlefshme!\n");
        }

    } while (zgjedhja != 0);

    return 0;
}
