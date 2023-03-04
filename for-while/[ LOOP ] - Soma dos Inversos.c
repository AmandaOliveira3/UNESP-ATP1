#include<stdio.h>
int main (void)
{
	int n;
	float i=1,soma=0.0;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		{
		soma=1/i+soma;
		}
	printf("%.2f",soma);
}
