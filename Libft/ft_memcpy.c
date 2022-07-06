#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t len)
{
    unsigned char *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (!dest && !src)
        return (0);
    while (len--)
        *d++ = *s++;
    return (dest);
}