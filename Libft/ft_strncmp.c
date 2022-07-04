#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  idx;

    idx = 0;
    while (n--)
    {
        if (s1[idx] != s2[idx])
            return ((const unsigned char)s1[idx] - (const unsigned char)s2[idx]);
        idx++;
    }
    return (0);
}