#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t count)
{
    const unsigned char *s1;
    const unsigned char *s2;
    int res;

    s1 = (const unsigned char*)str1;
    s2 = (const unsigned char*)str2;
    while (count--)
    {
        res = *(s1++) - *(s2++);
        if (res)
            return (res);
    }
    return 0;
}
/*
#include <stdio.h>
int main()
{
    printf("%d\n", ft_memcmp("apple/0abc", "apple/0def", 9));
    printf("%d\n", ft_memcmp("apple/0def", "apple/0adc", 9));
}
*/