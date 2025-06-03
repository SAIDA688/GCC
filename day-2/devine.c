#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    char rejouer = 'O';
    int max_essais = 10;

    srand(time(NULL));

    printf("========================================\n");
    printf("|   BIENVENUE DANS 'DEVINE LE NOMBRE'  |\n");
    printf("|      Trouvez le mystérieux nombre    |\n");
    printf("|         entre 1 et 100 !             |\n");
    printf("========================================\n\n");

    while (toupper(rejouer) == 'O') {
        int secret = rand() % 100 + 1;
        int essai, compteur = 0;
        int trouve = 0; 

        printf("\nNouvelle partie ! Prêt à relever le défi ?\n");
        printf("Vous avez %d essais pour trouver le nombre secret.\n\n", max_essais);

        while (compteur < max_essais && !trouve) {
            printf("Essai %d/%d > Entrez un nombre : ", compteur + 1, max_essais);
            if (scanf("%d", &essai) != 1) {
                printf("Entrée invalide. Veuillez entrer un nombre.\n");
                while(getchar() != '\n');
                continue;
            }
            compteur++;

            if (essai < secret) {
                printf("➤ Trop petit ! Essayez plus haut.\n");
            } else if (essai > secret) {
                printf("➤ Trop grand ! Essayez plus bas.\n");
            } else {
                trouve = 1;
                printf("\n");
                printf("╔══════════════════════════════════╗\n");
                printf("║          ✨ BRAVO ! ✨          ║\n");
                printf("║  Vous avez trouvé en %2d essais! ║\n", compteur);
                printf("╚══════════════════════════════════╝\n");
                
                if (compteur == 1) {
                    printf("Incroyable ! Vous êtes un vrai devin !\n");
                } else if (compteur <= 5) {
                    printf("Impressionnant ! Vous êtes doué !\n");
                } else if (compteur <= 10) {
                    printf("Bien joué ! Vous y êtes arrivé !\n");
                }
            }
        }

        if (!trouve) {
            printf("\n");
            printf("╔══════════════════════════════════╗\n");
            printf("║          ☠ PERDU ! ☠           ║\n");
            printf("║ Le nombre secret était %3d      ║\n", secret);
            printf("╚══════════════════════════════════╝\n");
            printf("Dommage ! La prochaine sera la bonne !\n");
        }

        printf("\nVoulez-vous rejouer ? (O/N) : ");
        scanf(" %c", &rejouer); 
        while(getchar() != '\n'); 
    }

    printf("\nMerci d'avoir joué ! À bientôt !\n");
    return 0;
}
