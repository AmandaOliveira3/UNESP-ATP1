/*Faça um programa que receba a altura (em metro) e o sexo (M ou F) de uma pessoa e que calcule e mostre o seu peso ideal*/

#include<stdio.h>
#include<stdlib.h>
int main(void)
{   

    float altura, peso;
	char sexo;
	scanf(" %f",&altura);
	scanf(" %c",&sexo);
	
	if(sexo == 'M')
	{ peso = (72.7 * altura) - 58;
		}
		else if(sexo == 'F')
		{ 
		peso = (62.1 * altura) - 44.7;
		}
	printf("%.3f", peso);
	
}
