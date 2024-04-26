//#include <bits/stdc++.h> //inclusão de um conjunto de bibliotecas interessantes para maratona
#include<stdio.h>

//função que calcula o tamanho da sequencia de números gerados por n
int tamanhoSequencia(int n){
	int tamanho = 1;
	while (n != 1){
		tamanho++;
		if (n%2 == 0)
			n = n/2;
		else
			n = n*3+1;

	}
	return tamanho;
}

//considera que i é menor que j e retorna o valor da manior sequencia
//de numeros entre i e j (incluindo i e j)
int maiorSequencia(int i, int j){
	int result = tamanhoSequencia(i);
	int k, temp;

	for (k=i+1; k<=j; k++){
		temp = tamanhoSequencia(k);
		if (temp>result)
			result = temp;
	}
	return result;			
}

int main(){
	int i, j, aux;

	//le os valores em pares (encerra quando não há mais valores para serem lidos)
	  while(scanf("%d %d", &i, &j) == 2){
       	//imprime os valores na ordem que foram lidos
		printf("%d %d ", i, j);

		if (i>j){
			aux = i;
			i = j;
			j = aux;
		}
		printf("%d\n",maiorSequencia(i,j));

	}
	return 0;
}
