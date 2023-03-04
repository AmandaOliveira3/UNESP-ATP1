#include<stdio.h>
	int main (void)
{
		const int tam=10;
		const int tamb=2*10;
		int vet_a[tam],vet_b[tam],vet_c[tamb],a=0,i=0,j=0,aux;
		for(a=0;a<tam;a++)
		{
			scanf("%d",&vet_a[a]);
			vet_c[a]=vet_a[a];
		}
		for(a=0;a<tam;a++)
		{
			scanf("%d",&vet_b[a]);
			vet_c[a+10]=vet_b[a];
		}

		for(i=0;i<tamb;i++)
		{ 
			for (j=0;j<tamb-1;j++)
				{
		
				if(vet_c[j]<vet_c[j+1])
				{	aux = vet_c[j];
					vet_c[j]= vet_c[j+1];
					vet_c[j+1]= aux;
				}
				}
		}
		for(i=0;i<tamb;i++)
		{
			printf("%d ",vet_c[i]);
		}	
}
		
