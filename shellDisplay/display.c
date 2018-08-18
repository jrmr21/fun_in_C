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
				break;
				case 'd':			//	if it's int
					i++;			//	move ++ in buffer (*s)
					int temp =  va_arg(arg, int);  // get int value
					putInt(temp);		//	put int value
					break;
				case 'f':			//	float print
					i++;
					float tempF = 0;	//	tempo float
					tempF = va_arg(arg, double);	// get float user
					putInt( tempF);		//	display int part of float
					putchar('.');		//	show .
					
					if(tempF < 0) tempF *= -1;	// convert positive value for easy maths progress...
					tempF = tempF - ((int)tempF);	//	get just float value ex: 12.354 =>> 0.354
					int i = 1;			//	init i size
					get_sizeDecimal(tempF, &i);	// get i size (for last example i== 100)

					i *=10;		//	add *10 to resolve bug (100 is bad, good size is 1000 for last example)
				
					if(tempF < 0) tempF *= -1;	//	if decimal is - convert to +
					putInt((int)(tempF * i)); 	//	print decimal after .
					break;
				case 's':				//	string print
					i++;
					char* tempStr = NULL;		//	temp buffer to string
					tempStr = va_arg(arg, void*);  // get string value
					
					int sizeStr = 0;	// prepare size string
					sizeStr = get_sizeDisplay( tempStr ); // get size string
					
					for(int i=0; i<sizeStr; i++)	// display string
					{
						putchar( tempStr[i]);
					}
														// corriger le 's' du #s qui traine	

					break;
				case 'b':
					i++;
					int tempoB = va_arg(arg,int);
					
					if( tempoB == 1 )
					{
						puts("true");
					}
					else
					{
						puts("false");
					}
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
}


static int get_sizeDisplay(char* string)	//	get size buffer
{
	int i;
	for(i=0; *string; string++) i++;
	return i;
}

static void get_sizeDecimal(float entre, int* i)
{
	float tempo = entre;
	for(*i; (entre - (int)tempo) > 0; *i *=10)
	{
		tempo = entre* *i;
	}

}
static int get_sizeInt(int entre, int* i)
{
	int size =0;
	for(*i; entre- *i > 10; *i *= 10)       //      read size
        {
	        size++;
        }
	return size;
}

static void putInt(int string)		//	display PUTIIIN VIVA RUSSIA LOL (display int)
{
	if(string < 0)		//	reverse negative value to read more easy
	{
	      string *= -1;
	      putchar('-');		//	but display negative value :)
	      //addBuffer( '-' );
	}

	int i=1;			//	prepare count
        int size = 0;		//	init size int (1, 10, 100 ect..)
	
	size = get_sizeInt(string, &i);
	
	if(size > 2)	//	if it's a big size
	{
		for(int b=0; b < (size); b++)
		{
			i /= 10;
			putchar((int)(string/i)%10 + '0');	
		}
	}
	else		//	if it's a little size
	{
		i *= 10; 		//	maths error to display an int with 1 or 2 size
		for(int b=-1; b < (size); b++)
		{
  	                i /= 10;
                	putchar((int)(string/i)%10 + '0');
		}
	}

}
