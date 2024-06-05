#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

/*
A ideia da solução é utilizar dois vetores. Um (v) que armazena todos os valores de entrada.
o segundo (d) tem como referencia o índice. caso d[i] == 0 significa que i não foi uma diferença absoluta encontrada.
basta checar então se existe um valor em d diferente de 1;
  */

int main()
{
    int n;
    int v[3002];
    int d[3001];
    int i;
    bool result;
    while (scanf("%d",&n)!=EOF){
        result = true;
        

        for (i=0; i<n; i++){
            cin >> v[i];
            d[i]=0;
        }
        
        for (i=0; i<n-1;i++){
            d[abs(v[i]-v[i+1])-1]++;
        }
        
        if (n==1){
            result = true;
        } else{
            for (i=0; i<n-1; i++){
                if (d[i]!= 1){
                    result = false;
                    break;
                }
            }   
        }
            
        
            
        if (result){
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
        
        
    }

    return 0;
}
