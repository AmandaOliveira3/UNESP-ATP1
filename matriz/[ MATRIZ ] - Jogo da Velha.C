
#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	int linha,coluna,partida,aux=0,i=0,win=1,j=0;
	char mat_[3][3] ={ {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '},	};
	while(win)
	{	partida=1;
		do{
		scanf(" %d%d",&linha,&coluna);
		if ( linha>=0 && linha < 3 && coluna >= 0 && coluna < 3 && mat_[linha][coluna] ==' ' )
		{
								
			if (aux%2==0 )
			{
			 	mat_[linha][coluna]='x';
			}
			 else 
			{
				
				mat_[linha][coluna]='o';
			}
			aux++;
			partida=0;
		}
		else 
			{
				printf("Erro\n");	
			}
		}while(partida);
		
		if(aux>=5)
		{	for(j=0;j<3;j++)
			{// jogador 1 ganha por linha
				if(mat_[j][0]=='x' && mat_[j][1]=='x' && mat_[j][2]=='x' )
				{	printf ("Jogador 1 venceu\n");
					printf ("Linha %d\n",j);
					win=0;
					break;} }
			for(j=0;j<3;j++)
			{// jogador 1 ganha por coluna
				if(mat_[0][j]=='x' && mat_[1][j]=='x' && mat_[2][j]=='x' )
				{	printf ("Jogador 1 venceu\n");
					printf ("Coluna %d\n",j);
					win=0;
					break;} }
			
				if(mat_[0][0]=='x' && mat_[1][1]=='x' && mat_[2][2]=='x' )
				{	printf ("Jogador 1 venceu\n");
					printf ("Diagonal principal\n");
					win=0;
				}		
				if(mat_[2][0]=='x' && mat_[1][1]=='x' && mat_[0][2]=='x' )
				{	printf ("Jogador 1 venceu\n");
					printf ("Diagonal secundaria\n");
					win=0;
					}
			for(j=0;j<3;j++)
			{
			// jogador 2 ganha por linha
				if(mat_[j][0]=='o' && mat_[j][1]=='o' && mat_[j][2]=='o' )
				{	printf ("Jogador 2 venceu\n");
					printf ("Linha %d\n",j);
					win=0;
					break;}}
			for(j=0;j<3;j++)
			{// jogador 2 ganha por coluna
				if(mat_[0][j]=='o' && mat_[1][j]=='o' && mat_[2][j]=='o' )
				{	printf ("Jogador 2 venceu\n");
					printf ("Coluna %d\n",j);
					win=0;
					break;
					}	}	
			
				if(mat_[0][0]=='o' && mat_[1][1]=='o' && mat_[2][2]=='o' )
					{	printf ("Jogador 2 venceu\n");
						printf ("Diagonal principal\n");
						win=0;
					}	
				
				if(mat_[0][2]=='o' && mat_[1][1]=='o' && mat_[2][0]=='o' )
					{	printf ("Jogador 2 venceu\n");
						printf ("Diagonal secundaria\n");
						win=0;
						}
				if(aux==9 && win!=0)// Se for empate
					{printf("Empate\n");
						win=0;	}
			
		}
	} 		
			for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
							
					printf("%c",mat_[i][j]);
					}
					printf("\n");
				}		
}

