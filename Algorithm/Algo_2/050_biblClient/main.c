/* ========================================================================== */
/* main.c : test des fonctions de client.c                                    */
/* -------------------------------------------------------------------------- */
/* Ce programme permet de remettre a jour le code Debit/Credit et le solde du */
/* client...                                                                  */
/* ========================================================================== */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "client.h"


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

/* -------------------------------------------------------------------------- */
/* DEBUT DU PROGRAMME : OUVERTURE DES FICHIERS                                */
/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des versements, en lecture                            */
/* -------------------------------------------------------------------------- */
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

            printf("\nNouveau code situation (C ou D) : ");
            gets(ligne);

            if(ligne[0] != 0)
            {
                client.codSit = ligne[0];
            }

            printf("\nNouveau solde : ");
            gets(ligne);

            if(ligne[0] != 0)
            {
                client.solde = (float)atof(ligne);
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
