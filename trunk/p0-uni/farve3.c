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
#define TagForskydningYakse1 -650
#define TagForskydningYakse2 28

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
      r1 = 
	  //Selve solen
	  (((j-SunCentrumX)*(j-SunCentrumX)+(i-SunCentrumY)*(i-SunCentrumY)<=(SunRadius)*(SunRadius)) ?255:0)
	  //Kalder funktion til solens 3 stråler
	  + sunbeam1(j,i)
	  + sunbeam2(j,i)
	  + sunbeam3(j,i)
	  //Laver de 4 cirkler til skyen
	  +(((j-SkyB1X)*(j-SkyB1X)+(i-SkyB1Y)*(i-SkyB1Y)<=(SkyB1R)*(SkyB1R)) ?255:0)
	  +(((j-SkyB2X)*(j-SkyB2X)+(i-SkyB2Y)*(i-SkyB2Y)<=(SkyB2R)*(SkyB2R)) ?255:0)
	  +(((j-SkyB3X)*(j-SkyB3X)+(i-SkyB3Y)*(i-SkyB3Y)<=(SkyB3R)*(SkyB3R)) ?255:0)
	  +(((j-SkyB4X)*(j-SkyB4X)+(i-SkyB4Y)*(i-SkyB4Y)<=(SkyB4R)*(SkyB4R)) ?255:0)
	  //Selve kassen til huset
	  + (280<j && j<400 && i>390 && i<480 && !((350<j && j<390 && i>400 && i<440) &&((368<j && j<372) || (418<i && i<422)))? 255 : 0)
	  //Taget til huset
	  + (j + TagForskydningYakse1 >= -i && -j + TagForskydningYakse2 >= -i && i <= 390 ? 105 : 0)
	  //Døren
	  +(300<j && j<340 && i>400 && i<480 && !(((j-325)*(j-325)+(i-445)*(i-445)<=(5)*(5)) || ((j-330)*(j-330)+(i-445)*(i-445)<=(5)*(5)) || +(325<=j && j<330 && i>440 && i<450? 255 : 0))? 80 : 0)
	  //Stangen til flagstang
	  +(20<j && j<30 && i>300 && i<480? 255 : 0)
	  //4 røde felter til flag (officiel RGB farve)
	  +(30<=j && j<60 && i>300 && i<330? 224 : 0)
	  +(30<=j && j<60 && i>340 && i<370? 224 : 0)
	  +(70<=j && j<122 && i>300 && i<330? 244 : 0)
	  +(70<=j && j<122 && i>340 && i<370? 224 : 0)
	  //Hvide streger i flag
	  +(60<=j && j<=70 && i>300 && i<370? 255 : 0)
	  +(30<=j && j<122 && i>=330 && i<=340? 255 : 0)
	  //knop til flag
	  +(((j-20)*(j-20)+(i-295)*(i-295)<=(5)*(5)) ?255:0)
	  +(((j-30)*(j-30)+(i-295)*(i-295)<=(5)*(5)) ?255:0)
	  +(20<=j && j<30 && i>290 && i<300? 255 : 0)
	  //regnbue
	  +regnbue(j,i,1)
	  //Dørhåndtag
	  +(((j-325)*(j-325)+(i-445)*(i-445)<=(5)*(5)) ?192:0)
	  +(((j-330)*(j-330)+(i-445)*(i-445)<=(5)*(5)) ?192:0)
	  +(325<=j && j<330 && i>440 && i<450? 192 : 0)
	  //Menneske
	  +menneske(j,i,1)
	  //Træ
	  +tree(j,i,1); 
	  
	  r2 = 
	  //Selve solen
	  (((j-SunCentrumX)*(j-SunCentrumX)+(i-SunCentrumY)*(i-SunCentrumY)<=(SunRadius)*(SunRadius)) ?255:0)
	  //3 solstråler
	  + sunbeam1(j,i)
	  + sunbeam2(j,i)
	  + sunbeam3(j,i)
	  //4 cirkler til skyen
	  +(((j-SkyB1X)*(j-SkyB1X)+(i-SkyB1Y)*(i-SkyB1Y)<=(SkyB1R)*(SkyB1R)) ?255:0)
	  +(((j-SkyB2X)*(j-SkyB2X)+(i-SkyB2Y)*(i-SkyB2Y)<=(SkyB2R)*(SkyB2R)) ?255:0)
	  +(((j-SkyB3X)*(j-SkyB3X)+(i-SkyB3Y)*(i-SkyB3Y)<=(SkyB3R)*(SkyB3R)) ?255:0)
	  +(((j-SkyB4X)*(j-SkyB4X)+(i-SkyB4Y)*(i-SkyB4Y)<=(SkyB4R)*(SkyB4R)) ?255:0)
	  //dør til hus
	  +(300<j && j<340 && i>400 && i<480 && !(((j-325)*(j-325)+(i-445)*(i-445)<=(5)*(5)) || ((j-330)*(j-330)+(i-445)*(i-445)<=(5)*(5)) || +(325<=j && j<330 && i>440 && i<450? 255 : 0))? 80 : 0)
	  //tag til hus
	  + (j + TagForskydningYakse1 >= -i && -j + TagForskydningYakse2 >= -i && i <= 390 ? 105 : 0)
	  //vindue til hus
	  +(350<j && j<390 && i>400 && i<440 && !(368<j && j<372) && !(418<i && i<422)? 255 : 0)
	  //stangen til flagstang
	  +(20<j && j<30 && i>300 && i<480? 255 : 0)
	  //4 røde felter til dannebrog (officiel RGB farve til flag)
	  +(30<=j && j<60 && i>300 && i<330? 24 : 0)
	  +(30<=j && j<60 && i>340 && i<370? 24 : 0)
	  +(70<=j && j<122 && i>300 && i<330? 24 : 0)
	  +(70<=j && j<122 && i>340 && i<370? 24 : 0)
	  //2 hvide streger i flag
	  +(60<=j && j<=70 && i>300 && i<370? 255 : 0)
	  +(30<=j && j<122 && i>=330 && i<=340? 255 : 0)
	  //Regnbue
	  +regnbue(j,i,2)
	  //Dørhåndtag
	  +(((j-325)*(j-325)+(i-445)*(i-445)<=(5)*(5)) ?192:0)
	  +(((j-330)*(j-330)+(i-445)*(i-445)<=(5)*(5)) ?192:0)
	  +(325<=j && j<330 && i>440 && i<450? 192 : 0)
	  //Menneske
	  +menneske(j,i,2)
	  //Træ
	  +tree(j,i,2);
	  
	  r3 = 
	  //4 cirkler til sky
	  (((j-SkyB1X)*(j-SkyB1X)+(i-SkyB1Y)*(i-SkyB1Y)<=(SkyB1R)*(SkyB1R)) ?255:0)
	  +(((j-SkyB2X)*(j-SkyB2X)+(i-SkyB2Y)*(i-SkyB2Y)<=(SkyB2R)*(SkyB2R)) ?255:0)
	  +(((j-SkyB3X)*(j-SkyB3X)+(i-SkyB3Y)*(i-SkyB3Y)<=(SkyB3R)*(SkyB3R)) ?255:0)
	  +(((j-SkyB4X)*(j-SkyB4X)+(i-SkyB4Y)*(i-SkyB4Y)<=(SkyB4R)*(SkyB4R)) ?255:0)
	  //Tag til hus
	  + (j + TagForskydningYakse1 >= -i && -j + TagForskydningYakse2 >= -i && i <= 390 ? 105 : 0)
	  //Dør til hus
	  +(300<j && j<340 && i>400 && i<480 && !(((j-325)*(j-325)+(i-445)*(i-445)<=(5)*(5)) || ((j-330)*(j-330)+(i-445)*(i-445)<=(5)*(5)) || +(325<=j && j<330 && i>440 && i<450? 255 : 0))? 50 : 0)
	  //Vindue til hus
	  +(350<j && j<390 && i>400 && i<440 && !(368<j && j<372) && !(418<i && i<422)? 255 : 0)
	  //Ramme til vindue
	  +(350<j && j<390 && i>400 && i<440 && ((368<j && j<372) || (418<i && i<422))? 1 : 0)
	  //Stangen til flagstang
	  +(20<j && j<30 && i>300 && i<480? 255 : 0)
	  //2 hvide streger til flag
	  +(60<=j && j<=70 && i>300 && i<370? 255 : 0)
	  +(30<=j && j<122 && i>=330 && i<=340? 255 : 0)
	  //4 røde felter til flag
	  +(30<=j && j<60 && i>300 && i<330? 54 : 0)
	  +(30<=j && j<60 && i>340 && i<370? 54 : 0)
	  +(70<=j && j<122 && i>300 && i<330? 54 : 0)
	  +(70<=j && j<122 && i>340 && i<370? 54 : 0)
	  //Regnbue
	  +regnbue(j,i,3)
	  //Dørhåndtag
	  +(((j-325)*(j-325)+(i-445)*(i-445)<=(5)*(5)) ?192:0)
	  +(((j-330)*(j-330)+(i-445)*(i-445)<=(5)*(5)) ?192:0)
	  +(325<=j && j<330 && i>440 && i<450? 192 : 0)
	  //Måger
	  +maage1(j,i)
	  //Menneske
	  +menneske(j,i,3)
	  //Træ
	  +tree(j,i,3)
	  ;
	  
	  
	  
	  //græs
	  if (r1 == 0  && r2 ==0 && r3 == 0 && i + sin(j)*2>450){
	   r1=80;
	   r2=186;
	   r3=34;}
	  //blå baggrund
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



#define maageCirR 20
#define maageCir1X 200
#define maageCir1Y 180
#define maageCir2X 200
#define maageCir2Y 185
#define maageCir3X 240
#define maageCir3Y 180
#define maageCir4X 240
#define maageCir4Y 185
#define maageCir5X 250
#define maageCir5Y 230
#define maageCir6X 250
#define maageCir6Y 235
#define maageCir7X 290
#define maageCir7Y 230
#define maageCir8X 290
#define maageCir8Y 235

int maage1 (int x, int y){
   int colorReturn = 0;
   
   colorReturn = ((x-maageCir1X)*(x-maageCir1X)+(y-maageCir1Y)*(y-maageCir1Y)<=(maageCirR)*(maageCirR)) && !((x-maageCir2X)*(x-maageCir2X)+(y-maageCir2Y)*(y-maageCir2Y)<=(maageCirR)*(maageCirR)) ||  ((x-maageCir3X)*(x-maageCir3X)+(y-maageCir3Y)*(y-maageCir3Y)<=(maageCirR)*(maageCirR)) && !((x-maageCir4X)*(x-maageCir4X)+(y-maageCir4Y)*(y-maageCir4Y)<=(maageCirR)*(maageCirR))?1:0;
   if (colorReturn == 0){
     colorReturn = ((x-maageCir5X)*(x-maageCir5X)+(y-maageCir5Y)*(y-maageCir5Y)<=(maageCirR)*(maageCirR)) && !((x-maageCir6X)*(x-maageCir6X)+(y-maageCir6Y)*(y-maageCir6Y)<=(maageCirR)*(maageCirR)) ||  ((x-maageCir7X)*(x-maageCir7X)+(y-maageCir7Y)*(y-maageCir7Y)<=(maageCirR)*(maageCirR)) && !((x-maageCir8X)*(x-maageCir8X)+(y-maageCir8Y)*(y-maageCir8Y)<=(maageCirR)*(maageCirR))?1:0;
   }
   
   return colorReturn;
}

#define benVforskydningY 540 
#define benHforskydningY 360
#define armVforskydningY 520
#define armHforskydningY 340
#define Vfactor -1
#define Hfactor 1
#define benTykkelse 5
#define menneskePunktRadius 5
#define benEndepunktX1 70
#define benEndepunktY1 470
#define benEndepunktX2 110
#define benEndepunktY2 470
#define armEndepunktX1 70
#define armEndepunktY1 450
#define armEndepunktX2 110
#define armEndepunktY2 450
#define hovedX 90
#define hovedY 410
#define hovedRadius 15
#define eyeRadius 3
#define eyeHX 85
#define eyeHY 408
#define eyeVX 95
#define eyeVY 408
#define mundRadius 10
#define mundX1 90
#define mundY1 410
#define mundX2 90
#define mundY2 408

int menneske (int x, int y, int color)
{
   int colorReturn = 0, colorCheck = 0;
   
   //Punkt på venstre ben
   if ((x-benEndepunktX1)*(x-benEndepunktX1)+(y-benEndepunktY1)*(y-benEndepunktY1)<=(menneskePunktRadius)*(menneskePunktRadius)){
     colorCheck = 2;
   }
   //Punkt på højre ben
   else if ((x-benEndepunktX2)*(x-benEndepunktX2)+(y-benEndepunktY2)*(y-benEndepunktY2)<=(menneskePunktRadius)*(menneskePunktRadius)){
     colorCheck = 2;
   }
   //Punkt ved venstre arm
   else if ((x-armEndepunktX1)*(x-armEndepunktX1)+(y-armEndepunktY1)*(y-armEndepunktY1)<=(menneskePunktRadius)*(menneskePunktRadius)){
     colorCheck = 2;
   }
   //Punkt ved højre arm
   else if ((x-armEndepunktX2)*(x-armEndepunktX2)+(y-armEndepunktY2)*(y-armEndepunktY2)<=(menneskePunktRadius)*(menneskePunktRadius)){
     colorCheck = 2;
   }
   //Venstre øje
   else if ((x-eyeVX)*(x-eyeVX)+(y-eyeVY)*(y-eyeVY)<=(eyeRadius)*(eyeRadius)){
     colorCheck = 4;
   }
   //Højre øje
   else if ((x-eyeHX)*(x-eyeHX)+(y-eyeHY)*(y-eyeHY)<=(eyeRadius)*(eyeRadius)){
     colorCheck = 4;
   }
   //Mund
   else if (((x-mundX1)*(x-mundX1)+(y-mundY1)*(y-mundY1)<=(mundRadius)*(mundRadius)) && !((x-mundX2)*(x-mundX2)+(y-mundY2)*(y-mundY2)<=(mundRadius)*(mundRadius))){
     colorCheck = 5;
   }
   //Hoved
   else if ((x-hovedX)*(x-hovedX)+(y-hovedY)*(y-hovedY)<=(hovedRadius)*(hovedRadius)){
     colorCheck = 2;
   }
   //Hår på hoved
   else if (sin(x*2)*150+(x-hovedX)*(x-hovedX)+(y-hovedY)*(y-hovedY)<=(hovedRadius)*(hovedRadius) && y<400){
     colorCheck = 3;
   }
   //Venstre ben
   else if (x*Vfactor+benVforskydningY <= y + benTykkelse && x*Vfactor+benVforskydningY >= y - benTykkelse && x > 70 && x < 90){
     colorCheck = 1;
   }
   //Højre ben
   else if (x*Hfactor+benHforskydningY <= y + benTykkelse && x*Hfactor+benHforskydningY >= y - benTykkelse && x >= 90 && x < 110){
     colorCheck = 1;
   }
   //Krop
   else if (x<95 && x>85 && y<450 && y> 415){
     colorCheck = 1;
   }
   //Højre arm
   else if (x*Hfactor+armHforskydningY <= y + benTykkelse && x*Hfactor+armHforskydningY >= y - benTykkelse && x >= 90 && x < 110){
     colorCheck = 1;
   }
   //Venstre arm
   else if (x*Vfactor+armVforskydningY <= y + benTykkelse && x*Vfactor+armVforskydningY >= y - benTykkelse && x >= 70 && x < 90){
     colorCheck = 1;
   }
   
   
   if (colorCheck == 1){
     if (color == 1){
	   colorReturn = 139;}
	 else if (color == 2){
	   colorReturn = 137;}
	 else if (color == 3){
	   colorReturn = 137;}
   } else if (colorCheck == 2){
     if (color == 1){
	   colorReturn = 244;}
	 else if (color == 2){
	   colorReturn = 164;}
	 else if (color == 3){
	   colorReturn = 96;}
	   
   }else if (colorCheck == 3){
     if (color == 1){
	   colorReturn = 160;}
	 else if (color == 2){
	   colorReturn = 82;}
	 else if (color == 3){
	   colorReturn = 45;}
	   
   }else if (colorCheck == 4){
     if (color == 1){
	   colorReturn = 65;}
	 else if (color == 2){
	   colorReturn = 105;}
	 else if (color == 3){
	   colorReturn = 225;}
   }else if (colorCheck == 5){
     colorReturn = 255;
   }
   
   return colorReturn;
}

#define bladRadius 25
#define bladX1 180
#define bladY1 370
#define bladX2 210
#define bladY2 370
#define bladX3 160
#define bladY3 340
#define bladX4 230
#define bladY4 340
#define bladX5 180
#define bladY5 310
#define bladX6 210
#define bladY6 310
#define bladX7 195
#define bladY7 340

#define appleRadius 5
#define appleX1 180
#define appleY1 370
#define appleX2 210
#define appleY2 370
#define appleX3 160
#define appleY3 340
#define appleX4 230
#define appleY4 340
#define appleX5 180
#define appleY5 310
#define appleX6 210
#define appleY6 310
#define appleX7 195
#define appleY7 340

int tree(int x, int y, int color){
  int colorReturn = 0, colorCheck = 0;
  
  //Æbler
  if ((x-appleX1)*(x-appleX1)+(y-appleY2)*(y-appleY2)<=(appleRadius)*(appleRadius)){
     colorCheck = 3;
  }else if ((x-appleX2)*(x-appleX2)+(y-appleY2)*(y-appleY2)<=(appleRadius)*(appleRadius)){
     colorCheck = 3;
  }else if ((x-appleX3)*(x-appleX3)+(y-appleY3)*(y-appleY3)<=(appleRadius)*(appleRadius)){
     colorCheck = 3;
  }else if ((x-appleX4)*(x-appleX4)+(y-appleY4)*(y-appleY4)<=(appleRadius)*(appleRadius)){
     colorCheck = 3;
  }else if ((x-appleX5)*(x-appleX5)+(y-appleY5)*(y-appleY5)<=(appleRadius)*(appleRadius)){
     colorCheck = 3;
  }else if ((x-appleX6)*(x-appleX6)+(y-appleY6)*(y-appleY6)<=(appleRadius)*(appleRadius)){
     colorCheck = 3;
  }else if ((x-appleX7)*(x-appleX7)+(y-appleY7)*(y-appleY7)<=(appleRadius)*(appleRadius)){
     colorCheck = 3;
  }
  //Blade
  else if ((x-bladX1)*(x-bladX1)+(y-bladY2)*(y-bladY2)<=(bladRadius)*(bladRadius)){
     colorCheck = 2;
  }else if ((x-bladX2)*(x-bladX2)+(y-bladY2)*(y-bladY2)<=(bladRadius)*(bladRadius)){
     colorCheck = 2;
  }else if ((x-bladX3)*(x-bladX3)+(y-bladY3)*(y-bladY3)<=(bladRadius)*(bladRadius)){
     colorCheck = 2;
  }else if ((x-bladX4)*(x-bladX4)+(y-bladY4)*(y-bladY4)<=(bladRadius)*(bladRadius)){
     colorCheck = 2;
  }else if ((x-bladX5)*(x-bladX5)+(y-bladY5)*(y-bladY5)<=(bladRadius)*(bladRadius)){
     colorCheck = 2;
  }else if ((x-bladX6)*(x-bladX6)+(y-bladY6)*(y-bladY6)<=(bladRadius)*(bladRadius)){
     colorCheck = 2;
  }else if ((x-bladX7)*(x-bladX7)+(y-bladY7)*(y-bladY7)<=(bladRadius)*(bladRadius)){
     colorCheck = 2;
  }
  //stamme på træ
  else if (x<210 && x> 180 && y<465 && y>390){
    colorCheck = 1;
  }
  
  if (colorCheck == 1){
     if (color == 1){
	   colorReturn = 139;}
	 else if (color == 2){
	   colorReturn = 69;}
	 else if (color == 3){
	   colorReturn = 19;}
   } else if (colorCheck == 2){
     if (color == 1){
	   colorReturn = 34;}
	 else if (color == 2){
	   colorReturn = 139;}
	 else if (color == 3){
	   colorReturn = 34;}
	   }
   else if (colorCheck == 3){
     if (color == 1){
	   colorReturn = 255;}
	 else if (color == 2){
	   colorReturn = 0;}
	 else if (color == 3){
	   colorReturn = 0;}
	   }
  
  return colorReturn;
}

#define forskydningY1 250
#define forskydningY2 200
#define factor 0.001
#define insidefactor 000.1

int regnbue(int x, int y, int color)
{
	int funktionY1, funktionY2, colorReturn = 0;
	float Procent, AfstandLinjer, AfstandPunkt;
	funktionY1 = (x+insidefactor)*(x+insidefactor)*factor+forskydningY1;
	funktionY2 = (x+insidefactor)*(x+insidefactor)*factor+forskydningY2;

	if (y<funktionY1 && y>funktionY2 && (x + TagForskydningYakse1 < -y || (-x + TagForskydningYakse2 < -y || y>390)) && !(y>390 && x<400) && y + sin(x)*2<=450 && !((x-bladX6)*(x-bladX6)+(y-bladY6)*(y-bladY6)<=(bladRadius)*(bladRadius))){

		AfstandLinjer = funktionY1 - funktionY2;
		AfstandPunkt = funktionY1 - y;
		Procent = (AfstandPunkt/AfstandLinjer)*100;
		
		if (Procent <= 20){
		  if (color == 1){
		    colorReturn = 255-(Procent/20)*255;}
		  else if (color == 2){
		    colorReturn = 0;}
		  else if (color == 3){
		    colorReturn = 255;}
		}
		else if (Procent <= 40){
		  if (color == 1){
		    colorReturn = 0;}
		  else if (color == 2){
		    colorReturn = ((Procent-20)/20)*255;}
		  else if (color == 3){
		    colorReturn = 255;}
		}
		else if (Procent <= 60){
		  if (color == 1){
		    colorReturn = 0;}
		  else if (color == 2){
		    colorReturn = 255;}
		  else if (color == 3){
		    colorReturn = 255-((Procent-40)/20)*255;}
		}
		else if (Procent <= 80){
		  if (color == 1){
		    colorReturn = ((Procent-60)/20)*255;}
		  else if (color == 2){
		    colorReturn = 255;}
		  else if (color == 3){
		    colorReturn = 0;}
		}
		else if (Procent <= 100){
		  if (color == 1){
		    colorReturn = 255;}
		  else if (color == 2){
		    colorReturn = 255-((Procent-80)/20)*255;}
		  else if (color == 3){
		    colorReturn = 0;}
		}
		
	}
	
	return colorReturn;
}

