#include <stdio.h>
#include <string.h>


#define MAXMSG MAXREP

void removeChars(char *str,int x, int start){
    for(int i = start; str[i]!= '\0';i++){
        str[i]=str[x+start];
        x++;
    }
}


void insertCinPos(char *txt, char c, int pos){
	int len=strlen(txt);
	for (int i=len-1; i>=pos;i--){
		txt[i+1]=txt[i];
	}
	txt[pos]=c;

}

int check_if_char_in_seq(char c, char *txt){
    int pos = -1;
    for(int i =0; txt[i]!='\0';i++){
        if(c==txt[i]){
            pos = i;
        }
    }
    return pos;
}


void crypteSeq(char *txt, char *crypte){
    char c;
    char d;
    int lentxt=strlen(txt);
    int lencrypte=0;
    int lenseq = 0;
    char seq[lentxt];
    int i;

    while(txt[0]!='\0'){
        c=txt[0];
        removeChars(txt,1,0);
        lentxt--;
        i =check_if_char_in_seq(c,seq);
        if(i==-1){
            lenseq++;
            lencrypte++;
            insertCinPos(seq,c,lenseq-1);
            insertCinPos(crypte,c,lencrypte-1);
        }else{
            if(i==0){
                d = seq[lenseq-1];
            }
            else{
                d = seq[i-1];
            }
            lencrypte++;
            insertCinPos(crypte,d,lencrypte-1); 
            removeChars(seq,1,i);
            insertCinPos(seq,c,lenseq-1);
        }
        
    }
}

// int main(){
// 	char txt[10000]="There will be no Nineteen Eighty-Four"; // pour stocker la rÃ©ponse du serveur
//     char enc[10000];
// 	crypteSeq( txt, enc);
// 	printf("%s\n",enc);
	
// 	return 0;
// }
