#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char snum[TAILLE_MAX];

void creer_pile(PileEntiers *p){
    p->n = 0;
}

/* Opérations d'accès */

/* Retourne vrai ssi p est vide */
int est_vide(PileEntiers *p){
    int empty = 0;
    if(p->n == 0){
        empty = 1;
    }
    return empty;
}

/* Renvoie l'entier en haut de la pile */
/* p doit être non vide */
char* sommet(PileEntiers *p){
    if(est_vide(p)==0){
        return p->tab[p->n-1];
    }
    else{
        fprintf(stderr,"%s","ERROR STACK IS EMPTY\n");
        return NULL;
    }
}

/* Renvoie le nombre d'éléments dans la pile */
int taille(PileEntiers *p){
    return p->n;
}

/* Afficher les éléments de la pile */
void print(PileEntiers *p){
    for(int i=0; i<taille(p);i++){
        printf("%s\n",p->tab[i]);
    }
}

/* Opérations de modification */

/* Vider la pile p */
void vider(PileEntiers *p){
    while(taille(p)>0){
        depiler(p);
    }
}

/* Empiler un entier x */
/* Précondition : taille(p) < TAILLE_MAX */
void empiler(PileEntiers *p, char* x){
    if(taille(p)<TAILLE_MAX){
        p->n = p->n+1;
        p->tab[p->n-1] = malloc(strlen(x));
        strcpy(p->tab[p->n-1],x);
    }
    else{
        fprintf(stderr,"%s","ERROR STACK IS FULL");
    }
}

/* Supprimer et renvoyer l'entier en haut de la pile */
/* Précondition : p non vide */
char* depiler(PileEntiers *p){
    if(est_vide(p)==0){
        char* first = p->tab[taille(p)-1];
        p->n--;
        return first;
    }
    else{
        fprintf(stderr,"%s","ERROR STACK IS EMPTY");
        return NULL;
    } 

    
}

void addition(PileEntiers *p){
    if(p->n>=2){
        int a = atoi(&depiler(p)[0]);
        int b = atoi(&depiler(p)[0]);
        int c= a+b;
        sprintf(snum, "%d", c);
        empiler(p, snum);
    }
    else{
        fprintf(stderr,"%s","ERROR NOT ENOUGH ELEMENTS");
        
    }
}

void minus(PileEntiers *p){
    if(p->n>=2){
        int a = atoi(&depiler(p)[0]);
        int b = atoi(&depiler(p)[0]);
        int c= b-a;
        sprintf(snum, "%d", c);
        empiler(p, snum);
    }
    else{
        fprintf(stderr,"%s","ERROR NOT ENOUGH ELEMENTS");
        
    }
}

void multiplication(PileEntiers *p){
    if(p->n>=2){;
        int a = atoi(&depiler(p)[0]);
        int b = atoi(&depiler(p)[0]);
        int c= a*b;
        sprintf(snum, "%d", c);
        empiler(p, snum);
    }
    else{
        fprintf(stderr,"%s","ERROR NOT ENOUGH ELEMENTS");
        
    }
}


