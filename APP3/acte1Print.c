#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbres.h"
#include "arbresphylo.h"
#include "common_tests.h"

void print_in_file(FILE *file,arbre a){
	if(a == NULL){
        return;
    }
	// if(a->droit == NULL && a->gauche==NULL){
	// 	fprintf(file,"	%s\n",a->valeur);

	// }
	if(a->gauche!=NULL){
		fprintf(file,"	%s -> %s[label = \"non\"]\n",a->valeur,a->gauche->valeur);
    	print_in_file(file,a->gauche);
	}
	if(a->droit!=NULL){
		fprintf(file,"	%s -> %s[label = \"oui\"]\n",a->valeur,a->droit->valeur);
    	print_in_file(file,a->droit);
	}
	 
}

void print_tree_in_file(FILE *outputFile,arbre a){
    
	fprintf(outputFile,"digraph arbre {\n");
	print_in_file(outputFile,a);
	fprintf(outputFile,"}");
	fclose(outputFile);
}