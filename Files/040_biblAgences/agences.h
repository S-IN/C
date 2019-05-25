/* ========================================================================== */
/* agences.h : entete des fonctions de gestion d'agence                       */
/* ========================================================================== */

typedef struct
{
    int numero;
    char nom[81];
} AGENCE;

/* -------------------------------------------------------------------------- */
/* Recherche du numero d'ENREGISTREMENT de l'agence numeroAgence              */
/* -------------------------------------------------------------------------- */
/* Valeur de retour : numero d'ENREGISTREMENT                                 */
/*                              ou                                            */
/*                    -1 si numeroAgence n'existe pas                         */
/* -------------------------------------------------------------------------- */
int chercheAgence(int numeroAgence, FILE* fichierAgences);
