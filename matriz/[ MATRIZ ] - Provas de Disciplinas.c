#include<stdio.h>
int main (void){
	const int idade=8;
	const int disciplinas=5;
	int i=0,j=0,k=0,vet_a[disciplinas],vet_b[idade],mat[idade][disciplinas],codigo,prova=0;
	float media,soma=0,contador=0;
	for(i=0;i<idade;i++)// leitura dos alunos
		{	scanf("%d",&vet_b[i]);	}
	for(i=0;i<disciplinas;i++)	// leitura dos codigos
		{	scanf("%d",&vet_a[i]);	}
	for(i=0;i<idade;i++)// leitura do numero das provas
		{	for(j=0;j<disciplinas;j++)	
			{
				scanf("%d",&mat[i][j]);	}	}
	scanf("%d",&codigo);
	for(i=0;i<disciplinas;i++) // se o codigo existe 
		{
			if(codigo==vet_a[i])
				k++;	}
	if (k==0)
		printf("Erro\n");
	else 
	{	for(i=0;i<idade;i++)
		{	if(( 18 <= vet_b[i]) && (vet_b[i] <= 25))	
				{for(j=0;j<disciplinas;j++)	
					{	if(vet_a[j]==codigo)
							{if(mat[i][j]>2)
								prova++;}	}	}	}
	printf("%d\n",prova);	}	
	
	for(i=0;i<idade;i++)
		{	for(j=0;j<disciplinas;j++)	
			{
				if(mat[i][j]<3)
					printf("%d %d %d\n",i,vet_b[i],vet_a[j]);	}	}
					
	for(i=0;i<idade;i++)
		{	for(j=0;j<disciplinas;j++)	
			{
				if(mat[i][j]==0) 
				{
					soma+=vet_b[i];
					contador++;
					break;}	}	}
		
	media=soma/contador;
	printf("%.2f",media);
}
