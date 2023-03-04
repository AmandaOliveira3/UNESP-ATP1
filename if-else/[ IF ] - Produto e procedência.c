/*Faça um programa que receba o código de origem e mostre a sua procedência. A procedência obedece à tabela a seguir.*/
#include<stdio.h>
int main(void)
{
	int codigo;
	scanf(" %d",& codigo);
	
	if (codigo ==1)
	{ 
		printf ("Sul");
	}
	else if (codigo == 2)
	{
		printf ("Norte");
	}
	else if (codigo == 3)
	{
		printf ("Leste");
	}
	else if (codigo == 4)
	{
		printf ("Oeste");
	}
	else if ((codigo==5) || (codigo==6))
	{
		printf ("Noroeste");
	}
	else if ((codigo==7) || (codigo==8) || (codigo==9))
	{
		printf ("Sudeste");
	}
	else if ((codigo >=10) && (codigo<=20))
	{
		printf ("Centro-oeste");
	}
	else if ((codigo >=21) && (codigo<=30))
	{
		printf ("Nordeste");
	}

}
