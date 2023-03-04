#include<stdio.h>
//#include<conio.h>
int main (void)
{
	int a=1,idade=0,bom=0,op=0,b=0;
	float porc=0.0,d=0,c=0;
	
	for(a=1;a<=15;a++)
	{
			scanf("%d %d",&idade,&op);
			if(op==1)
			 	 b++;
			if(op==2)
				bom++;
			if(op==3)
			{
				c++;
				d+=idade;
			}
	}
	porc=(100.0*bom)/15;
	printf("%.2f %d %.2f%%",d/c,b,porc);
	//getch();
}
