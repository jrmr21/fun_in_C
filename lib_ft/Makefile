#*********** JRMR MAKEFILE *************#

NAME 	= 	ft_lib.a

SRC	=	ft_atoi.c	\
		ft_putchar.c	\
		ft_putnbr.c

FLAGS	=	-Werror \
		-Wextra \
		-Wall

OBJETS	=	*.o

all 	: 
	gcc $(FLAGS) $(SRC) -c
	ar r $(NAME) $(OBJECTS)

range	:				# important to range your function /!\#
	ranlib $(NAME)

clean 	:	
	rm -f $(OBJETS)

fclean	:	
	clean
	rm -f $(name)
