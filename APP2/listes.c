#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"
#include <ctype.h>


/*
 *  Auteur(s) : Ivanina et Preshti
 *  Date : 
 *  Suivi des Modifications :
 *
 */

bool silent_mode = false;

void ajout_en_tete(sequence_t *l, char n) {
    /* votre code ici */
    cellule_t *node;
    node = malloc (sizeof(cellule_t));
    node->command = n;
    node->suivant = l->tete;
    l->tete = node;
}

cellule_t* nouvelleCellule (void)
{
    /* À compléter (utiliser malloc) */
    //printf("\n>>>>>>>>>>> A Faire : liste.c/nouvelleCellule() <<<<<<<<<<<<<<<<\n");
    cellule_t *cel_p;
    cel_p = malloc (sizeof(cellule_t));
    return cel_p;
}


void detruireCellule (cellule_t* cel)
{
    /* À compléter (utiliser free) */
    //printf("\n>>>>>>>>>>> A Faire : liste.c/detruireCellule() <<<<<<<<<<<<<<<<\n");
    // sequence_t *seq=NULL;
    // cellule_t *current = seq->tete;
    // cellule_t *prev;
    // while(current != cel && current!=NULL){
    //     prev = current;
    //     current = current->suivant;
    // }
    // if(current == NULL){
    //     return;
    // }
    // prev->suivant = current->suivant;
    free(cel);
}


void conversion (char *texte, sequence_t *seq)
{
  /* À compléter */
    //printf("\n>>>>>>>>>>> A Faire : liste.c/conversion() <<<<<<<<<<<<<<<<\n");

    int i =strlen(texte)-1;
    while(i>=0){
        if(texte[i] != ' '){
            ajout_en_tete(seq,texte[i]);
            
        }
        i--;
    }
}


void afficher (sequence_t* seq)
{
    assert (seq); /* Le pointeur doit être valide */
    
    cellule_t *c;
    c = seq->tete;
    while (c->suivant!=NULL) {
        if(c->suivant->suivant==NULL){
            printf(" %c",c->command);
        }else{
            printf(" %c->",c->command);
        }
        
        c = c->suivant;
    }
    printf("\n");
}

