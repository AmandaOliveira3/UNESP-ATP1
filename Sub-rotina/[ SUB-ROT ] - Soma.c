#include <stdio.h>
//#include <conio.h>
/*
Faça uma programa que contenha uma sub-rotina que receba um número inteiro e positivo N 
como parâmetro e retorne a soma dos números inteiros existentes entre o número 1 e N (inclusive).
*/
int soma(int N);

int main(void)
{
    int x;

    scanf("%d",&x);
    printf("%d", soma(x));

    return 0;
}
 int soma(int N){
 	int i=0;
	//int return=0;
	int resultado=0;
	 
 	for(i=1;i<=N;i++)
	 	{
	 		resultado+=i;
 		}
 		return resultado;
 }
