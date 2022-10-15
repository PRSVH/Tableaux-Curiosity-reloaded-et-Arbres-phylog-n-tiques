#include <stdio.h>
#include <string.h>

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

// int main(){
// 	   char enc[1000];
//     char txt[1000] = "Patria o muerte";
// 	encrypting( txt, enc);
// 	printf("%s\n",enc);
	
// 	return 0;
// }
