#include "libft.h"

size_t  strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  dst_len;
    size_t  src_len;
    size_t  cnt;

    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
    if (dstsize <= dst_len)
        return (src_len + dstsize);
    while (*dst)
        dst++;
    cnt = 0;
    while (*src && dst_len + cnt < dstsize - 1)
    {
        dst[dst_len + cnt] = src[cnt];
        cnt++;
    }
    dst[dst_len + cnt] = '\0';
    return (dst_len + src_len);
}