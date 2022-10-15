#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP
//On crée une fonction qui nous permettra de coder le texte dans le main
void code_cesar(char *texte,int key){
    unsigned long i = 0;
    int pos_alpha;
    char letter;
    key = key % 26;
    while (i < strlen(texte))
    {
        letter = texte[i];
        if (letter>='A'&&letter<='Z'){
            pos_alpha = (letter - 'A' + key)%26;
            if (pos_alpha < 0)
                letter = 'Z' + (pos_alpha-1);
            else{
            letter = 'A' + pos_alpha;
            }
        }
        if (letter>='a'&&letter<='z'){
            pos_alpha = (letter - 'a' + key)%26;
            if (pos_alpha < 0)
                letter = 'z' + (pos_alpha+1);
            else{
                letter = 'a' + pos_alpha;
            }
        }
        texte[i] = letter;
        i++;
    }
}
int main() {
    char reponse[MAXREP]; // pour stocker la réponse du serveur
    char message[MAXMSG]; // pour stocker le message à envoyer au serveur
    char message_code[]="hasta la revolucion";//pour stocker le message codé à envoyer au serveur
    int key;

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 9999);
    // utilisez le port 443 en cas de problème sur le 9999
    /* connexion("im2ag-appolab.u-ga.fr", 443); */

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 12003237 IVANOVA", reponse);
    envoyer_recevoir("load planB", reponse);
    // Notez qu'ici on n'utilise pas la reponse du serveur

    lire_clavier(message);   // message tapé au clavier
    envoyer_recevoir(message, reponse); // on envoie message, et on reçoit la réponse du serveur
    envoyer_recevoir("help", reponse);
    //on cherche d'abord la clé grâce à la premiere letter du message qui sera C
    key = (reponse[0] - 'C')%26;
    if (key<0)
        key = 26 - key;
    //On peut maintenant crypter le message "hasta la revolucion" avec la l'oppose de la key :
    code_cesar(message_code, -key);
    //On envoie le message codé au serveur
    envoyer_recevoir(message_code, reponse);
    lire_clavier(reponse);
    envoyer_recevoir(message, reponse);
    printf("Reponse du serveur: %s", reponse);

    printf ("Fin de la connection au serveur\n");
    return 0;
}
