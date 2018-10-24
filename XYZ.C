#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

float octave[7] = { 130.81, 146.83, 164.81, 174.61, 196, 220, 246.94};

void start()
{
	setcolor(1);

	setbkcolor(14);
	settextstyle(7,0,0);
	outtextxy(10,400,"  PRESS ANY KEY TO CONTINUE....");
	settextstyle(1,0,0);
	setcolor(4);
	setusercharsize(25,15,20,4);
	outtextxy(85,120,"DINO JUMP GAME");
	while( !kbhit() )
	{
		sound( octave[ random(7) ]*4 );
		delay(300);
	}
	nosound();
	getch();
}

void cloud(int x,int y)
{
	arc(x, y, 90, 180, 8);
	arc(x+8, y-8, 90, 180, 8);
	arc(x+16, y-16, 0, 180, 8);
	arc(x+24, y-8, 0, 90, 8);
	arc(x+32, y, 0, 90, 8);
	line(x-8, y, x+40, y);
	setfillstyle(1,15);
	floodfill(x,y-1,WHITE);
}

void dino(int i, int x, int y)
{
	if(i==0)
	{
		line(100+x,400+y,100+x,385+y);
		line(100+x,385+y,94+x,385+y);
		line(94+x,385+y,94+x,378+y);
		line(94+x,378+y,86+x,378+y);
		line(86+x,378+y,76+x,368+y);
		line(76+x,368+y,76+x,350+y);
		line(76+x,350+y,80+x,350+y);
		line(80+x,350+y,80+x,360+y);
		line(80+x,360+y,90+x,365+y);
		line(90+x,365+y,100+x,365+y);
		line(100+x,365+y,120+x,350+y);
		line(120+x,350+y,120+x,330+y);
		line(120+x,330+y,126+x,330+y);
		line(126+x,330+y,126+x,324+y);
		line(126+x,324+y,150+x,324+y);
		line(150+x,324+y,150+x,330+y);
		line(150+x,330+y,155+x,330+y);
		line(155+x,330+y,155+x,340+y);
		line(155+x,340+y,140+x,340+y);
		line(140+x,340+y,140+x,345+y);
		line(140+x,345+y,150+x,345+y);
		line(150+x,345+y,150+x,348+y);
		line(150+x,348+y,138+x,348+y);
		line(138+x,348+y,138+x,358+y);
		line(138+x,358+y,145+x,358+y);
		line(145+x,358+y,145+x,365+y);
		line(145+x,365+y,141+x,365+y);
		line(141+x,365+y,141+x,362+y);
		line(141+x,362+y,138+x,362+y);
		line(138+x,362+y,138+x,372+y);
		line(138+x,372+y,124+x,382+y);
		line(124+x,382+y,124+x,390+y);
		line(124+x,390+y,128+x,390+y);
		line(128+x,390+y,128+x,394+y);
		line(128+x,394+y,120+x,394+y);
		line(120+x,394+y,120+x,389+y);
		line(120+x,389+y,115+x,387+y);
		line(115+x,387+y,110+x,390+y);
		line(110+x,390+y,110+x,393+y);
		line(110+x,393+y,106+x,393+y);
		line(106+x,393+y,106+x,396+y);
		line(106+x,396+y,110+x,396+y);
		line(110+x,396+y,110+x,400+y);
		line(110+x,400+y,100+x,400+y);
		setfillstyle(1,8);
		floodfill(77,351,WHITE);
	}
	else
	{
		line(100+x,395+y,100+x,385+y);
		line(100+x,385+y,94+x,385+y);
		line(94+x,385+y,94+x,378+y);
		line(94+x,378+y,86+x,378+y);
		line(86+x,378+y,76+x,368+y);
		line(76+x,368+y,76+x,350+y);
		line(76+x,350+y,80+x,350+y);
		line(80+x,350+y,80+x,360+y);
		line(80+x,360+y,90+x,365+y);
		line(90+x,365+y,100+x,365+y);
		line(100+x,365+y,120+x,350+y);
		line(120+x,350+y,120+x,330+y);
		line(120+x,330+y,126+x,330+y);
		line(126+x,330+y,126+x,324+y);
		line(126+x,324+y,150+x,324+y);
		line(150+x,324+y,150+x,330+y);
		line(150+x,330+y,155+x,330+y);
		line(155+x,330+y,155+x,340+y);
		line(155+x,340+y,140+x,340+y);
		line(140+x,340+y,140+x,345+y);
		line(140+x,345+y,150+x,345+y);
		line(150+x,345+y,150+x,348+y);
		line(150+x,348+y,138+x,348+y);
		line(138+x,348+y,138+x,358+y);
		line(138+x,358+y,145+x,358+y);
		line(145+x,358+y,145+x,365+y);
		line(145+x,365+y,141+x,365+y);
		line(141+x,365+y,141+x,362+y);
		line(141+x,362+y,138+x,362+y);
		line(138+x,362+y,138+x,372+y);
		line(138+x,372+y,124+x,382+y);
		line(124+x,382+y,124+x,396+y);
		line(124+x,396+y,128+x,396+y);
		line(128+x,396+y,128+x,400+y);
		line(128+x,400+y,120+x,400+y);
		line(120+x,400+y,120+x,389+y);
		line(120+x,389+y,115+x,387+y);
		line(115+x,387+y,110+x,390+y);
		line(110+x,391+y,110+x,395+y);
		line(110+x,395+y,100+x,395+y);
		setfillstyle(1,8);
		floodfill(77,351,WHITE);
	}

}

void obstacle(int x)
{
	rectangle(x,374,x+10,400);
	setfillstyle(1,6);
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
	int i,j,x=0,y=0,k=0;
	char ch;
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

	start();

	settextstyle(10,0,2);

	setbkcolor(3);
	outtextxy(10,10,"LEVEL  : ");
	outtextxy(10,40,"POINTS : ");
	setcolor(WHITE);
	dino(0,0,0);
	rectangle(-1,400,700,500);
	setfillstyle(1,2);
	floodfill(0,402,WHITE);
	obstacle(1000);
	cloud(100,100);
	cloud(200,200);
	cloud(300,200);
	cloud(300,300);
	cloud(400,100);
	cloud(500,200);
	cloud(500,300);

	outtextxy(400,340,"PRESS ANY KEY TO START ");
	getch();

	j=4;
	while(1)
	{
		x=0;
		y=0;
		i=500;
		while(i>0)
		{

			while(!kbhit())
			{
				clearviewport();
				setbkcolor(3);
				outtextxy(10,10,"LEVEL  : ");
				outtextxy(10,40,"POINTS : ");
				setcolor(WHITE);
				dino(i%2,x,y);
				rectangle(-1,400,700,500);
				setfillstyle(1,2);
				floodfill(0,402,WHITE);
				obstacle(i);
				cloud(100,100);
				cloud(200,200);
				cloud(300,200);
				cloud(300,300);
				cloud(400,100);
				cloud(500,200);
				cloud(500,300);
				i=i-11;
				delay(j*j*j);
			}
			ch = getch();

			if(ch == 'w')
			{
				for(k=0;k>=-40;k-=4)
				{
					sound( octave[ random(7) ]*4 );
					clearviewport();
					setbkcolor(3);
					outtextxy(10,10,"LEVEL  : ");
					outtextxy(10,40,"POINTS : ");
					setcolor(WHITE);
					dino(i%2,x,k);
					rectangle(-1,400,700,500);
					setfillstyle(1,2);
					floodfill(0,402,WHITE);
					obstacle(i);
					cloud(100,100);
					cloud(200,200);
					cloud(300,200);
					cloud(300,300);
					cloud(400,100);
					cloud(500,200);
					cloud(500,300);
					i=i-11	;
					delay(j*j*j);
				}
				for(;k<=0;k+=3)
				{
					sound( octave[ random(7) ]*4 );
					clearviewport();
					setbkcolor(3);
					outtextxy(10,10,"LEVEL  : ");
					outtextxy(10,40,"POINTS : ");
					setcolor(WHITE);
					dino(i%2,x,k);
					rectangle(-1,400,700,500);
					setfillstyle(1,2);
					floodfill(0,402,WHITE);
					obstacle(i);
					cloud(100,100);
					cloud(200,200);
					cloud(300,200);
					cloud(300,300);
					cloud(400,100);
					cloud(500,200);
					cloud(500,300);
					i=i-11	;
					delay(j*j*j);
				}
			}
			else if(ch == 'x')
			{
				exit(0);
			}
			nosound();
		}
	}

   /* clean up */
   getch();
   closegraph();
   return 0;
}
