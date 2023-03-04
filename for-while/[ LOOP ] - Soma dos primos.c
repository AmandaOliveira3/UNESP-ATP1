#include<stdio.h>
int main (void)
{
	int n1,n2,x,i,soma=0;
	scanf("%d %d",&n1,&n2);
	
// se todo numerpo primo so é divisivel por 1 e por ele mesmo ,pode ser fazer a divisao a divisao por 1  e o propio numero ser certa e todas as outras serem erradas 
	for(n1=n1;n1<=n2;n1++)
	{ 	
		x=0;		
		for(i=1;i<=n1;i++)
		{			
			if(n1%i==0)
			{
				x++;				
			}
			if(x>2)
			{
				break;
			}
		}	
		   if(x==2)
			{
				soma=soma+n1;
			}	
		}	
	printf("%d",soma);
}
