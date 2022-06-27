#include "libft.h"

int ft_tolower(int c)
{
    if ('a' <= c && c <= 'z')
        c += 32;
    return (c);
}