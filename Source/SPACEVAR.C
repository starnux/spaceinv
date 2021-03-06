/****************************************************\
				  000       00000000000000
				 0   0          0000
				 0             0000
				  000 PACE    0000NVADERS
					  0       0000                0
				 0   0      0000                  0
				  000  00000000000000000000000000000  AFX/2
															 0
							  Sprites and levels		0

\****************************************************/
/****************************************************\
						Open Source Game
			Project under GNU Public Licence
				Available on Sourceforge.net
			Please Compile under Borland C++ 4.5
			 For 80286 CPU into Tiny Model
		Please leave my name under your projects
				if you use part of this code
		You can use parts but not use entire
		 Further info : superna@ifrance.com
				http://www.na-prod.fr.st
\****************************************************/
//************************** XPLOSION *************************
char xplos[][2][8]={
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x54,0x28,0x54,0x28,0x54,0x0,0x0},{0x92,0x7C,0x6C,0xD6,0x6C,0x7C,0x92,0x0}},
{{0x0,0x0,0x28,0x10,0x28,0x0,0x0,0x0},{0x0,0x54,0x38,0x7C,0x38,0x54,0x0,0x0}},
{{0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0},{0x0,0x0,0x28,0x10,0x28,0x0,0x0,0x0}}};
//*************************** FONDS ***************************
char lvl_fond[]={0,1,2,3,4,5,1,2,3,4};
//************************** ENNEMIS **************************
char ennemis0[10][20][6]={{{2,0,20,12,5,0},{2,0,31,12,5,0},{2,0,42,12,5,0},{2,0,53,12,5,0},
/*0*/		 {2,0,64,12,5,0},{2,0,76,12,5,0},{2,0,86,12,5,0},
			 {2,0,25,23,5,0},{2,0,36,23,5,0},{2,0,47,23,5,0},{2,0,58,23,5,0},
		    {2,0,69,23,5,0},{2,0,81,23,5,0},
			 {2,0,20,34,5,0},{2,0,31,34,10,0},{2,0,42,34,10,0},{2,0,53,34,10,0},
			 {2,0,64,34,5,0},{2,0,76,34,10,0},{2,0,86,34,10,0}},
/*1*/		{{4,1,20,12,10,1},{4,1,31,12,10,1},{2,0,42,12,5,0},{2,0,53,12,5,0},
			 {2,0,64,12,5,0},{4,1,76,12,10,0},{4,1,86,12,10,0},
		    {2,0,25,23,5,0},{2,0,36,23,5,0},{4,1,47,23,10,0},{4,1,58,23,10,0},
			 {2,0,69,23,5,0},{2,0,81,23,5,0},
			 {4,1,20,34,10,0},{4,1,31,34,10,0},{2,0,42,34,5,0},{2,0,53,34,5,0},
			 {2,0,64,34,5,0},{4,1,76,34,10,1},{4,1,86,34,10,1}},
/*2*/		{{5,2,20,12,15,1},{5,2,31,12,15,1},{4,1,42,12,10,0},{4,1,53,12,10,0},
			 {4,1,64,12,10,0},{4,2,76,12,15,0},{5,2,86,12,15,0},
			 {4,1,25,23,10,0},{4,1,36,23,10,0},{5,2,47,23,15,1},{5,2,58,23,15,1},
			 {4,1,69,23,10,0},{4,1,81,23,10,0},
			 {5,2,20,34,15,0},{5,2,31,34,15,0},{4,1,42,34,10,0},{4,1,53,34,10,0},
			 {4,1,64,34,10,0},{5,2,76,34,15,1},{5,2,86,34,15,1}},
/*3*/		{{5,2,25,12,15,1},{5,2,36,12,15,1},{4,1,47,12,10,0},{4,1,58,12,10,0},
			 {4,1,69,12,10,0},{4,2,80,12,15,0},
			 {4,1,25,23,10,0},{4,1,36,23,10,0},{5,2,47,23,15,1},{5,2,58,23,15,1},
			 {4,1,69,23,10,0},{4,1,81,23,10,0},
			 {5,2,31,34,15,0},{5,2,42,34,15,0},{4,1,53,34,10,0},{4,1,64,34,10,0},
			 {4,1,75,34,10,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},
/*4*/		{{10,3,31,10,20,1},{10,3,53,10,20,1},{10,3,73,10,20,1},
			 {4,2,20,12,10,0},{10,3,42,12,20,1},{10,3,64,12,20,1},{4,2,81,12,10,0},
			 {10,3,31,20,20,1},{10,3,53,20,20,1},{10,3,73,20,20,1},
			 {5,2,20,23,10,0},{4,1,42,23,10,0},{4,1,64,23,10,0},{5,2,81,23,10,0},
			 {4,1,20,34,10,0},{4,2,42,34,10,0},{4,2,64,34,10,0},{4,1,81,34,10,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},
/*5*/	   {{20,4,20,12,20,1},{20,4,31,12,20,1},{20,4,42,12,20,1},{20,4,53,12,20,1},
			 {20,4,64,12,20,1},{20,4,76,12,20,1},{20,4,86,12,20,1},
			 {20,4,20,23,20,1},{20,4,31,23,20,1},{20,4,42,23,20,1},{20,4,53,23,20,1},
			 {20,4,64,23,20,1},{20,4,76,23,20,1},{20,4,86,23,20,1},
			 {10,3,20,34,15,2},{10,3,42,34,15,2},{10,3,64,34,15,2},{10,3,86,34,15,2},{0,0,0,0,0,0},{0,0,0,0,0,0}},
/*6*/    {{25,5,20,12,20,2},{25,5,31,12,20,2},{25,5,42,12,20,2},{25,5,53,12,20,2},
			 {25,5,64,12,20,2},{25,5,76,12,20,2},{25,5,86,12,20,2},
			 {25,5,20,23,20,2},{25,5,42,23,20,2},{25,5,64,23,20,2},{25,5,86,23,20,2},
			 {20,4,20,34,20,1},{20,4,31,34,20,1},{20,4,42,34,20,1},{20,4,53,34,20,1},
			 {20,4,64,34,20,1},{20,4,76,34,20,1},{20,4,86,34,20,1},{0,0,0,0,0,0},{0,0,0,0,0,0}},
/*7*/    {{30,6,25,12,25,2},{30,6,36,12,25,2},{30,6,47,12,25,2},{30,6,58,12,25,2},
			 {30,6,69,12,25,2},{30,6,80,12,25,2},
			 {30,6,20,23,25,2},{30,6,31,23,25,2},{30,6,42,23,25,2},{30,6,53,23,25,2},
			 {30,6,64,23,25,2},{30,6,75,23,25,2},{30,6,86,23,25,2},
			 {25,5,20,34,20,2},{25,5,31,34,20,2},{25,5,42,34,20,2},{25,5,53,34,20,2},
			 {25,5,64,34,20,2},{25,5,76,34,20,2},{25,5,86,34,20,2}},
/*8*/    {{35,7,25,12,30,2},{35,7,39,12,30,2},{35,7,48,12,30,2},{35,7,57,12,30,2},
			 {35,7,66,12,30,2},{35,7,80,12,30,2},
			 {35,7,25,34,30,2},{35,7,36,34,30,2},{35,7,47,34,30,2},{35,7,58,34,30,2},
			 {35,7,69,34,30,2},{35,7,80,34,30,2},
			 {30,6,36,23,25,2},{30,6,47,23,25,2},{30,6,58,23,25,2},{30,6,69,23,25,2},{0,0,0,0,0,0}
			 ,{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}},
/*9*/    {{40,8,25,12,40,3},{40,8,36,12,40,3},{40,8,47,12,40,3},{40,8,58,12,40,3},
			 {40,8,69,12,40,3},{40,8,80,12,40,3},
			 {40,8,36,23,40,3},{40,8,47,23,40,3},{40,8,58,23,40,3},{40,8,69,23,40,3},
			 {40,8,25,34,40,3},{40,8,36,34,40,3},{40,8,47,34,40,3},{40,8,58,34,40,3},
			 {40,8,69,34,40,3},{40,8,80,34,40,3},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}}};
//*************************** BOSS ****************************
short boss0[10][6]={{0,0,0,1,15,0},{0,0,0,1,15,0},{0,1,0,1,30,1},{0,0,0,1,15,0},{0,0,0,1,15,0},
						 {0,1,0,1,30,1},{0,1,0,1,30,1},{0,1,0,1,30,1},{0,1,0,1,30,1},{0,1,0,1,30,1}};
//************************** PERSO ****************************
short moi0[5]={100,0,10,55,0};
//***********************SPRITES***********************
char cadeausprite[2][2][8]={
			{{0x38,0x44,0x92,0xBA,0x92,0x44,0x38,0x0}, // PLUS
			 {0x38,0x7C,0xFE,0xFE,0xFE,0x7C,0x38,0x0}},
			{{0x38,0x40,0xF0,0x40,0xF0,0x40,0x38,0x0},  // EURO
			 {0x38,0x40,0xF0,0x40,0xF0,0x40,0x38,0x0}}};
char tirsprite[8][2][8]={
			{{0x0,0x20,0x70,0x20,0x0,0x0,0x0,0x0},{0x50,0x70,0x70,0x20,0x0,0x0,0x0,0x0}},
			{{0x88,0x50,0x20,0x0,0x0,0x0,0x0,0x0},{0xD8,0x70,0x20,0x0,0x0,0x0,0x0,0x0}},
			{{0x50,0x50,0x50,0x50,0x0,0x0,0x0,0x0},{0x50,0x50,0x50,0x50,0x0,0x0,0x0,0x0}},
			{{0x88,0xA8,0x70,0x20,0x0,0x0,0x0,0x0},{0xA8,0xF8,0x70,0x20,0x0,0x0,0x0,0x0}},
			{{0x20,0x70,0x20,0x0,0x0,0x0,0x0,0x0},{0x20,0x70,0x70,0x50,0x0,0x0,0x0,0x0}},
			{{0x20,0x50,0x88,0x0,0x0,0x0,0x0,0x0},{0x20,0x70,0xA8,0x0,0x0,0x0,0x0,0x0}},
			{{0x20,0x70,0xA8,0x88,0x0,0x0,0x0,0x0},{0x20,0x70,0xF8,0xA8,0x0,0x0,0x0,0x0}},
			{{0x20,0x70,0xF8,0xA8,0x0,0x0,0x0,0x0},{0x20,0x70,0xF8,0xF8,0x20,0x0,0x0,0x0}}} ;

char ennemisprite[9][2][8]={
			{{0x82,0x82,0xFE,0x92,0x44,0x28,0x10,0x0},
/*0*/			 {0x82,0xFE,0xFE,0xBA,0x54,0x28,0x10,0x0}},
			{{0x82,0x82,0x7C,0x82,0xEE,0x10,0x10,0x0},
/*1*/		 	 {0x82,0xFE,0x7C,0xEE,0xFE,0x10,0x10,0x0}},
			{{0x38,0x44,0x92,0x92,0x92,0x6C,0x10,0x0},
/*2*/	 	 	 {0x38,0x54,0x92,0xBA,0xFE,0x6C,0x10,0x0}},
			{{0xAA,0xC6,0x82,0xC6,0xAA,0xAA,0x10,0x0},
/*3*/	 		 {0xBA,0xD6,0xC6,0xEE,0xBA,0xBA,0x10,0x0}},
			{{0x92,0xEE,0x82,0x7C,0x92,0x6C,0x28,0x0},
/*4*/			 {0x92,0xFE,0xEE,0x7C,0xFE,0x6C,0x28,0x0}},
			{{0x38,0xEE,0x82,0x44,0x28,0x38,0x10,0x0},
/*5*/	 		 {0x38,0xFE,0xEE,0x44,0x38,0x38,0x10,0x0}},
			{{0xBA,0x44,0xAA,0xBA,0x54,0x28,0x28,0x0},
/*6*/			 {0xBA,0x6C,0xBA,0xFE,0x7C,0x28,0x28,0x0}},
			{{0x82,0x92,0x6C,0x28,0x38,0x54,0xBA,0x0},
/*7*/	  		 {0x92,0xBA,0x6C,0x38,0x7C,0xD6,0xBA,0x0}},
			{{0xC6,0xC6,0xC6,0x82,0x7C,0x38,0x10,0x0},
/*8*/	  		 {0xC6,0xC6,0xD6,0xFE,0x7C,0x38,0x10,0x0}}};
char moisprite[4][2][8]={
			{{0x10,0x10,0x28,0x54,0x6C,0xFE,0x44,0x0},
			 {0x10,0x10,0x38,0x54,0x7C,0xFE,0x44,0xEE}},   //0
			{{0x10,0x92,0x6C,0x54,0xEE,0x44,0x44,0x0},
			 {0x10,0x92,0x7C,0x54,0xFE,0x6C,0x44,0xEE}},   //1
			{{0x10,0x92,0x6C,0x54,0xEE,0xC6,0x44,0x0},
			 {0x92,0xBA,0x7C,0x54,0xFE,0xEE,0x44,0xEE}},   //2
			{{0x10,0x38,0x6C,0xD6,0x54,0xEE,0x44,0x0},
			 {0x10,0xBA,0x7C,0xFE,0x54,0xFE,0x44,0xEE}}};  //3
char bosssprite[2][4][8]={
			 {{0x20,0x7F,0xFF,0x15,0xA,0xA,0x0,0x0},  //0
			 {0x80,0xC0,0xE0,0x0,0x0,0x0,0x0,0x0},
			 {0x71,0x7F,0xFF,0x15,0xE,0xA,0x0,0x0},
			 {0xC0,0xC0,0xE0,0x0,0x0,0x0,0x0,0x0}},
			 {{0x20,0x44,0x7F,0x15,0x2E,0xA,0x0,0x0},  //1
			 {0x80,0x40,0xC0,0x0,0x0,0x80,0x0,0x0},
			 {0x2E,0x64,0x7F,0x9F,0x2E,0xA,0x0,0x0},
			 {0x80,0xC0,0xC0,0x20,0x0,0x80,0x0,0x0}}};
