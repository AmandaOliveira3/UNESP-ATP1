#include<stdio.h>
//#include<conio.h>
int main (void)
{
float salario,salariom=0.0,b=0,c=0,m=0,mediaf,medias,porcentagem ;
int filho,d=0;
//scanf("%d",&filho);

	while(1)
		{
		scanf("%f",&salario);
			if(salario<0)
		    	break;
		c++;  	
		 scanf("%d",&filho);
		 b+=salario;		 
		 d+=filho;
			if(salario>salariom)
				salariom=salario;
			if(salario<=150)
				m++;
		}
			medias=b/c;
			mediaf=d/c;
			porcentagem=(100*m)/c;
			printf("%.2f %.2f %.2f %.2f%%",medias,mediaf,salariom,porcentagem);
}
