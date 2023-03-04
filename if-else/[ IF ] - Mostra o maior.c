#include <stdio.h>
#include <stdlib.h>
int main(void)
   {
	
	int n1,n2,n3;
	
	scanf("%d%d%d",&n1 ,&n2, &n3);
	
	if((n1<n2) && (n1<n3)){
	 if(n2<=n3)
	  printf("%d",n3);
	   if(n3<=n2)
	    printf("%d",n2);
	    
	}

	if((n2<n1)&&(n2<n3)){
		if(n1<=n3)
		printf("%d",n3);
		if(n3<=n1)
		printf("%d",n1);
		  
	}
	if((n3<n1) && (n3<n2)){
	
	  if(n1<=n2)
	  printf("%d",n2);
	   if(n2<=n1)
	   printf("%d",n1);
	   }
	    
	     
	}
	
	
	
	

