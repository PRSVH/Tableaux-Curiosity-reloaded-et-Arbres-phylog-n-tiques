#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"
#include <stdbool.h>



bool isLeaf(arbre node){
   if(node ==NULL){
      return false;
   }
   if(node->gauche == NULL && node->droit == NULL){
      return true;
   }
   return false;
}

void analyse (arbre racine, int* nb_esp, int* nb_carac)
{
   
   if (racine != NULL){
      if(isLeaf(racine)){
         (*nb_esp)++;
      }else{
         (*nb_carac)++;
         analyse(racine->gauche,nb_esp,nb_carac);
         analyse(racine->droit,nb_esp,nb_carac);
      }
   }

}

void analyse_arbre (arbre racine, int* nb_esp, int* nb_carac)
{

   //(*nb_esp)=0;
   (*nb_carac)=0;
   analyse (racine, nb_esp,nb_carac);
}



/* ACTE II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y mettre les
 * caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 */
int rechercher_espece (arbre racine, char *espece, liste_t* seq)
{
   if(racine == NULL){
      return 1;
   }
   if(strcmp(racine->valeur,espece)==0){
      return 0 ;

   }else{
      if(rechercher_espece(racine->droit,espece,seq)==0 ){
         ajouter_tete(seq,racine->valeur);
         return 0 ;
      }
      if(rechercher_espece(racine->gauche,espece,seq)==0){
         return 0 ;
      }
           
   }
   return 1;

}

// creates a new node for a tree
struct noeud_s *getNewNode(char *val)
{
   noeud *newNode = (arbre)malloc(sizeof(noeud));
   newNode->valeur = malloc( strlen (val) +1 );
   strcpy(newNode->valeur,val);
   newNode->gauche  = NULL;
   newNode->droit = NULL;
   return newNode;
}

/* ACTE III */
/* Doit renvoyer 0 si l'espece a bien ete ajoutee, 1 sinon, et ecrire un 
 * message d'erreur.
 */
int ajouter_espece (arbre* a, char *espece, cellule_t* seq) {
  
   if((*a) == NULL){
      if(seq == NULL){
         (*a) = getNewNode(espece);
         return 0;
      }else{
         (*a) = getNewNode(seq->val);
         ajouter_espece(&((*a)->droit),espece,seq->suivant);
      }
   }
   if((*a)->valeur == NULL){
      if(seq != NULL){
         (*a)->valeur = malloc( strlen (seq->val) +1 );
         strcpy((*a)->valeur,seq->val);
         (*a)->gauche  = NULL;
         (*a)->droit = NULL;
         (*a)->droit = nouveau_noeud();
         
         ajouter_espece(&((*a)->droit),espece,seq->suivant); 
      }else{
         
         (*a)=getNewNode(espece);
         
         return 0;
         
      }
      

   }
   else if(isLeaf(*a)){
      
      if(seq == NULL){
         //there is a espece already -> can't find diff
         printf("Ne peut ajouter %s: possède les mêmes caractères que %s.\n",espece,(*a)->valeur);
         return 1;
      }else{
     
         
         // add the existing element to the left and then replace the value with the next character
         char temp[100000];

         strcpy(temp,(*a)->valeur);
         
         (*a)->gauche = getNewNode(temp);
         strcpy((*a)->valeur,seq->val);
         
         if(seq != NULL && seq->suivant == NULL){
            (*a)->droit = getNewNode(espece);
         }else{
            
            (*a)->droit = nouveau_noeud();
            
            ajouter_espece(&((*a)->droit),espece,seq->suivant);
         }
      }

      
   }else
   {
      
      if(seq == NULL){
        
         if((*a)->gauche == NULL){
            (*a)->gauche = nouveau_noeud();
            ajouter_espece(&((*a)->gauche),espece,seq);

            return 0;
         }else{
            ajouter_espece(&((*a)->gauche),espece,seq);
         }
         
      }else{
         if(strcmp((*a)->valeur,seq->val)==0){
            ajouter_espece(&((*a)->droit),espece,seq->suivant);

         }else{
            ajouter_espece(&((*a)->gauche),espece,seq);
         }
      }
      
   }
   return 0;
}
/* ACTE III-b */
//returns the height of the tree
int maxDepth(arbre node)
{
    if (node == NULL)
        return -1;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->gauche);
        int rDepth = maxDepth(node->droit);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}


/* Print nodes at a given level */
void printGivenLevel(arbre root, int level, FILE* fout)
{
   if (root == NULL)
      return;
   if (level == 1){
      if(!isLeaf(root)){
         fprintf(fout,"%s ", root->valeur);
         
      }
   }
   else if (level > 1)
   {
      printGivenLevel(root->gauche, level-1,fout);
      printGivenLevel(root->droit, level-1,fout);
   }
}

/* Doit afficher la liste des caractéristiques niveau par niveau, de gauche
 * à droite, dans le fichier fout.
 * Appeler la fonction avec fout=stdin pour afficher sur la sortie standard.
 */
//uses functions printGivenLevel and maxDepth
void afficher_par_niveau (arbre racine, FILE* fout) {
   int h = maxDepth(racine);
   int i;
   for (i=1; i<=h; i++)
   {
      printGivenLevel(racine, i,fout);
      fprintf(fout,"\n");

   }
}

// Acte 4

int ajouter_carac(arbre* a, char* carac, cellule_t* seq) {
   return 0;
}
