#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "opositeCrypteSeq.c"

#define MAXMSG MAXREP

void takeChars(char *str,char *pass,int x, int start){
    for(int i = 0; i<x;i++){
        pass[i]=str[start+i];
    }
}

int main() {
    char reponse[MAXREP]; // pour stocker la rÃ©ponse du serveur
    //char message[MAXMSG];// pour stocker le message Ã  envoyer au serveur
    char rep[MAXREP];
    // char mes[MAXREP];

    // Affiche les Ã©changes avec le serveur (false pour dÃ©sactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 443);
    
    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 12003237 IVANOVA", reponse);
    envoyer_recevoir("load LostCause", reponse);
    envoyer_recevoir("start", reponse);	
    envoyer_recevoir("aide", reponse);	
    opositecrypteSeq(reponse,rep);
    printf("%s\n",rep);
    
    
    return 0;
}