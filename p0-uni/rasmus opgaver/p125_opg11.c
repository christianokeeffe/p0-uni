#include <stdio.h>  

int main(void)
{
    int m, n, side1, side2, hyp;    
    printf("M: ");      
    scanf("%d", &m);          
    printf("n: ");      
    scanf("%d", &n); 

	side1 = (m*m)-(n*n);
	side2 = 2*m*n;
	hyp	  = (m*m)+(n*n);
    
    printf("side1: %d side2: %d hypotenuse: %d", side1, side2, hyp); /* Resultatet udskrives */
    return 0;
}