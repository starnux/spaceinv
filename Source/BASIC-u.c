//Remix par Superna pour Space Invaders
//Juste l'organisation a ete modifiee
//Aucun code n'a ete modifie
/*********************************************
**   TOUCHE 3.7				    **
**					    **
**  Copyright (c) John Wellesz 2001 - 2002  **
**  All rights Reserved.		    **
*********************************************/

//BASIC_librairies release 1.02

/*
 * Read/write Routines for basics file. version 1.02
 * You have the right to use these functions ONLY if you let it in these originals file (BASICf-u.c and BASICf-u.h).
 */

//#include "BASIC-u.h"
// *******  BASIC-u.h file ********
struct BASICfile {		    //This structure is used by all the functions
    unsigned int b_offset;	    //to have information about the basic file
    unsigned int b_segment;	    //you have to define one and init it with the
    unsigned int b_inner_offset;    //function search_basic_file.
    unsigned int b_size;
    unsigned char b_name[10];
    unsigned char b_password[10];
};


/* This function must be used one time before other functions to init the BASICfile structure
 * then you will have to send the address of this structure to the other functions.
 *
 *  progname is the name of the basic prog
 *  bf is the name of a BASICfile structure
 *
 *  this function return the size of the basic prog if found and -1 if not.
 *
 *  Example:
 *
 *  void main (void)
 *  {
 *	struct BASICfile bf;
 *
 *	if (search_basic_file("TEST", &bf) != -1)
 *	    printf("TEST found ! The size is %u", bf.b_size);
 *	else
 *	    printf("TEST not found !");
 *  }
 *
 */
long		search_basic_file
    (unsigned char *progname, struct BASICfile *bf);
    
/* This function works like the write function for real files,
 * string can be everything, an int, a string, a structure...
 * offset is the location in the basic file where to write.
 * length is the length to write, if length > b_size then only b_size -24 are written.
 * So your calculator memory is protected it CAN only write within the basic file pointed by bf.
 *
 * EXAMPLE :
 *
 * {
 *	write_toBfile(&bf, &f1, 2, sizeof(f1));
 * }
 *
 * f1 is a structure.
 */
    
unsigned int	write_toBfile
    (struct BASICfile *bf, const void *string, int offset, unsigned length);
    
    /*
     * Well this change the password of a basic prog, password is the new one.
     * */
int		change_password
    (struct BASICfile *bf, unsigned char *password);
    
    /*works like the write one, dest can be everything an int, a string...
     *
     *
     * EXAMPLE:
     *
     * {
     *	unsigned int file_begining;
     * 
     *	read_toBfile(&bf, &file_begining, 0, sizeof(unsigned int));
     * }
     *
     * IMPORTANT the order of the two last arguments has been imverted (/version 1.0) to be like the write function one
     * SORRY for this but it was a mistake and caused me to loose a lot of time of debugging certain of my programs
     * just because I had inverted the arguments...
     * 
     */
unsigned	read_toBfile
    (struct BASICfile *bf, void *dest, unsigned offset,	unsigned length);

    /*
     *This fill a basic file with NULLs.
     */
void		clear_basfile
    (const struct BASICfile *bf);
//************************************
//#include "DEF.h"
//*********** DEF.h File *************
#ifndef _DEF_h_
#define _DEF_h_

#define ABS(a) (-(a) * ((a) < 0) + (a) * ((a) > 0))
#define SIGNUM(a) (-((a)<0)  + ((a)>0))

#define INT16MAX 0xFFFFL

typedef unsigned char u_char;
typedef unsigned int  u_int;

#endif // _DEF_h_
//*************************************
#include <dos.h>
#include <string.h>
unsigned int segm_video=0x1A20;
/*
   this is the video segment of our g100 the start of the
   basic prog info is at segm_video + 0x200.
   you have to set this address using this line before using any of the function below:
	Note that it is an extern variable so you have to init this variable in your main program (main function)

   Just put unsigned int segm_video; at the begining of your main .c file.
   This file cannot be included in your main .c file with the command #include "" you must add this
   file in your make file or in your project.

   To init this variable (segm_video) just put the line below in your main function.
   Note that you should include the file dos.h
   in your main .c file so the peek function can be put in inline mode and will be faster.

   segm_video=peekb(0x4E,0) + (peekb(0x4E,1) << 8);//this address has been discovered by Brad Normand

   See the file BASICf-u.h to know how to use these functions.
   */

// unsigned long search_basic_file {{{
long search_basic_file(unsigned char *progname, struct BASICfile *bf)
{
    long abs_address;
    unsigned int found,  prognamelength, progseg;
    //long offset, maxoffset, segment;
    unsigned int offset, maxoffset, segment;
    unsigned int b, i;
    unsigned char realname[11];

    progseg=segm_video + 0x200;
    prognamelength=strlen((char *)progname);

    realname[0]=1;//this char exist befor every name of a basic prog
    strcpy((char *)(realname + 1), (char *)progname);
    for(i=prognamelength + 1; i<9; i++)
	realname[i]=0;

    b=0; found=0; maxoffset = 0x10;
    for(segment=progseg; segment < (0x4000L); segment++)
    {
	//the next two lines are useless since segment < 4000
	//if (segment == 0xFFFFL)
	  //  maxoffset = 0x10000L;
	for (offset=0; offset < maxoffset; offset++)
	{
	    if (((unsigned char)peekb(segment, offset)) == ((unsigned char)realname[b]))
	    {
		b++;
		if (b==9)
		{
		    found=1;
		    break;
		}
	    }
	    else 
	    {
		if (b)
		{
		    b=0;
		    offset--;//the next iteratio, if offset was 0, offset will stay at 0
		}
	    }
	}
	if(found) break;
    }
    if (!found)

    {
	return (-1);
    }

    b++;
    abs_address = ((long)segment * 16) + offset - b;//calc the absolute address

    bf->b_offset  = (unsigned int)(abs_address % 16L);
    bf->b_segment = (unsigned int)(((long)(abs_address - bf->b_offset)) / 16L);
    
    //the segment is < to 4000h so the next commented lines are useless !
    //offset  = abs_address % 16;
    //segment = ((abs_address - offset) / 16L);

    //if (segment > INT16MAX)
    //{
    //	offset = abs_address - INT16MAX * 16;
    //	segment = INT16MAX;
    //}
    
    //bf->b_offset  = (unsigned int)offset;
    //bf->b_segment = (unsigned int)segment;
    
    
    bf->b_size=peek(bf->b_segment, bf->b_offset);//on the size directly because of the b += 3

    bf->b_inner_offset = bf->b_offset + 16 + 2 + 3;//on the content of the prog

    bf->b_offset += 3;//on the first letter of the name
    for (i=0; i<9; i++)
    {
    bf->b_password[i]=peekb(bf->b_segment, (unsigned int )(bf->b_offset + 8 + i));
	bf->b_name[i]=realname[i + 1];
    }
    bf->b_password[9]=0;
    bf->b_name[9]=0;

    return bf->b_size;
}
// }}}

// int change_password {{{
int change_password(struct BASICfile *bf, unsigned char *password)
{
    int i, length;
    unsigned char ctow;

    length=strlen((char *)password);
    
    if (length > 8)
    {
	return -1;
    }
    
    for (i=0; i<8; i++)
    {
	
	if (i < length)
	    ctow = password[i];
	else 
	    ctow = '\000';
	
	pokeb(bf->b_segment, bf->b_offset + 8 + i, ctow);
    }

    return length;
}
// }}}

// unsigned read_toBfile {{{
unsigned read_toBfile(struct BASICfile *bf, void *dest, unsigned offset, unsigned length)
{
    unsigned int real_size, i;

    real_size=(bf->b_size - 24);
    if (length > (real_size - offset))
	length = real_size - offset;


    for (i=0; i < length; i++)
    {
	((unsigned char *)dest)[i]=peekb(bf->b_segment, bf->b_inner_offset + i + offset);
    }
    
    return i;
}
// }}}

// unsigned int write_toBfile {{{
unsigned int write_toBfile(struct BASICfile *bf, const void *string, int offset,
	unsigned length)
{
    unsigned int real_size, i;

    real_size=(bf->b_size - 24);
    if (length > (real_size - offset))
	length = real_size - offset;

    for (i=0; i < length; i++)
    {
	pokeb(bf->b_segment, bf->b_inner_offset + i + offset, ((unsigned char *)string)[i]);
    }

    return i;
}
// }}}

// void clear_basfile {{{
void clear_basfile(const struct BASICfile *bf)
{
    long i, realsize;

    realsize= bf->b_size - 24;

    for (i=0; i<realsize; i++)
	pokeb(bf->b_segment, bf->b_inner_offset + i, (char)0);
}
// }}}
