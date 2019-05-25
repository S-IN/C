/* ========================================================================== */
/* Projet : creationContacts                                                  */
/* -------------------------------------------------------------------------- */
/* initialisation du fichier des contacts a  partir d'un fichier texte        */
/* (contactsTries.txt). Ce fichier est cree en C pour etre lu en Java.        */
/* ========================================================================== */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "\\10.75.96.101\User\Stagiaires\Group64\Reference\C\utilitaires\entetes\chaines.h"

typedef struct
{
    int numero;
    char nom[21];
    char adresse[51];
    char codePostal[6];
    char ville[21];
    int  codeSecteur;
} CONTACT;

int main()
{
    FILE* fichierContacts;
    CONTACT contact;

    FILE* fichierTexteContacts;
    char ligne[201];

    char mot[201];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier texte des contacts                                    */
/* -------------------------------------------------------------------------- */
    fichierTexteContacts = fopen("..\\fichiers\\contactsTries.txt", "rt");

    if (fichierTexteContacts == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER contactsTries.txt *****\n");
        exit(1);
    }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier binaire des contacts                                  */
/* -------------------------------------------------------------------------- */
    fichierContacts = fopen("..\\fichiers\\contacts.dat", "wb");

    if (fichierContacts == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER contacts.dat *****\n");
        exit(0);
    }

/* -------------------------------------------------------------------------- */
/* Lecture du premier produit :                                               */
/* -------------------------------------------------------------------------- */
    fgets(ligne, 200, fichierTexteContacts);

    while(!feof(fichierTexteContacts))
    {
        //puts(ligne);
        isole(ligne, mot);
        contact.numero = atoi(mot);
        isole(ligne, contact.nom);
        isole(ligne, contact.adresse);
        isole(ligne, contact.codePostal);
        isole(ligne, contact.ville);
        isole(ligne, mot);
        contact.codeSecteur = atoi(mot);

        fwrite(&contact, sizeof(CONTACT), 1, fichierContacts);
        fgets(ligne, 200, fichierTexteContacts);
    }

    fclose(fichierContacts);
    fclose(fichierTexteContacts);

    return 0;
}
