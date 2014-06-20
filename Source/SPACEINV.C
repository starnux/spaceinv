/****************************************************\
							0   0   0
							00  0  0 0
							0 0 0 0 0 0
							0  000     0
							Productions00
							0000000000000

				  000       00000000000000
				 0   0          0000
				 0             0000
				  000 PACE    0000NVADERS
					  0       0000                0
				 0   0      0000                  0
				  000  00000000000000000000000000000  AFX/2
															 0
															0
					Space Invaders Beta 2 mod 3
								Main File
 Ennemis : 9
 Niveaux : 10
 Boss : 2
 Couleurs : Gris mode Db (+7 Menus)
 Fond : 6
\****************************************************/
/****************************************************\
							 Nouveautes
 - Beta 2 Mod 3
  - Securite contre l'extinction pendant le jeu
  - Desactivation du menu pendant les menus de SI
  - Game Over et Bravo en gris relief
 - Beta 2 Mod 2
  - Tirs affiches byte par byte
  - Acceleration de l'affichage du fond
  - De nouveaux menus en gris
  - Explosion des ennemis
  - Pret pour sauvegarde
  - Un nouveau fond
  - Les 2 bugs regles
 - Beta 2 Mod 1
  - Reorganisation des sources
  - Passage en Open-Source
  - Nouvel Ecran de Copyright
  - Tout en gris
  - Affichage Byte par byte sprites sauf tirs
  - Fond deroulant
  - 2 Menus en gris
  - De Nouvelles Armes
  - Passage a L'euro
  - Des bonus
  - 10 Niveaux
  - 9 Ennemis
  - ...
\****************************************************/
/****************************************************\
							 Bugs Connus
 - Extinction dans les menus possible
\****************************************************/
/****************************************************\
							  A Faire
 - Tout les menus en gris
  -> Reste plus que :
	- Level n
	- Magasin
	+ - Menu Play Saved Game / New Game
	  - Menu Save Game / Stop Game
	  - Menu Setup
 - Menu Setup
 - Nouveaux Sprites du Boss
 - Sauvegarde de la partie
  -> Save ou quit (menu pause->Quit)
  -> Saved game ou New game (menu General->Play)
  -> Warning au start du jeu en image  -OK
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
//Fonctions Basic de 2072
#include "basic-u.c"
//Images
#include "spaceimg.c"
//FONCTIONS
#include "spaceft.c"
//Le fichier basic
struct BASICfile bf;
//************* ROUTINES **********************
void addxplos(int,int);
//*********** Collisions Tirs et Bonus ********
void refreshtirs(int xposme,int yposme){int i,j;
for(i=0;i<30;i++){

  if(tirmoi[i][0]>=1){

	tirmoi[i][2]-=2;
	if(tirmoi[i][2]<0) tirmoi[i][0]=0;

	 for(j=0;j<20;j++){
	if(ennemis[j][0]<=0) ennemis[j][0]=0;
	if(!(ennemis[j][0]>0)) goto suite1;
	if(tirmoi[i][1]<ennemis[j][2]) goto suite1;
	if(tirmoi[i][1]>ennemis[j][2]+7) goto suite1;
	if(tirmoi[i][2]<ennemis[j][3]) goto suite1;
	if(tirmoi[i][2]>ennemis[j][3]+7) goto suite1;
	tirmoi[i][0]=0;
	ennemis[j][0]-=(moi[1]+1);
	if(ennemis[j][0]<=0) { moi[4]+=10;
		addxplos(ennemis[j][2],ennemis[j][3]);}
		suite1:
    }
	if(boss[0]<1) goto suite2;
	if(tirmoi[i][1]<boss[2]) goto suite2;
	if(tirmoi[i][1]>boss[2]+10) goto suite2;
	if(tirmoi[i][2]<boss[3]) goto suite2;
	if(tirmoi[i][2]>boss[3]+6) goto suite2;
	tirmoi[i][0]=0;
	boss[0]-=moi[1]+1;
	if(boss[0]<=0) { moi[4]+=10;
		addxplos(boss[2],boss[3]);}
	suite2:    
  }
  if(tirennemi[i][0]>=1){

	tirennemi[i][2]++;
	if(tirennemi[i][2]>61) tirennemi[i][0]=0;

	if(tirennemi[i][1]<xposme) goto suite3;
	if(tirennemi[i][1]>xposme+7) goto suite3;
	if(tirennemi[i][2]<yposme) goto suite3;
	if(tirennemi[i][2]>yposme+7) goto suite3;
	tirennemi[i][0]=0;
	moi[0]-=ennemis[(tirennemi[i][3])][4];
	suite3:
  }
  if(tirboss[i][0]>=1){

	tirboss[i][2]++;
	if(tirboss[i][2]>61) tirboss[i][0]=0;

	if(tirboss[i][1]<xposme) goto suite4;
	if(tirboss[i][1]>xposme+7) goto suite4;
	if(tirboss[i][2]<yposme) goto suite4;
	if(tirboss[i][2]>yposme+7) goto suite4;
	tirboss[i][0]=0;
	moi[0]-=boss[4];
	suite4:
  }}};

void refreshcadeaux(){int i,j;
if(cadeauio==1){
 for(i=0;i<5;i++){
  if(cadeaux[i][0]>=1){
   cadeaux[i][2]++;
	if(cadeaux[i][2]>57) cadeaux[i][0]=0;
	if(cadeaux[i][1]<moi[2]) goto suite1;
	if(cadeaux[i][1]>moi[2]+7) goto suite1;
	if(cadeaux[i][2]+7<moi[3]) goto suite1;
	if(cadeaux[i][2]+7>moi[3]+7) goto suite1;
   goto suiteok;
   suite1:
	if(cadeaux[i][1]+7<moi[2]) goto suite2;
	if(cadeaux[i][1]+7>moi[2]+7) goto suite2;
	if(cadeaux[i][2]+7<moi[3]) goto suite2;
	if(cadeaux[i][2]+7>moi[3]+7) goto suite2;
   suiteok:
	if(cadeaux[i][3]==0&&moi[0]<=95){
    moi[0]+=5;
	 cadeaux[i][0]=0;}
	if(cadeaux[i][3]==1){
    moi[4]+=10;
	 cadeaux[i][0]=0;}
  suite2:
  }}}};

//************ AJOUT ****************
void addxplos(int x,int y){
	int i;
	for(i=0;i<10;i++){
	 if(xplosion[i][0]>12){
	  xplosion[i][1]=x;
	  xplosion[i][2]=y;
	  xplosion[i][0]=0;
	  return;} }};
void addcadeau(int x,int y,int type){
	int i;
	for(i=0;i<5;i++){
	 if(cadeaux[i][0]==0){
	  cadeaux[i][1]=x;
	  cadeaux[i][2]=y;
	  cadeaux[i][3]=type;
	  cadeaux[i][0]=1;
	  return;} }};
void addtirmoi(int x,int y){
	int i;
	for(i=0;i<30;i++){
	 if(tirmoi[i][0]==0){
	  tirmoi[i][1]=x;
	  tirmoi[i][2]=y;
	  tirmoi[i][0]=1;
	  return;} }};
void addtirennemi(int x,int y,int who){
	int i;
	if(ennemis[who][0]>0)
	for(i=0;i<30;i++){
	 if(tirennemi[i][0]==0){
	  tirennemi[i][1]=x;
	  tirennemi[i][2]=y;
	  tirennemi[i][3]=who;
	  tirennemi[i][0]=1;
	  return;} }};
void addtirboss(int x,int y){
	int i;
	if(boss[0]>0)
	for(i=0;i<30;i++){
	 if(tirboss[i][0]==0){
	  tirboss[i][1]=x;
	  tirboss[i][2]=y;
	  tirboss[i][0]=1;
	  return;} }};
//*********** Routines de dessin groupés *************
void drawennemis(){int i;
	for(i=0;i<20;i++)
		if(ennemis[i][0]>=1)
			ennemidraw(ennemis[i][2],ennemis[i][3],ennemis[i][1],1);}
void drawtirs(int page){
	int i;
	for(i=0;i<30;i++){
	if(tirmoi[i][0]>0) tirdraw(tirmoi[i][1]-2,tirmoi[i][2],moi[1]+4,page);
	if(tirennemi[i][0]>0) tirdraw(tirennemi[i][1]-2,tirennemi[i][2],ennemis[i][5],page);
	if(tirboss[i][0]>0) tirdraw(tirboss[i][1]-2,tirboss[i][2],boss[5],page);}};
void drawcadeaux(int page){
	int i;
	for(i=0;i<5;i++){
	if(cadeaux[i][0]==1) cadeaudraw(cadeaux[i][1],cadeaux[i][2],cadeaux[i][3],page) ;}};
//************* Compte les ennemis restants ************
int countennemi(){int i,nb=0;
	for(i=0;i<20;i++) if(ennemis[i][0]>0) nb++;
	if(boss[0]>0) nb++;
	return nb;};
//******************* MENUS *****************************
//*************** Choix du Niveau ***********************
int chooselvl(){int key,i=0,carres[3][2]={{21,32},{32,43},{43,54}};
	//clearpage(0);
	disp_bmp(DIFFI1,0);
	disp_bmp(DIFFI2,2);
	fillgRect(35,carres[i][0],91,carres[i][1],0);
	debut:
	key=waitkey();
	if(key==1) return 50;
	if(key==28) return (3-i);
	if(key==72||key==80){
	//invRect(35,carres[i][0],91,carres[i][1],0);
	if(key==72) i--;
	if(i<0) i=2;
	if(key==80) i++;
	if(i==3) i=0;
	disp_bmp(DIFFI2,3);
	fillgRect(35,carres[i][0],91,carres[i][1],1);
	movedata(0x1ae0,0,0x1aa0,0,1024);    //Copie les pages 3 a 2
	}
	goto debut;}
//****************** 1er Menu *******************
int choosemenu(){short key,i=0,carres[3][4]={{9,34,46,45},{39,46,85,57},{79,34,113,45}};
	//clearpage(0);
	disp_bmp(MENU1,0);
	disp_bmp(MENU2,2);
	fillgRect(carres[i][0],carres[i][1],carres[i][2],carres[i][3],0);
	debut:
	key=waitkey();
	if(key==28&&i!=1) return i+1;
	if(key==77||key==75){
	if(key==77) i++;
	if(i==3) i=0;
	if(key==75) i--;
	if(i<0) i=2;
	disp_bmp(MENU2,3);
	fillgRect(carres[i][0],carres[i][1],carres[i][2],carres[i][3],1);
	movedata(0x1ae0,0,0x1aa0,0,1024);    //Copie les pages 3 a 2
	}
	goto debut;}
//*********************** Magasin **********************
char shopnames[5][17]={"LIFE 5       20","LIFE 10      40","WEAPON 2    500","WEAPON 3    800","WEAPON 4   1600"};
short shopprices[5]={20,40,500,800,1600};
void spaceshop(){int i,key,carres[5][4]={{11,15,114,23},{11,23,114,31},{11,31,114,39},{11,39,114,47},{11,47,114,55}};
	//clearpage(0);
	debutshop:
	disp_bmp(SPACESHOP,0);
	hline2(13,100,11,0,0);
	gotoxy(8,1);
	printf("%i",moi[4]);
	for(i=0;i<5;i++) locate(3,i+3,shopnames[i]);
	i=0;
	invRect(carres[i][0],carres[i][1],carres[i][2],carres[i][3],0);
	debut:
   gotoxy(8,1);
	printf("%i  ",moi[4]);
	hline2(13,moi[0]+13,11,0,1);  // Vie remet
	key=waitkey();
	if(key==59) goto buy;
	if(key==28) return;
	if(key==80||key==72){
	invRect(carres[i][0],carres[i][1],carres[i][2],carres[i][3],0);
	if(key==80) i++;
	if(i==5) i=0;
	if(key==72) i--;
	if(i<0) i=4;
	invRect(carres[i][0],carres[i][1],carres[i][2],carres[i][3],0);}
	goto debut;
	buy:
	if((moi[4]-shopprices[i])<0) goto debut;
	if(i==0){if(moi[0]<=95){moi[0]+=5;moi[4]=moi[4]-shopprices[0];}};
	if(i==1){if(moi[0]<=90){moi[0]+=10;moi[4]=moi[4]-shopprices[1];}};
	if(i==2){if(moi[1]!=1){moi[1]=1;moi[4]=moi[4]-shopprices[2];shopprices[2]=0;}};
	if(i==3){if(moi[1]!=2){moi[1]=2;moi[4]=moi[4]-shopprices[3];shopprices[2]=0;}};
	if(i==4){if(moi[1]!=3){moi[1]=3;moi[4]=moi[4]-shopprices[4];shopprices[2]=0;}};
	goto debut;};
//********************** Pause dans le Jeu ********************
short spacepause(){short key=0,i=0,box[3][2]={{21,32},{32,43},{43,54}};
	actint9();
	//setpage(0);
	//clearpage(0);
	disp_bmp(PAUSE1,0);
	disp_bmp(PAUSE2,2);
	fillgRect(34,box[i][0],92,box[i][1],0);
	debut:
	key=waitkey();
	if(key==88) contplus();
	if(key==89) contless();
	if(key==28&&i==2) return 1;
	if(key==28&&i==0){desactint9(); return 0;}
	if(key==69) shutcalc();
	if(key==72||key==80){
	//invRect(34,box[i][0],92,box[i][1],0);
	if(key==72) i--;
	if(i<0) i=2;
	if(key==80) i++;
	if(i==3) i=0;
	disp_bmp(PAUSE2,3);
	fillgRect(34,box[i][0],92,box[i][1],1);
	movedata(0x1ae0,0,0x1aa0,0,1024);    //Copie les pages 3 a 2
	}
	goto debut; };
//*********************** DEMARAGE DU PROGRAMME *********************
void main(){
int i,j,key=0,move=1,passage=0;
int speed=3,psgtir=0,rnd=0,bossmove=1,range=30,pfond=0,nfond=0,save_ok=0,is_saved=0;
char save_pfond,save_speed,save_psgtir,save_bossmove,save_move,save_passage;
//********* DEBUT PROG **********
//Desactive le menu
desactmenu();
//Affiche le logo Na-Prod
setpage(0);
clearpage(0);
clearpage(2);
setgray();
disp_bmp(SPACENA1,0);
disp_bmp(SPACENA2,2);
waitkey();
//CHERCHER LE BASIC
if (search_basic_file(" SIDAT", &bf) == -1) goto warning;
if (bf.b_size<1024) goto warning;
//Verifier si jeu deja sauvegarde et mettre is_saved a 1
save_ok=1;
goto bas_ok;
warning:
save_ok=0;
disp_bmp(WARNING1,0);
disp_bmp(WARNING2,2);
waitkey();
bas_ok:
//Remet en C3
clearpage(0);
setnb();
debutgame:
//Met en gris
setgray();
//Reset Player
loadmoi();
//Vide Buffers
delbuf();
//Maz Level
level=0;
//Rmet page
setpage(0);
//Menu de Depart
start:
//Attends le choix
key=choosemenu();
clearpage(0);
setnb();
//On Quitte deja !!
if(key==3) goto fin;
//On remet en gris
setgray();
//Ici si is_saved et save_ok afficher le menu : saved/new
// Si save, loader et aller a debutlevel
//On va jouer
range=chooselvl();
//ESC -> Menu de Depart
if(range==50) goto start;
//On repasse en C3
setnb();
//Reglage de Vitesse
speed=range+vitesse;
//Boucle de LEVEL
debutlevel:
//On charge le level
loadlevel(level);
//On efface
clearpage(0);
//Oh le beau dessin
disp_bmp(SPACELEVEL,0);
//On en est ou alors ?
locate(7,4,"Level ");
gotoxy(13,4);
printf("%i",level+1);
waitkey();
//Nous voila arrivés au jeu
//On prépare la mem vidéo
setpage(0);
clearpage(0);
clearpage(1);
clearpage(2);
clearpage(3);
//desactive le remplissage du buffer touche
desactint9();
//On met le gris
setgray();
//On definie le fond a prendre
nfond=lvl_fond[level];
//************************ DEBUT DE LA BOUCLE ****************
DebutBoucle:
//****** Mise en Gris ********
asm mov al,0xdb;
asm out 0x02,al;
//****** Variables ********
	passage++;  //Ajoute 1 au compteur de passage (vitesse ennemie)
	pfond++;    //Fait avancer le fond d'une ligne
	if(pfond>=128) pfond=0;  //Verifie si n'a pas depasse
//****** VIDEO ********
	clearpage(1);   //Efface la page temp 1
	clearpage(3);   //Efface la page temp 3
//****** DESSINS ********
	show_fond(nfond,pfond,3,fonds);  //Affiche le fond
	drawtirs(1);   //Affiche les tirs
	drawcadeaux(1); //Affiche les bonus
	moidraw(moi[2],moi[3],moi[1],1);  //Affiche le perso
	hlineg(0,moi[0],63,1);  //Ligne de Vie
	if(boss[0]>0) bossdraw(boss[2],boss[3],boss[1],1); //Affiche le boss
	drawennemis(); //Les ennemis
//***** Les Explosions ******
	for(i=0;i<10;i++)
		if(xplosion[i][0]<13){
			xplosdraw(xplosion[i][1],xplosion[i][2],xplosion[i][1],1);
			xplosion[i][0]++;
			xplosion[i][2]++; }
//****** SCRENSHOT ********
	if(checkshift()==1&&checkf6()==1){
		shootpage(0,"HCOPY1");
		shootpage(2,"HCOPY2");}
//****** PAUSE ********
	if(checkesc()==1) {
		//setnb();
		if(spacepause()==1){
			//Si save_ok alors demander si ils veulent sauvegarder
			moi[0]=0;            //On SE casse !
			goto endgame; }
		//setgray();
		}
//****** REFRESH ********
	movedata(0x1a60,0,0x1a20,0,1024);    //Copie les pages 1 a 0
	movedata(0x1ae0,0,0x1aa0,0,1024);    //Copie les pages 3 a 2
//****** BONUS ********
	if(rand()%50==15&&cadeauio==1) addcadeau(40+rand()%48,6,rand()%2); //Ajout de bonus
//****** PERSO ********
	if(checkgauche()==1&&moi[2]>6) moi[2]-=3;  //A Gauche
	if(checkdroite()==1&&moi[2]<115) moi[2]+=3;  //A droite
	if(checkfire()==1) psgtir++;
	if(checkfire()==1&&psgtir>2){
		addtirmoi(moi[2]+3,55);  //moi tire
		psgtir=0;}
//****** ENNEMIS ********
	if(passage>speed){            //Compteur de vitesse ecoulé ?
		range=30;                  //Indice de Random
		passage=0;                 //Compteur a 0
		if(move==1) {posxennemi+=2;   //On avance les ennemis
			for(i=0;i<21;i++){ rnd=rand()%range;   //On fait tirer les enemis
			if(ennemis[i][0]>0){        //Seulement les ennemis OK avancent
			ennemis[i][2]++;   //On fait avancer 1 par un
			if(rnd==14) addtirennemi(ennemis[i][2]+2,ennemis[i][3]+5,i);}}} //Et les fait tirer si c bon
		if(move==0) {posxennemi-=2;      //pareil mais dans l'autre sens
			for(i=0;i<21;i++){ rnd=rand()%range;
			if(ennemis[i][0]>0){
			ennemis[i][2]--;
			if(rnd==14) addtirennemi(ennemis[i][2]+2,ennemis[i][3]+5,i);}}}
		if(posxennemi>=53) move=0;           //On inverse le sens
		if(posxennemi<=3) move=1;            //On inverse le sens
//****** BOSS ********
		range=10;            //Indice inferieur
		if(bossmove==1) if(boss[0]>0) { rnd=rand()%range;    //Compteur de vitesse
			 boss[2]+=2;                                      //On l'avance et fait tirer
			 if(rnd==4) addtirboss(boss[2]+5,boss[3]+5);}
		if(bossmove==0) if(boss[0]>0) {
			rnd=rand()%range;
			boss[2]-=2;                                       //On l'avance et fait tirer
			if(rnd==4) addtirboss(boss[2]+5,boss[3]+5);}
		if(boss[2]>=110) if(boss[0]>0) bossmove=0;   //On inverse le sens
		if(boss[2]<=0) if(boss[0]>0) bossmove=1;}    //On inverse le sens
//****** AUTRES ********
	refreshtirs(moi[2],55);             //Les tirs ont-ils fait des degats ?
	refreshcadeaux();                   //Et les bonus des heureux?
//****** FIN DU JEU ********
	if(countennemi()==0) goto endgame;     //Ya pu personne ?
	if(countennemi()==5&&boss[0]==0) boss[0]=6+(4-speed)*level;  //On met le boss
	if(moi[0]<1) goto endgame;    //Suis-je mort ?
	if(checkf1()!=0) goto endgame;   //Ahah un trick de DEBUG !!
//****** ON RECOMENCE SANS CONDITION ********
asm jmp DebutBoucle;
//****** FIN BOUCLE ********
endgame:
setnb(); //Remet en Noir&Blanc
endpause:
actint9();  //Reactive le remplissage
delbuf();
if(moi[0]<1) {
	clearpage(0);
	setgray();
	disp_bmp(GOVER1,0);
	disp_bmp(GOVER2,2);
	setnb();
	setpage(0);
	waitkey();
	goto debutgame; }
if(level==9) {
	clearpage(0);
	setgray();
	disp_bmp(BRAVO1,0);
	disp_bmp(BRAVO2,2);
	setnb();
	setpage(0);
	waitkey();
	goto debutgame; }
clearpage(0);
clearpage(1);
setpage(0);
spaceshop();
level++;
goto debutlevel;
fin:
clearpage(0);
clearpage(2);
setpage(0);
setgray();
disp_bmp(SPACEEND1,0);
disp_bmp(SPACEEND2,2);
waitkey();
clearpage(0);
setnb();
reactmenu();
return;
}

