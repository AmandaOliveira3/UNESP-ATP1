#include <stdio.h>
void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam_v);
float media(float *salario, int tam_v);
void idades(int *idade, int *maior, int *menor, int tam_v);
int qtdade(char *sexo, int *filhos, float *salario, int tam_v);

int main(void)
{	const int habitantes=15;
	int idade[habitantes],filhos[habitantes],maior=0,menor=0;
	float salario[habitantes];
	char sexo[habitantes];
     /* DECLARAÇÃO DAS VARIÁVEIS */
     
    le_dados(idade,sexo,salario,filhos,habitantes);
    printf("%.2f ", media(salario,habitantes));
    idades(idade,&maior,&menor,habitantes );
    printf("%d ", menor);
    printf("%d ", maior);
    printf("%d", qtdade(sexo,filhos,salario,habitantes));
    return 0;
}
void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam_v){
	int i=0;
	for(i=0;i<tam_v;i++){
     	scanf("%d %c %f %d",&idade[i],&sexo[i],&salario[i],&filhos[i]);	
	 }
}
float media(float *salario, int tam_v){
	float soma=0;
	int i=0;
	for(i=0;i<tam_v;i++){
	soma+=salario[i];}
	return (soma/15);
}
void idades(int *idade, int *maior, int *menor, int tam_v){
	int i=0;
	*maior=idade[0];
	*menor=idade[0];
	for(i=0;i<tam_v;i++){
	if(idade[i]>(*maior))
		(*maior)=idade[i];
	if(idade[i]<(*menor))
		(*menor)=idade[i];		}
}
int qtdade(char *sexo, int *filhos, float *salario, int tam_v){
	int num=0,i=0;
	for(i=0;i<tam_v;i++){
	if((filhos[i]==3)&& (salario[i]<=500.00) && (sexo[i]=='M'))
	num++;}
	return num;
}
/* INCLUA AQUI SUAS FUNÇÕES */
