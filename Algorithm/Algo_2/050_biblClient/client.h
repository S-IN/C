/* ========================================================================== */
/* client.h : entetes des fonctions de gestion du fichier client              */
/* ========================================================================== */

/* ========================================================================== */
/* Structure CLIENT                                                           */
/* -------------------------------------------------------------------------- */
/* noCli       : numero de client (identifiant)                               */
/* nom         : nom (prenom) du client                                       */
/* adresse     : adresse du client (Ex : 1, rue Barbe)                        */
/* cPost       : code postal                                                  */
/* ville       : ville                                                        */
/* noRep       : numero de représentant                                       */
/* codPays     : Code pays                                                    */
/* codSit      : code situation ('D' : débit, 'C' : crédit)                   */
/* solde       : montant du solde                                             */
/* ========================================================================== */


typedef struct
{
   char  noCli[5];
   char  nom[51];
   char  adresse[51];
   char  cPost[6];
   char  ville[51];
   char  noRep[4];
   char  codPays[3];
   char  codSit;
   float solde;
} CLIENT;



/* ========================================================================== */
/* Declaration des fonctions                                                  */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* litClient :   lecture d'un enregistrement du fichier client connaissant    */
/*               la clef (noCli).                                             */
/*                                                                            */
/*               La clef  doit etre renseignee avant l'appel.                 */
/*                                                                            */
/*               Valeur retournee : >0 (numero de l'enregistrement trouve)    */
/*                                   0 (non trouve)                           */
/* -------------------------------------------------------------------------- */
int litClient(CLIENT *c, FILE *fichier);


/* -------------------------------------------------------------------------- */
/* ecritClient : mise à jour ou ajout dans le fichier client connaissant      */
/*               la clef (noCli).                                             */
/*                                                                            */
/*               Remplir TOUS les champs avant d'écrire !                     */
/*                                                                            */
/*               Valeur retournee : >0 (numero de l'enregistrement ecrit)     */
/*                                   0 (non ecrit)                            */
/* -------------------------------------------------------------------------- */
int ecritClient(CLIENT *c, FILE *fichier);
