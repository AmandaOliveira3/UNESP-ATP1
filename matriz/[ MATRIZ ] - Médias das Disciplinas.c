#include<stdio.h>
int main (void){
	const int turmas=2;
	const int alunos=5;
	const int disciplinas=2;
	int i=0,j=0,l=0;
	float soma=0,mediaaluno,mediaaluno2,mediaturma,mat[turmas][alunos][disciplinas];
	
	for(i=0;i<turmas;i++)
	{	for(j=0;j<alunos;j++)
		{	for(l=0;l<disciplinas;l++)
			{	scanf("%f",&mat[i][j][l]);	}	}	}
	
	printf("Turma 1\n");
	for(j=0;j<alunos;j++)
		{	for(l=0;l<disciplinas;l++)
				{	soma+=mat[0][j][l];	}
		mediaaluno=soma/2;	
		printf("%.2f\n",mediaaluno);
		soma=0;	}	
	soma=0;	
	printf("Turma 2\n");
	for(j=0;j<alunos;j++)
		{	for(l=0;l<disciplinas;l++)
				{	soma+=mat[1][j][l];		}
		mediaaluno2=soma/2;	
		printf("%.2f\n",mediaaluno2);
		soma=0;	}	
	printf("Media das turmas\n");
	for(i=0;i<turmas;i++)
	{	for(j=0;j<alunos;j++)
		{	for(l=0;l<disciplinas;l++)
				{	soma+=mat[i][j][l];	} }
		mediaturma=soma/10;	
		printf("%.2f\n",mediaturma);
		soma=0;	}
}
