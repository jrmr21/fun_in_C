#include "embed_malloc.h"
#include <stdio.h>


int	main(int argc, char** argv)
{
	char 	c ;
	tab_s 	test;

	
	test.next	= NULL;
	test.data	= 0;

	c		= 2;

	c 		= add_element(&test, 13);
	c		= setValue_element(&test, 10, 14);

	
	printf("debug : %d \nresult :  %d \nsize: %d\n", c, getValue_element(&test, 10),  sizeof_element(&test));

	show_element(&test);
	
	printf("\n\n ---------------------------------- \n\n");	
	clearAll_element(&test);

	show_element(&test);

	if (argc || argv)
		return (1);
	return (0);
}
