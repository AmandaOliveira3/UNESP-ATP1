#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
int main (void){
	int N,a=1,b=0,c,d=0,e=0,f=0,g=0,idade;
	
	scanf("%d",&N);	
	for(a=1;a<=N;a++)
	{
	scanf("%d",&idade);
	if(idade<=15)
	b++;
	if((idade>=16)&& (idade<=30))
	c++;
	if((idade>=31) && (idade<=45))
	d++;
	if((idade>=46) && (idade<=60))
	e++;
	if(idade>=61) 
	f++;
	g++;
	}
	printf("%d %d %d %d %d\n",b,c,d,e,f);
	printf("%.2f%%",100.0*(b+f)/g);
	//getch();
}
