/*Elabore uma sub-rotina que leia um número não determinado de valores positivos e retorne a média aritmética desses valores. 
A condição de parada se dá ao entrar um valor negativo.*/
#include <stdio.h>
//#include <conio.h>
float media(void);

int main(void)
{
    printf("%.2f", media());

   // return 0;
}
float media(void){
	int num;
	int soma=0;
	float contador=0;
	float media;
	while(1){
		scanf("%d",&num);
		if(num<0)
		break;
		
		else{
			soma+=num;
			contador++;	}
	}
	media = soma/contador;
	return media;
}

