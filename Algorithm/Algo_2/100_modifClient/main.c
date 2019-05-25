/* ========================================================================== */
/* Projet : modifClient                                                       */
/* -------------------------------------------------------------------------- */
/* Ce programme permet de changer le nom et l'adresse du client               */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "C:\C\utilitaires\entetes\client.h"


/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{

    /* -------------------------------------------------------------------------- */
    /* VARIABLES                                                                  */
    /* -------------------------------------------------------------------------- */
    /* Variables pour l'utilisation du fichier                                    */
    /* -------------------------------------------------------------------------- */
    FILE* fichierClient;
    CLIENT client;

    int codeRetour;
    char ligne[81];

    fichierClient = fopen("C:\\C\\fichiers\\client", "r+b");

    if (fichierClient == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER client *****\n");
    }

/* -------------------------------------------------------------------------- */
/* Lecture d'un client                                                        */
/* -------------------------------------------------------------------------- */
    printf("\n\nNumero de client : ");
    gets(client.noCli);

    while (client.noCli[0] != 0)
    {
        codeRetour = litClient(&client, fichierClient);

        if (codeRetour != 0)
        {
            printf("%4s\n%-50s\n%-50s\n%5s  %-50s\n%3s  %2s\n%c %8.2f\n\n",
                   client.noCli,
                   client.nom,
                   client.adresse,
                   client.cPost,
                   client.ville,
                   client.noRep,
                   client.codPays,
                   client.codSit,
                   client.solde);

            printf("\nNouveau nom : ");
            gets(ligne);

            if(ligne[0] != 0)
            {
                strcpy(client.nom, ligne);
            }

            printf("\nNouvelle adresse : ");
            gets(ligne);

            if(ligne[0] != 0)
            {
                strcpy(client.adresse, ligne);
            }

            codeRetour = ecritClient(&client, fichierClient);
        }
        else
        {
            printf("Client %s inconnu.\n\n", client.noCli);
        }

        printf("\n\nNumero de client : ");
        gets(client.noCli);
    }

    fclose(fichierClient);

    return 0;
}
