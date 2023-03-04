#include<stdio.h>

int main(void)
{	const int tam1= 15;
	const int tam2= 10;
	int vet_logica[tam1],vet_linguagem[tam2],a=0,i=0;
		for(a=0;a<tam1;a++)
			{
			//printf(" nota %d",a+1);
			scanf("%d",&vet_logica[a]);
			}
			
		for(i=0;i<tam2;i++)
			{
			//printf("nota de linguagem %d",i+1);	
			scanf("%d",&vet_linguagem[i]);
			}
			a=0;
			i=0;	
		for(i=0;i<tam2;i++)
			{	for(a=0;a<tam1;a++)
				{
					if(vet_linguagem[i]==vet_logica[a])
						printf("%d ",vet_linguagem[i]);
				}	
			}
}
