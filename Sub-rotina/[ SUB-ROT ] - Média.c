/*Elabore uma sub-rotina que leia um n�mero n�o determinado de valores positivos e retorne a m�dia aritm�tica desses valores. 
A condi��o de parada se d� ao entrar um valor negativo.*/
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

