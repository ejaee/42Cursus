#include "libft_h"

size_t  strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  idx;
    size_t  src_len;

    src_len = ft_strlen(src);
    if (!dstsize)
        return (src_len);
    while (src[idx] && idx < (dstsize - 1))
    {
        dst[idx] = src[idx];
        idx++;
    }
    dst[idx] = '\0';
    return (src_len);
}