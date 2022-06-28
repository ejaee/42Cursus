#include "libft.h"

char    *strchr(const char *s, int c)
{
    char *res;

    res = '\0';
    while (1)
    {
        if (*s == (char)c)
            res = (char *)s;
        if (*s == '\0')
            return (res);
        s++;
    }
}