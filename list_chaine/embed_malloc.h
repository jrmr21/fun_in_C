#ifndef EMBED_MALLOC_H_
#define EMBED_MALLOC_H_

#include <stdlib.h>
#include <stdint.h>

#include <stdio.h>

typedef struct tab_s tab_s;

struct			tab_s
{
	uint8_t		data;
	tab_s	*	next;
};

uint8_t	add_element(tab_s * tab, int size);

uint8_t setValue_element(tab_s * tab, int bloc, uint8_t playLoad);

uint8_t getValue_element(tab_s * tab, int bloc);

uint8_t	clearAll_element(tab_s * tab);

int	sizeof_element(tab_s * tab);

void	show_element(tab_s * tab);

#endif
