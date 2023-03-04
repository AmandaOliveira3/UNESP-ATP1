#include<stdio.h>

#include<stdlib.h>
int main (void)
{
	int a=0,b=0,c=0,d=0,n,pessoa,g=0;
	float por1,por2,por3,por4;

	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		scanf("%d",&pessoa);
		if(n==4)
		a++;
		if(n==5)
		b++;
		if(n==7)
		c++;
		if(n==12)
	     d++;
        g++;
		}

		por1=(100.0*a)/g;
		por2=(100.0*b)/g;
		por3=(100.0*c)/g;
		por4=(100.0*d)/g;
	printf("%.2f%% %.2f%% %.2f%% %.2f%%",por1,por2,por3,por4);
}
