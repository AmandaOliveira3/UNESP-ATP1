#include<stdio.h>
	int main (void)
{
	const int tam=5;
	int veta_[tam],vetb_[tam],vetor_[tam],a=0,i=4;
		for(a=0;a<tam;a++)
		{
				scanf("%d",&veta_[a]);
		}
		for(a=0;a<tam;a++)
		{
				scanf("%d",&vetb_[a]);
		}
		//i=4;
		for(a=0;a<tam;a++)
		{
			vetor_[a]=veta_[a]-vetb_[i];
			printf("%d ",vetor_[a]);
			i=i-1;
				
		}
			//printf("%d ",vetor_[tam]);
}
