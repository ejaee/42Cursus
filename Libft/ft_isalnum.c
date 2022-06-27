#include "libft.h"

int ft_isalnum(int c)
{
    if ('0' <= c && c <= '9')
        return (1);
    else if ('A' <= c && c <= 'Z')
        return (1);
    else if ('a' <= c && c <= 'z')
        return (1);
    else
        return (0);
}