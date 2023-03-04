/*Faça um programa que receba dois números e execute uma das operações listadas a seguir de acordo com a escolha do usuário. Se for digitada uma opção inválida mostrar a mensagem de erro abaixo e terminar a execução do programa. As opção são:

Média entre os dois números
Diferença do maior pelo menor
O produto entre os dois números*/ 
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
