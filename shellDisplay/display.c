#include "display.h"


extern void displayTest()
{
	putchar('\n');	
	puts("JRMR DISPLAY");
	putchar('\n');

}

extern void display(void* s, ...)
{
	char* string = s;
	va_list arg; // create you arg list
	va_start( arg, s); // init to read past string (despues senor)
	
	int argNumber = get_sizeDisplay(string);
	//printf("vous avez entre : %s \n",string);

	for(int i=0; i < argNumber; i++)	//	checking all arg
	{	
		if( string[i] == '#')		//	check type
		{
			switch(string[i+1])	//	if it's true MAGICAL RUN
			{
				case 'c':		//	for char
					i = i+1;		//	move ++ in *s
					putchar( (char) (va_arg(arg, int)) ); 	//putchar
					break;
				case 'd':			//	if it's int
					i++;			//	move ++ in buffer (*s)
					int temp = va_arg(arg, void*);  // get int value

					putInt(temp);		//	put int value
					break;
				default:
					break;
			}

		}
		else
		{
			putchar(string[i]);	//	just putchar for all buffer (exept #value)
		}
	}

	putchar('\n');		//	prout...
}


static int get_sizeDisplay(char* string)	//	get size buffer
{
	int i;
	for(i=0; *string; string++) i++;
	return i;
}

void putInt(int string)		//	display PUTIIIN VIVA RUSSIA LOL (display int)
{
	if(string < 0)		//	reverse negative value to read more easy
	{
	      string *= -1;
	      putchar('-');		//	but display negative value :)
	}

	int i=1;			//	prepare count
        int size = 0;		//	init size int (1, 10, 100 ect..)
	
	for(i=1; string-i > 10; i = i*10)	//	read size
        {
  	      size++;
        }
	if(size > 2)	//	if it's a big size
	{

		for(int b=0; b<size; b++)
		{
			i /= 10;
			putchar((int)(string/i)%10 + '0');	
		}
	}
	else if(size > 1)	//	if it's a midle size
	{
		putchar((int)(string/10)%10 + '0');
		putchar((int)(string)%10 + '0');
	}
	else		//	if it's a little size
	{
		putchar((int)(string)%10 + '0');
	}
}

