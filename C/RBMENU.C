/* ======================================================================= */
/*                     Menu System for Rail Baron                          */
/*  Rev. 3.1 changes on 7/1/93 added closegraph() to fix problem           */
/* ======================================================================= */

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
extern char new_city[100];
extern int ECODE;

/*  ---------------------------------------------------------------------- */
/*                     Initialize Graphics System                          */
/*  ---------------------------------------------------------------------- */
/*  This function initializes the graphics for VGA.                        */
/*  Present Modes:
		VGA Driver = 9
		CGA Driver = 1
		Background color is "4" : RED
		Foreground color is "14" : YELLOW
*/
	void init_graphics()
	{
	int graph_drv = 9;
	int graph_mode = 1;
	initgraph(&graph_drv, &graph_mode,"");
	setbkcolor(4);
	setcolor(14);
	}

/*  ---------------------------------------------------------------------  */
/*		       Display Title Screen                                */
/*  ---------------------------------------------------------------------  */

	void title_screen()
	{
	char *title = "Welcome to Rail Baron";
	char *title1 = "Game Play Enhancement Program";
	char *title2 = "By Mr. Man Software";
	char *title3 = "Mr. Mann Software is a wholly owned subsidiary of the Mr. Mann Corporation";
	int large = 3;
	int medium = 2;
	int small = 1;
	cleardevice();
	settextstyle(0,0,large);
	outtextxy(65,15,title);
	settextstyle(0,0,medium);
	outtextxy(80,80,title1);
	settextstyle(0,0,medium);
	outtextxy(150,140,title2);
	settextstyle(0,0,small);
	outtextxy(35,330,title3);
	sleep(3);
	}

/*  ---------------------------------------------------------------------  */
/*		       Display Credits Screen                                */
/*  ---------------------------------------------------------------------  */

	void credits_screen()
	{
	char *title1= "Author:";
	char *title2= "John Davidson";
	char *title3 = "Inspiration:";
	char *title4 = "`Diamond' Dave McCoy";
	char *title5 = "Mike Boutiette - Mr. Mann Himself !!";
	char *title6 = "Dick Boysen - The Dick-Miester";
	char *title7 = "Ver. 3.1 Copyright (C) 1993 by John Davidson, All Rights Reserved";
	int medium = 2;
	int small = 1;
	cleardevice();
	settextstyle(0,0,medium);
	outtextxy(260,40,title1);
	outtextxy(220,65,title2);
	outtextxy(230,130,title3);
	outtextxy(180,170,title4);
	outtextxy(80,200,title6);
	outtextxy(40,230,title5);
	settextstyle(0,0,small);
	outtextxy(60,330,title7);
	sleep(3);
	}


/*  ---------------------------------------------------------------------  */
/*		       Get New Destination Screen                          */
/*  ---------------------------------------------------------------------  */

	void destin_screen()
	{
	char ss[2];
	char city[100];
	int x;
	closegraph();
	restorecrtmode();
	textmode(3);                          /* 80 column color text mode */
	textbackground(5);
	textcolor(14);
	for (x=0; x!=25; x++) insline();         /* write background color */
	gotoxy(25,1);
	cprintf("      NEW DESTINATION SCREEN");
        strcpy(city,get_destin());
	gotoxy(5,10);
	if ( ECODE == 0 )
	{
	textcolor(10+128);
	cprintf("%s",city);
	sound(1000);
	delay(1000);
	nosound();
	}
	textcolor(14);
	gotoxy(25,20);
	cprintf("Press ANY KEY to return to MAIN Menu");
	ss[1] = getch();
	}
