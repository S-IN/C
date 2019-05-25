/* ========================================================================== */
/* chaines.h : Prototypes des fonctions developpees dans le TP biblChaines    */
/* ========================================================================== */

int compteLettres(char* ligne, char lettre);
void enleveLettres(char* ligne, char lettre);
char* inverse(char* ligne);
int pcdc(char* chaine, int* pc, int *dc);
void placeSousChaine(char* chaine, char* sChaine, int pos, char cadrage);
