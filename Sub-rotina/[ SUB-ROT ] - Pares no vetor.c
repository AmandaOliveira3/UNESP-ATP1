/*Elabore uma sub-rotina que receba um vetor X de 30 números inteiros como parâmetro e retorne a quantidade de valores pares em X.*/
#include <stdio.h>

int qtdade(int *x, int tam_v);

int main(void)
{	const int linha = 30;
	int vet_[linha],i=0;
     /* DECLARAÇÃO DAS VARIÁVEIS */
	for(i=0;i<linha;i++)
	{
		scanf("%d",&vet_[i]);}
    printf("%d", qtdade(vet_,linha));
    return 0;
}
int qtdade(int *x, int tam_v){
	int pares=0;
	int i=0;
	for(i=0;i<tam_v;i++)
	{
		if(x[i]%2==0)
			pares++;	}	
	return pares;
}
/* INCLUA AQUI SUAS FUNÇÕES */
