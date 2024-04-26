#include <bits/stdc++.h> //inclusão de um conjunto de bibliotecas interessantes para maratona

using namespace std;

/*
verificar a diferença entre quem pagou mais quem pagou menos e a media que deveria ser paga
*/

int main(){
    
    //d dolar, c cent
    int n, i, d, c;

    //o valor armazenado em totalEstudante será em centavos
    // te total por estudante, tg total gasto e gm gasto medio
    // duas variaveis para diferenciar a diferença de 1 centavo
    int te[1000],tg, gmAcima, gmAbaixo;
    char p; // apenas para a leitura do ponto que separa os digitos
    // valor por estudante a pagar ou receber
    int v, vp, vn;

    while(true){
        cin >> n;

        tg =0;
        //deve ser encerrado
        if (n==0) break;

        for (i=0; i<n; i++){
            // da pra fazer sem p scanf("%d.%d",&d,&c);
            cin >> d >> p >> c; 
            te[i] = d*100 + c;
            tg += te[i];
        }

        gmAbaixo = tg/n;
        //caso a quantidade de centavos não seja exatamente divisível por N o centavo sobrando deve ser considerado
        gmAcima = gmAbaixo + ((tg%n) ? 1 : 0);

        vn = 0; vp=0;
        for (i=0; i<n; i++){
            if (te[i]>gmAcima)  vp+= te[i]- gmAcima;
            if (te[i]<gmAbaixo) vn+= -(te[i]- gmAbaixo);
        }

        v = max(vp,vn);

        printf("$%d.%02d\n",v/100,v%100);

    }

    return 0;
}
