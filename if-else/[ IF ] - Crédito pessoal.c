/*Um banco conceder� um cr�dito especial aos seus clientes de acordo com o saldo m�dio no �ltimo ano. 
Fa�a um programa que receba o saldo m�dio de um cliente e calcule e mostre o valor do cr�dito .*/
#include<stdio.h>

int main(void)
{
	float saldo, per;
	scanf(" %f",&saldo);
	
	if(saldo<=199.99){
		per = 0.10*saldo;
		printf("%.2f",per );
	}
	if((saldo>=200.00 ) && (saldo<=299.99)){
		per = 0.20*saldo;
		printf("%.2f",per );
	}
	if((saldo>=300.00 ) && (saldo<=399.99)){
		per = 0.25 *saldo;
		printf("%.2f",per );
	}
	if(saldo>=400.00){
		per = 0.30*saldo;
		printf("%.2f",per );
	}
	
	
}
