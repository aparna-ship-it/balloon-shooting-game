#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void dino()
{
	line(100,400,100,385);
	line(100,385,94,385);
	line(94,385,94,378);
	line(94,378,86,378);
	line(86,378,76,368);
	line(76,368,76,350);
	line(76,350,80,350);
	line(80,350,80,360);
	line(80,360,90,365);
	line(90,365,100,365);
	line(100,365,120,350);
	line(120,350,120,330);
	line(120,330,126,330);
	line(126,330,126,324);
	line(126,324,150,324);
	line(150,324,150,330);
	line(150,330,155,330);
	line(155,330,155,340);
	line(155,340,140,340);
	line(140,340,140,345);
	line(140,345,150,345);
	line(150,345,150,348);
	line(150,348,138,348);
	line(138,348,138,358);
	line(138,358,145,358);
	line(145,358,145,365);
	line(145,365,141,365);
	line(141,365,141,362);
	line(141,362,138,362);
	line(138,362,138,372);
	line(138,372,124,382);
	line(124,382,124,390);
	line(124,390,128,390);
	line(128,390,128,394);
	line(128,394,120,394);
	line(120,394,120,389);
	line(120,389,115,387);
	line(115,387,110,390);
	line(110,390,110,393);
	line(110,393,106,393);
	line(106,393,106,396);
	line(106,396,110,396);
	line(110,396,110,400);
	line(110,400,100,400);
	setfillstyle(1,WHITE);
	floodfill(77,351,WHITE);
	rectangle(132,329,136,333);

}

void obstacle(int x)
{
	rectangle(x,374,x+10,400);
	setfillstyle(1,WHITE);
	floodfill(x+1,375,WHITE);

	rectangle(x-10,378,x,382);
	floodfill(x-9,379,WHITE);
	rectangle(x-10,370,x-7,378);
	floodfill(x-9,371,WHITE);

	rectangle(x+10,384,x+15,390);
	floodfill(x+11,385,WHITE);
	rectangle(x+15,372,x+18,390);
	floodfill(x+16,373,WHITE);
	rectangle(x+15,370,x+20,372);
	floodfill(x+16,371,WHITE);

}

int main(void)
{
	int i,j;
       /* request auto detection */
	int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
	initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
	errorcode = graphresult();

	if (errorcode != grOk)  /* an error occurred */
	{
	   printf("Graphics error: %s\n", grapherrormsg(errorcode));
	   printf("Press any key to halt:");
	   getch();
	   exit(1);             /* return with error code */
	}
	//initwindow(1024,768,"xyz",0,0);
	settextstyle(10,0,2);
	j=4;
	while(j>0)
	{
		i=500;
		while(i>0)
		{

			clearviewport();
			outtextxy(10,10,"LEVEL  : ");
			outtextxy(10,40,"POINTS : ");
			setcolor(WHITE);
			dino(i%2);
			rectangle(-1,400,700,500);
			setfillstyle(1,8);
			floodfill(0,402,WHITE);
			obstacle(i);
			i=i-11;
			delay(j*j*j*j);
		}
		j--;
	}

   /* clean up */
   getch();
   closegraph();
   return 0;
}
