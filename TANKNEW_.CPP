/* MINITANK V01 */

#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
int getscan();
void front();
void loading();
void game();
void gameover();
int left(int,int);
int right(int,int);
int up(int,int);
int down(int,int);
main()
{
 int gdriver=DETECT,gmode,errorcode,choice,select;
 int i=0,j=400,k=0,key,val;
 initgraph(&gdriver,&gdriver,"");
 cleardevice();
 front();
 getch();
 cleardevice();
while(1)
      {
       setcolor(9);
       setbkcolor(4);
       settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
       outtextxy(160,120,"MINI TANK");
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
       outtextxy(270,200,"(S)TART");
       outtextxy(270,235,"(O)PTION");
       outtextxy(270,270,"(I)NSTUCTIONS");
       outtextxy(270,305,"E(X)IT");
       randomize();
       k=0;
while(i<165)
   {
    circle(320,240,j);
    i++;
    j--;
    val=random(5000);
    sound(val);
    delay(10);
    nosound();
   }
j=400;
while(k<165)
  {
   circle(320,240,j);
   j--;
   k++;
  }
key=getch();
if(key=='i')
 {
  cleardevice();
  setcolor(4);
  setbkcolor(4);
  setfillstyle(1,9);
  bar(100, 100, 540, 380);
  outtextxy(260,130,"INSTRUCTIONS");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
  outtextxy(110,350,"<-(B)ack");
instruction:
key=getch();
if(key=='b')
  {
   cleardevice();
   k=0;
   continue;
  }
else
  {
  goto instruction;
  }
 }
if(key=='o')
   {
    cleardevice();
    setcolor(4);
    setbkcolor(4);
    setfillstyle(1,9);
    bar(100, 100, 540, 380);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    outtextxy(290,130,"KEYS");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(180,180,"Up");
    outtextxy(180,205,"Down");
    outtextxy(180,230,"Right");
    outtextxy(180,255,"Left");
    outtextxy(180,280,"Fire up");
    outtextxy(180,305,"Fire down");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    outtextxy(275,180,"-");
    outtextxy(275,205,"-");
    outtextxy(275,230,"-");
    outtextxy(275,255,"-");
    outtextxy(275,280,"-");
    outtextxy(275,305,"-");
    outtextxy(330,180,"up arrow key");
    outtextxy(330,205,"down arrow key");
    outtextxy(330,230,"right arrow key");
    outtextxy(330,255,"left arrow key");
    outtextxy(330,280,"A");
    outtextxy(330,305,"S");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(110,350,"<-(B)ack");
option:
    key=getch();
if(key=='b')
    {
     cleardevice();
     k=0;
     continue;
    }
else
   {
   goto option;
   }
}
if(key=='x'||key=='X')
    {
     exit(0);
    }
if(key=='s'||key=='S')
    {
     cleardevice();
     setbkcolor(0);
     loading();
     game();
    }
      }
}

void game()
{
 cleardevice();
 int opt,c=200,r=200,i=251,o=10,p=50,k=0,l,y=0,guns=15,d=0,f,q=1;
 int val=5;
 int m,n;
 char val1[3],val2[3];
 int num1=0,num2=1;
 delay(3000);
 setbkcolor(0);
 randomize();
 setcolor(15);
  settextstyle(SMALL_FONT,HORIZ_DIR,5);
  itoa(num1,val1,10);
  outtextxy(0,0,"POINTS =");
  outtextxy(70,0,val1);
  setcolor(15);
  itoa(num2,val2,10);
  outtextxy(0,13,"ALIEN =");
  outtextxy(70,13,val2);
while(1)
 {
  alien:
if(k==670)
 {
  k=0;
  o=1;
  p=random(405)+45;
  val=random(10)+5;

  settextstyle(SMALL_FONT,HORIZ_DIR,5);
  setcolor(0);
  itoa(num2,val2,10);
  outtextxy(70,13,val2);
  num2++;
  setcolor(15);
  itoa(num2,val2,10);
  outtextxy(0,13,"ALIEN =");
  outtextxy(70,13,val2);

 }
settextstyle(1,HORIZ_DIR,1);
while(k<670)
  {
   setcolor(q);
   outtextxy(o,p,"<*>");
   delay(val);
   setcolor(0);
   outtextxy(o,p,"<*>");
   setcolor(3);
   o++;
   k++;
if(y==1)
  {
   goto gunss;
  }
if(y==2)
  {
   y=0;
   goto gunendss;
  }
if(i<250)
  {
   goto gun;
  }
if(i==250)
  {
   goto gunend;
  }
if(o==c&&r<=(p+6)&&r>=(p-6))                  /* GAME OVER */
  {
   gameover();
  }
setcolor(3);

if(kbhit())
   {
 opt=getscan();

 if(opt==75)                         /* Left */
    {
     c=left(c,r);
    if(o==c&&r<=(p+6)&&r>=(p-6))              /* GAME OVER */
      {
       gameover();
      }
    }

 if(opt==77)                          /*  RIGHT */
    {
     c=right(c,r);
     if(o==c&&r<=(p+6)&&r>=(p-6))              /* GAME OVER */
      {
       gameover();
      }
    }

 if(opt==80)                          /* DOWN */
    {
     r=down(c,r);
    if(o==c&&r<=(p+6)&&r>=(p-6))              /* GAME OVER */
     {
      gameover();
     }
    }

 if(opt==72)                         /* UP */
    {
     r=up(c,r);
     if(o==c&&r<=(p+6)&&r>=(p-6))             /* GAME OVER */
      {
       gameover();
      }
    }

 if(opt==28)                         /* CHEATS */
    {
     printf("\n\n\nCheats =");
     scanf("%d",&f);
     if(f==2129)
      {
       printf("gun=+100");
       printf("\nCheater!");
       delay(4000);
       guns=guns+100;
      }
    }

 if(opt==25)                         /* PAUSE */
   {
    opt=getscan();
    if(opt==25)
     {
     }
   }

 if(opt==1)                         /* EXIT */
  {
   exit(1);
  }

if(opt==31)                         /* Down fire */
{
	sound(1000);
	delay(5);
	nosound();
 y=1;
 i=0;
 m=c+16;
 n=r+13;
while(i<250&&guns>0)
  {
   gunss:
   outtextxy(m,n,"|");
   setcolor(0);
   outtextxy(m,n,"|");
   n++;
   setcolor(3);
   outtextxy(m,n,"|");
   if(kbhit())
   {
    opt=getscan();
    if(opt==72)
    {
     r=up(c,r);
    }
    if(opt==80)
    {
     r=down(c,r);
    }
    if(opt==75)
    {
     c=left(c,r);
    }
    if(opt==77)
    {
     c=right(c,r);
    }
   }
if(i==249)
{
 setcolor(0);
 outtextxy(m,n,"|");
 y=2;
}
i++;
if(m>=(o-7)&&m<=(o+26)&&n==p)
{
 q++;
 setcolor(q);

 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 setcolor(0);
 itoa(num1,val1,10);
 outtextxy(70,0,val1);
 num1++;
 setcolor(15);
 itoa(num1,val1,10);
 outtextxy(0,0,"POINTS =");
 outtextxy(70,0,val1);

}
goto alien;
  }
gunendss:
d++;
if(d==14)
{
 while(1)
 {
  opt=getscan();
  if(opt==28)
  {
   break;
  }
 }
 cleardevice();
 return;
}
guns--;
m=c-16;
i=251;
n=r-13;
}

if(opt==30)                       /* Up fire */
{
	sound(1000);
	delay(5);
	nosound();
 i=0;
 m=c+16;
 n=r-13;
while(i<250&&guns>0)
  {
   gun:
   outtextxy(m,n,"|");
   setcolor(0);
   outtextxy(m,n,"|");
   n--;
   setcolor(3);
   outtextxy(m,n,"|");
   if(kbhit())
   {
    opt=getscan();
    if(opt==72)
    {
     r=up(c,r);
    }
    if(opt==80)
    {
     r=down(c,r);
    }
    if(opt==75)
    {
     c=left(c,r);
    }
    if(opt==77)
    {
     c=right(c,r);
    }
   }
if(i==249)
{
 setcolor(0);
 outtextxy(m,n,"|");
}
i++;
if(m>=(o-7)&&m<=(o+26)&&n==p)
{
 q++;
 setcolor(q);

 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 setcolor(0);
 itoa(num1,val1,10);
 outtextxy(70,0,val1);
 num1++;
 setcolor(15);
 itoa(num1,val1,10);
 outtextxy(0,0,"POINTS =");
 outtextxy(70,0,val1);
}
goto alien;
  }
gunend:
d++;
if(d==14)
{
 while(1)
 {
  opt=getscan();
  if(opt==28)
  {
   break;
  }
 }
 cleardevice();
 return;
}
guns--;
m=c-16;
i=251;
n=r+13;
}//upfire end

}//kbhit end

}//inner while end

}//outter while end

}//function end

int getscan()
{
union REGS i,o;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}
 int left(int c,int r)
   {
     outtextxy(c,r,"[-|-]");
     setcolor(0);
     outtextxy(c,r,"[-|-]");
     c=c-3;
     setcolor(3);
     outtextxy(c,r,"[-|-]");
     return(c);
   }
 int right(int c,int r)
   {
     outtextxy(c,r,"[-|-]");
     setcolor(0);
     outtextxy(c,r,"[-|-]");
     c=c+3;
     setcolor(3);
     outtextxy(c,r,"[-|-]");
     return(c);
   }
 int up(int c,int r)
   {
     outtextxy(c,r,"[-|-]");
     setcolor(0);
     outtextxy(c,r,"[-|-]");
     r=r-3;
     setcolor(3);
     outtextxy(c,r,"[-|-]");
     return(r);
   }
 int down(int c,int r)
   {
     outtextxy(c,r,"[-|-]");
     setcolor(0);
     outtextxy(c,r,"[-|-]");
     r=r+3;
     setcolor(3);
     outtextxy(c,r,"[-|-]");
     return(r);
   }
void gameover()
{
       cleardevice();
       setbkcolor(15);
       setcolor(4);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
       outtextxy(110,200,"GAME OVER");
      getch();
       main();
}

void front()                 /* we make your dream text */
{
 int i=0,j=2,val,k=0;
 setcolor(7);
 setbkcolor(4);
   while(i<=5)
    {
     cleardevice();
     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,j);
     outtextxy(282,200,"y");
     outtextxy(269,200," ");
     outtextxy(305,200,"o");
     outtextxy(232,200,"e");
     outtextxy(334,200,"u");
     outtextxy(211,200,"k");
     outtextxy(363,200,"r");
     outtextxy(181,200,"a");
     outtextxy(131,200,"m");
     outtextxy(407,200,"D");
     outtextxy(82,200,"e");
     outtextxy(440,200,"r");
     outtextxy(39,200,"W");
     outtextxy(459,200,"e");
     outtextxy(487,200,"a");
     outtextxy(518,200,"m");
     outtextxy(568,200,"s");
     delay(1000);
     j++;
     i++;
    }
j--;
cleardevice();
setcolor(7);
setbkcolor(15);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,j);
outtextxy(282,200,"y");
outtextxy(269,200," ");
outtextxy(305,200,"o");
outtextxy(232,200,"e");
outtextxy(334,200,"u");
outtextxy(211,200,"k");
outtextxy(363,200,"r");
outtextxy(181,200,"a");
outtextxy(131,200,"m");
outtextxy(407,200,"D");
outtextxy(82,200,"e");
outtextxy(440,200,"r");
outtextxy(39,200,"W");
outtextxy(459,200,"e");
outtextxy(487,200,"a");
outtextxy(518,200,"m");
outtextxy(568,200,"s");
}


void loading()         /* loading */
{
 cleardevice();
 setbkcolor(0);
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 int i=0,j=5,k=15;
    while(i<630)
    {
     setfillstyle(1,k);
     bar(j,454,5,460);
     j++;
     i++;
    if(i==50)
     {
      setcolor(15);
      outtextxy(260,430,"LOADING BACKGROUND...");
     }
    if(i==200)
     {
      k=7;
      setcolor(0);
      outtextxy(260,430,"LOADING BACKGROUND...");
      setcolor(15);
      outtextxy(260,430,"LOADING SETTINGS...");
     }
    if(i==400)
     {
      k=8;
      setcolor(0);
      outtextxy(260,430,"LOADING SETTINGS...");
      setcolor(15);
      outtextxy(260,430,"LOADING GRAPHICS...");
     }
    delay(1);
    }
      setcolor(0);
      outtextxy(260,430,"LOADING GRAPHICS...");
      setcolor(15);
while(!kbhit())
   {
    setcolor(15);
    outtextxy(270,430,"PRESS ANY KEY!");
    delay(1000);
    setcolor(0);
    outtextxy(270,430,"PRESS ANY KEY!");
    delay(1000);
   }
getch();
return;
}