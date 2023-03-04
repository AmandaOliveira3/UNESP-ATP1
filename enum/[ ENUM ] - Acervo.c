#include<stdio.h>

typedef enum s_modalidade{
	MESTRADO=1,
	DOUTORADO=2,
}MODALIDADE;

typedef struct S_livros{
	char autor[30],titulo[30],editora[30],cidade[30];
	int ano;
}LIVROS;

typedef struct S_teses {
	int mes,ano;
	char autor[30],titulo[30],universidade[30],programa[30],orientador[30];
	MODALIDADE tipo;
}TESES;

typedef struct s_periodicos{
	int volume,mes,ano,n_paginas;
	char titulo[30],editora[30],cidade[30];
}PERIODICOS;

typedef union s_obra{
	LIVROS livros;
	TESES teses;
	PERIODICOS periodico;
	
}OBRA;
typedef enum s_indetificador{
	E_LIVROS=1,
	E_TESES=2,
	E_PERIODICOS=3,
}INDENTIFICADOR;

typedef struct S_trabalho{
	INDENTIFICADOR tipo;
	OBRA conclusao;
    
}TRABALHO;

int main(){
	const int tm=5;
	int opcao,i=0,cadastro=0,verifica=0,cont_tese=0,cont_livro=0,cont_per=0,conf[tm],consulta=0,cont_cadastro=0;
	
	TRABALHO vetor[tm];
	
	do{
		scanf(" %d",&opcao);
		switch(opcao){
			case 1:{
				if(cont_cadastro==5){
					printf("Limite de cadastros excedido!\n");
				}
				else{
					scanf(" %u",&cadastro);
					switch(cadastro){
						case 1:{// cadastro livro
						
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.livros.autor );
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.livros.titulo );
							
							scanf(" %d",&vetor[cont_cadastro].conclusao.livros.ano);
							
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.livros.editora );
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.livros.cidade );
							
							printf("-----Livro Cadastrado!-----\n");
							conf[cont_cadastro]=E_LIVROS;
							cont_cadastro++;
							cont_livro++;
							break;
						}
						case 2:{//cadastro tese
							
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.teses.autor);
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.teses.titulo);
							
							scanf(" %d",&vetor[cont_cadastro].conclusao.teses.mes);
							scanf(" %d",&vetor[cont_cadastro].conclusao.teses.ano);
							
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.teses.universidade);
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.teses.programa);
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.teses.orientador);
							scanf(" %u",&vetor[cont_cadastro].conclusao.teses.tipo);
							
							printf("-----Tese Cadastrada!-----\n");
							conf[cont_cadastro]=E_TESES;
							cont_cadastro++;
							cont_tese++;
							break;
						}
						case 3:{// cadastro periodico
							
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.periodico.titulo);
							
							scanf(" %d",&vetor[cont_cadastro].conclusao.periodico.volume );
							scanf(" %d",&vetor[cont_cadastro].conclusao.periodico.mes);
							scanf(" %d",&vetor[cont_cadastro].conclusao.periodico.ano);
							
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.periodico.editora);
							scanf(" %[^\n]",vetor[cont_cadastro].conclusao.periodico.cidade );
							
							scanf(" %d",&vetor[cont_cadastro].conclusao.periodico.n_paginas);
							printf("-----Periodico Cadastrado!-----\n");	
							conf[cont_cadastro]=E_PERIODICOS;
							cont_cadastro++;
							cont_per++;
							break;
						}
					}
				}
				break;
			}
			case 2:{
					scanf(" %d",&consulta);
					verifica=0;
					for(i=0;i<cont_cadastro;i++){
					
							if(verifica<cont_livro && consulta==E_LIVROS &&conf[i]==E_LIVROS){
								printf("Autor: %s\n",vetor[i].conclusao.livros.autor);
								printf("Titulo: %s\n", vetor[i].conclusao.livros.titulo);
								printf("Ano: %d\n", vetor[i].conclusao.livros.ano);
								printf("Editora: %s\n",vetor[i].conclusao.livros.editora);
								printf("Cidade: %s\n", vetor[i].conclusao.livros.cidade);
								printf("-----------------\n");
								verifica++;
							}
			
							if(verifica<cont_tese && consulta==E_TESES &&conf[i]==E_TESES ){
								printf("Autor: %s\n", vetor[i].conclusao.teses.autor);
								printf("Titulo: %s\n", vetor[i].conclusao.teses.titulo);
								printf("Mes: %d\n", vetor[i].conclusao.teses.mes);
								printf("Ano: %d\n", vetor[i].conclusao.teses.ano);
								printf("Universidade: %s\n", vetor[i].conclusao.teses.universidade);
								printf("Programa: %s\n", vetor[i].conclusao.teses.programa);
								printf("Orientador: %s\n", vetor[i].conclusao.teses.orientador);
								printf("Graduacao: %u\n", vetor[i].conclusao.teses.tipo );
								printf("-----------------\n");
								verifica++;		
								
							}
			
							if(verifica<cont_per && consulta==E_PERIODICOS && conf[i]==E_PERIODICOS){
								printf("Titulo: %s\n",vetor[i].conclusao.periodico.titulo);
								printf("Volume: %d\n",vetor[i].conclusao.periodico.volume);
								printf("Mes: %d\n",vetor[i].conclusao.periodico.mes);
								printf("Ano: %d\n",vetor[i].conclusao.periodico.ano);
								printf("Editora: %s\n",vetor[i].conclusao.periodico.editora);
								printf("Cidade: %s\n",vetor[i].conclusao.periodico.cidade);
								printf("Numero de paginas: %d\n",vetor[i].conclusao.periodico.n_paginas);
								printf("-----------------\n");
								verifica++;
						}
							
						}
					
					break;
				}
			case 3:{
				printf("Fim de execucao\n");
				break;
			}}
		
	}while(opcao!=3);
}
