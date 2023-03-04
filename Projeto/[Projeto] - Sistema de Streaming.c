#include<stdio.h>
#include<string.h>
/* 		PARTE FINAL  	*/

	typedef enum e_status{
		INATIVO,ATIVO,
	}STATUS;
	
	typedef struct s_cliente{// maximo 10 clientes.
		int CPF;
		char nome[50];
		char email[50];
		char telefone[50];
		STATUS est_status;
	}CLIENTE;
	
	typedef enum e_genero{
		AVENTURA,COMEDIA,DRAMA,TERROR,ACAO,ROMANCE,
	}GENERO;
	
	typedef enum e_classificao{
		LIVRE,MDEZ,MDOZE,MQUATORZE,MDEZESSEIS,MDEZOITO,
	}CLASSIFICACAO;
	
	typedef struct s_filmes{//maximo de 10 filmes.codigo começa em 1001
		int cod_unico;
		char nome[50];
		GENERO tipo_genero;
		CLASSIFICACAO tipo_class ;
	}FILMES;
	
	typedef struct s_premium{
		float valor_bas_premium;
	}PREMIUM;
	
	typedef struct s_basico{
		int quant_filmes;
		float valor_base;
		float valor_exc;
	}BASICO;
	
	typedef struct u_planos{
		BASICO plano_basico;
		PREMIUM plano_premium;
	}PLANO;
	
	typedef enum e_tipodeplano{
		E_BASICO,E_PREMIUM,
	}TIPO_DE_PLANO;
	
	typedef struct s_data{
		int dia;
		int mes;
	}DATA;
	
	typedef struct s_debito{
		int num_agencia;
		int num_conta;
	}DEBITO;
	
	typedef struct s_credito{
		int num_cartao;
	}CREDITO;
	
	typedef enum e_pagamento{
		E_DEBITO,E_CREDITO,
	}NUM_DE_PAGAMENTO;
	
	typedef union u_pagamento{
		DEBITO pag_debito;
		CREDITO pag_credito;
	}PAGAMENTO;
	
	typedef struct s_contrato{//cada cliente pode ter apenas 1 contrato
		int CPF_cliente;
		TIPO_DE_PLANO tipo_plano;
		PAGAMENTO tipo_pag;
		DATA contratacao;
		DATA cancelamento;
	}CONTRATO;
	
	typedef struct s_historico{//maximo de 30 filmes por mes
		int cod_filme;
		int ordem;
		DATA dat_filme;
	}HISTORICO;

int cadastra_cliente(CLIENTE *C,int *cont_cliente);//maximo de clientes cadastrado ainda nao foi conferido

void cadastra_filme(FILMES *F,int *cont_filme);//maximo de filmes cadastrado ainda nao foi conferido

void cadastrar_plano_basico(PLANO *P);//ok

void cadastrar_plano_premium(PLANO *P);//ok

void cadastro_contrato(CONTRATO *CON,int *cont_contrato,CLIENTE *C,int cont_cliente, int cont_mes);//ok

void carregar_filme(CLIENTE *C,int cont_cliente,FILMES *F,int cont_filme,CONTRATO *CON,int cont_contrato,HISTORICO MAT[][31],int dias,PLANO *P,int *filmes_assitido, int cont_mes);

void cancelar_contrato(CLIENTE *C,int *cont_cliente,CONTRATO *CON,int *cont_contrato,int *filmes_assitido,PLANO *P,int *cont_mes);

void gerar_fatura(CLIENTE *C,int *cont_cliente,FILMES *F,int *cont_filme,PLANO *P,CONTRATO *CON,int *cont_contrato,HISTORICO MAT[][31],int clientes,int dias,int *filmes_assitido,int*cont_mes);

void lista_dados_cliente(CLIENTE *C,int cont_cliente);//ok

void lista_historico_cliente(CLIENTE *C,int cont_cliente,HISTORICO MAT[][31],int dias,int cont_mes,FILMES *F,int cont_filme,int *filmes_assitido);

void lista_clientes_execederam_conta(CLIENTE *C,int cont_cliente,PLANO *P,int *filmes_assitido);

void frequencia_filmes(FILMES *F,int cont_filme, int cont_cliente,HISTORICO MAT[][31],int dias);

void recomendar_filme(CLIENTE *C,int cont_cliente,FILMES *F,int cont_filme,HISTORICO MAT[][31],int dias);

int main(){
	
	const int tm=10;
	const int dias=31;
	int opcao,cont_cliente=0,cont_mes=1,cont_filme=0,cont_contrato=0,i=0,j=0,res=0,filmes_assitido[tm];
	
	CLIENTE vet_cliente[tm];
	FILMES vet_filme[tm];
	PLANO plano;
	CONTRATO vet_contrato[tm];
	HISTORICO mat_principal[tm][dias];
	
	for(i=0;i<tm;i++){
		filmes_assitido[i]=0;
		for(j=0;j<dias;j++){
		mat_principal[i][j].cod_filme=0;
		mat_principal[i][j].dat_filme.dia=00;
		mat_principal[i][j].dat_filme.mes=00;
		}
	}
	
	do{
		scanf("%d",&opcao);
		switch(opcao){
			
				case 1:{	//Cadastro de Cliente
						if(cont_cliente<tm){
							res=cadastra_cliente(vet_cliente,&cont_cliente);
							if(res==0){
								printf("ERRO: CPF do cliente ja cadastrado\n");
							}
							else{
								printf("Cliente cadastrado com sucesso\n");
							}
						}
						else{
							printf("ERRO: Numero maximo de clientes no sistema atingido\n");
						}
					break;
				}
				case 2:{	//Cadastrar filme
						if(cont_filme<tm){
							cadastra_filme(vet_filme,&cont_filme);
						}
						else{
							printf("ERRO: Numero maximo de filmes no sistema atingido\n");
						}
					break;
				}
				case 3:{ //Cadastrar plano básico
					cadastrar_plano_basico(&plano);
					break;
				}
				case 4:{//Cadastrar plano premium
					cadastrar_plano_premium(&plano);
					break;
				}
				case 5:{//Cadastrar contrato
					if(cont_contrato<tm){
						if(cont_cliente==0){//if(cont_cliente) nao funciona ?
							printf("ERRO: Nenhum cliente cadastrado no sistema\n");
						}
						else{
							cadastro_contrato(vet_contrato,&cont_contrato,vet_cliente,cont_cliente,cont_mes);
						}
					}	
					else{
						printf("ERRO: Numero maximo de contratos no sistema atingido\n");
					}
					
					break;
				}
				case 6:	{//Carregar filme
					if(cont_cliente==0){
						printf("ERRO: Nenhum cliente cadastrado no sistema\n");
						}
						
					else{
						carregar_filme(vet_cliente,cont_cliente,vet_filme,cont_filme,vet_contrato,cont_contrato,mat_principal,dias,&plano,filmes_assitido,cont_mes);
						}
						
					break;
				}
				case 7:	{//Cancelar contrato
					if(cont_contrato==0){
							printf("ERRO: Nenhum contrato cadastrado no sistema\n");
						}
					else{
						cancelar_contrato(vet_cliente,&cont_cliente,vet_contrato,&cont_contrato,filmes_assitido,&plano,&cont_mes);
						}
					break;
				}
				case 8:	{ //Gerar fatura
					gerar_fatura(vet_cliente,&cont_cliente,vet_filme,&cont_filme,&plano,vet_contrato,&cont_contrato,mat_principal,tm,dias,filmes_assitido,&cont_mes);
					break;
				}
				case 9:	{// Listar os dados de um dado cliente
					lista_dados_cliente(vet_cliente,cont_cliente);
					break;
				}
				case 10:{// Listar o histórico de uma dado cliente
					if(cont_cliente==0){
							printf("ERRO: Nenhum cliente cadastrado no sistema\n");
						}
						else{
							lista_historico_cliente(vet_cliente,cont_cliente,mat_principal,dias,cont_mes,vet_filme,cont_filme,filmes_assitido);
						}
						
					break;
				}
				case 11:{//Listar clientes que excederam a cota mensal
					if(cont_cliente==0 || cont_contrato==0){
							printf("ERRO: Nenhum cliente excedente\n");
						}
						else{
							 lista_clientes_execederam_conta(vet_cliente,cont_cliente,&plano,filmes_assitido);
						}
					break;
				}
				case 12:{//Frequência de um dado filme
					if(cont_filme==0 || cont_cliente==0 || cont_contrato==0 ){
							printf("ERRO: Nenhum filme cadastrado no sistema\n");
						}
						else{
							frequencia_filmes(vet_filme,cont_filme,cont_cliente,mat_principal,dias);
						}
					break;
				}
				case 13:{ //Recomendar filme
					if(cont_cliente==0){
							printf("ERRO: Nenhum cliente cadastrado no sistema\n");
						}
						else{
							recomendar_filme(vet_cliente,cont_cliente,vet_filme,cont_filme,mat_principal,dias);
						}
					break;
				}
				case 0:	{
					printf("Finalizando programa...");
					break;
				}
				default:{
					printf("ERRO: Opcao invalida\n");
					break;
				}
	
		}
	}while(opcao!=0);
}
int cadastra_cliente(CLIENTE *C,int *cont_cliente){
	int i=0,j=0,aux;
	i=(*cont_cliente);
	scanf(" %d", &aux);
	
	for(j=0;j<*cont_cliente;j++){
		if(aux==C[j].CPF)
		return 0;//CPF ja cadastrado		
	}
	
	C[i].CPF=aux;
	scanf(" %[^\n]%*c",C[i].nome);
	scanf(" %s",C[i].email);
	scanf(" %s",C[i].telefone);
	
	C[i].est_status= INATIVO;
	(*cont_cliente)++;//*cont_cliente++ nao funciona ?
	return 1;// cadastro com sucesso
	
}
void cadastra_filme(FILMES *F,int *cont_filme){// 
	int i=0;
	i=(*cont_filme);
	scanf(" %[^\n]%*c",F[i].nome);
	
	do{
		scanf("%u",&F[i].tipo_genero);
		if(F[i].tipo_genero<AVENTURA || F[i].tipo_genero>ROMANCE)		
			printf("ERRO: Genero invalido\n");
			
				
	}while(F[i].tipo_genero<AVENTURA || F[i].tipo_genero>ROMANCE);
	
	do{
		scanf("%u",&F[i].tipo_class);
		if(F[i].tipo_class<LIVRE || F[i].tipo_class>MDEZOITO)
			printf("ERRO: Classificao invalida\n");		
		
		
	}while(F[i].tipo_class<LIVRE || F[i].tipo_class>MDEZOITO);
		
	(*cont_filme)++;
	F[i].cod_unico=1001+i;
	printf("Filme cadastrado com sucesso\n");		
}
void cadastrar_plano_basico( PLANO *P){
	scanf("%d", &P->plano_basico.quant_filmes);
	scanf("%f", &P->plano_basico.valor_base); 
	scanf("%f", &P->plano_basico.valor_exc); 
	
	printf("Plano Basico cadastrado com sucesso\n");
	
}
void cadastrar_plano_premium(PLANO *P){
	
	scanf("%f", &P->plano_premium.valor_bas_premium); 

	printf("Plano Premium cadastrado com sucesso\n");
	
}

void cadastro_contrato(CONTRATO *CON,int *cont_contrato,CLIENTE *C,int cont_cliente, int cont_mes){
	int j=0,m=0,i=0,aux, n_pag;
	scanf(" %d", &aux);
	
	for(j=0;j<cont_cliente;j++){
		if(aux==C[j].CPF){
		m++;
		break;	}
	}
	if(m==0){
		printf("ERRO: Cliente nao cadastrado\n");	}
	else{
		m=0;
		for(i=0;i<cont_cliente;i++){
			if(aux==CON[i].CPF_cliente){
			m++;
			break;	}}
			
		if(m!=0){
			printf("ERRO: Cliente com contrato existente\n");	}
		else{
			i=0;
			CON[(*cont_contrato)].CPF_cliente=aux;
			C[j].est_status= ATIVO;
	
			do{
				scanf("%u", &CON[(*cont_contrato)].tipo_plano);
				if(CON[(*cont_contrato)].tipo_plano!=E_BASICO && CON[(*cont_contrato)].tipo_plano!=E_PREMIUM){
					printf("ERRO: Tipo de plano invalido\n");
				}
			
			}while(CON[(*cont_contrato)].tipo_plano!=E_BASICO && CON[(*cont_contrato)].tipo_plano!=E_PREMIUM);
			
			do{
				scanf("%d", &n_pag);
				if(n_pag !=E_DEBITO && n_pag!=E_CREDITO){
					printf("ERRO: Tipo de pagamento invalido\n");
				}
				else{
					if(n_pag==E_DEBITO){
						scanf("%d", &CON[(*cont_contrato)].tipo_pag.pag_debito.num_agencia);
						scanf("%d", &CON[(*cont_contrato)].tipo_pag.pag_debito.num_conta);
					}
					else{
						scanf("%d", &CON[(*cont_contrato)].tipo_pag.pag_credito.num_cartao);
					}
				}
				
			}while(n_pag!=E_DEBITO && n_pag!=E_CREDITO);
	
			do{
				scanf("%d", &CON[(*cont_contrato)].contratacao.dia);
				if(CON[*cont_contrato].contratacao.dia>31 || CON[(*cont_contrato)].contratacao.dia<1){
					printf("ERRO: Dia invalido\n");
				}
			}while(CON[(*cont_contrato)].contratacao.dia>31 || CON[(*cont_contrato)].contratacao.dia<1);
			
			CON[(*cont_contrato)].contratacao.mes=cont_mes;
			CON[(*cont_contrato)].cancelamento.dia=00;
			CON[(*cont_contrato)].cancelamento.mes=00;
			(*cont_contrato)++;
			printf("Contrato cadastrado com sucesso\n");	}	}
}

void carregar_filme(CLIENTE *C,int cont_cliente,FILMES *F,int cont_filme,CONTRATO *CON,int cont_contrato,HISTORICO MAT[][31],int dias,PLANO *P,int *filmes_assitido, int cont_mes){
 	int j=0,x=0,dia=0,tipo=0,m=0,cod=0,esc=0,bin=0,aux;
 	scanf(" %d", &aux);
 	
 	for(x=0;x<cont_cliente;x++){
		if(aux==C[x].CPF){
			m++;
			break;}	}
			
	if(m==0){
		printf("ERRO: Cliente nao cadastrado\n");
	}
 	else{
 		if(CON[j].tipo_plano==E_PREMIUM && filmes_assitido[x]>=dias-1 ){
 			printf("ERRO: Numero maximo de filmes no sistema atingido\n");
		 }
 		else{
		if(C[x].est_status==ATIVO){
				do{
				 	scanf("%d", &dia);
				 	if(dia>31 || dia<1){
				 		printf("ERRO: Dia invalido\n"); }
				 	
				}while(dia>31 || dia<1);
				 
				do{
				 	scanf("%d", &esc);
				 	 if(esc!=0 && esc!=1){
				 		printf("ERRO: Escolha invalida\n");
					}
					
				}while(esc!=0 && esc!=1);
				
				do{
					scanf("%d", &tipo);
					 if(tipo<AVENTURA || tipo>ROMANCE){
					 	printf("ERRO: Escolha invalida\n");
					}
					
				}while(tipo<AVENTURA || tipo>ROMANCE);
				
				if(esc==0){
					for(j=0;j<cont_filme;j++){
						if(tipo==F[j].tipo_genero){
							printf("Codigo: %d\n",F[j].cod_unico);
							printf("Nome: %s\n",F[j].nome);	
								}	} }
				else{
					for(j=0;j<cont_filme;j++){
						if(tipo==F[j].tipo_class){
							printf("Codigo: %d\n",F[j].cod_unico);
							printf("Nome: %s\n",F[j].nome);	
								}	} }
								
				scanf("%d", &cod);
				m=0;
				
				for(j=0;j<cont_filme;j++){
					if(cod==F[j].cod_unico){
						m++;
						break;	 
					} }		
						
				if(m==0){
					printf("ERRO: Filme nao encontrado\n");		
					}		
				else{
					for(j=0;j<cont_contrato;j++){
						if(C[x].CPF==CON[j].CPF_cliente)
						break;	
						}
				
					if(CON[j].tipo_plano==E_BASICO){
						if(filmes_assitido[x]< P->plano_basico.quant_filmes){
							MAT[x][dia-1].cod_filme=cod;
							MAT[x][dia-1].dat_filme.dia=dia;
							MAT[x][dia-1].dat_filme.mes=cont_mes;
							MAT[x][dia-1].ordem=filmes_assitido[x];
							filmes_assitido[x]++;
							printf("Filme carregado com sucesso\n");
							}
						else{
							do{
							scanf("%d", &bin);	
								if(bin!=0 && bin!=1){
									printf("ERRO: Escolha invalida\n");
								}
							}while(bin!=0 && bin!=1);
							if(bin==0){
								printf("ERRO: Taxa adicional negada\n");
								}
							else{
								MAT[x][dia-1].cod_filme=cod;
								MAT[x][dia-1].dat_filme.dia=dia;
								MAT[x][dia-1].dat_filme.mes=cont_mes;
								MAT[x][dia-1].ordem=filmes_assitido[x];
								filmes_assitido[x]++;
								printf("Filme carregado com sucesso\n");
								}
							}				
					}	
					else{
							MAT[x][dia-1].cod_filme=cod;
							MAT[x][dia-1].dat_filme.dia=dia;
							MAT[x][dia-1].dat_filme.mes=cont_mes;
							MAT[x][dia-1].ordem=filmes_assitido[x];
							filmes_assitido[x]++;
							printf("Filme carregado com sucesso\n");
									
						}
					}
				}						 	
 		else{
 			printf("ERRO: Cliente nao ativo\n");
		}
	 }
 }
}
 
void cancelar_contrato(CLIENTE *C,int *cont_cliente,CONTRATO *CON,int *cont_contrato,int *filmes_assitido,PLANO *P, int *cont_mes){
	int j=0,i=0,dia=0,m=0,aux;
 	float valor=0; 
 	scanf(" %d", &aux);
 	
 	
	for(i=0;i<(*cont_cliente);i++){
			if(aux==C[i].CPF){
				m++;
				break;}	
		}			
	if(m==0){
		printf("ERRO: Cliente nao cadastrado\n");
	}
 	else{
 		for(j=0;j<(*cont_contrato);j++){
			if(aux==CON[j].CPF_cliente){
				m++;
				break;}	}
		
	 	if(C[i].est_status==ATIVO){
		 	do{
					scanf("%d", &dia);
				 	if(dia>31 || dia<1 ){
				 		printf("ERRO: Dia invalido\n");
					}
						
			}while(dia>31 || dia<1 /*|| dia<CON[j].contratacao.dia*/);	 	
			
			if((*cont_mes)==CON[j].contratacao.mes && dia<CON[j].contratacao.dia){
				printf("ERRO: Data de cancelamente anteiror a data de contratacao\n");	
			}
			else if((*cont_mes)<CON[j].contratacao.mes){//caso tenha mais de um ano para analisar
				printf("ERRO: Data de cancelamente anteiror a data de contratacao\n");
			}
			else{
				if(CON[j].tipo_plano==E_BASICO){
					CON[j].cancelamento.dia=dia;
				 	CON[j].cancelamento.mes=(*cont_mes);
				 	
				 	CON[j].CPF_cliente=0;
					C[i].est_status=INATIVO;
					
					if(filmes_assitido[i]>=P->plano_basico.quant_filmes){
						valor=P->plano_basico.valor_base+(((filmes_assitido[i]+1)-P->plano_basico.quant_filmes)*P->plano_basico.valor_exc);
						printf("Valor devido: %.2f\n",valor);
						printf("Cancelamento feito com sucesso\n");
					}
					else{
						valor=P->plano_basico.valor_base;
						printf("Valor devido: %.2f\n",valor);
						printf("Cancelamento feito com sucesso\n");
					}
				}
				else{
					CON[j].cancelamento.dia=dia;
				 	CON[j].cancelamento.mes=(*cont_mes);
				 	CON[j].CPF_cliente=0;
					C[i].est_status=INATIVO;
					
					valor=P->plano_premium.valor_bas_premium;
					printf("Valor devido: %.2f\n",valor);
					printf("Cancelamento feito com sucesso\n");
				}
			}
		}
	 	else{
	 		printf("ERRO: Cliente inativo\n");
		 }
	}
}

void gerar_fatura(CLIENTE *C,int *cont_cliente,FILMES *F,int *cont_filme,PLANO *P,CONTRATO *CON,int *cont_contrato,HISTORICO MAT[][31],int clientes,int dias,int *filmes_assitido,int*cont_mes){
	int j=0,op=0,i=0,cod=0,x=0,g=0,m=0;
	float valor=0;
	do{
		scanf("%d", &op);
		if(op!=0 && op!=1 ){
			printf("ERRO: Escolha invalida\n");
		}
		
	}while(op!=0 && op!=1 );
	
	if(op==0){
		if(*cont_cliente==0){
			printf("ERRO: Nenhum cliente cadastrado no sistema\n");
		}
		else{
			if(*cont_contrato==0){
				printf("ERRO: Nenhum contrato cadastrado no sistema\n");
			}
			else{
				scanf("%d", &cod);
				for(i=0;i<(*cont_cliente);i++){
					if(cod==C[i].CPF){
						m++;
						break;
				}}
				if(m==0){
					printf("ERRO: Cliente nao cadastrado\n");
				}
				else{
					
					m=0;
					for(j=0;j<(*cont_contrato);j++){
						if(cod==CON[j].CPF_cliente){
							m++;
							break;}
						}
					if(m==0){
						printf("ERRO: Cliente nao possui contrato\n");
					}
					else{
						for(g=0;g<=filmes_assitido[i];g++){
							for(m=0;m<dias;m++){
								for(x=0;x<(*cont_filme);x++){
									if(MAT[i][m].cod_filme==F[x].cod_unico && MAT[i][m].ordem==g){
										if(filmes_assitido[i]>=P->plano_basico.quant_filmes ){
												
												printf("Nome: %s\n", F[x].nome); //nome do filme
												printf("Data: %d/%d\n", MAT[i][m].dat_filme.dia,MAT[i][m].dat_filme.mes); //data do carregamento
												//
											}
										else if(filmes_assitido[i]<P->plano_basico.quant_filmes){
												printf("Nome: %s\n", F[x].nome); //nome do filme
												printf("Data: %d/%d\n", MAT[i][m].dat_filme.dia,MAT[i][m].dat_filme.mes); //data do carregamento
												
											}
										else{
											printf("Nome: %s\n",F[x].nome); //nome do filme
											printf("Data: %d/%d\n",MAT[i][m].dat_filme.dia ,MAT[i][m].dat_filme.mes); //data do carregamento
										}
									}
									}
								}
							}
							if(CON[j].tipo_plano==E_BASICO){
								if(filmes_assitido[i]>=P->plano_basico.quant_filmes){
									valor= P->plano_basico.valor_base+((filmes_assitido[i]-P->plano_basico.quant_filmes)*P->plano_basico.valor_exc);
									printf("Valor devido: %.2f\n", valor);
								}
								else{
									printf("Valor devido: %.2f\n", P->plano_basico.valor_base);
								}
							}
							else{
								printf("Valor devido: %.2f\n",P->plano_premium.valor_bas_premium);
							}
						}
					}
				}
			}
		}	
	else{	
			for(j=0;j<(*cont_cliente);j++){
				for(i=0;i<(*cont_contrato);i++){
					if(C[i].est_status==ATIVO && C[i].CPF==CON[j].CPF_cliente){
						if(CON[j].tipo_plano==E_BASICO){
					
								if(filmes_assitido[i]>=P->plano_basico.quant_filmes){
									valor=P->plano_basico.valor_base+((filmes_assitido[i]-P->plano_basico.quant_filmes)*P->plano_basico.valor_exc);
									printf("CPF: %d\n", C[i].CPF);
									printf("Nome: %s\n", C[i].nome);
									printf("Valor devido: %.2f\n", valor);
										
								}
								else{
									valor=P->plano_basico.valor_base;
									printf("CPF: %d\n", C[i].CPF);
									printf("Nome: %s\n", C[i].nome);
									printf("Valor devido: %.2f\n", valor);
									
								}
							}
							else{
								valor=P->plano_premium.valor_bas_premium;
									printf("CPF: %d\n", C[i].CPF);
									printf("Nome: %s\n", C[i].nome);
									printf("Valor devido: %.2f\n", valor);
									
							}
						}
					}
				}
						
		for(i=0;i<clientes;i++){
			filmes_assitido[i]=0;
			for(j=0;j<dias;j++){
			 	MAT[i][j].cod_filme=00;
				MAT[i][j].dat_filme.dia=00;
			}
		}
		
		(*cont_mes)++;
		printf("Mes vigente apos a fatura: %d\n",(*cont_mes));
			
	}
}

void lista_dados_cliente(CLIENTE *C,int cont_cliente){
	int j=0,m=0,aux;

	if(cont_cliente==0){//if(*cont_cliente) nao funciona
		printf("ERRO: Nenhum cliente cadastrado no sistema\n");
	}
	else{
		scanf(" %d", &aux);
		for(j=0;j<cont_cliente;j++){
			if(aux==C[j].CPF){
				m++;
				break;}}
		if(m==0){// if(m) é igual a (m==0)?
		printf("ERRO: Cliente nao cadastrado\n");
		}
		else{
		printf("Nome: %s\n", C[j].nome);
		printf("Email: %s\n", C[j].email);
		printf("Telefone: %s\n", C[j].telefone);
		printf("Status: %d\n", C[j].est_status);
	}}
}

void lista_historico_cliente(CLIENTE *C,int cont_cliente,HISTORICO MAT[][31],int dias,int cont_mes,FILMES *F,int cont_filme,int *filmes_assitido){

	int i=0,m=0,g=0,j=0,x=0,aux;
	char genero[6][50] = {"aventura", "comedia", "drama", "terror", "acao","romance"};
	char classificacao[6][50] = {"livre","+10","+12","+14","+16","+18"}; 
	
	scanf(" %d", &aux);
	
	for(j=0;j<cont_cliente;j++){
		if(aux==C[j].CPF){
			m++;
			break;}
	}
	if(m==0){
		printf("ERRO: Cliente nao cadastrado\n");
	}
	else{
		if(C[j].est_status==ATIVO){
			printf("Estado: Ativo\n");}
		else{
			printf("Estado: Inativo\n");}
		m=0;	
		for(g=0;g<filmes_assitido[j];g++){
		for(i=0;i<dias;i++){
			for(x=0;x<cont_filme;x++){
				if(MAT[j][i].cod_filme==F[x].cod_unico && MAT[j][i].ordem==g){
						printf("Codigo: %d\n",MAT[j][i].cod_filme);
						printf("Nome: %s\n",F[x].nome);
						printf("Genero: %s\n", genero[F[x].tipo_genero]);
						printf("Classificacao: %s\n", classificacao[F[x].tipo_class]);
						printf("Data do carregamento: %d/%d\n\n",MAT[j][i].dat_filme.dia,MAT[j][i].dat_filme.mes);
						m++;
				}
			}
		}
		}
		if(m==0){
			printf("ERRO: Nenhum filme assistido\n");
		}	
	}
}

void lista_clientes_execederam_conta(CLIENTE *C,int cont_cliente,PLANO *P,int *filmes_assitido){
	int j=0,m=0;
	float excesso=0;
	
	for(j=0;j<cont_cliente;j++){
		if(C[j].est_status==ATIVO && filmes_assitido[j]>P->plano_basico.quant_filmes ){
			printf("CPF: %d\n",C[j].CPF);
			printf("Nome: %s\n",C[j].nome);
			excesso= ((filmes_assitido[j]-P->plano_basico.quant_filmes)*P->plano_basico.valor_exc);
			printf("Valor excedente: %.2f\n\n",excesso);
			m++;
		}	}
		
	if(m==0){
		printf("ERRO: Nenhum cliente excedente\n");
	}
}

void frequencia_filmes(FILMES *F,int cont_filme,int cont_cliente,HISTORICO MAT[][31],int dias){
	int i=0,j=0,aux;
	float a=0,m=0.0;
	
	scanf("%d", &aux);
	
	for(j=0;j<cont_filme;j++){
		if(aux==F[j].cod_unico){
			m++;
			break;}
	}
	
	if(m==0){
		printf("ERRO: Codigo invalido\n");
	}
	else{
		m=0;
		for(i=0;i<cont_cliente;i++){
			for(j=0;j<dias;j++){
				if(MAT[i][j].cod_filme!=0){
					if(aux==MAT[i][j].cod_filme)
						m++;
					a++;	}	
				}	}
				
	if(a==0){
			printf("ERRO: Nenhum filme assistido\n");	}
	else{
			
			printf("Frequencia: %.2f%%\n",(m*100)/a);
		}		
	}	
}

void recomendar_filme(CLIENTE *C,int cont_cliente,FILMES *F,int cont_filme,HISTORICO MAT[][31],int dias){
	const int tmg=5;
	
	int j=0,m=0,i=0,x=0,vet_gen[tmg],a=0,maior=0,aux,vetor[cont_filme],g=0;
	char genero[6][50] = {"aventura", "comedia", "drama", "terror", "acao","romance"};
	char classificacao[6][50] = {"livre","+10","+12","+14","+16","+18"}; 
	
		for(i=0;i<=tmg;i++){
			vet_gen[i]=0;
		}
	
	scanf(" %d", &aux);
	
	for(j=0;j<cont_cliente;j++){
		if(aux==C[j].CPF){
			m++;
			break;}	}
			
	if(m==0){
		printf("ERRO: Cliente nao cadastrado\n");
	}
	else{
		m=0;
		if(C[j].est_status==ATIVO){
			
			for(i=0;i<dias;i++){
				for(x=0;x<cont_filme;x++){
					if(	MAT[j][i].cod_filme==F[x].cod_unico){
						vet_gen[F[x].tipo_genero]++;
						vetor[x]=F[x].cod_unico;
							m++;	
					}
				}
			}
						
			if(m==0){
				printf("ERRO: Nenhum filme assistido\n");
			}
			else{
				
				for(i=0;i<=tmg;i++){
					if(maior<=vet_gen[i]){
						maior=vet_gen[i];
					}	
				}
				
				for(i=0;i<=tmg;i++){
					for(x=0;x<cont_filme;x++){
						for(g=0;g<dias;g++){				
							if(F[x].tipo_genero==i && vet_gen[i]==maior && a!=F[x].cod_unico && vetor[x]!=F[x].cod_unico && MAT[j][g].cod_filme!=0 ){
								a=F[x].cod_unico;
								printf("Codigo: %d\n",F[x].cod_unico);
								printf("Nome: %s\n",F[x].nome);
								printf("Genero: %s\n", genero[F[x].tipo_genero]);
								printf("Classificacao: %s\n", classificacao[F[x].tipo_class]);	
								}
							}
						}	
					}
			if(a==0){
					printf("ERRO: Todos os filmes do(s) genero(s) foram assistidos\n");
				}
			}
		}
		else{
			printf("ERRO: Cliente nao ativo\n");
		}
	}
}
