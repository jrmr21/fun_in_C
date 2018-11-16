#include "ft_header.h"

//          WORK IN PROGRESS...

void    ft_average(void* in, void* out)
{
    int*    pt;
    int*    pto;
    int     i;

    pt      = (int)&in;
    i       = 0;
    *pto    = 0;
    while(*pt)
    {
        *pto += *pt;
        pt++;
        i++;
    }
    *pto /= i;
}
