#include<stdio.h>
int main(void)
{
	int N,a=0,b=0,c=0,freq,matricula;
	float n1,n2,n3,maior=0,menor=11,media,porc;
	
	scanf("%d",&N);
	
	for(a=0;a<N;a++)
	{
		scanf("%d %f %f %f %d",&matricula,&n1,&n2,&n3,&freq);
		media=(n1+n2+n3)/3;	
		if(media>maior){
			maior=media;
		}
		if (media<menor){
			menor=media;
		}
		printf("%d %.2f",matricula,media);
	    if((media>=6)&&(freq>40)) {  
			printf(" Aprovado\n");
		}
		else {
			printf(" Reprovado\n");
			b++;
			if(freq<40) {
				c++;
			}
		}
	}	
	porc= (100.0*c)/N;
	printf("%.2f %.2f %d %.2f%%",maior,menor,b,porc);
}
