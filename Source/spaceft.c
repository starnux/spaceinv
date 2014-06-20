/****************************************************\
				  000       00000000000000
				 0   0          0000
				 0             0000
				  000 PACE    0000NVADERS
					  0       0000                0
				 0   0      0000                  0
				  000  00000000000000000000000000000  AFX/2
															 0
						Functions and Routines		0

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
#include "spacevar.c"
#define DATA_SIZE 1024
typedef unsigned char BMPTabType [DATA_SIZE];
void setbpix();
//******************* DEFINITIONS *************
//Xplosion : 0-nb 1-x 2-y
char xplosion[10][3];
char save_xplosion[10][3];
//ENNEMIS: 0-Vie 1-type 2-X 3-Y 4-Force 5-TypeTir
short ennemis[20][6];
char save_ennemis[20][6];
//MOI: 0-Vie 1-Arme 2-X 3-Y 4-Argent
short moi[5]={100,0,10,55,0};
short save_moi[5];
//BOSS: 0-Vie 1-type 2-X 3-Y 4-Force 5-TypeTir
short boss[6];
char save_boss[6];
// TIRMOI : 0-On/Off 1-X 2-Y
signed short int tirmoi[30][3];
char save_tirmoi[30][3];
// TIRENNEMI : 0-On/Off 1-X 2-Y 3-Source
signed short int tirennemi[30][4];
char save_tirennemi[30][4];
// TIRBOSS : 0-On/Off 1-X 2-Y
signed short int tirboss[30][3];
char save_tirboss[30][3];
// TIRMOI : 0-On/Off 1-X 2-Y 3-Type
signed short int cadeaux[5][4];
char save_cadeaux[5][4];
//Position Générale de l'ennemi
short posxennemi=20;
char save_posxennemi=20;
//Bonus activés ?
short cadeauio=1;
char save_cadeauio=1;
//Coefficient de ralentissement
short vitesse=0;
char save_vitesse=0;
//******************* Charge Levels ****************
//Level
short level=0;
char save_level=0;
//Charge un level
void loadlevel(short level){int i,j;
for(i=0;i<20;i++) for(j=0;j<6;j++) ennemis[i][j]=ennemis0[level][i][j];
for(i=0;i<6;i++) boss[i]=boss0[level][i];
posxennemi=20;}
//Recharge le perso initial
void loadmoi(){int i;for(i=0;i<5;i++) moi[i]=moi0[i];}
//Vide les buffers TIRS
void delbuf(){short i,j;
	for(i=0;i<30;i++){
		for (j=0;j<3;j++){tirboss[i][j]=0;tirmoi[i][j]=0;}
		for (j=0;j<4;j++) tirennemi[i][j]=0  ; }
	for(i=0;i<5;i++) for(j=0;j<4;j++) cadeaux[i][j]=0 ; }
//********************** Affichage Sprites *******************
void tirdraw(int x,int y,int nb,int page){
asm { mov ax,page
		shl ax,6
		add ax,0x1a20
		mov es,ax
		mov bx,120
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov ch,0 };
debut:
asm {	mov di,offset tirsprite
		xor dx,dx
		mov ax,nb
		shl ax,4
		mov dl,ch
		add di,ax
		add di,dx
		xor ax,ax
		mov dl,ds:[di]
		add di,8
		mov al,ds:[di]
		shl dx,cl
		or es:[si],dx
		add si,0x800
		shl ax,cl
		or es:[si],ax
		sub si,0x800
		sub si,16
		inc ch
		cmp ch,8
		jb debut}}
void xplosdraw(int x,int y,int nb,int page){
asm { mov ax,page
		shl ax,6
		add ax,0x1a20
		mov es,ax
		mov bx,120
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov ch,0 };
debut:
asm {	mov di,offset xplos
		xor dx,dx
		mov ax,nb
		shl ax,4
		mov dl,ch
		add di,ax
		add di,dx
		xor ax,ax
		mov dl,ds:[di]
		add di,8
		mov al,ds:[di]
		shl dx,cl
		or es:[si],dx
		add si,0x800
		shl ax,cl
		or es:[si],ax
		sub si,0x800
		sub si,16
		inc ch
		cmp ch,8
		jb debut}}
void ennemidraw(int x,int y,int nb,int page){
asm { mov ax,page
		shl ax,6
		add ax,0x1a20
		mov es,ax
		mov bx,120
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov ch,0 };
debut:
asm {	mov di,offset ennemisprite
		xor dx,dx
		mov ax,nb
		shl ax,4
		mov dl,ch
		add di,ax
		add di,dx
		xor ax,ax
		mov dl,ds:[di]
		add di,8
		mov al,ds:[di]
		shl dx,cl
		or es:[si],dx
		add si,0x800
		shl ax,cl
		or es:[si],ax
		sub si,0x800
		sub si,16
		inc ch
		cmp ch,8
		jb debut}}

void bossdraw(int x,int y,int nb,int page){
asm { mov ax,page
		shl ax,6
		add ax,0x1a20
		mov es,ax
		mov bx,120
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov ch,0 };
debut:
asm {	mov di,offset bosssprite
		xor dx,dx
		mov ax,nb
		shl ax,5
		mov dl,ch
		add di,ax
		add di,dx
		xor ax,ax
		mov dl,ds:[di]
		add di,16
		mov al,ds:[di]
		shl dx,cl
		or es:[si],dx
		add si,0x800
		shl ax,cl
		or es:[si],ax
		sub si,0x800
		sub si,16
		inc ch
		cmp ch,8
		jb debut
		mov ch,0
		dec si
		add si,112}
debut2:
asm { mov di,offset bosssprite
		xor dx,dx
		mov ax,nb
		shl ax,5
		mov dl,ch
		add di,ax
		add di,dx
		xor ax,ax
		add di,8
		mov dl,ds:[di]
		add di,16
		mov al,ds:[di]
		shl dx,cl
		or es:[si],dx
		add si,0x800
		shl ax,cl
		or es:[si],ax
		sub si,0x800
		sub si,16
		inc ch
		cmp ch,8
		jb debut2} }

void cadeaudraw(int x,int y,int nb,int page){
asm { mov ax,page
		shl ax,6
		add ax,0x1a20
		mov es,ax
		mov bx,120
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov ch,0 };
debut:
asm {	mov di,offset cadeausprite
		xor dx,dx
		mov ax,nb
		shl ax,4
		mov dl,ch
		add di,ax
		add di,dx
		xor ax,ax
		mov dl,ds:[di]
		add di,8
		mov al,ds:[di]
		shl dx,cl
		or es:[si],dx
		add si,0x800
		shl ax,cl
		or es:[si],ax
		sub si,0x800
		sub si,16
		inc ch
		cmp ch,8
		jb debut}}
/*void tirdraw(short x,short y,short type,short page)
{int i,j;
for(i=0;i<4;i++)
for(j=0;j<5;j++)
if(tirsprite[type][i][j]==1) setbpix(x+j,y+i,page);}; */

void moidraw(int x,int y,int nb,int page){
asm { mov ax,page
		shl ax,6
		add ax,0x1a20
		mov es,ax
		mov bx,120
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov ch,0 };
debut:
asm {	mov di,offset moisprite
		xor dx,dx
		mov ax,nb
		shl ax,4
		mov dl,ch
		add di,ax
		add di,dx
		xor ax,ax
		mov dl,ds:[di]
		add di,8
		mov al,ds:[di]
		shl dx,cl
		or es:[si],dx
		add si,0x800
		shl ax,cl
		or es:[si],ax
		sub si,0x800
		sub si,16
		inc ch
		cmp ch,8
		jb debut}}
//*************************** ECRAN**************************

/*void copypage(int source,int target){	//Copy la page source a la page target - Superna
asm{ xor di,di
     mov ax,target
     shl ax,6
     add ax,0x1a20
	  mov es,ax
	  mov ax,source
     shl ax,6
     add ax,0x1A20
     mov si,ax
     CLD
	  mov cx,0x200
	  rep movsw } }*/

void setPix(short X,short Y,short page,unsigned char couleur){  // Met un pixel Whyp&BradN&Superna
asm {	mov ax,page
	shl ax,6
	add ax,0x1a20
	mov es,ax
	mov cx,X
	mov dx,Y
	mov si,0x003f
	sub si,dx
	sub cx,0x80
	not cx
	push cx
	and cl,0xf8
	shl cx,0x03
	add si,cx
	pop cx
	and cl,0x07
	mov al,couleur
	mov bl,es:[si]		// Recupere le byte a changer
	db 0x0F,0x12,0x0C3      // clr1 bl,cl (specifique au nec v20/30)
	rol al,cl		// met le 1 (si 1) a la place voulue
	or bl,al		// Ecris le 1 (si 1)
	mov es:[si],bl };}	// Remet le byte

void invpixel(int X, int Y, int page) { // Inverse un pixel
asm {	mov ax,page
	shl ax,6
	add ax,0x1a20
	mov es,ax
	mov cx,X
	mov dx,Y
	mov si,0x003f
	sub si,dx
	sub cx,0x80
	not cx
	mov ax,cx
	and cl,0xf8
	shl cx,0x03
	add si,cx
	mov cx,ax
	and cl,0x07
	mov bl,es:[si];
	db 0x0F,0x016,0x0C3	//not1 bl,cl (specifique au nec v20/30)
	mov es:[si],bl; } }
/*
void invpixFB(int x,int y,int page){
asm {		mov ax,page
		shl ax,6
		add ax,0x1a20
		mov es,ax
		mov bx,127
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov al,1
		shl al,cl
		xor es:[si],al
		add si,0x800
		xor es:[si],al }}
  */
void setbpix(int x,int y,int page){
asm {		mov ax,page
		shl ax,6	
		add ax,0x1a20
		mov es,ax
		mov bx,127
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov al,1
		shl al,cl
		or es:[si],al
		add si,0x800
		or es:[si],al }}

void setgpix(int x,int y,int page){
asm {		mov ax,page
		shl ax,6	
		add ax,0x1a20
		mov es,ax 
		mov bx,127
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov al,1
		shl al,cl
		add si,0x800
		or es:[si],al }}

 /*
void show_spr(int x,int y,int nb,int page){
asm {		mov ax,page
		shl ax,6	
		add ax,0x1a20
		mov es,ax 
		mov bx,120
		mov si,63
		sub bx,x
		sub si,y
		shl si,4
		mov cl,bl
		shr bl,3
		and cl,7
		add si,bx
		mov ch,0 };
debut:
asm {		mov di,offset ennemisprite
		xor dx,dx
		mov ax,nb
		shl ax,4
		mov dl,ch
		add di,ax
		add di,dx
		xor ax,ax
		mov dl,ds:[di]
		add di,8
		mov al,ds:[di]
		shl dx,cl
		or es:[si],dx
		add si,0x800
		shl ax,cl
		or es:[si],ax
		sub si,0x800
		sub si,16
		inc ch
		cmp ch,8
		jb debut }} */

void clearpage(short page) {
int i;
asm mov ax,page;
asm shl ax,6;
asm add ax,0x1A20;
asm mov es,ax;
asm xor ax,ax;
for (i=0;i<1024;i+=2){
	_SI=i;
	asm mov es:[si],ax; } } 

int getpage(void) { //Prens la page courante (Moi)
	short sEgMt=peek(0x4E,0); // Recupere le segment
	return ((sEgMt-0x1A20)/0x40);}

void setpage(short page){  // Met la page voulue Libthium
	asm{
	mov ax,page
	shl ax,6
	add ax,0x1A20
	xor dx,dx
	shl ax,1
	rcl dx,1
	shl ax,1
	rcl dx,1
	shl ax,1
	rcl dx,1
	shl ax,1
	rcl dx,1
	out 0x05,ax
	mov al,dl
	out 0x07,al } }

void hlineg(int x1,int x2,int y,int page){int i;
for(i=x1;i<=x2;i++) setbpix(i,y,page);}

void hline2(int x1, int x2, int y,int page , int state) //Dessine une ligne Horizontale Duobab
	{int i;for(i=x1; i<x2;i++) setPix(i,y,page,state) ;}

void vline2(int y1, int y2, int x,int page , int state) //Dessine une ligne Verticale Duobab
	{int i;for(i=y1; i<y2;i++) setPix(x,i,page,state) ;}

void rect(int x1,int y1,int x2,int y2, int page, int state) //Dessine un rectangle Duobab
	{hline2(x1,x2,y1,page,state);
	hline2(x1,x2,y2,page,state);
	vline2(y1,y2,x1,page,state);
	vline2(y1,y2,x2,page,state);}

void fillRect(int x1,int y1,int x2,int y2,int page,int state) //Rempli un rectangle Duobab
	{int i,j;
	for(i=x1;i<=x2;i++)
		for(j=y1;j<=y2;j++)
			setPix(i,j,page,state);}
void fillgRect(int x1,int y1,int x2,int y2,int page) //Rempli un rectangle de gris Duobab
// Mode DB
// Ecriture sur (page+2)
	{int i,j;
	for(i=x1;i<=x2;i++)
		for(j=y1;j<=y2;j++)
			setgpix(i,j,page);}

void invRect(int x1,int y1,int x2,int y2,int page) //Inverse un rectangle Moi
	{int i,j;
	for(i=x1;i<=x2;i++)
		for(j=y1;j<=y2;j++)
			invpixel(i,j,page);}

int waitkey() //Attends une touche pressee et la retourne
	{int v=getch();
	if (v==0) v=getch();
	return v;}

void locate(int x,int y,char st[]){
	gotoxy(x,y);
	printf(st);}

void shutcalc(){ //Eteint la calculatrice Whyp
asm mov al,0x08;
asm out 0x0C,al;
//outportb(0x0C,0x08);
}

void contplus(){    //Plus fonce
asm{mov bl,0
mov ah,0x22
int 0x7C};};

void contless(){    //Plus Clair
asm{mov bl,1
mov ah,0x22
int 0x7C};};

void disp_bmp (BMPTabType BmpTab,int page) { // Plus rapide Par Moi, Whyp et Roeoender
asm{ mov ax,page
     shl ax,6
     add ax,0x1a20
     mov es,ax
     mov si,BmpTab
     xor di,di
     mov cx,0x200
     cld
	  rep movsw } }
/*
void show_fond(int nb,int ligne,int page,void * tab){int i,j;
asm mov ax,page;
asm shl ax,6;
asm add ax,0x1a20;
asm mov es,ax;
asm xor ax,ax;
asm mov si,ax;
asm sub si,2;
for(i=ligne;i<64+ligne;i++){
for(j=0;j<16;j+=2){
asm {
mov ax,i
shl ax,4
add ax,j
cmp ax,2048
jb is_ok
sub ax,2048 }
is_ok:
asm{
mov di,tab
mov bx,nb
shl bx,11
add di,bx
add di,ax
mov bx,ds:[di]
add si,2
mov es:[si],bx
}}}}
/*void show_fond(int nb,int ligne,int page,void * tab){int i,j;
asm mov ax,page;
asm shl ax,6;
asm add ax,0x1a20;
asm mov es,ax;
asm xor ax,ax;
asm mov si,ax;
//asm sub si,2;
for(i=ligne;i<64+ligne;i++){
//for(j=0;j<16;j+=2){
asm {
mov ax,i
shl ax,4
add ax,j
cmp ax,2048
jb is_ok
sub ax,2048 }
is_ok:
asm{
mov si,tab
mov bx,nb
shl bx,11
add si,bx
add si,ax
mov cx,8
rep movsw
//}
}}}*/

void show_fond(int nb,int ligne,int page,void * tab){
asm{
xor ax,ax
mov di,ax
mov si,ax
mov dx,ax
mov ax,page
shl ax,6
add ax,0x1a20
mov es,ax
cld }
start:
asm {
mov ax,dx
add ax,ligne
shl ax,4
cmp ax,2048
jb is_ok
sub ax,2048 }
is_ok:
asm{
mov si,tab
mov bx,nb
shl bx,11
add si,bx
add si,ax
mov cx,8
rep movsw
inc dx
cmp dx,64
jb start
}}

//********************** Complexes *************************
int shootpage(short page,char realname[6]) {  // Y@SS Prends un Screenshot
unsigned int segm_video=0x1A20+(page*0x40);
unsigned long adresse; 
unsigned int found=0, b=0, i, offset, progseg, segment;
progseg=segm_video + 0x200;
for(segment=progseg; segment < (progseg + 9000); segment++) {
	for (offset=0; offset < 16; offset++) { 
	if (((unsigned char)peekb(segment, offset)) == ((unsigned char)realname[b])) {
		b++; 
		if (b==5) { 
			found=1; 
			break; } } 
	else { 
		if (b) {
			b=0;
			offset--; } } } 
	if(found) break; } 
	if (!found) { 
		return (-1); } 
b--; b--; 
b += 3;
adresse=((unsigned long)segment) * 16 + offset;
segment=((adresse ) - (adresse )%16 )/16;
offset= (adresse )%16;
offset+=3;
movedata(segm_video,0,segment,offset,1024);
//for(b=0;b<=1024;b++) pokeb( segment , offset+b , peekb (segm_video, b));
return 1; }

int OldInt9Seg,OldInt9Off;    //adresses Int 9
void desactint9(void){asm {
	xor ax,ax
	mov es,ax
	mov ax,es:0x26     //Segment interruption 9
	mov OldInt9Seg,ax  //stocke dans variable
	mov ax,es:0x24     //Offset int9
	mov OldInt9Off,ax  //stocke dans variable
	mov ax,es:0x03FE   //segment int ff
	mov es:0x26,ax     //remplace seg 9 par seg ff
	mov ax,es:0x03FC   //offset int ff
	mov es:0x24,ax }}  //remplace offset 9 par offset ff
void actint9(void){asm{
	xor ax,ax
	mov es,ax
	mov ax,OldInt9Seg
	mov es:0x26,ax     //remet segment d'origine
	mov ax,OldInt9Off
	mov es:0x24,ax } } //remet offset d'origine

int OldInt7dSeg,OldInt7dOff;    //adresses Int 7d
void desactmenu(void){asm {
	xor ax,ax
	mov es,ax
	mov ax,es:0x1F6     //Segment interruption 9
	mov OldInt7dSeg,ax  //stocke dans variable
	mov ax,es:0x1f4     //Offset int9
	mov OldInt7dOff,ax  //stocke dans variable
	mov ax,es:0x03FE   //segment int ff
	mov es:0x1f6,ax     //remplace seg 9 par seg ff
	mov ax,es:0x03FC   //offset int ff
	mov es:0x1f4,ax }}  //remplace offset 9 par offset ff
void reactmenu(void){asm{
	xor ax,ax
	mov es,ax
	mov ax,OldInt7dSeg
	mov es:0x1f6,ax     //remet segment d'origine
	mov ax,OldInt7dOff
	mov es:0x1f4,ax } } //remet offset d'origine
// Verif appui des touches
short r;
int checkall(){
	asm mov ax,0xFFF;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0xFF;
	if(_AL!=0) return 1;
	return 0;}
int checkfire(){
	asm mov ax,0x100;
	asm out 0x13,ax;
	for(r=0;r<5;r++);
	asm in al,0x13;
	asm and al,0x20;
	if(_AL!=0) return 1;
	return 0;}
int checkdroite(){
	asm mov ax,0x200;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0x8;
	if(_AL!=0) return 1;
	return 0;}
int checkgauche(){
	asm mov ax,0x200;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0x40;
	if(_AL!=0) return 1;
	return 0;}
int checkbas(){
	asm mov ax,0x200;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0x10;
	if(_AL!=0) return 1;
	return 0;}
int checkhaut(){
	asm mov ax,0x200;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0x20;
	if(_AL!=0) return 1;
	return 0;}
int checkexe(){
	asm mov ax,0x002;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0x04;
	if(_AL!=0) return 1;
	return 0;}
int checkesc(){
	asm mov ax,0x80;
	asm out 0x13,ax;
	for(r=0;r<5;r++);
	asm in al,0x13;
	asm and al,0x8;
	if(_AL!=0) return 1;
	return 0;}
int checkshift(){
	asm mov ax,0x100;
	asm out 0x13,ax;
	for(r=0;r<5;r++);
	asm in al,0x13;
	asm and al,0x40;
	if(_AL!=0) return 1;
	return 0;}
int checkf6(){
	asm mov ax,0x400;
	asm out 0x13,ax;
	for(r=0;r<5;r++);
	asm in al,0x13;
	asm and al,0x2;
	if(_AL!=0) return 1;
	return 0;}
int checkf1(){
	asm mov ax,0x400;
	asm out 0x13,ax;
	for(r=0;r<5;r++);
	asm in al,0x13;
	asm and al,0x40;
	if(_AL!=0) return 1;
	return 0;}
int checkac(){
	asm mov ax,0x0001;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0x01;
	if(_AL!=0) return 1;
	return 0;}
int checkplus(){
	asm mov ax,0x004;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0x08;
	if(_AL!=0) return 1;
	return 0;}
int checkmoins(){
	asm mov ax,0x004;
	asm out 0x13,ax;
	asm nop;
	asm nop;
	asm nop;
	asm in al,0x13;
	asm and al,0x04;
	if(_AL!=0) return 1;
	return 0;}

void setgray(){int i;
asm mov al,0xfb;
asm out 0x02,al;
for(i=0;i<6;i++) contplus();}
void setnb(){int i;
asm mov al,0xc3;
asm out 0x02,al;
for(i=0;i<6;i++) contless();}