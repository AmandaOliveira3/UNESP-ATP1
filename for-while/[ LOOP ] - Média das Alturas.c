#include<stdio.h>
//#include<conio.h>

int main (void)
{
	int idade=0,b=0;
	float altura,a=0.00,media;
	//scanf("%d%.2f",idade,altura);
	while(1)
	{
	   scanf("%d",&idade);
		 if(idade<=0)
		  break;
		 
	   scanf("%f",&altura);
		if(idade>50)
		 {// printf("leia");
		 a=altura+a; // a+=altura;
		  b++;}
	}
	media= a/b;
	printf("%.2f",media);
	//getch();
}
