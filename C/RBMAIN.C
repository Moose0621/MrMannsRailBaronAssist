
/*            Rail Baron Utility Program ------ Version 3.1                */
/*            Copyright (C) 1993 by John Davidson                          */
/*            Rev. 3.1 - 7/1/93 - added closegraph() function to fix bug   */
/*            Main Control Functions, Menu Screen                          */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <graphics.h>
#define DEBUG 0
char d_city[128];          /* initialize destination city var.       */
char o_city[128];          /* initialize origin city var.            */
#include "array.h"         /* all destination values are stored hear */
			   /* cities parsing array stored hear       */


/*                       FUNCTIONS                                   */
void get_ocity (char *s);  /* ORIGIN CITY                            */
void get_dcity (char *s);  /* DESTINATION CITY                       */
float payoff_calc();
float search();
void dice_screen();

/*                       GLOBAL VARIABLES                            */
int doubles = 0;
int o_index = -1;          /* INDEX INTO THE CITIES ARRAY            */
int d_index = -1;          /* INDEX INTO THE CITIES ARRAY            */
int ECODE = 0;             /* ERROR CODE VARIABLE                    */

main ()

{
	int roll,x;
	int loop = 999;
	int match;
	float pay,p;
	int select = 0;
	char *title1 = "Main Menu";
	char *title2 = "Press 1 for a Dice Roll";
	char *title3 = "Press 2 for a New Destination";
	char *title4 = "Press 3 for a Payoff";
	char *title5 = "Press 9 to Exit";
	int large = 3;
	int medium = 2;


/*  ---------------------------------------------------------------------  */
/*		       Rail Baron Start-Up Screens                         */
/*  ---------------------------------------------------------------------  */

	init_graphics();             /* initialize graphics hardware */
	title_screen();              /* Title Screen                 */
	credits_screen();            /* Credits Screen               */

/*  ---------------------------------------------------------------------  */
/*		   Display Main Menu Control Screen                        */
/*  ---------------------------------------------------------------------  */


	/* Display Selections */

	do {
		ECODE = 0;	                       /* reset error flag */
		cleardevice();
        	settextstyle(0,0,large);
		outtextxy(210,15,title1);
		settextstyle(0,0,medium);
		outtextxy(120,100,title2);
		outtextxy(120,160,title3);
		outtextxy(120,220,title4);
		outtextxy(120,280,title5);

/* ---------------------------------------------------------------------- */
/*                          Get Input from USER                           */
/* ---------------------------------------------------------------------- */

		select = getch();
		switch (select)
			{
			case 49:
				dice_screen();
				break;

			case 50:
				destin_screen();
				init_graphics();
				break;

			case 51:
				payoff_screen(); /* text mode screen */
				init_graphics();
				break;

			case 57:
				loop = 0;
				init_graphics();
				break;

			default:
				break;
			}
	} while ( loop == 999 );
	closegraph();
}

/* ======================================================================= */
/* ======================================================================= */
/* ======================================================================= */
/*                       Function Area                                     */
/* ======================================================================= */


/* ----------------------------------------------------------------------- */
/*                        Generate a dice roll                             */
/* ----------------------------------------------------------------------- */
/* This function generates a dice roll using the ramdomize
   function.  For loops were used to seed the randomizer with
   different time values as best as possible.

   Uses & loads Global variable "dice_val"
   Returns the value for doubles                                  */

	dice_roll()
	{
	int full_dice_roll = 0;
	int value1, value2 = 0;
	value1 = roll_one();
	#if DEBUG
	printf("\n Dice Number 1 = %d",value1);
	#endif
	value2 = roll_one(4000);
	#if DEBUG
	printf("\n Dice Number 2 = %d",value2);
	#endif
	if (value1 == value2)
	   {
	   doubles = 1;                   /* set doubles ON */
	   }
	else
	   {
	   doubles = 0;                   /* set doubles OFF */
	   }
	full_dice_roll = value1 + value2;
	return (full_dice_roll);
	}


/* ----------------------------------------------------------------------- */
/*                     DESTINATION PAYOFF FUNCTION                         */
/* ----------------------------------------------------------------------- */

	float payoff_calc ()
	{
	char tmpstr[256];
	int x;
	float payment;

/*  ---------------------------------------------------------------------- */
/*  Origin City Parser for Index into the payoff array                     */
/*  This code returns the index value for the entered city                 */
/*  ---------------------------------------------------------------------- */

	/*  ====== check city_a array for match ============== */
	for (o_index=0; citys_a[o_index] != NULL ; o_index++)
		{
		if (!stricmp(o_city, citys_a[o_index]) != 0) break;
		}
	if (citys_a[o_index] == NULL)        /* if NULL, city is not found */
		{
		ERROR(ECODE = 15);
		}
	else
		{
		#if DEBUG
		printf("\n The origin city index #  = %d", o_index);
		#endif
		}

/*  ---------------------------------------------------------------------- */
/*  Destination City Parser for Index into the payoff array                */
/*  This code returns the index value for the entered city                 */
/*  ---------------------------------------------------------------------- */

	/*  ====== check city_a array for match ============== */
	for (d_index=0; citys_a[d_index] != NULL ; d_index++)
		{
		if (!stricmp(d_city, citys_a[d_index]) != 0) break;
		}
	if (citys_a[d_index] == NULL)        /* if NULL, city is not found */
		{
		ERROR(ECODE = 15);
		}
		else
		{
		#if DEBUG
		printf("\n\n The dest. city index #  = %d", d_index);
		#endif
		}

	/* -- Check if Origin & Destination Cities need swapping -- */

	if ( o_index < d_index )
	   {
	   payment = search();
	   #if DEBUG
	   printf("\npayment=$%gK \no_index=%d",payment,o_index);
	   #endif
	   }
	   else
		{
		strcpy(tmpstr, o_city);
		strcpy(o_city, d_city);
		strcpy(d_city, tmpstr);
		#if DEBUG
		printf("\n\n [SWAP ON] OCITY = %s  DCITY = %s",o_city,d_city);
		#endif
		x = o_index;
		o_index = d_index;
		d_index = x;
		payment = search();
		}
	return(payment);
	}


/*  Search Alogrithm through the payoff arrays                   */
/*  This function computes the payoff actual payoff              */

	float search()
	{
	float p=0;
	if ( stricmp(o_city,"ALB") == 0) {
		p = ALB[d_index]; }
	if ( stricmp(o_city,"BAL") == 0) {
		p = BAL[d_index]; }
	if ( stricmp(o_city,"BOS") == 0) {
		p = BOS[d_index]; }
	if ( stricmp(o_city,"BUF") == 0) {
		p = BUF[d_index]; }
	if ( stricmp(o_city,"NYC") == 0) {
		p = NYC[d_index]; }
	if ( stricmp(o_city,"PHI") == 0) {
		p = PHI[d_index]; }
	if ( stricmp(o_city,"PIT") == 0) {
		p = PIT[d_index]; }
	if ( stricmp(o_city,"PME") == 0) {
		p = PME[d_index]; }
	if ( stricmp(o_city,"WAS") == 0) {
		p = WAS[d_index]; }
	if ( stricmp(o_city,"ATL") == 0) {
		p = ATL[d_index-9]; }
	if ( stricmp(o_city,"CHL") == 0) {
		p = CHL[d_index-9]; }
	if ( stricmp(o_city,"CHR") == 0) {
		p = CHR[d_index-9]; }
	if ( stricmp(o_city,"CHT") == 0) {
		p = CHT[d_index-9]; }
	if ( stricmp(o_city,"JAC") == 0) {
		p = JAC[d_index-9]; }
	if ( stricmp(o_city,"KNO") == 0) {
		p = KNO[d_index-9]; }
	if ( stricmp(o_city,"MIA") == 0) {
		p = MIA[d_index-9]; }
	if ( stricmp(o_city,"MOB") == 0) {
		p = MOB[d_index-9]; }
	if ( stricmp(o_city,"NOR") == 0) {
		p = NOR[d_index-9]; }
	if ( stricmp(o_city,"RIC") == 0) {
		p = RIC[d_index-9]; }
	if ( stricmp(o_city,"TAM") == 0) {
		p = TAM[d_index-9]; }
	if ( stricmp(o_city,"CHI") == 0) {
		p = CHI[d_index-20]; }
	if ( stricmp(o_city,"CIN") == 0) {
		p = CIN[d_index-20]; }
	if ( stricmp(o_city,"CLE") == 0) {
		p = CLE[d_index-20]; }
	if ( stricmp(o_city,"COL") == 0) {
		p = COL[d_index-20]; }
	if ( stricmp(o_city,"DET") == 0) {
		p = DET[d_index-20]; }
	if ( stricmp(o_city,"IND") == 0) {
		p = IND[d_index-20]; }
	if ( stricmp(o_city,"MIL") == 0) {
		p = MIL[d_index-20]; }
	if ( stricmp(o_city,"SLO") == 0) {
		p = SLO[d_index-20]; }
	if ( stricmp(o_city,"BIR") == 0) {
		p = BIR[d_index-28]; }
	if ( stricmp(o_city,"DAL") == 0) {
		p = DAL[d_index-28]; }
	if ( stricmp(o_city,"FOR") == 0) {
		p = FOR[d_index-28]; }
	if ( stricmp(o_city,"HOU") == 0) {
		p = HOU[d_index-28]; }
	if ( stricmp(o_city,"LIT") == 0) {
		p = LIT[d_index-28]; }
	if ( stricmp(o_city,"LOU") == 0) {
		p = LOU[d_index-28]; }
	if ( stricmp(o_city,"MEM") == 0) {
		p = MEM[d_index-28]; }
	if ( stricmp(o_city,"NAS") == 0) {
		p = NAS[d_index-28]; }
	if ( stricmp(o_city,"NOL") == 0) {
		p = NOL[d_index-28]; }
	if ( stricmp(o_city,"SAN") == 0) {
		p = SAN[d_index-28]; }
	if ( stricmp(o_city,"SHR") == 0) {
		p = SHR[d_index-28]; }
	if ( stricmp(o_city,"DEN") == 0) {
		p = DEN[d_index-39]; }
	if ( stricmp(o_city,"DES") == 0) {
		p = DES[d_index-39]; }
	if ( stricmp(o_city,"FAR") == 0) {
		p = FAR[d_index-39]; }
	if ( stricmp(o_city,"KAN") == 0) {
		p = KAN[d_index-39]; }
	if ( stricmp(o_city,"MIN") == 0) {
		p = MIN[d_index-39]; }
	if ( stricmp(o_city,"OKL") == 0) {
		p = OKL[d_index-39]; }
	if ( stricmp(o_city,"OMA") == 0) {
		p = OMA[d_index-39]; }
	if ( stricmp(o_city,"PUE") == 0) {
		p = PUE[d_index-39]; }
	if ( stricmp(o_city,"SPA") == 0) {
		p = SPA[d_index-39]; }
	if ( stricmp(o_city,"BIL") == 0) {
		p = BIL[d_index-48]; }
	if ( stricmp(o_city,"BUT") == 0) {
		p = BUT[d_index-48]; }
	if ( stricmp(o_city,"CAS") == 0) {
		p = CAS[d_index-48]; }
	if ( stricmp(o_city,"POC") == 0) {
		p = POC[d_index-48]; }
	if ( stricmp(o_city,"POR") == 0) {
		p = POR[d_index-48]; }
	if ( stricmp(o_city,"RAP") == 0) {
		p = RAP[d_index-48]; }
	if ( stricmp(o_city,"SAL") == 0) {
		p = SAL[d_index-48]; }
	if ( stricmp(o_city,"SEA") == 0) {
		p = SEA[d_index-48]; }
	if ( stricmp(o_city,"SPO") == 0) {
		p = SPO[d_index-48]; }
	if ( stricmp(o_city,"ELP") == 0) {
		p = ELP[d_index-57]; }
	if ( stricmp(o_city,"LAS") == 0) {
		p = LAS[d_index-57]; }
	if ( stricmp(o_city,"LOS") == 0) {
		p = LOS[d_index-57]; }
	if ( stricmp(o_city,"OAK") == 0) {
		p = OAK[d_index-57]; }
	if ( stricmp(o_city,"PHO") == 0) {
		p = PHO[d_index-57]; }
	if ( stricmp(o_city,"REN") == 0) {
		p = REN[d_index-57]; }
	if ( stricmp(o_city,"SAC") == 0) {
		p = SAC[d_index-57]; }
	if ( stricmp(o_city,"SDE") == 0) {
		p = SDE[d_index-57]; }
	if ( stricmp(o_city,"SFR") == 0) {
		p = SFR[d_index-57]; }
	if ( stricmp(o_city,"TUC") == 0) {
		p = TUC[d_index-57]; }
	if ( stricmp(o_city,NULL) == 0) {
		ERROR(ECODE = 10); }
	return (p);
	}


	/*      Error Code Handler   */

	int ERROR()
	{
	switch  (ECODE) {
		case 10:
			gotoxy(5,24);
			textcolor(10+128);
			cprintf("ERROR...... Cannot compute payoff?");
			break;
		case 15:
			textcolor(10+128);
			gotoxy(30,24);
			cprintf("ERROR...... City not found !!!!!");
			break;
		default:
			break;
			}
	}


/*  ---------------------------------------------------------------------  */
/*		       Destination Payoff Screen                           */
/*  ---------------------------------------------------------------------  */

	payoff_screen()
	{
	int ss[1];
	int x;
	float p = 10000;
	closegraph();
	restorecrtmode();
	textmode(3);                          /* 80 column color text mode */
	textbackground(5);
	textcolor(14);
	for (x=0; x!=25; x++) insline();         /* write background color */
	gotoxy(25,1);
	cprintf("PAYOFF CALCULATION SCREEN");
	gotoxy(5,3);
	cprintf("Enter the first three letters of each city's name. Then press ENTER");
	gotoxy(10,5);
	cprintf("Exceptions Are: ");
	gotoxy(10,6);
	cprintf("PME - Portland Maine       POR - Portland Oregon");
	gotoxy(10,7);
	cprintf("CHL - Charleston           SPA - Saint Paul");
	gotoxy(10,8);
	cprintf("CHT - Chattanooga          SDE - San Diego");
	gotoxy(10,9);
	cprintf("CHR - Charlotte            SLO - Saint Louis");
	gotoxy(10,10);
	cprintf("NYC - New York City        SAN - San Antonio");
	gotoxy(10,11);
	cprintf("NOL - New Orleans          SFR - San Francisco");
	gotoxy(10,13);
	textcolor(10);
	cprintf("Enter the origin city -> ", o_city);
	get_ocity(o_city);
	strupr(o_city);
	gotoxy(10,15);
	textcolor(10);
	cprintf("Enter the destination city -> ", d_city);
	get_dcity (d_city);
	strupr(d_city);
	p = payoff_calc();
	if ( ECODE == 0 )
	{
	gotoxy(10,18);
	textcolor(10);
	cprintf("Congratulations, your PAYOFF is $%gK !!!",p);
	sound(1000);
	delay(1000);
	nosound();
	}
	textcolor(14);
	gotoxy(25,21);
	cprintf("Press ANY KEY to return to MAIN Menu");
	ss[1] = getch();



	}

