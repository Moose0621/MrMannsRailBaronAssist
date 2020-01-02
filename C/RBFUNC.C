/*                    Rail Baron Utility Program                         */
/*            Rev. 3.1 - 7/1/93                                          */

#define DEBUG 0
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <dos.h>

/* ============================================================= */
/*               Rail Baron Function Library                     */
/* ============================================================= */

	char new_city[100];
	extern int ECODE;
	extern int doubles;

/* ----------------------------------------------------------------------- */
/*                        Dice Roll Screen                                 */
/* ----------------------------------------------------------------------- */

	int dice_screen()
	{
	char *title =  "Dice Roll Screen";
	char *title1 = "Your Roll is -> ";
	char *title2 = "Press Any Key to Continue";
	char *title3 = "DOUBLES !!!!!";
	char a[55];
	int ss[2];
	int i;
	int large = 3;
	int medium = 2;
	char hold[20];
	cleardevice();
	settextstyle(0,0,large);
	outtextxy(120,15,title);
	settextstyle(0,0,medium);
	outtextxy(100,100,title1);
        sprintf(hold,"%d",dice_roll());
	if ( ECODE == 0 )
	{
	outtextxy(350,100, hold);
	sound(1000);
	delay(1000);
	nosound();
	}
	/* Doubles DISPLAY */
	if (doubles == 1 )
	   {
		outtextxy(200,200,title3);
		for (i = 0; i !=4 ; i++);
			{
			sound(200+(i*30));
			delay(2000);
			nosound();
			}
		#if DEBUG
		{
		printf("\nDoubles !!!!!!\n");
		}
		#endif
	   }
	outtextxy(130,310,title2);
	ss[1] = getch();
	}


/* ----------------------------------------------------------------------- */
/*                   Get the Origin City                                   */
/* ----------------------------------------------------------------------- */

	void get_ocity (char *s)
	{
	gets(s);
	}

/* ----------------------------------------------------------------------- */
/*                      Get the Destination City                           */
/* ----------------------------------------------------------------------- */

	void get_dcity (char *s)
	{
	gets(s);
	}

/* ----------------------------------------------------------------------- */
/*                       Roll one dice function                            */
/* ----------------------------------------------------------------------- */

	int roll_one(delay)
	int delay;
	{
	int value, j = 0;
	randomize();
	for (j=2000 + delay; j!=0; --j)
	    {
	    value = random(6) +1;
	    }
	#if    DEBUG
	      {
	      printf("\n Dice Number 1 = %d",value);
	      }
	#endif
	return (value);
	}

/*  ---------------------------------------------------------------  */
/*                 Get New Destination Function                      */
/*  ---------------------------------------------------------------  */
	char get_destin()
	{
	int odd_even = 2;            /* 0 = even roll, 1 = odd roll */
	int num, z;
	/* char city[75]; */
	num = roll_one();    /* roll one device for odd/even select */
	if (num == 1 || num == 3 || num == 5)
		{
		odd_even = 1;                     /* odd roll */
		}
		else
			{
			odd_even = 0;             /*  even roll  */
			}
	z = dice_roll();                     /* get full dice roll */
	/*  ----------------------------------------------  */
	/*         Find Region and City                     */
	/*  ----------------------------------------------  */
	if ( odd_even == 1)
		{
		switch (z)     /* odd dice roll */
			{
			case 2:
				plains();
				break;
			case 3:
				southeast();
				break;
			case 4:
				southeast();
				break;
			case 5:
				southeast();
				break;
			case 6:
				north_central();
				break;
			case 7:
				north_central();
				break;
			case 8:
				northeast();
				break;
			case 9:
				northeast();
				break;
			case 10:
				northeast();
				break;
			case 11:
				northeast();
				break;
			case 12:
				northeast();
				break;
			}

		}
	if ( odd_even == 0)
		{
		switch (z)
			{
			case 2:
				southwest();
				break;
			case 3:
				south_central();
				break;
			case 4:
				south_central();
				break;
			case 5:
				south_central();
				break;
			case 6:
				southwest();
				break;
			case 7:
				southwest();
				break;
			case 8:
				plains();
				break;
			case 9:
				northwest();
				break;
			case 10:
				northwest();
				break;
			case 11:
				plains();
				break;
			case 12:
				northwest();
				break;
			}
		}

/*	printf("\n\n%s",new_city);*/
	}

/*  ---------------------------------------------------------------------- */
/*                  Select Southwest City                                  */
/*  ---------------------------------------------------------------------- */
	int southwest()
	{
	char city[50];
	int num, z;
	int odd_even = 2;
	num = roll_one();   /* roll one dice for odd even calc */
	z = dice_roll();    /* roll two dice for city select */
	if (num == 1 || num == 3 || num == 5)
		{
		odd_even = 1;                     /* odd roll */
		}
		else
			{
			odd_even = 0;             /*  even roll  */
			}
	if ( odd_even == 1)     /* odd dice roll */
		{
		switch (z)
			{
			case 2:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is San Diego");
				break;
			case 3:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is San Diego");
				break;
			case 4:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Reno");
				break;
			case 5:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is San Diego");
				break;
			case 6:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Sacramento");
				break;
			case 7:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Las Vegas");
				break;
			case 8:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Phoenix");
				break;
			case 9:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is El Paso");
				break;
			case 10:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Tucumcari");
				break;
			case 11:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Phoenix");
				break;
			case 12:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Phoenix");
				break;
			}
		}
	if ( odd_even == 0)       /* even dice roll */
		{
		switch (z)
			{
			case 2:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Los Angeles");
				break;
			case 3:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Oakland");
				break;
			case 4:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Oakland");
				break;
			case 5:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Oakland");
				break;
			case 6:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Los Angeles");
				break;
			case 7:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Los Angeles");
				break;
			case 8:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is Los Angeles");
				break;
			case 9:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is San Francisco");
				break;
			case 10:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is San Francisco");
				break;
			case 11:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is San Francisco");
				break;
			case 12:
				strcpy(new_city,"Your new region is Southwest. \nYour new destination city is San Francisco");
				break;
				}
			}

		}

 /*  ---------------------------------------------------------------------- */
/*                  Select Northwest City                                  */
/*  ---------------------------------------------------------------------- */
	int northwest()
	{
	char city[50];
	int num, z;
	int odd_even = 2;
	num = roll_one();   /* roll one dice for odd even calc */
	z = dice_roll();    /* roll two dice for city select */
	if (num == 1 || num == 3 || num == 5)
		{
		odd_even = 1;                     /* odd roll */
		}
		else
			{
			odd_even = 0;             /*  even roll  */
			}
	if ( odd_even == 1)     /* odd dice roll */
		{
		switch (z)   
			{
			case 2:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Spokane");
				break;
			case 3:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Spokane");
				break;
			case 4:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Seattle");
				break;
			case 5:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Seattle");
				break;
			case 6:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Seattle");
				break;
			case 7:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Seattle");
				break;
			case 8:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Rapid City");
				break;
			case 9:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Casper");
				break;
			case 10:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Billings");
				break;
			case 11:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Billings");
				break;
			case 12:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Spokane");
				break;
			}
		}
	if ( odd_even == 0)       /* even dice roll */
		{
		switch (z)
			{
			case 2:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Spokane");
				break;
			case 3:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Salt Lake City");
				break;
			case 4:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Salt Lake City");
				break;
			case 5:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Salt Lake City");
				break;
			case 6:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Portland");
				break;
			case 7:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Portland");
				break;
			case 8:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Portland");
				break;
			case 9:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Pocatello");
				break;
			case 10:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Butte");
				break;
			case 11:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Butte");			break;
			case 12:
				strcpy(new_city,"Your new region is Northwest. \nYour new destination city is Portland");
				break;
				}
			}

		}

/*  ---------------------------------------------------------------------- */
/*                  Select Plains City                                     */
/*  ---------------------------------------------------------------------- */
	int plains()
	{
	char city[50];
	int num, z;
	int odd_even = 2;
	num = roll_one();   /* roll one dice for odd even calc */
	z = dice_roll();    /* roll two dice for city select */
	if (num == 1 || num == 3 || num == 5)
		{
		odd_even = 1;                     /* odd roll */
		}
		else
			{
			odd_even = 0;             /*  even roll  */
			}
	if ( odd_even == 1)     /* odd dice roll */
		{
		switch (z)   
			{
			case 2:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Kansas City");
				break;
			case 3:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Kansas City");
				break;
			case 4:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Denver");
				break;
			case 5:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Denver");
				break;
			case 6:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Denver");
				break;
			case 7:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Kansas City");
				break;
			case 8:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Kansas City");
				break;
			case 9:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Kansas City");
				break;
			case 10:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Pueblo");
				break;
			case 11:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Pueblo");
				break;
			case 12:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Oklahoma City");
				break;
			}
		}
	if ( odd_even == 0)       /* even dice roll */
		{
		switch (z)
			{
			case 2:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Oklahoma City");
				break;
			case 3:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is St. Paul");
				break;
			case 4:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Minneapolis");
				break;
			case 5:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is St. Paul");
				break;
			case 6:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Minneapolis");
				break;
			case 7:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Oklahoma City");
				break;
			case 8:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Des Moines");
				break;
			case 9:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Omaha");
				break;
			case 10:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Omaha");
				break;
			case 11:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Fargo");
				break;
			case 12:
				strcpy(new_city,"Your new region is Plains. \nYour new destination city is Fargo");
				break;
				}
			}

		}
	       
/*  ---------------------------------------------------------------------- */
/*                  Select South Central City                              */
/*  ---------------------------------------------------------------------- */
	int south_central()
	{
	char city[50];
	int num, z;
	int odd_even = 2;
	num = roll_one();   /* roll one dice for odd even calc */
	z = dice_roll();    /* roll two dice for city select */
	if (num == 1 || num == 3 || num == 5)
		{
		odd_even = 1;                     /* odd roll */
		}
		else
			{
			odd_even = 0;             /*  even roll  */
			}
	if ( odd_even == 1)     /* odd dice roll */
		{
		switch (z)   
			{
			case 2:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Memphis");
				break;
			case 3:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Memphis");
				break;
			case 4:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Memphis");
				break;
			case 5:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Litle Rock");
				break;
			case 6:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is New Orleans");
				break;
			case 7:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Birmingham");
				break;
			case 8:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Louisville");
				break;
			case 9:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Nashville");
				break;
			case 10:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Nashville");
				break;
			case 11:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Louisville");
				break;
			case 12:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Memphis");
				break;
			}
		}
	if ( odd_even == 0)       /* even dice roll */
		{
		switch (z)
			{
			case 2:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Shreveport");
				break;
			case 3:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Shreveport");
				break;
			case 4:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Dallas");
				break;
			case 5:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is New Orleans");
				break;
			case 6:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Dallas");
				break;
			case 7:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is San Antonio");
				break;
			case 8:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Houston");
				break;
			case 9:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Houston");
				break;
			case 10:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Fort Worth");
				break;
			case 11:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Fort Worth");
				break;
			case 12:
				strcpy(new_city,"Your new region is South Central. \nYour new destination city is Fort Worth");
				break;
				}
			}

		}

/*  ---------------------------------------------------------------------- */
/*                  Select North Central City                              */
/*  ---------------------------------------------------------------------- */
	int north_central()
	{
	char city[50];
	int num, z;
	int odd_even = 2;
	num = roll_one();   /* roll one dice for odd even calc */
	z = dice_roll();    /* roll two dice for city select */
	if (num == 1 || num == 3 || num == 5)
		{
		odd_even = 1;                     /* odd roll */
		}
		else
			{
			odd_even = 0;             /*  even roll  */
			}
	if ( odd_even == 1)     /* odd dice roll */
		{
		switch (z)   
			{
			case 2:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Cleveland");
				break;
			case 3:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Cleveland");
				break;
			case 4:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Cleveland");
				break;
			case 5:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Cleveland");
				break;
			case 6:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Detroit");
				break;
			case 7:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Detroit");
				break;
			case 8:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Indianapolis");
				break;
			case 9:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Milwaukee");
				break;
			case 10:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Milwaukee");
				break;
			case 11:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Chicago");
				break;
			case 12:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Milwaukee");
				break;
			
			}
		}
	if ( odd_even == 0)       /* even dice roll */
		{
		switch (z)
			{
			case 2:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Cincinnati");
				break;
			case 3:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Chicago");
				break;
			case 4:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Cincinnati");
				break;
			case 5:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Cincinnati");
				break;
			case 6:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Columbus");
				break;
			case 7:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Chicago");
				break;
			case 8:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Chicago");
				break;
			case 9:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is St. Louis");
				break;
			case 10:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is St. Louis");
				break;
			case 11:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is St. Louis");
				break;
			case 12:
				strcpy(new_city,"Your new region is North Central. \nYour new destination city is Chicago");
				break;

			}
		   }

	     }
	       
/*  ---------------------------------------------------------------------- */
/*                  Select Southeast City                                  */
/*  ---------------------------------------------------------------------- */
	int southeast()
	{
	char city[50];
	int num, z;
	int odd_even = 2;
	num = roll_one();   /* roll one dice for odd even calc */
	z = dice_roll();    /* roll two dice for city select */
	if (num == 1 || num == 3 || num == 5)
		{
		odd_even = 1;                     /* odd roll */
		}
		else
			{
			odd_even = 0;             /*  even roll  */
			}
	if ( odd_even == 1)     /* odd dice roll */
		{
		switch (z)   
			{
			case 2:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Charlotte");
				break;
			case 3:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Charlotte");
				break;
			case 4:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Chattanooga");
				break;
			case 5:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Atlanta");
				break;
			case 6:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Atlanta");
				break;
			case 7:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Atlanta");
				break;
			case 8:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Richmond");
				break;
			case 9:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Knoxville");
				break;
			case 10:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Mobile");
				break;
			case 11:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Knoxville");
				break;
			case 12:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Mobile");
				break;
			}
		}
	if ( odd_even == 0)       /* even dice roll */
		{
		switch (z)
			{
			case 2:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Norfolk");
				break;
			case 3:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Norfolk");
				break;
			case 4:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Norfolk");
				break;
			case 5:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Charleston");
				break;
			case 6:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Miami");
				break;
			case 7:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Jacksonville");
				break;
			case 8:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Miami");
				break;
			case 9:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Tampa");
				break;
			case 10:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Tampa");
				break;
			case 11:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Moile");
				break;
			case 12:
				strcpy(new_city,"Your new region is Southeast. \nYour new destination city is Norfolk");
				break;

				}
			}

		}

/*  ---------------------------------------------------------------------- */
/*                  Select Northeast City                                  */
/*  ---------------------------------------------------------------------- */
	int northeast()
	{
	char city[50];
	int num, z;
	int odd_even = 2;
	num = roll_one();   /* roll one dice for odd even calc */
	z = dice_roll();    /* roll two dice for city select */
	if (num == 1 || num == 3 || num == 5)
		{
		odd_even = 1;                     /* odd roll */
		}
		else
			{
			odd_even = 0;             /*  even roll  */
			}
	if ( odd_even == 1)     /* odd dice roll */
		{
		switch (z)   
			{
			case 2:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is New York");
				break;
			case 3:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is New York");
				break;
			case 4:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is New York");
				break;
			case 5:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Albany");
				break;
			case 6:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Boston");
				break;
			case 7:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Buffalo");
				break;
			case 8:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Boston");
				break;
			case 9:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Portland");
				break;
			case 10:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is New York");
				break;
			case 11:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is New York");
				break;
			case 12:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is New York");
				break;
			}
		}
	if ( odd_even == 0)       /* even dice roll */
		{
		switch (z)
			{
			case 2:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is New York");
				break;
			case 3:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Wasington");
				break;
			case 4:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Pittsburgh");
				break;
			case 5:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Pittsburgh");
				break;
			case 6:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Philadelphia");
				break;
			case 7:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Wasington");
				break;
			case 8:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Philadelphia");
				break;
			case 9:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Baltimore");
				break;
			case 10:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Baltimore");
				break;
			case 11:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is Baltimore");
				break;
			case 12:
				strcpy(new_city,"Your new region is Northeast. \nYour new destination city is New York");
				break;

				}
			}

		}



