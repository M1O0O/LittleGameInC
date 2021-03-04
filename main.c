#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialisation
    srand(time(NULL));

    // Configuratin du jeu
    int minValue = 0,
        level[3] = {10, 100, 1000},
        levelChosed,
        lastNumberMin = 0,
        lastNumberMax = 0,
        TotalTry = 0,
        NumberInput,
        maxChance = 10;

    maxChance--;

    // Demande au joueur de choisir un niveau
    printf("Quel niveau voulez-vous jouer ?\n1. %d\n2. %d\n3. %d\n", level[0], level[1], level[2]);
    scanf("%d", &levelChosed);

    // Tant que le niveau choisit n'existe pas, lui demande de re-choisir un niveau
    while (levelChosed >= 4 || levelChosed <= 0){
        printf("Quel niveau voulez-vous jouer ?\n1. %d\n2. %d\n3. %d\n", level[0], level[1], level[2]);
        scanf("%d", &levelChosed);
    }

    levelChosed--;

    // Génération d'un nombre aléatoire entre 0 et le niveau chosit
    int NumberToSearch = rand() % level[levelChosed] + 1;

    // Demande au joueur de rentrée un nombre
    printf("Chercher le nombre compris entre %d a %d \n", minValue, level[levelChosed]);
    scanf("%d", &NumberInput);

    // Tant que le chiffre entrée n'est pas egal au chiffre génèrer
    while (NumberInput != NumberToSearch) {
        // Arrête de jeu si le joueur a utiliser tous ses essais
        if (TotalTry >= maxChance) return printf("Le chiffre rechercher etait : %d", NumberToSearch);

        // Si le nombre entré est supérieur au chiffre a chercher
        if (NumberInput > NumberToSearch){
            // Si le joueur a déjà entré une valeur inférieur et qu'il recommence
            if (NumberInput > lastNumberMax && NumberToSearch < lastNumberMax) printf("QI = 1\n");

            // ne redéfinit pas la variable "lastNumberMax" si le chiffre n'est pas définis et n'est pas inférieur
            if (lastNumberMax == 0 || NumberInput < lastNumberMax) lastNumberMax = NumberInput;
            printf("Le nombre a chercher est inferieur \n");
        }
        // Si le nombre entré est inférieur au chiffre a chercher
        else {
            // Si le joueur a déjà entré une valeur supérieur et qu'il recommence
            if (NumberInput < lastNumberMin && NumberToSearch > lastNumberMin) printf("QI = 1\n");

            // ne redéfinit pas la variable "lastNumberMin" si le chiffre n'est pas définis et n'est pas supérieur
            if (lastNumberMin == 0 || NumberInput > lastNumberMin) lastNumberMin = NumberInput;
            printf("Le nombre a chercher est superieur \n");
        }

        // Demande au joueur de rentrée un nombre
        printf("Il vous reste %d chances !\n", maxChance - TotalTry);
        scanf("%d", &NumberInput);

        // Incrémente le nombre d'essaie
        TotalTry++;
    }

    printf("Vous avez gagner !");
    return 0;
}
