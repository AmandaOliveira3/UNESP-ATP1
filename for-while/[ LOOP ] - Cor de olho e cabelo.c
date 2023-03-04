#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
int main (void)
{
	int idade,a=1,b=0,c=0,d=0,q=0;
	float peso,media,k=0,altura,porc=0.0;
	char olho,cabelo;
	
	for(a=1;a<=20;a++)
	{
		scanf("%d %f %f %c %c",&idade,&peso,&altura,&olho,&cabelo);
		if ((olho!='A')&& (cabelo=='R'))
		q++;
		if ((idade>50)&& (peso<60.0))
		c++;
		if (olho=='A')
		b++;
		if (altura>1.50)
		{d++;
		k=idade+k;}
	} 
	media=k/d;
	porc=100.0*b/20;
	printf("%d %.2f %.2f%% %d",c,media,porc,q);
	//getch();
}

