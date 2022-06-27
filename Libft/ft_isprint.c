#include "libft.h"

int ft_isalnum(int c)
{
    if (' ' <= c && c <= '~')
        return (1);
    else
        return (0);
}