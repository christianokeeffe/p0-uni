#include <stdio.h>  

int main(void)
{
    int house_length, house_width,
	yard_length, yard_width, house_square_feet,
	yard_square_feet, grass_square_feet, grass_cut_time;    
    printf("House length x width: ");      
    scanf("%d x %d", &house_length, &house_width);          
    printf("Yard length x width: ");      
    scanf("%d x %d", &yard_length, &yard_width);       

	house_square_feet = house_length*house_width;
	
	yard_square_feet = yard_length*yard_width;
	
	grass_square_feet = yard_square_feet-house_square_feet;

	grass_cut_time = grass_square_feet*3;

    printf("Det tager %d sekunder at slaa graesset", grass_cut_time); /* Resultatet udskrives */
    return 0;
}