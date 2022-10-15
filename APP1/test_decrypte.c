#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 10000


typedef char vecteur_char[TAILLE_MAX];

typedef struct{
	int len;
	vecteur_char tab;
}seq;

void removeC(seq txt,int x, int start){
    for(int i = start; txt.tab[i]!='\0';i++){
        txt.tab[i]=txt.tab[x+start];
        x++;
	txt.len--;
    }
    
}

void insertChar(seq txt, char c, int pos){
	int len=txt.len;
	for (int i=len-1; i>=pos;i--){
		txt.tab[i+1]=txt.tab[i];
	}
	txt.tab[pos]=c;
	txt.len++;
	

}


void decrypting(seq txt, seq enc){
	char c;
	seq temp;
	int x;
	int lentxt=txt.len;
	int lenenc=enc.len;
	while (enc.tab[0]=='\0'){
		c=enc.tab[lenenc-1];
		insertChar(txt,c,0);
		x=c%8;
		if (x>0 && lentxt>x){
			strcpy(&txt.tab[lentxt-x],temp.tab);
			removeC(txt,x,lentxt-x);
			for (int j=0;j<x;j++){
				insertChar(txt, temp.tab[j], j+1);
			}
		}
		removeC(enc,1,lenenc-1);
	
	}
}

int main(){
	seq txt;
	seq enc;
	enc.len = 20;
	strcpy("Pee ct mosusriae.ttg",enc.tab);
	decrypting( txt, enc);
	printf("%s",txt.tab);
	
	return 0;
}

	