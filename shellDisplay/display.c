#include "display.h"

static void addBuffer(char input)
{
	*out++ = input;
}

extern void displayTest()
{
	putchar('\n');	
	puts("JRMR DISPLAY");
	putchar('\n');

}

extern void display(void* s, ...)
{
	char* string = s;
	out = NULL;
	va_list arg; // create you arg list
	va_start( arg, s); // init to read past string (despues senor)
	
	int argNumber = get_sizeDisplay(string);
	

	for(int i=0; i < argNumber; i++)	//	checking all arg
	{	
		if( string[i] == '#')		//	check type
		{
			switch(string[i+1])	//	if it's true MAGICAL RUN
			{
				case 'c':		//	for char
					i++;		//	move ++ in *s
					putchar( (char) (va_arg(arg, int)) ); 	//putchar
				
		//			addBuffer( (char) (va_arg(arg, int)) );
				break;
				case 'd':			//	if it's int
					i++;			//	move ++ in buffer (*s)
					int temp = 0;
					temp = va_arg(arg, void*);  // get int value
					putInt(temp);		//	put int value
					break;
				case 's':
					i++;
					char* tempStr = NULL;		//	temp buffer to string
					tempStr = va_arg(arg, void*);  // get string value
					
					int sizeStr = 0;	// prepare size string
					sizeStr = get_sizeDisplay( tempStr ); // get size string
					
					for(int i=0; i<sizeStr; i++)	// display string
					{
						putchar( tempStr[i]);
					}	
					break;
				default:
					break;
			}

		}
		else
		{
			putchar(string[i]);	//	just putchar for all buffer (exept #value)
			//	addBuffer( string[i] );
		}
	}

	//putchar('\n');		//	prout...
	

	//puts( out);
	//putchar('\n');
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
	      //addBuffer( '-' );
	}

	int i=1;			//	prepare count
        int size = 0;		//	init size int (1, 10, 100 ect..)
	
	for(i=1; string-i > 10; i = i*10)	//	read size
        {
  	      size++;
        }
	
	if(size > 2)	//	if it's a big size
	{
		
		for(int b=0; b < (size); b++)
		{
			i /= 10;
			putchar((int)(string/i)%10 + '0');
			
			//addBuffer( ((int)(string/i)%10 + '0') );	
		}
	}
	else		//	if it's a little size
	{
		i *= 10; 		//	maths error to display an int with 1 or 2 size
		for(int b=-1; b < (size); b++)
		{
  	                i /= 10;
                	putchar((int)(string/i)%10 + '0');

			//addBuffer( ((int)(string/i)%10 + '0') );
		}
	}

}


