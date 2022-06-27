#include "libft.h"

int ft_isalpha(int c)
{
    if ('A' <= c && c <= 'Z')
        return (1);
    else if ('a' <= c && c <= 'z')
        return (1);
    else
        return (0);
}