#include <stdio.h>
#include <string.h>

#define MAXMSG MAXREP

void removeC(char *str,int x, int start){
    for(int i = start; str[i]!= '\0';i++){
        str[i]=str[x+start];
        x++;
    }
}

void insertChar(char *txt, char c, int pos){
	int len=strlen(txt);
	for (int i=len-1; i>=pos;i--){
		txt[i+1]=txt[i];
	}
	txt[pos]=c;

}


void decrypeMove(char *txt, char *enc){
    char c;
    int x=0;
    char temp[10000];
    int lenenc=strlen(enc);
    int lentxt=0;
	

    while(enc[0]!='\0'){
        c=enc[lenenc-1];
        insertChar(txt,c,0);
        lentxt++;
        x=c%8;
        if (x>0 && lentxt>x){
			strcpy(temp,&txt[lentxt-x]);
			removeC(txt,x,lentxt-x);
			for (int j=0;j<x;j++){
				insertChar(txt, temp[j], j+1);
			}
		}
		removeC(enc,1,lenenc-1);
        lenenc--;
        //enc[lenenc-1]='\0';
        
    }
}

// int main(){
// 	char txt[100]; // pour stocker la rÃ©ponse du serveur
//     char enc[1000] = "Patria o muerte";
// 	decrypeMove( txt, enc);
// 	printf("%s",txt);
	
// 	return 0;
// }

