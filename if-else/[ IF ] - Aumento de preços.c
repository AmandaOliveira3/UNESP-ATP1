#include <stdio.h>

/*Faça um programa que receba o preço, a categoria (1, 2 ou 3) e a situação (R ou N) de um produto. Calcule o valor do aumento de preço
e utilizando a Tabela 2 recalcule para os casos apresentados, caso o aumento esteja fora do escopo da tabela, deve-se tomar o valor calculado.
 Mostre o valor do aumento e o valor final.*/
 
int main(void)
{
	
	float c, p, a, dif, valor ;
	char s;
	
	
	 scanf(" %f%f",&p,&c);
	 scanf(" %c",&s);
	 
	
	if((p <= 25.00) && (c == 1)) // primeiro caso , aumento 
	 { a = 1.05*p;}
	    else if ((p <=25.00) && (c == 2))
	    {a = 1.08*p ;}
         else if ((p<=25.00) && (c == 3))
	     {a = 1.10*p ;}
	     	     
    if((p >= 25.00) && (c == 1)) 
	     { a = 1.12*p;}
	    else if ((p >=25.00) && (c == 2))
	     { a = 1.15*p ;}
          else if ((p>=25.00) && (c == 3))
	      {a = 1.18*p ;}
	      
	 dif= a - p;     
		
	if((dif <= 0.99) && (s == 'N')) 
 	   {dif = 2.00;}
	   else if ((dif<=0.99) && (s == 'R'))
		{dif = 1.00;}
		 else if ((dif >= 99.00) && (s =='N'))
		 {dif = 20.00;}
		  else if ((dif >= 99.00) && (s == 'R'))
		  { dif = 10.00;}
		
	valor = p + dif;
	
	printf("%.2f ", dif);
	printf("%.2f", valor);
	
	
}
