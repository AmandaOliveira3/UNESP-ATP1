#include<stdio.h>
int main(void)
{
	float h_extra,h_falta,H,grat;
	
	scanf(" %f%f",&h_extra,&h_falta);
	
	H = h_extra -  (3*h_falta)/4 ;
	
	if(H<=600){
		grat =100.00;
		printf("%.2f ",grat  );
	}
	if((H>600) && (H<=1200)){
		grat =200.00;
		printf("%.2f ", grat );
	}
    if((H>1200) && (H<=1800)){
    	grat =300.00;
    	printf("%.2f ", grat);
	}
	if((H>1800) && (H<=2400)){
		grat =400.00;
		printf("%.2f ", grat );
	}
	if(H > 2400){
		grat = 500.00;
		printf("%.2f ", grat );
	}

}
