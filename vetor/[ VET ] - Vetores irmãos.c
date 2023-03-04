#include<stdio.h>
int main (void)
{
	const int tam=10;
	const int tamb=5;
	int veta_[tam],vetb_[tamb],veta_res[10]={0},vetb_res[5]={0},ndivisores=0,a=0,i=0;
		for(a=0;a<tam;a++)
		{
			scanf("%d",&veta_[a]);
		}
		
		for(a=0;a<tamb;a++)
		{
			scanf("%d",&vetb_[a]);
		}
		veta_res[a]=0;
		
			
		for(a=0;a<tam;a++)
		{	veta_res[a]=veta_[a];
			if(veta_[a]%2==0)
			for(i=0;i<tamb;i++)
			{		
					{
					veta_res[a]=veta_res[a]+vetb_[i];
					}
			}
			if(veta_res[a]!=veta_[a])
			printf("%d ",veta_res[a]);
		}
		
			vetb_res[a]=0;
		for(a=0;a<tam;a++)
		{
			
			if(veta_[a]%2!=0)
			{					
				for(i=0;i<tamb;i++)
				{
				if(veta_[a]%vetb_[i]==0)
					ndivisores++;
				}
				vetb_res[a]=ndivisores;
				printf("%d ",vetb_res[a]);
			}
			ndivisores=0;
		}
}
