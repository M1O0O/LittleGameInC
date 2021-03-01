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
    while (levelChosed >= 3 || levelChosed <= 0){
        printf("Quel niveau voulez-vous jouer ?\n1. %d\n2. %d\n3. %d\n", level[0], level[1], level[2]);
        scanf("%d", &levelChosed);
    }

    levelChosed--;

    // G�n�ration d'un nombre al�atoire entre 0 et le niveau chosit
    int NumberToSearch = rand() % level[levelChosed] + 1;

    // Demande au joueur de rentr�e un nombre
    printf("Chercher le nombre compris entre %d a %d \n", minValue, level[levelChosed]);
    scanf("%d", &NumberInput);

    // Tant que le chiffre entr�e n'est pas egal au chiffre g�n�rer
    while (NumberInput != NumberToSearch) {
        // Arr�te de jeu si le joueur a utiliser tous ses essais
        if (TotalTry >= maxChance) return printf("Le chiffre rechercher etait : %d", NumberToSearch);

        // Si le nombre entr� est sup�rieur au chiffre a chercher
        if (NumberInput > NumberToSearch){
            // Si le joueur a d�j� entr� une valeur inf�rieur et qu'il recommence
            if (NumberInput > lastNumberMax && NumberToSearch < lastNumberMax) printf("QI = 1\n");

            // ne red�finit pas la variable "lastNumberMax" si le chiffre n'est pas d�finis et n'est pas inf�rieur
            if (lastNumberMax == 0 || NumberInput < lastNumberMax) lastNumberMax = NumberInput;
            printf("Le nombre a chercher est inferieur \n");
        }
        // Si le nombre entr� est inf�rieur au chiffre a chercher
        else {
            // Si le joueur a d�j� entr� une valeur sup�rieur et qu'il recommence
            if (NumberInput < lastNumberMin && NumberToSearch > lastNumberMin) printf("QI = 1\n");

            // ne red�finit pas la variable "lastNumberMin" si le chiffre n'est pas d�finis et n'est pas sup�rieur
            if (lastNumberMin == 0 || NumberInput > lastNumberMin) lastNumberMin = NumberInput;
            printf("Le nombre a chercher est superieur \n");
        }

        // Demande au joueur de rentr�e un nombre
        printf("Il vous reste %d chances !\n", maxChance - TotalTry);
        scanf("%d", &NumberInput);

        // Incr�mente le nombre d'essaie
        TotalTry++;
    }

    printf("Vous avez gagner !");
    return 0;
}
