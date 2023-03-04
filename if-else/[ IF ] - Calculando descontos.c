
#include <stdio.h>
int main (void){

float codigo, quant,p,pnota,pdes,vdes;

scanf(" %f",&codigo);
scanf(" %f",&quant);
if(codigo<=10)
{ p = 10.00;
pnota = p*quant;}
  if(codigo>=11 && (codigo<=20))
  {p = 15.00;
  pnota= p*quant;}
   if(codigo>=21 && (codigo<=30))
   {p = 20.00;
   pnota= p*quant;}
    if(codigo>=31 && (codigo<=40))
    {p = 30.00;
    pnota= p*quant;}
if(pnota<249.99)
{  pdes= 0.05*pnota;
   vdes= pnota - pdes;
}
 if((pnota >=250.00 ) && (pnota <= 499.99))
 {  pdes= 0.10*pnota;
 	vdes= pnota - pdes;
 }
 if(pnota >= 500.00)
 {  pdes= 0.15*pnota;
 	vdes= pnota - pdes;
 }
 vdes= pnota-pdes;
printf("%.2f %.2f %.2f %.2f", p, pnota,pdes, vdes);

}
