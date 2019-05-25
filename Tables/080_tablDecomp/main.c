/* ========================================================================== */
/* Projet : tablDecomp                                                        */
/* -------------------------------------------------------------------------- */
/* Decomposition d'un nombre saisi au clavier                                 */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>               /* Pour scanf, printf...                     */

int calculTotal(int tab[], int dernierPoste);
int remplirTableau(int tab[], int nombre, int depart);


int main()
{
    int nombre;                  /* Nombre a decomposer                       */
    int tab[500];                /* Tableau de travail                        */
    int posteVariable;           /* Le total des postes de 0 jusqu'a ce       */
                                 /* poste est <= nombre                       */
    int fin;                     /* Indicateur de fin de traitement (0, 1)    */
    long nombreCombinaisons;     /* Nombre de combinaisons                    */
    int i;

/* -------------------------------------------------------------------------- */
/* Saisie du nombre a decomposer                                              */
/* -------------------------------------------------------------------------- */
    printf("Entrez le nombre a decomposer : ");
    scanf("%d", &nombre);

/* -------------------------------------------------------------------------- */
/* remplissage initial du tableau                                             */
/* -------------------------------------------------------------------------- */
    tab[0] = 1;
    posteVariable = remplirTableau(tab, nombre, 0);
    fin = 0;
    nombreCombinaisons = 0;

    while(fin != 1)
    {

/* -------------------------------------------------------------------------- */
/* Calcul de la valeur correcte de posteVariable et affichage du tableau      */
/* -------------------------------------------------------------------------- */
        tab[posteVariable] += nombre - calculTotal(tab, posteVariable);
        nombreCombinaisons++;

        for (i= 0; i <= posteVariable; i++)
        {
            printf("%-5d", tab[i]);
        }
        printf("\n");


/* -------------------------------------------------------------------------- */
/* Si le traitement n'est pas termine, incrementer le poste precedent         */
/* posteVariable et remplir le tableau a partir ce ce poste                   */
/* -------------------------------------------------------------------------- */
        if (posteVariable == 0)
        {
            fin = 1;
        }
        else
        {
            posteVariable--;
            tab[posteVariable]++;
            posteVariable = remplirTableau(tab, nombre, posteVariable);
        }
    }

    printf("\n\nNombre de combinaisons : %ld\n", nombreCombinaisons);
    return 0;
}

/* ========================================================================== */
/* Calcul du total des postes du tableau tab de 0 a dernierPoste              */
/* ========================================================================== */

int calculTotal(int tab[], int dernierPoste)
{
    int total;
    int i;

    total = 0;
    for (i = 0; i <= dernierPoste; i++)
    {
        total += tab[i];
    }

    return total;
}


/* ========================================================================== */
/* Remplissage du tableau                                                     */
/* -------------------------------------------------------------------------- */
/* nombre : le total des valeurs du tableau doit etre <= nombre               */
/* depart : indice de depart du remplissage (cette case est deja remplie, le  */
/*          tableau se remplit a partir de depart + 1                         */
/* -------------------------------------------------------------------------- */
/* Valeur de retour : indice du dernier poste rempli                          */
/* ========================================================================== */

int remplirTableau(int tab[], int nombre, int depart)
{
    int i;
    int total;             // Total des cases remplies
    int valeurPoste;       // Valeur a mettre dans un poste du tableau
    int posteVariable;     // Numero du poste trouve

/* -------------------------------------------------------------------------- */
/* Calcul du total initial (de 0 a depart)                                    */
/* -------------------------------------------------------------------------- */
    total = calculTotal(tab, depart);

/* -------------------------------------------------------------------------- */
/* Recherche de posteVariable et remplissage du tableau a partir de depart +1 */
/* -------------------------------------------------------------------------- */
    posteVariable = depart;
    valeurPoste = tab[depart] + 1;

    i = depart + 1;
    total += valeurPoste;

    while(total <= nombre)
    {
        posteVariable++;
        tab[i] = valeurPoste;
        valeurPoste++;
        total += valeurPoste;
        i++;
    }

    return posteVariable;
}
