/* ========================================================================== */
/* Projet : lectureContacts : lecture du fichier des contacts                 */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    fichierContacts = fopen("..\\fichiers\\contacts.dat", "rb");
    if (fichierContacts == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER contacts.dat *****\n");
        exit(0);
    }

/* -------------------------------------------------------------------------- */
/* Boucle de lecture et d'affichage des contacts                              */
/* -------------------------------------------------------------------------- */
    printf("LISTE DES CONTACTS\n\n");
    fread(&contact, sizeof(CONTACT), 1, fichierContacts);

    while (!feof(fichierContacts))
    {
        printf("%5d  %s  %s  %s  %s  %d\n",
               contact.numero,
               contact.nom,
               contact.adresse,
               contact.codePostal,
               contact.ville,
               contact.codeSecteur);

        fread(&contact, sizeof(CONTACT), 1, fichierContacts);
    }

    fclose(fichierContacts);

    return 0;
}
