#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
int main (void)
{     int a=0,b=0,c=0,d=0,e=0,f=0,n=0,x=0;
      float porc1,porc2;
//scanf("%d",&n);

	while(1)
	{   scanf("%d",&n);
		if(n==0)
		 break;
		if(n==1)
		 {a++; 
		 x++;
		 continue;}
		if(n==2)
		 {b++;
		 x++;
		 continue;}
		if(n==3)
		 {c++;
	      x++;
		  continue;}
		if(n==4)
		 {d++;
		 x++;
		 continue;}
		if(n==5)
		 {e++;
		 x++;
		 continue;}
		if(n==6)
		 {f++;
		 x++;
		 continue;}
	}
	porc1=(100.0*e)/x;
	porc2=(100.0*f)/x;
printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
printf("%.2f%% %.2f%%",porc1 ,porc2);
//getch();
return 0;}


