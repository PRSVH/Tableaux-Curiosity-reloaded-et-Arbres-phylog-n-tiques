#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"
#include "curiosity.h"
#include "stack.h"


/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */

void stop (void)
{
    char enter = '\0';
    printf ("Appuyer sur entrée pour continuer...\n");
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
}



int interprete (sequence_t* seq, bool debug)
{
    // Version temporaire a remplacer par une lecture des commandes dans la
    // liste chainee et leur interpretation.

    char commande;

    //debug = true; /* À enlever par la suite et utiliser "-d" sur la ligne de commandes */

    printf ("Programme:");
    afficher(seq);
    printf ("\n");
    if (debug) stop();

    // À partir d'ici, beaucoup de choses à modifier dans la suite.
    //printf("\n>>>>>>>>>>> A Faire : interprete.c/interprete() <<<<<<<<<<<<<<<<\n");
    cellule_t *curr = seq->tete;
    commande = curr->command ; //à modifier: premiere commande de la sequence

    PileEntiers p;
    creer_pile(&p);
    
    int ret;         //utilisée pour les valeurs de retour
    char *str = NULL;
    char s[10];
    //int counter=0;
    char* F;
    char* V;
    int count_opening_curly;
    int count_closing_curly;
    while ( curr != NULL ) { //à modifier: condition de boucle

        switch (commande) {
            /* Ici on avance tout le temps, à compléter pour gérer d'autres commandes */

            case 'A':
                ret = avance();
                if (ret == VICTOIRE) return VICTOIRE; /* on a atteint la cible */
                if (ret == RATE)     return RATE;     /* tombé dans l'eau ou sur un rocher */
                break; /* à ne jamais oublier !!! */
            case 'D':
                droite();
                break;
            case 'G':
                gauche();
                break;
            case '0' ... '9':
                strcpy(s,&commande);
                empiler(&p,s);
                print(&p);
                break;
            case '+':
                addition(&p);
                print(&p);
                break;
            case '-':
                minus(&p);
                print(&p);
                break;
            case '*':
                multiplication(&p);
                print(&p);
                break;
            case 'P':
                print(&p);
                pose(atoi(&depiler(&p)[0]));
                break;
            case 'M':
                print(&p);
                mesure(atoi(&depiler(&p)[0]));
                break;
            case '{':
                count_opening_curly++;
                while((curr->command != '}')&&(count_opening_curly!=count_closing_curly)){
                    strcat(str,&curr->command);
                    if(curr->command == '}') count_closing_curly++;
                    if(curr->command == '{') count_opening_curly++;
                    curr = curr->suivant;
                    commande = curr->command;
                }
                count_closing_curly++;
                strcat(str,"}");
                empiler(&p,str);
                count_opening_curly = 0;
                count_closing_curly = 0;
                break;
            case '}':
                break;
            case '?':
                strcpy(depiler(&p),F);
                // insert F in linked list
                strcpy(depiler(&p),V);
                // insert v in linked list
                int b = atoi(&depiler(&p)[0]);
                if(b==0){
                    //int i =1;
                    // while(strlen(F)>i-2){
                    // V
                    // }
                }else{
                    //v
                }

                break;
            default:
                eprintf("Caractère inconnu: '%c'\n", commande);
                break;
                
        }
        curr = curr->suivant;
        commande = curr->command;

        /* Affichage pour faciliter le debug */
        afficherCarte();
        printf ("Programme:");
        afficher(seq);
        printf ("\n");
        if (debug) stop();
    }

    /* Si on sort de la boucle sans arriver sur la cible,
     * c'est raté :-( */

    return CIBLERATEE;
}




