#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

int main() {
    char reponse[MAXREP]; 
    mode_debug(true);

    
    connexion("im2ag-appolab.u-ga.fr", 9999);
   
   
    envoyer_recevoir("login 12003237 IVANOVA", reponse);
    envoyer_recevoir("load projetX", reponse);
    envoyer_recevoir("aide", reponse);	
    envoyer_recevoir("start", reponse);	
    
    envoyer_recevoir("veni vidi vici", reponse);
    printf("%c",'\n');
    
    return 0;
}
