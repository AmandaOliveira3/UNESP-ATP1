/*Fa�a um programa que receba dois n�meros e execute uma das opera��es listadas a seguir de acordo com a escolha do usu�rio. Se for digitada uma op��o inv�lida mostrar a mensagem de erro abaixo e terminar a execu��o do programa. As op��o s�o:

M�dia entre os dois n�meros
Diferen�a do maior pelo menor
O produto entre os dois n�meros*/ 
#include<stdio.h>
int main(){
	
int dif,pod;
float n1,n2,med,op ;	

scanf(" %f%f%f",&n1, &n2, &op);

 if(op == 1)
 { med= (n1 + n2)/ 2;
 printf("%.2f", med);
 }
 
 else if(op==2)
    {if (n1>n2 ){
    dif= n1 - n2;
     printf("%d", dif);}
     else if(n2>n1){
	  dif = n2 - n1;
      printf("%d", dif);}}
      
     else if(op==3)
     { pod = n1*n2;
     printf("%d", pod);
     }
  else if (op > 3) 
  {printf("Entrada incorreta");}	
}
