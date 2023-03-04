/*Faça uma sub-rotina que receba uma matriz 10X10 e determine o maior elemento acima da diagonal principal. 
Este valor deverá ser mostrado no programa principal.*/
#include <stdio.h>

int elemento(int mat[][10], int linhas, int colunas);

int main(void)
{
    const int linhas=10;
    const int colunas = 10;
	int mat_[linhas][colunas],i=0,j=0;
	/* DECLARAÇÃO DAS VARIÁVEIS */
    for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			scanf("%d",&mat_[i][j]);	}}
	/* PREENCHE MATRIZ */
    printf("%d", elemento(mat_,linhas,colunas));
    //return 0;
}
int elemento(int mat[][10], int linhas, int colunas) {
	int i=0,j=0,maior=0;
	maior = mat[0][1];
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			if(j>i)
			{ if(mat[i][j]>maior)
				{maior=mat[i][j];}	}	}}
	return maior;
}
/* INCLUA AQUI SUA FUNÇÃO */
