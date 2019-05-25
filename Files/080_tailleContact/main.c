/* ========================================================================== */
/* Projet : tailleContact                                                     */
/* -------------------------------------------------------------------------- */
/* Taille de la structure CONTACT, en octets.                                 */
/* ========================================================================== */
#include <stdio.h>

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
    printf("Taille enreg : %d\n", sizeof(CONTACT));
    return 0;
}
