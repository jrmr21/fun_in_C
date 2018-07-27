#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdio.h>
#include <stdarg.h>	// multiple arg
#include <string.h>

#define symbole #

/*
 c=va_arg(ap,int); // get arg at position (i++)
 va_list ap;	   // get all arg (it's a *) in ap
 va_start(ap,a);   // init AT THE FIRST ARG !!!!!

 thank's to: https://codes-sources.commentcamarche.net/faq/877-les-fonctions-a-nombre-variable-d-arguments


Operation	Result	Note
123 % 10	3	This gives the third/last digit
123 / 10	12	The gives the remaining digits
12 % 10		2	This gives the second digit
12 / 10		1	This gives the remaining digits
1 % 10		1	This gives the first digit
1 / 10		0	This is when we stop

 thank's to: https://wuhrr.wordpress.com/2007/11/09/how-to-print-a-long-integer-using-only-putchar/


	 	just display int (#d), char(#c) and string(#s) 
*/
#define bool int 	//	my boolean define /!\ no compatible official library
#define true 1
#define false 0


static char* out=NULL;		//	future surprise ^.^
extern void displayTest();
extern void display(void* string, ...);		// my little printf(work in progress..)


static int get_sizeInt(int entre,int* i);	//	size int (1, 10, 100, 1000...)
static void get_sizeDecimal(float entre,int *i);	//help to convert decimal to int
static void putInt(int string);		//	putchar for int
static int get_sizeDisplay(char* string);	//get size string
static void addBuffer(char input);


#endif
