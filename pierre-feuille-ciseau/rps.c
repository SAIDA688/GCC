#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int joueur, ordinateur;
    const char *choix[] = {"Pierre", "Papier", "Ciseaux"};

    printf("Bienvenue dans Pierre - Papier - Ciseaux !\n");
    printf("Choisissez une option :\n");
    printf("1 - Pierre\n2 - Papier\n3 - Ciseaux\n");
    printf("Votre choix : ");
    scanf("%d", &joueur);
    if (joueur < 1 || joueur > 3) {
        printf("Choix invalide. Veuillez choisir entre 1, 2 ou 3.\n");
        return 1;
    }
    srand(time(NULL));
    ordinateur = rand() % 3 + 1;

    printf("L'ordinateur a choisi : %s\n", choix[ordinateur - 1]);

    if (joueur == ordinateur) {
        printf("Égalité !\n");
    } else if (joueur == 1 && ordinateur == 3){
        printf("Bravo vous avez gagné en jouant pierre contre ciseaux! \n");
    } else if (joueur == 1 && ordinateur == 2) {
        printf("Dommage vous avez perdu en jouant pierre contre papier!\n");
    } else if (joueur == 2 && ordinateur == 3) {
        printf("Dommage vous avez perdu en jouant papier contre ciseaux!\n");
    } else if (joueur == 2 && ordinateur == 1) {
        printf("Bravo vous avez gagné en jouant papier contre pierre!\n");
    } else if (joueur == 3 && ordinateur == 1) {
        printf("Dommage vous avez perdu en jouant ciseaux contre pierre!\n");
    } else if (joueur == 3 && ordinateur == 2) {
        printf("Bravo vous avez gagné en jouant ciseaux contre papier!\n");
    }

    return 0;
}
