#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


#define MAXMSG MAXREP
void removeChars(char *txt,int x, int start){
    for(int i = start; txt[i]!='\0';i++){
        txt[i]=txt[x+start];
        x++;
    }
}

void encrypting(char *txt, char *enc){
    char c;
    int x=0;
    char temp[10000];
    while(txt[0]!='\0'){
        c=txt[0];
        x=c%8;
        strcat(enc,&c);
	    removeChars(txt,1,0);
        if(x!=0 && txt[x-1] !='\0'){
            strncat(temp,txt,x);
	        removeChars(txt,x,0);
	        strcat(txt,temp);
	        temp[0]='\0';
        }
        
    }
}
int main() {
    char reponse[MAXREP]; // pour stocker la rÃ©ponse du serveur
    char message[MAXMSG];// pour stocker le message Ã  envoyer au serveur
    char rep[MAXREP];
    char mes[MAXREP];

    // Affiche les Ã©changes avec le serveur (false pour dÃ©sactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 443);
    // utilisez le port 443 en cas de problÃ¨me sur le 9999
    /* connexion("im2ag-appolab.u-ga.fr", 443); */

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 12003237 IVANOVA", reponse);
    envoyer_recevoir("load crypteMove", reponse);
    envoyer_recevoir("aide", rep);
    encrypting(rep,mes);	
    envoyer_recevoir("start", reponse);	

    envoyer_recevoir(mes, message);
   
    printf ("Reponse du serveur: %s\n", reponse);

    return 0;
}
