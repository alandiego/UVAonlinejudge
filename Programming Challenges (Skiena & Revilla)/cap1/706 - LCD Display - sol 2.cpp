#include <bits/stdc++.h> //inclusão de um conjunto de bibliotecas interessantes para maratona

using namespace std;

//codifica o tipo de impressão de uma linha
char tipo[5][6] = {
    {"    "},{"   |"},{"|   "},{"|  |"},{" -- "},
    };

//codifica por seção de impressão como é cada numeiro
/*
cada linha representa um numero, cada coluna um tipo de linha de impressão
linha inicial
linha meio
linha final
*/
int Num[10][5] = {
    {4,3,0,3,4},/*0*/
    {0,1,0,1,0},/*1*/
    {4,1,4,2,4},/*2*/
    {4,1,4,1,4},/*3*/
    {0,3,4,1,0},/*4*/
    {4,2,4,1,4},/*5*/
    {4,2,4,3,4},/*6*/
    {4,1,0,1,0},/*7*/
    {4,3,4,3,4},/*8*/
    {4,3,4,1,4}/*9*/
                    };
void PrintNum(int s, char n[]) {
    int i, j, k, tn;
    for(i = 0; i < 5; i++) {
        // diferenciar se a linha dentro do while vai ser impressa 1 vez ou s vezes
        if(i == 0 || i == 2 || i == 4) tn = 1;
        else tn = s;
        for(;tn;tn--) {
            for(j = 0; n[j]; j++) {
                putchar(tipo[Num[n[j]-'0'][i]][0]);
                for(k = 0; k < s; k++)
                    putchar(tipo[Num[n[j] - '0'][i]][1]);
                putchar(tipo[Num[n[j] - '0'][i]][3]);
                if(n[j+1] != '\0') putchar(' ');
            }
            puts("");
        }
    }
}
int main() {
    int s;
    char n[10];
    while(true){
        cin >> s >> n;

        if (s==0) break;

        PrintNum(s, n);
        puts("");
    }
    return 0;
}
