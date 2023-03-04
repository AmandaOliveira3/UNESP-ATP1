#include <stdio.h>

int main (void)
{
float p_ant, p_novo;
 
 
scanf("%f",&p_ant);

if(p_ant<=49.99)
 {p_novo= 1.05*p_ant;}
  else if(( p_ant>=50.00) && (p_ant<=99.99))
   {p_novo=1.10*p_ant;}
    else if(p_ant>=100.00)
    {p_novo=1.15*p_ant;}
    
  printf("%.2f\n",p_novo);
  
if(p_novo<=79.99)
{printf("Barato");}
  else if(( p_novo>=80.00) && (p_novo<=119.99))
 {printf("Normal");}
  else if((p_novo>=120.00) && (p_novo<=199.99))
  {printf("Caro");}
   else if(p_novo>=200.00)
   {printf("Muito Caro");}


}
