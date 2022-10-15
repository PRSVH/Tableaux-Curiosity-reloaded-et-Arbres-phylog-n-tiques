#include <stdio.h>
#include <string.h>

void rmChars(char *str,int x, int start){
    for(int i = start; str[i]!= '\0';i++){
        str[i]=str[x+start];
        x++;
    }
}


void insertPos(char *txt, char c, int pos){
	int len=strlen(txt);
	for (int i=len-1; i>=pos;i--){
		txt[i+1]=txt[i];
	}
	txt[pos]=c;

}

int check_char_pos(char c, char *txt){
    int pos = -1;
    for(int i =0; txt[i]!='\0';i++){
        if(c==txt[i]){
            pos = i;
        }
    }
    return pos;
}


void opositecrypteSeq(char *txt, char *crypte){
    char c;
    char d;
    int lentxt=strlen(txt);
    int lencrypte=0;
    int lenseq = 0;
    char seq[100000]="";
    int i;

    while(txt[0]!='\0'){
        c=txt[0];
        rmChars(txt,1,0);
        lentxt--;
        i =check_char_pos(c,seq);
        if(i==-1){
            lenseq++;
            lencrypte++;
            insertPos(seq,c,lenseq-1);
            insertPos(crypte,c,lencrypte-1);
        }else{
            if(i==lenseq-1){
                d = seq[0];
                rmChars(seq,1,0);
            }
            else{
                d = seq[i+1];
                rmChars(seq,1,i+1);
            }
            lencrypte++;
            insertPos(crypte,d,lencrypte-1);
            //rmChars(seq,1,i); 
            insertPos(seq,d,lenseq-1);
        }
        
    }
}
