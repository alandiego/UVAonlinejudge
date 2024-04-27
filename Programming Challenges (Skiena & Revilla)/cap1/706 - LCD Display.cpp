#include <bits/stdc++.h> //inclusão de um conjunto de bibliotecas interessantes para maratona

/*
    a ideia pra solução é separar por conj de linhas com mesma caracteristica de impressão. primeira linha. linha intermediaria entre inicio e meio. linha do meio. intermediaria entre linha do meio e final e linha final.
*/

using namespace std;



int main(){
	int s, i, j, k;
    char n[10];

    while (true){
        cin >> s >> n;

        if (s==0) break;

        //imprime primeira linha
        for(j=0; j<strlen(n); j++){
            //printf("%c %c",n[j], n[j+1]);
            printf(" ");
            for(k=0; k<s; k++){
                if (n[j]!='1' && n[j]!='4' ) printf("-");
                else printf(" ");
            }
            printf(" ");
            if(n[j+1]!='\0') printf(" ");
        }
        printf("\n");
        
        //imprime linhas entre início e meio
        for (i = 0; i<s; i++){
            for(j=0; j<strlen(n); j++){
                if (n[j]!='1' && n[j]!='2' && n[j]!='3' && n[j]!='7' ) printf("|");
                else printf(" ");		
                for(k=0; k<s; k++){
                    printf(" ");
                }
                if (n[j]!='5' && n[j]!='6' ) printf("|");
                else printf(" ");
                if(n[j+1]!='\0') printf(" ");
            }
            printf("\n");
        }

        //imprime linha do meio
        for(j=0; j<strlen(n); j++){
            printf(" ");		
            for(k=0; k<s; k++){
                if (n[j]!='1' && n[j]!='7' && n[j]!='0' ) printf("-");
                else printf(" ");
            }
            printf(" ");
            if(n[j+1]!='\0') printf(" ");
        }
        printf("\n");

        //imprime linhas entre meio e fim
        for (i = 0; i<s; i++){
            for(j=0; j<strlen(n); j++){
                if (n[j]!='1' && n[j]!='3' && n[j]!='4' && n[j]!= '5' 
                        && n[j]!= '7' && n[j]!= '9') printf("|");
                else printf(" ");		
                for(k=0; k<s; k++){
                    printf(" ");
                }
                if (n[j]!='2') printf("|");
                else printf(" ");
                if(n[j+1]!='\0') printf(" ");
            }
            printf("\n");
        }

        //imprime ultima linha
        for(j=0; j<strlen(n); j++){
            printf(" ");
            for(k=0; k<s; k++){
                if (n[j]!='1' && n[j]!='4' && n[j]!='7' ) printf("-");
                else printf(" ");
            }
            printf(" ");
            if(n[j+1]!='\0') printf(" ");
        }
        printf("\n\n");
    }
    return 0;
}
