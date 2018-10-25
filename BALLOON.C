#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
void draw_screen();
void show_screen(int chance,int success,int score,int level,int color);
void draw_shaft(int x,int y,int c);
void draw_baloon(int x,int y,int c);
void show_score(int chance,int success,int score,int level,int color);
void level_1();
void level_2();
void level_3();
void over_1();
void finish();
int point,i=20;
void main()
{  float octave[7] = { 130.81, 146.83, 164.81, 174.61, 196, 220, 246.94};
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setcolor(1);

	setbkcolor(14);
	settextstyle(7,0,0);
	outtextxy(10,400,"  PRESS ANY KEY TO CONTINUE....");
	settextstyle(1,0,0);
	setcolor(4);
	setusercharsize(25,15,20,4);
	outtextxy(85,120,"BALLOON SHOOTING");

	while( !kbhit() )
	{
		sound( octave[ random(7) ]*4 );
		delay(300);
	}
	nosound();
	getch();
	clearviewport();
	rectangle(1,1,638,478);
	settextstyle(3,0,1);
	setusercharsize(50,30,50,30);
	outtextxy(150,10,"INSTRUCTIONS");
	setbkcolor(12);
	settextstyle(1,0,1);
	setusercharsize(40,70,20,20);
	outtextxy(10,70,"1. You can play three levels.");
	outtextxy(10,110,"2. You can move the bow UP and DOWN with the help of arrow keys.");
	outtextxy(10,150,"3. Press Enter key to shoot the arrow.");
	outtextxy(10,190,"4. You score 10 points every time you shoot the balloon.");
	outtextxy(10,230,"5. First level has 6 arrows and 10 balloons.");
	outtextxy(10,270,"6. You require to score 100 points to enter the second level.");
	outtextxy(10,310,"7. Second level has 6 arrows and 8 balloons.");
	outtextxy(10,350,"8. You require to score 200 points to enter the third level.");
	outtextxy(10,390,"9. Third level has 6 arrows and 6 balloons.");
	settextstyle(7,0,1);
	outtextxy(150,430,"PRESS ANY KEY TO CONITINUE");

	getch();
	setusercharsize(1,1,1,1);
	settextstyle(0,0,0);
	setbkcolor(10);
	clearviewport();
	 level_1();
getch();
closegraph();
}


void draw_screen()
{ int i;
setfillstyle(1,2);
bar(0,0,150,20);
outtextxy(30,5,"Score Board");
setfillstyle(1,3);
bar(0,20,150,250);
setcolor(1);
outtextxy(30,40,"Total Chance");
outtextxy(30,80,"Success");
outtextxy(30,120,"  Score");
outtextxy(30,160,"  Level");
setcolor(15);
setfillstyle(1,2);
bar(0,255,150,275);
outtextxy(30,260,"Control key");
setfillstyle(1,3);
bar(0,275,150,479);

setcolor(1);
outtextxy(30,290,"UP");
setcolor(4);
for(i=0;i<=5;i++)
{line (100-i,285+i,100+i,285+i);
line(100,290,100,300);
}
setcolor(1);
outtextxy(30,330,"DOWN");
setcolor(4);
for(i=0;i<=5;i++)
line(95+i,330+i,105-i,330+i);
line(100,320,100,330);

setcolor(1);
outtextxy(30,370,"Shoot");
setcolor(4);
outtextxy(100,370,"Enter");

setcolor(1);
outtextxy(30,410,"Exit");
setcolor(4);
outtextxy(100,410,"Esc");
setfillstyle(1,1);
bar(151,0,639,479);
}
void show_score(int chance,int success,int score ,int level,int color)
{ char str[3];
setcolor(color);

gcvt(chance,3,str);
outtextxy(70,60,str);
gcvt(success,3,str);
outtextxy(70,100,str);
gcvt(score,3,str);
outtextxy(70,140,str);
gcvt(level,3,str);
outtextxy(70,180,str);
}
void draw_shaft(int x, int y, int c)
{
setcolor(c);

rectangle(x-1,y-1,x-30,y+1);
line(x,y,x-30,y);
line(x,y,x-6,y-4);
line(x,y,x-6,y+4);
}
void draw_baloon(int x,int y,int c)
{ int i;
setcolor(c);
setfillstyle(1,c);
sector(x,y,0,180,10,10);
for(i=0;i<=12;i++)
line(x-10+i,y+i,x+10-i,y+i);
}
void level_1()
{  int chance=0,success=0,score=0,chance_end=0,level=1;
 int shaft_x=185,shaft_y=200,shaft_color=4;
 int baloon_x=400,baloon_y=400,baloon_color=15;
 int gd=0,gm;
 char ch;
 union REGS ii,oo;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 draw_screen();


 /*show initial score*/
 show_score (chance,success,score,level,0);
 draw_shaft(shaft_x,shaft_y,shaft_color);
 draw_baloon(baloon_x,baloon_y,baloon_color);

 while(1)
 {
  chance_end=0;//initialize chance*/
  while (!chance_end)
  {
   //while not chance end//
   //until a key is hited ,move the ballon up//
   while (!kbhit())
   {
    delay(20);//wait 20 miliseconds//
    baloon_color=1;//to irrage baloon with screen color
    draw_baloon(baloon_x,baloon_y,baloon_color);
    //move up and draw in new place
    baloon_y--;
    baloon_color=15;
    draw_baloon(baloon_x,baloon_y,baloon_color);

   }
   ii.h.ah=0;
   int86(22,&ii,&oo);
   if(oo.h.al==0)
   {
    //if the pressed key was a function key
    switch(oo.h.ah)
    {
     case 72: //up
     //irrage shaft from old plece
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //draw shaft in new place
     shaft_y=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;
     case 80: //down
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_y+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;

    }

   }
  else
  {
   switch(oo.h.al)
   {
    case 13://enter key was pressed to hit baloon
    /*move both baloon and shaft until the baloon is being hitted, or the shaft goes outside of boundary*/
    do{
     delay(20);
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     baloon_y--;
     baloon_color=15;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_x+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //check if baloon is hitted
     if(shaft_x>baloon_x-10&& shaft_x<baloon_x+10&& shaft_y>baloon_y-10 && shaft_y<baloon_y+10)
     {
     for(i=800;i<=1000;i+=20)
     {
     sound(250);
     delay(5);
     }
     nosound();
      baloon_color=1;
      draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      success++;
      score+=10;
      point=score;
      show_score(chance,success,score,level,1);
      chance_end=1;
      //set position of the shaft and baloon for next chance
      shaft_x=185;
      shaft_y=200;//get a random x coordinate
      //of baloon whether it must be
      //between 300 and 600
      if (point>=30)
      {
      level_2();
      }
      do{
       baloon_x=rand()%600;

      }
      while(baloon_x<300);
      baloon_y=400;//y is fixed

     }
     else
     //check if baloon or shaft over the boundaries
     if (shaft_x>640|| baloon_y<0)
     {
     //irrage both baloon and shaft
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      show_score(chance,success,score,level,0);
      chance_end=1;
      shaft_x=185;
      shaft_y=200;
      do{
       baloon_x=rand()%600;

      }while(baloon_x<300);
      baloon_y=400;
     }
     }
     while(!chance_end);
     break;
     case 27:
     closegraph();
     exit(1);
    }
   }
  }
  }
}
void level_2()
{union REGS ii,oo;
 int chance=0,success=0,score=0,chance_end=0,level=2;
 int shaft_x=185,shaft_y=200,shaft_color=4;
 int baloon_x=400,baloon_y=400,baloon_color=15;
char ch;
int gd=DETECT,gm;
initgraph(&gd, &gm,"C:\\TC\\BGI");
setcolor(1);
for (i=20;i<=2000;i+=20)
{
sound(i);
delay(20);

}
outtextxy(100,100,"Welcome to level TWO");
outtextxy(100,200,"Press '2' to enter level Two");
if(getch()=='2')
{
nosound();

 initgraph(&gd,&gm,"C:\\TC\\BGI");
 draw_screen();


 /*show initial score*/
 show_score (chance,success,score,level,0);
 draw_shaft(shaft_x,shaft_y,shaft_color);
 draw_baloon(baloon_x,baloon_y,baloon_color);

 while(1)
 {
  chance_end=0;//initialize chance*/
  while (!chance_end)
  {
   //while not chance end//
   //until a key is hited ,move the ballon up//
   while (!kbhit())
   {
    delay(10);//wait 20 miliseconds//
    baloon_color=1;//to irrage baloon with screen color
    draw_baloon(baloon_x,baloon_y,baloon_color);
    //move up and draw in new place
    baloon_y--;
    baloon_color=15;
    draw_baloon(baloon_x,baloon_y,baloon_color);

   }
   ii.h.ah=0;
   int86(22,&ii,&oo);
   if(oo.h.al==0)
   {
    //if the pressed key was a function key
    switch(oo.h.ah)
    {
     case 72: //up
     //irrage shaft from old plece
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //draw shaft in new place
     shaft_y=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;
     case 80: //down
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_y+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;

    }

   }
  else
  {
   switch(oo.h.al)
   {
    case 13://enter key was pressed to hit baloon
    /*move both baloon and shaft until the baloon is being hitted, or the shaft goes outside of boundary*/
    do{
     delay(10);
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     baloon_y--;
     baloon_color=15;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_x+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //check if baloon is hitted
     if(shaft_x>baloon_x-10&& shaft_x<baloon_x+10&& shaft_y>baloon_y-10 && shaft_y<baloon_y+10)
     {
     for(i=20;i<=2000;i+=20)
     {
      sound(250);
      delay(8);
     }
     nosound();
      baloon_color=1;
      draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      success++;
      score+=10;
      point=score;
      show_score(chance,success,score,level,1);
      chance_end=1;
      //set position of the shaft and baloon for next chance
      shaft_x=185;
      shaft_y=200;//get a random x coordinate
      //of baloon whether it must be
      //between 300 and 600
      if (point>=60)
      {
      level_3();
      }
      do{
       baloon_x=rand()%600;

      }
      while(baloon_x<300);
      baloon_y=400;//y is fixed

     }
     else
     //check if baloon or shaft over the boundaries
     if (shaft_x>640|| baloon_y<0)
     {
     //irrage both baloon and shaft
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      show_score(chance,success,score,level,0);
      chance_end=1;
      shaft_x=185;
      shaft_y=200;
      do{
       baloon_x=rand()%600;

      }while(baloon_x<300);
      baloon_y=400;
     }
     }
     while(!chance_end);
     break;
     case 27:
     closegraph();
     exit(1);
    }
   }
  }
  }
}
else
{
outtextxy(100,300,"Wrong Key ! Please Enter The Right Key");
if(getch()=='2')
{
nosound();

 initgraph(&gd,&gm,"C:\\TC\\BGI");
 draw_screen();


 /*show initial score*/
 show_score (chance,success,score,level,0);
 draw_shaft(shaft_x,shaft_y,shaft_color);
 draw_baloon(baloon_x,baloon_y,baloon_color);

 while(1)
 {
  chance_end=0;//initialize chance*/
  while (!chance_end)
  {
   //while not chance end//
   //until a key is hited ,move the ballon up//
   while (!kbhit())
   {
    delay(10);//wait 10 miliseconds//
    baloon_color=1;//to irrage baloon with screen color
    draw_baloon(baloon_x,baloon_y,baloon_color);
    //move up and draw in new place
    baloon_y--;
    baloon_color=15;
    draw_baloon(baloon_x,baloon_y,baloon_color);

   }
   ii.h.ah=0;
   int86(22,&ii,&oo);
   if(oo.h.al==0)
   {
    //if the pressed key was a function key
    switch(oo.h.ah)
    {
     case 72: //up
     //irrage shaft from old plece
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //draw shaft in new place
     shaft_y=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;
     case 80: //down
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_y+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;

    }

   }
  else
  {
   switch(oo.h.al)
   {
    case 13://enter key was pressed to hit baloon
    /*move both baloon and shaft until the baloon is being hitted, or the shaft goes outside of boundary*/
    do{
     delay(10);
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     baloon_y--;
     baloon_color=15;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_x+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //check if baloon is hitted
     if(shaft_x>baloon_x-10&& shaft_x<baloon_x+10&& shaft_y>baloon_y-10 && shaft_y<baloon_y+10)
     {
     for(i=20;i<=2000;i+=20)
     {
      sound(250);
      delay(8);
     }
     nosound();
      baloon_color=1;
      draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      success++;
      score+=10;
      point=score;
      show_score(chance,success,score,level,1);
      chance_end=1;
      //set position of the shaft and baloon for next chance
      shaft_x=185;
      shaft_y=200;//get a random x coordinate
      //of baloon whether it must be
      //between 300 and 600
      if (point>=30)
      {
      level++;
      level_2();
      }
      do{
       baloon_x=rand()%600;

      }
      while(baloon_x<300);
      baloon_y=400;//y is fixed

     }
     else
     //check if baloon or shaft over the boundaries
     if (shaft_x>640|| baloon_y<0)
     {
     //irrage both baloon and shaft
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      show_score(chance,success,score,level,0);
      chance_end=1;
      shaft_x=185;
      shaft_y=200;
      do{
       baloon_x=rand()%600;

      }while(baloon_x<300);
      baloon_y=400;
     }
     }
     while(!chance_end);
     break;
     case 27:
     closegraph();
     exit(1);
    }
   }
  }
  }
}

}
nosound();
getch();
closegraph();

}

void level_3()
{int chance=0,success=0,score=0,chance_end=0,level=3;
 int shaft_x=185,shaft_y=200,shaft_color=4;
 int baloon_x=400,baloon_y=400,baloon_color=15;
int gd=DETECT,gm;
union REGS ii,oo;
char ch;
int e;
initgraph(&gd, &gm,"C:\\TC\\BGI");
setcolor(1);
for (i=20;i<=2000;i+=20)
{
sound(i);
delay(20);

}
outtextxy(100,100,"Welcome to level THREE");
outtextxy(100,200,"Press '3' to enter level THREE");
if(getch()=='3')
{
nosound();

 initgraph(&gd,&gm,"C:\\TC\\BGI");
 draw_screen();


 /*show initial score*/
 show_score (chance,success,score,level,0);
 draw_shaft(shaft_x,shaft_y,shaft_color);
 draw_baloon(baloon_x,baloon_y,baloon_color);

 while(1)
 {
  chance_end=0;//initialize chance*/
  while (!chance_end)
  {
   //while not chance end//
   //until a key is hited ,move the ballon up//
   while (!kbhit())
   {
    delay(8);//wait 20 miliseconds//
    baloon_color=1;//to irrage baloon with screen color
    draw_baloon(baloon_x,baloon_y,baloon_color);
    //move up and draw in new place
    baloon_y--;
    baloon_color=15;
    draw_baloon(baloon_x,baloon_y,baloon_color);

   }
   ii.h.ah=0;
   int86(22,&ii,&oo);
   if(oo.h.al==0)
   {
    //if the pressed key was a function key
    switch(oo.h.ah)
    {
     case 72: //up
     //irrage shaft from old plece
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //draw shaft in new place
     shaft_y=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;
     case 80: //down
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_y+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;

    }

   }
  else
  {
   switch(oo.h.al)
   {
    case 13://enter key was pressed to hit baloon
    /*move both baloon and shaft until the baloon is being hitted, or the shaft goes outside of boundary*/
    do{
     delay(10);
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     baloon_y--;
     baloon_color=15;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_x+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //check if baloon is hitted
     if(shaft_x>baloon_x-10&& shaft_x<baloon_x+10&& shaft_y>baloon_y-10 && shaft_y<baloon_y+10)
     {
     for(i=20;i<=2000;i+=20)
     {
      sound(250);
      delay(5);
     }
     nosound();
      baloon_color=1;
      draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      success++;
      score+=10;

e=chance;
      point=score;
      show_score(chance,success,score,level,1);
      chance_end=1;
      //set position of the shaft and baloon for next chance
      shaft_x=185;
      shaft_y=200;//get a random x coordinate
      //of baloon whether it must be
      //between 300 and 600
      if (point>=70)
      {
      over_1();
      }
if(e>=15)
finish();
      do{
       baloon_x=rand()%600;

      }
      while(baloon_x<300);
      baloon_y=400;//y is fixed

     }
     else
     //check if baloon or shaft over the boundaries
     if (shaft_x>640|| baloon_y<0)
     {
     //irrage both baloon and shaft
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      show_score(chance,success,score,level,0);
      chance_end=1;
      shaft_x=185;
      shaft_y=200;
      do{
       baloon_x=rand()%600;

      }while(baloon_x<300);
      baloon_y=400;
     }
     }
     while(!chance_end);
     break;
     case 27:
     closegraph();
     exit(1);
    }
   }
  }
  }
}
else
{
outtextxy(100,300,"Wrong Key ! Please Enter The Right Key");
if(getch()=='3')
{
nosound();

 initgraph(&gd,&gm,"C:\\TC\\BGI");
 draw_screen();

 /*show initial score*/
 show_score (chance,success,score,level,0);
 draw_shaft(shaft_x,shaft_y,shaft_color);
 draw_baloon(baloon_x,baloon_y,baloon_color);

 while(1)
 {
  chance_end=0;//initialize chance*/
  while (!chance_end)
  {
   //while not chance end//
   //until a key is hited ,move the ballon up//
   while (!kbhit())
   {
    delay(8);//wait 10 miliseconds//
    baloon_color=1;//to irrage baloon with screen color
    draw_baloon(baloon_x,baloon_y,baloon_color);
    //move up and draw in new place
    baloon_y--;
    baloon_color=15;
    draw_baloon(baloon_x,baloon_y,baloon_color);

   }
   ii.h.ah=0;
   int86(22,&ii,&oo);
   if(oo.h.al==0)
   {
    //if the pressed key was a function key
    switch(oo.h.ah)
    {
     case 72: //up
     //irrage shaft from old plece
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //draw shaft in new place
     shaft_y=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;
     case 80: //down
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_y+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     break;

    }

   }
  else
  {
   switch(oo.h.al)
   {
    case 13://enter key was pressed to hit baloon
    /*move both baloon and shaft until the baloon is being hitted, or the shaft goes outside of boundary*/
    do{
     delay(8);
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     baloon_y--;
     baloon_color=15;
     draw_baloon(baloon_x,baloon_y,baloon_color);
     shaft_color=1;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     shaft_x+=5;
     shaft_color=4;
     draw_shaft(shaft_x,shaft_y,shaft_color);
     //check if baloon is hitted
     if(shaft_x>baloon_x-10&& shaft_x<baloon_x+10&& shaft_y>baloon_y-10 && shaft_y<baloon_y+10)
     {
     for(i=20;i<=2000;i+=20)
     {
      sound(250);
      delay(5);
     }
     nosound();
      baloon_color=1;
      draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      success++;
      score+=10;

   e=chance;
      point=score;
      show_score(chance,success,score,level,1);
      chance_end=1;
      //set position of the shaft and baloon for next chance
      shaft_x=185;
      shaft_y=200;//get a random x coordinate
      //of baloon whether it must be
      //between 300 and 600
      if (point>=70)
      {
      over_1();
      }
if(e>=15)
finish();
      do{
       baloon_x=rand()%600;

      }
      while(baloon_x<300);
      baloon_y=400;//y is fixed

     }
     else
     //check if baloon or shaft over the boundaries
     if (shaft_x>640|| baloon_y<0)
     {
     //irrage both baloon and shaft
     baloon_color=1;
     draw_baloon(baloon_x,baloon_y,baloon_color);
      shaft_color=1;
      draw_shaft(shaft_x,shaft_y,shaft_color);
      show_score(chance,success,score,level,3);
      chance++;
      show_score(chance,success,score,level,0);
      chance_end=1;
      shaft_x=185;
      shaft_y=200;
      do{
       baloon_x=rand()%600;

      }while(baloon_x<300);
      baloon_y=400;
     }
     }
     while(!chance_end);
     break;
     case 27:
     closegraph();
     exit(1);
    }
   }
  }
  }
}

}
nosound();
getch();
closegraph();


}
void finish()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setcolor(1);
while(i<2000)
{
 sound(i);
 delay(250);
 i+=10;
}
outtextxy(200,150,"You Lose");
getch();
nosound();
closegraph();
}
void over_1()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setcolor(1);
while(i<2000)
{
 sound(i);
 delay(250);
 i+=10;
}
outtextxy(200,150,"Congrats.You Win");
getch();
nosound();
closegraph();
}