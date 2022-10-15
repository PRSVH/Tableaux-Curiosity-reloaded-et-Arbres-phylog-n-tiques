#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "BayOfPigs.c"

#define MAXMSG MAXREP

int main() {
    char reponse[MAXREP]; // pour stocker la rÃ©ponse du serveur
    //char message[MAXMSG];// pour stocker le message Ã  envoyer au serveur
    //char rep[MAXREP];
    char mes[MAXREP];

    // Affiche les Ã©changes avec le serveur (false pour dÃ©sactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 443);
    // utilisez le port 443 en cas de problÃ¨me sur le 9999
    /* connexion("im2ag-appolab.u-ga.fr", 443); */

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 12003237 IVANOVA", reponse);
    envoyer_recevoir("load OneMillion", reponse);
    decrypeMove(mes,reponse);
    printf("%s\n",mes);	
    envoyer_recevoir("aide", reponse);
    envoyer_recevoir("start", reponse);	
    // decrypeMove(mes,reponse);
    // printf("%s\n",mes);
    // decrypeMove(mes,rep);	
    // printf("%s\n",mes);
    // envoyer_recevoir("Par otuam eriet",reponse);
    // decrypeMove(mes,reponse);
    // envoyer_recevoir(mes,reponse);


    return 0;
}