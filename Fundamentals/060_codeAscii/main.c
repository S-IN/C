/* ========================================================================== */
/* projet : code ascii -- affichage des codes ascii des touches du clavier    */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    char ch;              /* caractere tape */

    ch = _getch();

    while(ch != '\r')
    {
        printf("'%c'  %d\n", ch, ch);
        ch = _getch();
    }
    return 0;
}

