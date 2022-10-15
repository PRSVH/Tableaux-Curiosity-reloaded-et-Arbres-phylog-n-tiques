#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "listes.h"
#include "arbres.h"

/* fichier à compléter au besoin */

void init_liste_vide(liste_t* L) {
   //printf ("<<<<< À faire: fonction init_liste_vide fichier " __FILE__ "\n >>>>>");
    /* a completer */
    L->tete = NULL;
}

void liberer_liste(liste_t* L) {
   //printf ("<<<<< À faire: fonction liberer_liste fichier " __FILE__ "\n >>>>>");
    /* a completer */
    
   if(L !=NULL){
        cellule_t *prev = L->tete;
        cellule_t *temp ;
        while (prev!=NULL){
            temp = prev;
            prev = prev->suivant;
            free(temp);
            
        }
   }
    
   
}



int ajouter_tete(liste_t* L, string c) { /* retourne 0 si OK, 1 sinon  */
   //printf ("<<<<< À faire: fonction ajouter_tete fichier " __FILE__ " >>>>>\n");
    /* a completer */
    if(L == NULL){
        return 1;
    }
    cellule_t *node;
    node = malloc (sizeof(cellule_t));
    node->val = c;
    node->suivant = L->tete;
    L->tete = node;
    return 0;
}

int add_on_head_and_delete_last(List_Two_Trees *L, arbre a){

    if(L == NULL){
        return 1;
    }
    ListNode_Tree* node;
    node = malloc(sizeof(ListNode_Tree));
    node->tree = a;
    node->next = L->head;
    L->head = node;
    ListNode_Tree* temp = L->head->next->next->next;
    free(temp);
    L->head->next->next->next = NULL;
    return 0;
}

void afficher (liste_t* seq)
{
    assert (seq); /* Le pointeur doit être valide */
    
    cellule_t *c;
    c = seq->tete;
    while (c->suivant!=NULL) {
        if(c->suivant->suivant==NULL){
            printf(" %s",c->val);
        }else{
            printf(" %s->",c->val);
        }
        
        c = c->suivant;
    }
    printf("\n");
}

void deleteHead(cellule_t* head){
    if (head != NULL){
        cellule_t* temp = head;
        head = head->suivant;
 
        free(temp);
    }
        
 
    // Move the head pointer to the next node
    
 
   
}
