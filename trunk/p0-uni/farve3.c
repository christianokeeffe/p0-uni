#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SunCentrumX 450
#define SunCentrumY 50
#define SunRadius 100
#define SkyB1X 100
#define SkyB1Y 100
#define SkyB1R 50
#define SkyB2X 150
#define SkyB2Y 80
#define SkyB2R 50
#define SkyB3X 200
#define SkyB3Y 100
#define SkyB3R 50
#define SkyB4X 150
#define SkyB4Y 100
#define SkyB4R 50
#define TagForskydningYakse1 -600
#define TagForskydningYakse2 78

int main(void) {

  FILE *image_file;
  int i, j;
  int r1, r2, r3;

  image_file = fopen("image-file-4.pnm", "wb"); 

  fputs("P6\n", image_file); 
  fputs("500 500\n", image_file);
  fputs("255\n", image_file);

  for(i = 0; i < 500; i++){
    for (j = 0; j < 500; j++){
      r1 = (((j-SunCentrumX)*(j-SunCentrumX)+(i-SunCentrumY)*(i-SunCentrumY)<=(SunRadius)*(SunRadius)) ?255:0)
	  +(((j-SkyB1X)*(j-SkyB1X)+(i-SkyB1Y)*(i-SkyB1Y)<=(SkyB1R)*(SkyB1R)) ?255:0)
	  +(((j-SkyB2X)*(j-SkyB2X)+(i-SkyB2Y)*(i-SkyB2Y)<=(SkyB2R)*(SkyB2R)) ?255:0)
	  +(((j-SkyB3X)*(j-SkyB3X)+(i-SkyB3Y)*(i-SkyB3Y)<=(SkyB3R)*(SkyB3R)) ?255:0)
	  +(((j-SkyB4X)*(j-SkyB4X)+(i-SkyB4Y)*(i-SkyB4Y)<=(SkyB4R)*(SkyB4R)) ?255:0)
	  + sunbeam1(j,i)
	  + sunbeam2(j,i)
	  + sunbeam3(j,i)
	  + (280<j && j<400 && i>350 && i<480? 255 : 0)
	  + (j + TagForskydningYakse1 >= -i && -j + TagForskydningYakse2 >= -i && i < 355 ? 105 : 0)
	  +(300<j && j<340 && i>400 && i<480? 80 : 0)
	  +(350<j && j<390 && i>370 && i<410? 255 : 0)
	  +(20<j && j<30 && i>300 && i<480? 255 : 0)
	  +(30<=j && j<60 && i>300 && i<330? 224 : 0)
	  +(30<=j && j<60 && i>340 && i<370? 224 : 0)
	  +(70<=j && j<122 && i>300 && i<330? 244 : 0)
	  +(70<=j && j<122 && i>340 && i<370? 224 : 0)
	  +(60<=j && j<=70 && i>300 && i<370? 255 : 0)
	  +(30<=j && j<122 && i>=330 && i<=340? 255 : 0)
	  +(((j-20)*(j-20)+(i-295)*(i-295)<=(5)*(5)) ?255:0)
	  +(((j-30)*(j-30)+(i-295)*(i-295)<=(5)*(5)) ?255:0)
	  +(20<=j && j<30 && i>290 && i<300? 255 : 0); 
	  
	  r2 = (((j-SunCentrumX)*(j-SunCentrumX)+(i-SunCentrumY)*(i-SunCentrumY)<=(SunRadius)*(SunRadius)) ?255:0)
	  + sunbeam1(j,i)
	  + sunbeam2(j,i)
	  + sunbeam3(j,i)
	  +(((j-SkyB1X)*(j-SkyB1X)+(i-SkyB1Y)*(i-SkyB1Y)<=(SkyB1R)*(SkyB1R)) ?255:0)
	  +(((j-SkyB2X)*(j-SkyB2X)+(i-SkyB2Y)*(i-SkyB2Y)<=(SkyB2R)*(SkyB2R)) ?255:0)
	  +(((j-SkyB3X)*(j-SkyB3X)+(i-SkyB3Y)*(i-SkyB3Y)<=(SkyB3R)*(SkyB3R)) ?255:0)
	  +(((j-SkyB4X)*(j-SkyB4X)+(i-SkyB4Y)*(i-SkyB4Y)<=(SkyB4R)*(SkyB4R)) ?255:0)
	  //door
	  +(300<j && j<340 && i>400 && i<480? 80 : 0)
	  + (j + TagForskydningYakse1 >= -i && -j + TagForskydningYakse2 >= -i && i < 355 ? 105 : 0)
	  +(350<j && j<390 && i>370 && i<410? 255 : 0)
	  +(20<j && j<30 && i>300 && i<480? 255 : 0)
	  +(30<=j && j<60 && i>300 && i<330? 24 : 0)
	  +(30<=j && j<60 && i>340 && i<370? 24 : 0)
	  +(70<=j && j<122 && i>300 && i<330? 24 : 0)
	  +(70<=j && j<122 && i>340 && i<370? 24 : 0)
	  +(60<=j && j<=70 && i>300 && i<370? 255 : 0)
	  +(30<=j && j<122 && i>=330 && i<=340? 255 : 0); 
	  
	  r3 = (((j-SkyB1X)*(j-SkyB1X)+(i-SkyB1Y)*(i-SkyB1Y)<=(SkyB1R)*(SkyB1R)) ?255:0)
	  +(((j-SkyB2X)*(j-SkyB2X)+(i-SkyB2Y)*(i-SkyB2Y)<=(SkyB2R)*(SkyB2R)) ?255:0)
	  +(((j-SkyB3X)*(j-SkyB3X)+(i-SkyB3Y)*(i-SkyB3Y)<=(SkyB3R)*(SkyB3R)) ?255:0)
	  +(((j-SkyB4X)*(j-SkyB4X)+(i-SkyB4Y)*(i-SkyB4Y)<=(SkyB4R)*(SkyB4R)) ?255:0)
	  + (j + TagForskydningYakse1 >= -i && -j + TagForskydningYakse2 >= -i && i < 355 ? 105 : 0)
	  +(300<j && j<340 && i>400 && i<480? 50 : 0)
	  +(350<j && j<390 && i>370 && i<410? 255 : 0)
	  +(20<j && j<30 && i>300 && i<480? 255 : 0)
	  +(60<=j && j<=70 && i>300 && i<370? 255 : 0)
	  +(30<=j && j<122 && i>=330 && i<=340? 255 : 0)
	  +(30<=j && j<60 && i>300 && i<330? 54 : 0)
	  +(30<=j && j<60 && i>340 && i<370? 54 : 0)
	  +(70<=j && j<122 && i>300 && i<330? 54 : 0)
	  +(70<=j && j<122 && i>340 && i<370? 54 : 0);
	  
	  
	  
	  //græs
	  if (r1 == 0  && r2 ==0 && r3 == 0 && i + sin(j)*2>450){
	   r1=80;
	   r2=186;
	   r3=34;}
	  if (r1 == 0  && r2 ==0 && r3 == 0){
	   r1=27;
	   r2=224;
	   r3=214;}
	  
      fputc(r1, image_file);  fputc(r2, image_file); fputc(r3, image_file);
    }}

  fclose(image_file);
  return 0;
}

#define Sunbeam1_ForskydningY -500
#define Sunbeam1_Tykkelse 5

int sunbeam1(int x, int y) {
  int colorReturn = 0;
	
  if (x + Sunbeam1_ForskydningY + sin(x)*3 <= -y + Sunbeam1_Tykkelse && x + Sunbeam1_ForskydningY + sin(x)*3>= -y - Sunbeam1_Tykkelse && x > 300 && x < 350 && y < 200 && y > 150){
	colorReturn = 255;
  }
  
  return colorReturn;
}

#define Sunbeam2_ForskydningY -2100
#define Sunbeam2_Faktor_X 4.5
#define Sunbeam2_Tykkelse 15

int sunbeam2(int x, int y) {
  int colorReturn = 0;
	
  if (x*Sunbeam2_Faktor_X + Sunbeam2_ForskydningY + sin(y)*10 <= -y + Sunbeam2_Tykkelse && x*Sunbeam2_Faktor_X + Sunbeam2_ForskydningY + sin(y)*10>= -y - Sunbeam2_Tykkelse && y < 260 && y > 190 ){
	colorReturn = 255;
  }
  
  return colorReturn;
}

#define Sunbeam3_ForskydningY -120
#define Sunbeam3_Faktor_X 0.2
#define Sunbeam3_Tykkelse 3

int sunbeam3(int x, int y) {
  int colorReturn = 0;
	
  if (x*Sunbeam3_Faktor_X + Sunbeam3_ForskydningY + sin(x)*2 <= -y + Sunbeam3_Tykkelse && x*Sunbeam3_Faktor_X + Sunbeam3_ForskydningY + sin(x)*2>= -y - Sunbeam3_Tykkelse && x < 310 && x > 210){
	colorReturn = 255;
  }
  
  return colorReturn;
}
