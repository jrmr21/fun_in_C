#ifndef FT_HEADER_H
#define FT_HEADER_H

# include <stdlib.h>
# include <unistd.h>

//**** ft_putchar.c                          ** print char
void    ft_putchar(char c);
//****  ft_putstr.c                          ** print str
void	ft_putstr(char *str);
//****  ft_putnbr.c                          **  print int
void	ft_putnbr(int nb);
//****  ft_swap.c                            **  just swap it's equal to made a switch in skate LOL
void	ft_swap(int *a, int *b);
//****  ft_strlen.c                          ** get size table
int		ft_strlen(char *str);
//****  ft_strrev.c                          ** reverse char table order
char	*ft_strrev(char *str);
//****  ft_atoi.c                            ** convert char to int
int		ft_atoi(char *str);
//****  ft_short_integer_table.c             ** tri a bulle
void	ft_sort_integer_table(int *tab, int size);
//****  ft_iterative_factorial.c             ** factorialle du int max
int		ft_iterative_factorial(int nb);
//****  ft_recursive_factorial.c              ** factorialle du int max in recursive (MORE FAST)
int		ft_recursive_factorial(int nb);
//****  ft_recusrive_power.c                   ** power function
int		ft_recursive_power(int nb, int power);
//****  ft_strcpy.c                             ** cpy str to str
char	*ft_strcpy(char *dest, char *src);
//****  ft_strncpy.c                            **  cpy x number str to str
char	*ft_strncpy(char *dest, char *src, unsigned int n);
//****  ft_strcmp.c                             **  compare 2 char in char*
int		ft_strcmp(char *s1, char *s2);
//****  ft_strncmp.c                             ** cmp 2 str with limit read (n)
int		ft_strncmp(char *s1, char *s2, unsigned int n);
//****  ft_strupcase(char *str)                 **  in char* up char minuscule to majuscule
char	*ft_strupcase(char *str);
//****  ft_strlowcase.c                         **  in char* DOWN char minuscule to UP
char	*ft_strlowcase(char *str);
//****  ft_strcapitalize.c                      **  just for fun, up or down double char
char	*ft_strcapitalize(char *str);
//****  ft_str_is_alpha.c                       ** char* is a letter return 1, else return 0
int		ft_str_is_alpha(char *str);
//****  ft_str_is_numeric.c                     ** char* is a number return 1, else return 0
int		ft_str_is_numeric(char *str);
//****  ft_str_is_numeric.c                     ** char* is a char LOW return 1, else return 0
int		ft_str_is_lowercase(char *str);
//****  ft_str_is_numeric.c                     ** char* is a char UP return 1, else return 0
int		ft_str_is_uppercase(char *str);
//****  ft_str_is_printable.c                   ** char* is printable, in ASCII return 1, else return 0
int		ft_str_is_printable(char *str);
//****  ft_strcat.c                             **  add to table char* a new char
char	*ft_strcat(char *dest, char *src);
//****  ft_strncat.c                             **  add to table char* a new char in size nd
char	*ft_strncat(char *dest, char *src, int nb);
//****

//****
#endif
