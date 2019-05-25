/* ========================================================================== */
/* Projet : creationEmployes -- creation du fichier des employes              */
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
    char ligne[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des employes                                          */
/* On ouvre le fichier en ajout (append), Si le fichier n'existe pas, il est  */
/* cree.                                                                      */
/* -------------------------------------------------------------------------- */
    fichierEmployes = fopen("..\\fichiers\\employes", "ab");

    if (fichierEmployes == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER EMPLOYES *****\n\n");
        exit(1);
    }

/* -------------------------------------------------------------------------- */
/* Saisie du numero de l'employe :                                            */
/* -------------------------------------------------------------------------- */
    printf("Numero d'employe : ");
    gets(ligne);

/* -------------------------------------------------------------------------- */
/* Saisie des autres proprietes de l'employe :                                */
/* -------------------------------------------------------------------------- */
    while (ligne[0] != 0)
    {
        employe.numero = atoi(ligne);

        printf("Nom : ");
        gets(employe.nom);

        printf("Prenom : ");
        gets(employe.prenom);

        printf("Numero d'agence : ");
        gets(ligne);
        employe.numeroAgence = atoi(ligne);

        fwrite(&employe, sizeof(EMPLOYE), 1, fichierEmployes);

        printf("\n\nNumero d'employe : ");
        gets(ligne);
    }

    fclose(fichierEmployes);

    return 0;
}
