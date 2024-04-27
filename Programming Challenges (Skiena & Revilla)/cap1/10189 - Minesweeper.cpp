#include <bits/stdc++.h> //inclusão de um conjunto de bibliotecas interessantes para maratona

using namespace std;

/*
A ideia a ser utilizada na solução
é criar uma tabela maior que a matriz
que representa o campo preenchendo todos os espaços com '0' e contar quandos '*' sao encontrados na adjacencia
*/

int main(){
    int i, j, m, n, cont=1;
    char temp;
    
    while (true){
        int campo[102][102] = {0};

        scanf("%d %d",&n, &m);
        
        //encerra quando é dado 0 linhas e 0 colunas
        if (n==0 || m==0) break;

        //imprimir quebra de linha que separa os campos
        if (cont>1) printf("\n");

        //leitura das entradas
        for (i=1; i<n+1; i++){
            for (j=1; j<m+1; j++){
                cin >> temp;
                
                if (temp == '*'){
                    //-1 representa bomba
                    campo[i][j] = -1;

                    //atualizar quantidade de bombas em volta da posição [i][j]
                    /*
                    111
                    1*1
                    111
                    */
                    if (campo[i-1][j-1] !=-1)   campo[i-1][j-1]++;
                    if (campo[i-1][j] !=-1)     campo[i-1][j]++;
                    if (campo[i-1][j+1] !=-1)   campo[i-1][j+1]++;
                    if (campo[i][j-1] !=-1)     campo[i][j-1]++;
                    if (campo[i][j+1] !=-1)     campo[i][j+1]++;
                    if (campo[i+1][j-1] !=-1)   campo[i+1][j-1]++;
                    if (campo[i+1][j] !=-1)     campo[i+1][j]++;
                    if (campo[i+1][j+1] !=-1)   campo[i+1][j+1]++;
                } 
            }
        }
        
        printf("Field #%d:\n",cont++);
        for (i=1; i<=n; i++){
            for (j=1; j<=m; j++){
                if (campo[i][j]==-1) printf("*");
                else printf("%d",campo[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
