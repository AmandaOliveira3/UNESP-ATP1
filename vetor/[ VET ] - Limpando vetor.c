#include<stdio.h>
	int main(void)
	{
		const int tam1=20;
		//const int tamb=tam1-i;
		int vet_a[tam1],a=0;
			for(a=0;a<tam1;a++)
			{
				scanf("%d",&vet_a[a]);
				//if(vet_a[a]>0)
					//b++;
			}
			for(a=0;a<tam1;a++)
			{
				if(vet_a[a]>0)
					{
						printf("%d ",vet_a[a]);
					}
			}
	}
