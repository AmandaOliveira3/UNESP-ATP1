#include <stdio.h>
//#include <conio.h>
/*
Fa�a uma programa que contenha uma sub-rotina que receba um n�mero inteiro e positivo N 
como par�metro e retorne a soma dos n�meros inteiros existentes entre o n�mero 1 e N (inclusive).
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
