#include <stdio.h>
#include <stdarg.h>

#define NONE	0


void*	salut(void* p, ...)
{
	printf("\nsalut toi ");
}

void*	bye(void* p, ...)
{
	printf("\nbye bye");
}

void*	addition(void* p, ...)
{
	void*	v_out;
	int	size;
	int	out;
	va_list	arg;				// create list arg

	out	= 0;
	size	= *((int*) p);
	va_start(arg, p);			// init start pointer arg_list to *p pointer 

	for (int i = 0; i < size; i++)
	{
		out	+= *(va_arg(arg, int*));	// cast arg 1 to end in int	
	}						// evry call you move arg pointer
	
	va_end(arg);
		 
	return ((void*) &out);			// return pointer void
}


int	main(int argc, char** argv)
{
	void*	tmp[4];
	int	number[4];
	int	result;
	void*	(*dialogue[3])(void* i, ...);

	dialogue[0] = &salut;
	dialogue[1] = &bye;		// set function pointer in tab
	dialogue[2] = &addition;

	(*dialogue[0])(NONE);
	(*dialogue[1])(NONE);

	number[0]	= 1;
	number[1]	= 2;		// prepare values
	number[2]	= 3;

	
	tmp[0]	= (void*)&number[0];
	tmp[1]	= (void*)&number[1];	// cast value to void*
	tmp[2]	= (void*)&number[2];

	result	= (int)*(*dialogue[2])(tmp[2], tmp[0], tmp[1], tmp[2]);
	
	printf("\nfinal result %d", result);
	return (0);
}
