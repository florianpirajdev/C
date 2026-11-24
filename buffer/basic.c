#include <stdio.h>
#include <string.h>

// Shembulli 1 - Ruajtja e tekstit ne Buffer
void shembulli1() {
    char buffer[20];

    strcpy(buffer, "Florian");

    printf("Buffer: %s\n", buffer);
    printf("Madhesia: %zu byte\n", sizeof(buffer));
    printf("Karaktere: %zu\n", strlen(buffer));
}

// Shembulli 2 - Riperdoimi i Buffer-it
void shembulli2() {
    char buffer[20];

    strcpy(buffer, "Arber");
    printf("Buffer: %s\n", buffer);

    strcpy(buffer, "Elsa");
    printf("Buffer: %s\n", buffer);

    strcpy(buffer, "Florian");
    printf("Buffer: %s\n", buffer);
}

// Shembulli 3 - Marrja e tekstit me fgets()
void shembulli3() {
    char buffer[20];

    printf("Shkruaj emrin dhe mbiemrin: ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("Teksti i ruajtur: %s\n", buffer);
    printf("Madhesia e buffer-it: %zu byte\n", sizeof(buffer));
    printf("Karaktere te lexuara: %zu\n", strlen(buffer));
}

// Funksioni kryesor
int main() {

    printf("===== SHEMBULLI 1 =====\n");
    shembulli1();

    printf("\n===== SHEMBULLI 2 =====\n");
    shembulli2();

    printf("\n===== SHEMBULLI 3 =====\n");
    shembulli3();

    return 0;
}