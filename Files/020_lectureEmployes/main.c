/* ========================================================================== */
/* Projet : lectureEmployes : lecture du fichier des employes                 */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int numero;
    char nom[51];
    char prenom[41];
    int numeroAgence;
} EMPLOYE;

int main()
{
    EMPLOYE employe;
    FILE* fichierEmployes;

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des employes (en lecture)                             */
/* -------------------------------------------------------------------------- */
    fichierEmployes = fopen("..\\fichiers\\employes", "rb");

    if (fichierEmployes == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER EMPLOYES *****\n\n");
        exit(1);
    }

/* -------------------------------------------------------------------------- */
/* Boucle de lecture et d'affichage des employes                              */
/* -------------------------------------------------------------------------- */
    printf("LISTE DES EMPLOYES\n\n");
    fread(&employe, sizeof(EMPLOYE), 1, fichierEmployes);

    while (!feof(fichierEmployes))
    {
        printf("%3d  %s %s (%d)\n", employe.numero,
               employe.prenom,
               employe.nom,
               employe.numeroAgence);

        fread(&employe, sizeof(EMPLOYE), 1, fichierEmployes);
    }

    fclose(fichierEmployes);

    return 0;
}
