/*Faça uma sub-rotina que receba um vetor X de 30 elementos inteiros como parâmetro e retorne dois vetores A e B. 
O vetor A deve conter os elementos de X que sejam maiores do que zero e o vetor B os elementos menores ou iguais à zero.*/
#include <stdio.h>

void maior_menor(int *x, int *a, int *b, int tam_v, int *cont_a, int *cont_b);

int main(void)
{	const int linha=30;
	int i=0,vet_[linha],vet_a[linha],vet_b[linha],conta=0,contb=0;
    /* DECLARAÇÃO DAS VARIÁVEIS */

    /* PREENCHER VETOR X */
	for(i=0;i<linha;i++){
			scanf("%d",&vet_[i]);
			if(vet_[i]>0)
				conta++;
			else
				contb++;	}
    maior_menor( vet_,vet_a,vet_b,linha,&conta,&contb );
    /*for(i=0;i<conta;i++){
	printf("%d ", vet_a[i]);}*/
	/*for(i=0;i<contb;i++){
	printf("%d ", vet_b[i]);	}*/
	
	
    return 0;
}
void maior_menor(int *x, int *a, int *b, int tam_v, int *cont_a, int *cont_b)
{	
	int i=0,j=0,c=0;
	for(i=0;i<tam_v;i++){
		if(x[i]>0) 
			{a[j]=x[i];
			j++;}
		else{
			b[c]=x[i];
			c++;}}
	for(i=0;i<*cont_a;i++){
	printf("%d ", a[i]);}			
	for(i=0;i<*cont_b;i++){
		printf("%d ", b[i]);	}
	
			
	//return a,b;
	/*return b;
	return *cont_a;
	return *cont_b;*/
}

/* INCLUA AQUI SUA FUNÇÃO */

